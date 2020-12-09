#ifndef DEC_7_H
#define DEC_7_H
#include "dec_5.h"
#include <algorithm>


class AmpCircuit {
public:
	AmpCircuit() {};
	~AmpCircuit() {};
	void createPermutations(string);
	void RunCurcuit();
	void RunCurcuitLoop();
	int getHighest_thrust() { return highest_thrust; };

private:
	vector<vector<int>> sequences;
	int highest_thrust = 0;
};


#endif //DEC_7_H
