#ifndef DEC_1_1_H
#define DEC_1_1_H
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

class FuelCounterUpper {
public:
	FuelCounterUpper();
	~FuelCounterUpper() {};
	void CalculateFuel();
	int getTotalFuelCounter();

private:
	vector<int> fuelInput;
	vector<int> calculatedFuel;
	int TotalFuelCounter;
};

#endif //DEC_1_1_H
