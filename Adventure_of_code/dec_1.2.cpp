#include "dec_1.2.h"

FuelCounterController::FuelCounterController() {
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
	for (auto& it : fuelInput) {
		calculatedFuel.push_back(CalculateFuel(it));
	}
}

int FuelCounterController::CalculateFuel(int value) {
	int tmp_v;
	tmp_v = int(floor(float(value) / 3)-2);
	if (tmp_v <= 0) {
		return 0;
	}
	else {
		return tmp_v + CalculateFuel(tmp_v);
	}
}

void FuelCounterController::TotalFuelCounter() {
	for (auto& n : calculatedFuel) {
		TotalFuel += n;
	}
}

int FuelCounterController::getTotalFuelCounter() {
	return TotalFuel;
}
