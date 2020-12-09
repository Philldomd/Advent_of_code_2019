#include "dec_4.h"

SecureContainer::SecureContainer() {
	char delim = '-';
	ifstream InputFile;
	InputFile.open("dec_4_input.txt");
	getline(InputFile, rangeLow, delim);
	getline(InputFile, rangeHigh, delim);
	//rangeLow = "111122";
	//rangeHigh = "111145";
}

bool SecureContainer::CheckDouble(string &test) {
	constexpr int size = numeric_limits<int>::max();
	for (int i = 0; i < 5; i++) {
		if (test[i] == test[i + 1]) {
			return true;
		}
	}
	return false;
}

bool SecureContainer::CheckDoubleTwo(string &test) {
	int size = numeric_limits<int>::max();
	int group, num;
	for (int i = 0; i < 5; i++) {
		if (test[i] == test[i + 1]) {
			group = 2;
			num = test[i];
			for (int j = i + 1; j < 5; j++) {
				if (num == test[j] && test[j] == test[j + 1]) {
					group += 1;
					i += 1;
				}
			}
			size = min(size, group);
		}
	}
	if (size > 2) {
		return false;
	}
	return true;
}

bool SecureContainer::CheckNumbers(string &test) {
	for (int i = 0; i < 5; i++) {
		if (test[i] > test[i + 1]) {
			return false;
		}
	}
	return true;
}

void SecureContainer::PasswordCount(int part) {
	int L = stoi(rangeLow), H = stoi(rangeHigh);
	for (int i = L; i <= H; i++) {
		string number = to_string(i);
		if (part == 1) {
			if (!CheckNumbers(number) || !CheckDouble(number)) {
				continue;
			}
		}
		else {
			if (!CheckNumbers(number) || !CheckDoubleTwo(number)) {
				continue;
			}
		}
		passwords.push_back(stoi(number));
	}
}