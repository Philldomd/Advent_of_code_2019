#include "dec_2.1.h"

Intcode::Intcode() {
	string tmp;
	ifstream InputFile;
	InputFile.open("dec_2_input.txt");
	if (InputFile.is_open()) {
		while (getline(InputFile, tmp, ',')) {
			intVector.push_back(stoi(tmp));
		}
		InputFile.close();
	}
}

void Intcode::initialize(int noun, int verb) {
	intVector.at(1) = noun;
	intVector.at(2) = verb;
	computePos = 0;
	computeVector.assign(intVector.begin(), intVector.end());
}

int Intcode::Compute(void) {
	int opcode = computeVector.at(computePos);
	if (opcode == 99) {
		return 0;
	}
	int pos1 = computeVector.at(computeVector.at(computePos + 1));
	int pos2 = computeVector.at(computeVector.at(computePos + 2));
	int store = computeVector.at(computePos + 3);
	if (opcode == 1) {
		int value = pos1 + pos2;
		computeVector.at(store) = value;
		computePos += 4;
		Compute();
	}
	else if (opcode == 2) {
		int value = pos1 * pos2;
		computeVector.at(store) = value;
		computePos += 4;
		Compute();
	}
	else {
		cout << "An Error Occurred!\nOPCODE: " << opcode;
		return 0;
	}
	return computeVector.at(0);
}

int Intcode::getValue() {
	return computeVector.at(0);
}