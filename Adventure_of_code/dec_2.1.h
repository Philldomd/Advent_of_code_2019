#ifndef DEC_2_1_H
#define	DEC_2_1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Intcode {
public:
	Intcode();
	~Intcode() {};
	void initialize(int, int);
	int Compute(void);
	int getValue(void);
	
private:
	vector<int> intVector;
	vector<int> computeVector;
	int computePos = 0;
};

class IntCodeSearch {
public:
	IntCodeSearch() {};
	~IntCodeSearch() {};
	static void Search(int& _number) {
		int noun = 0;
		int verb = 0;
		int result;
		Intcode IC;
		IC.initialize(0, 0);
		for (noun = 0; noun <= 99; noun++) {
			for (verb = 0; verb <= 99; verb++) {
				IC.initialize(noun, verb);
				result = IC.Compute();
				if (result == 19690720) {
					break;
				}
			}
			if (result == 19690720) {
				break;
			}
		}
		_number = 100 * noun + verb;
	};
};
#endif //DEC_2_1_H

