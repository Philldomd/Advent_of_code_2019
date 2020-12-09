#include "dec_7.h"

void AmpCircuit::createPermutations(string seq){
	sequences.clear();
	sort(seq.begin(), seq.end());
	vector<int> temp;
	do {
		for (int i = 0; i < 5; i++) {
			temp.push_back(seq[i]-'0');
		}
		sequences.push_back(temp);
		temp.clear();
	} while (next_permutation(seq.begin(), seq.end()));
}

void AmpCircuit::RunCurcuit() {
	Intcode2 IC2("dec_7_input.txt");
	int out = 0;
	highest_thrust = 0;
	for (auto& sequence : sequences) {
		for (int i = 0; i < 5; i++) {
			IC2.Compute(sequence.at(i), out);
			IC2.initialize();
		}
		if (out > highest_thrust) {
			highest_thrust = out;
		}
		out = 0;
	}
}

void AmpCircuit::RunCurcuitLoop() {
	Intcode2 IC2A("dec_7_input.txt");
	Intcode2 IC2B("dec_7_input.txt");
	Intcode2 IC2C("dec_7_input.txt");
	Intcode2 IC2D("dec_7_input.txt");
	Intcode2 IC2E("dec_7_input.txt");
	int out = 0;
	highest_thrust = 0;
	for (auto& sequence : sequences) {
		while (IC2E.getHalted() != true) {
			IC2A.Compute(sequence.at(0), out);
			IC2B.Compute(sequence.at(1), out);
			IC2C.Compute(sequence.at(2), out);
			IC2D.Compute(sequence.at(3), out);
			IC2E.Compute(sequence.at(4), out);
		}
		if (out > highest_thrust) {
			highest_thrust = out;
		}
		IC2A.initialize();
		IC2B.initialize();
		IC2C.initialize();
		IC2D.initialize();
		IC2E.initialize();
		out = 0;
	}
}