#include "dec_5.h"

Intcode2::Intcode2(string input) {
	string tmp;
	ifstream InputFile;
	InputFile.open(input);
	if (InputFile.is_open()) {
		while (getline(InputFile, tmp, ',')) {
			intVector.push_back(stoi(tmp));
		}
		InputFile.close();
		computeVector.assign(intVector.begin(), intVector.end());
	}
}

void Intcode2::initialize() {
	computePos = 0;
	computeVector.assign(intVector.begin(), intVector.end());
	first = true;
	halted = false;
	paused = false;
}

int Intcode2::Compute(void) {
	int opcode = computeVector.at(computePos);
	int param1 = 0;
	int param2 = 0;
	uint_fast8_t test = stoi(to_string(opcode / 100),NULL,2);
	bool A = ((test & AFlag) == AFlag), B = ((test & BFlag) == BFlag), C = ((test & CFlag) == CFlag);
	int DE = opcode % 100;
	int value = 0;
	if (DE % 100 == 99) {
		return 0;
	}
	if (C == false) {
		param1 = computeVector.at(computeVector.at(computePos + 1));
	}
	else {
		param1 = computeVector.at(computePos + 1);
	}
	if (DE == 3) {
		param1 = computeVector.at(computePos + 1);
		cin >> computeVector.at(param1);
		computePos += 2;
		Compute();
		return 0;
	}
	else if (DE == 4) {
		cout << param1 << endl;
		computePos += 2;
		Compute();
		return 0;
	}

	if (B == false) {
		param2 = computeVector.at(computeVector.at(computePos + 2));
	}
	else {
		param2 = computeVector.at(computePos + 2);
	}

	if (DE == 1) {
		computeVector.at(computeVector.at(computePos + 3)) = param1 + param2;
		computePos += 4;
		Compute();
	}
	else if (DE == 2) {
		computeVector.at(computeVector.at(computePos + 3)) = param1 * param2;
		computePos += 4;
		Compute();
	}
	else if (DE == 5) {
		if (param1 != 0) {
			computePos = param2;
		}
		else {
			computePos += 3;
		}
		Compute();
	}
	else if (DE == 6) {
		if (param1 == 0) {
			computePos = param2;
		}
		else {
			computePos += 3;
		}
		Compute();
	}
	else if (DE == 7) {
		if (param1 < param2) {
			computeVector.at(computeVector.at(computePos + 3)) = 1;
		}
		else {
			computeVector.at(computeVector.at(computePos + 3)) = 0;
		}
		computePos += 4;
		Compute();
	}
	else if (DE == 8) {
		if (param1 == param2) {
			computeVector.at(computeVector.at(computePos + 3)) = 1;
		}
		else {
			computeVector.at(computeVector.at(computePos + 3)) = 0;
		}
		computePos += 4;
		Compute();
	}
	else {
		cout << "An Error Occurred!\nOPCODE: " << opcode << endl;
		return 0;
	}

	return computeVector.at(0);
}

void Intcode2::Compute(int& in, int& out) {
	int opcode = computeVector.at(computePos);
	int param1 = 0;
	int param2 = 0;
	uint_fast8_t test = stoi(to_string(opcode / 100), NULL, 2);
	bool A = ((test & AFlag) == AFlag), B = ((test & BFlag) == BFlag), C = ((test & CFlag) == CFlag);
	int DE = opcode % 100;
	int value = 0;
	if (DE % 100 == 99) {
		halted = true;
		return;
	}
	if (paused) {
		paused = false;
		return;
	}
	if (C == false) {
		param1 = computeVector.at(computeVector.at(computePos + 1));
	}
	else {
		param1 = computeVector.at(computePos + 1);
	}
	if (DE == 3) {
		param1 = computeVector.at(computePos + 1);
		first ? computeVector.at(param1) = in : computeVector.at(param1) = out;
		first = false;
		computePos += 2;
		Compute(in, out);
		return;
	}
	else if (DE == 4) {
		out = param1;
		computePos += 2;
		paused = true;
		Compute(in, out);
		return;
	}

	if (B == false) {
		param2 = computeVector.at(computeVector.at(computePos + 2));
	}
	else {
		param2 = computeVector.at(computePos + 2);
	}

	if (DE == 1) {
		computeVector.at(computeVector.at(computePos + 3)) = param1 + param2;
		computePos += 4;
		Compute(in, out);
	}
	else if (DE == 2) {
		computeVector.at(computeVector.at(computePos + 3)) = param1 * param2;
		computePos += 4;
		Compute(in, out);
	}
	else if (DE == 5) {
		if (param1 != 0) {
			computePos = param2;
		}
		else {
			computePos += 3;
		}
		Compute(in, out);
	}
	else if (DE == 6) {
		if (param1 == 0) {
			computePos = param2;
		}
		else {
			computePos += 3;
		}
		Compute(in, out);
	}
	else if (DE == 7) {
		if (param1 < param2) {
			computeVector.at(computeVector.at(computePos + 3)) = 1;
		}
		else {
			computeVector.at(computeVector.at(computePos + 3)) = 0;
		}
		computePos += 4;
		Compute(in, out);
	}
	else if (DE == 8) {
		if (param1 == param2) {
			computeVector.at(computeVector.at(computePos + 3)) = 1;
		}
		else {
			computeVector.at(computeVector.at(computePos + 3)) = 0;
		}
		computePos += 4;
		Compute(in, out);
	}
	else {
		cout << "An Error Occurred!\nOPCODE: " << opcode << endl;
		return;
	}

	return;
}

int Intcode2::getValue() {
	return computeVector.at(0);
}