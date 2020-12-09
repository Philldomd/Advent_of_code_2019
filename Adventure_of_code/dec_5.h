#ifndef DEC_5_H
#define	DEC_5_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
static int_fast8_t AFlag{ 0b0000'0100 };
static int_fast8_t BFlag{ 0b0000'0010 }; 
static int_fast8_t CFlag{ 0b0000'0001 };

class Intcode2 {
public:
	Intcode2(string);
	~Intcode2() {};
	void initialize();
	int Compute(void);
	void Compute(int&, int&);
	int getValue(void);
	bool getHalted() { return halted; };

private:
	vector<int> intVector;
	vector<int> computeVector;
	int computePos = 0;
	bool first = true;
	bool halted = false;
	bool paused = false;
};
#endif //DEC_5_H