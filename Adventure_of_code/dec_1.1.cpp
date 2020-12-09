#include "dec_1.1.h"

FuelCounterUpper::FuelCounterUpper() {
	string tmp;
	ifstream InputFile;
	InputFile.open("dec_1_input.txt");
	if (InputFile.is_open()) {
		int nol = 0;
		while (getline(InputFile, tmp)) {
			fuelInput.push_back(stoi(tmp));
		}
		InputFile.close();
	}
	else {
		cout << "No file found";
	}
}

void FuelCounterUpper::CalculateFuel() {
	for (auto& it : fuelInput) {
		float value = float(it) / 3;
		value = floor(value);
		calculatedFuel.push_back(int(value - 2));
	}
	for (auto& n : calculatedFuel)
	{
		TotalFuelCounter += n;
	}
}

int FuelCounterUpper::getTotalFuelCounter() {
	return TotalFuelCounter;
}
