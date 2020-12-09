#ifndef DEC_1_2_H
#define DEC_1_2_H
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

class FuelCounterController {
public:
	FuelCounterController();
	~FuelCounterController() {};
	int getTotalFuelCounter();
	void TotalFuelCounter();
private:
	int CalculateFuel(int value);

private:
	vector<int> fuelInput;
	vector<int> calculatedFuel;
	int TotalFuel;
};

#endif //DEC_1_2_H
