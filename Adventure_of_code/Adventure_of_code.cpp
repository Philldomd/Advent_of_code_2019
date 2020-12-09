// Adventure_of_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "dec_1.1.h"
#include "dec_1.2.h"
#include "dec_2.1.h"
#include "dec_3.1.h"
#include "dec_4.h"
#include "dec_5.h"
#include "dec_6.h"
#include "dec_7.h"
#include <iostream>
#include "Adventure_of_code.h"

static int DAY = 0;

int main()
{
	cout << "................................................................" << endl;
	cout << "--------------------     Advent Of Code     --------------------" << endl;
 	cout << "................................................................" << endl << endl;

	if (DAY == 0 || DAY == 1) {
		cout << "*********************     Fuel Counter     *********************" << endl;
		FuelCounterUpper FCU;
		FCU.CalculateFuel();
		std::cout << "Day 1.1: " << FCU.getTotalFuelCounter() << endl;
		FuelCounterController FCC;
		FCC.TotalFuelCounter();
		std::cout << "Day 1.2: " << FCC.getTotalFuelCounter() << endl;
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 2) {
		cout << "***********************     Int Code     ***********************" << endl;
		Intcode IC;
		IC.initialize(12, 2);
		IC.Compute();
		std::cout << "Day 2.1: " << IC.getValue() << endl;
		int number = 0;
		IntCodeSearch::Search(number);
		std::cout << "Day 2.2: " << number << endl;
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 3) {
		cout << "*********************     Crossed Wire     *********************" << endl;
		CrossedWires CW;
		int Delay = numeric_limits<int>::max();
		int Dist = numeric_limits<int>::max();
		CW.Check(Dist, Delay);
		cout << "Day 3.1: " << Dist << endl;
		cout << "Day 3.2: " << Delay <<  endl;
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 4) {
		cout << "*******************     Secure Container     *******************" << endl;
		SecureContainer SC;
		SC.PasswordCount(1);
		cout << "Day 4.1: " << SC.GetCount() << endl;
		SC.ClearCount();
		SC.PasswordCount(2);
		cout << "Day 4.2: " << SC.GetCount() << endl;
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 5) {
		cout << "***********************     Int Code2     **********************" << endl;
		Intcode2 IC2("day_5_input.txt");
		cout << "Day 5.1: " << endl;
		cout << "Enter 1!" << endl;
		IC2.Compute();
		IC2.initialize();
		cout << "Day 5.2: " << endl;
		cout << "Enter 5!"  << endl;
		IC2.Compute();
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 6) {
		cout << "***********************      Orbiter      **********************" << endl;
		Orbiter orb;
		orb.process();
		cout << "Day 6.1: " << orb.getOrbits() << endl;
		orb.scan(&orb.nodes["YOU"]);
		cout << "Day 6.2: " << orb.getSteps()-2 << endl;
		cout << "****************************************************************" << endl << endl;
	}
	if (DAY == 0 || DAY == 7) {
		cout << "***********************     AmpCircuit    **********************" << endl;
		AmpCircuit AC;
		AC.createPermutations("01234");
		AC.RunCurcuit();
		cout << "Day 7.1: " << AC.getHighest_thrust() << endl;
		AC.createPermutations("98765");
		AC.RunCurcuitLoop();
		cout << "Day 7.2: " << AC.getHighest_thrust() << endl;
		cout << "****************************************************************" << endl << endl;
	}
	return 0;
}

