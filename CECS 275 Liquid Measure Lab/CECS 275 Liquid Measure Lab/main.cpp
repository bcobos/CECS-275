/**
 * @authors Bernardo Cobos, Dong Jae Shin
 * @date Started 11/1/18; Due 11/6/18
 * This program overloads operators to give a simple interface for computing Imperial Liquid Measures
 * Input: ...
 * Output: ...
 */

#include <iostream>
#include "LiquidMeasure.h"

using namespace std;

int main() {
	//Debug code:

	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;

	// 3 Quarts and 2 Cups
	LiquidMeasure lm1 = LiquidMeasure(0, 3, 2, 0);
	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;
	// display the defined measurement.
	cout << lm1.to_string();

	// 2 Quarts and 3 Cups
	LiquidMeasure lm2 = LiquidMeasure(0, 2, 3, 0);
	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;
	// display the defined measurement.
	cout << lm2.to_string();

	// 2 Quarts
	LiquidMeasure lm3 = LiquidMeasure(0, 2, 0, 0);
	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;
	// display the defined measurement.
	cout << lm3.to_string();

	// 5 gallon container has no water in it
	LiquidMeasure container_5_gal = LiquidMeasure(0, 0, 0, 0);

	const int FIVEGALLON_TO_OUNCES = 5 * QUARTS_PER_GALLON * CUPS_PER_QUART * OUNCES_PER_CUP;
	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;
	
	// trip counter
	int trips = 0;

	do {
		// update the trip counter
		trips++;

		bool iCanGoAlone = true;

		// use all measurement cups only if it does not add up to 5 gallons
		// only use the measuring cups that are needed that will get the 5 gallon up to the limit
		if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm1 + lm2 + lm3).getOunces()) {
			container_5_gal = container_5_gal + lm1 + lm2 + lm3;
			iCanGoAlone = false;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm1 + lm2).getOunces()) {
			container_5_gal = container_5_gal + lm1 + lm2;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm1 + lm3).getOunces()) {
			container_5_gal = container_5_gal + lm1 + lm3;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm2 + lm3).getOunces()) {
			container_5_gal = container_5_gal + lm2 + lm3;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm1).getOunces()) {
			container_5_gal = container_5_gal + lm1;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm2).getOunces()) {
			container_5_gal = container_5_gal + lm2;
		}
		else if (FIVEGALLON_TO_OUNCES >= (container_5_gal + lm3).getOunces()) {
			container_5_gal = container_5_gal + lm3;
		}

		// display the container at the camp
		cout << "Container at camp currently has: " << endl << container_5_gal.to_string();

		// if only two or one cups are needed go alone
		if (iCanGoAlone) {
			cout << "I can go alone for this trip!" << endl;
		}

		// display the content after every trips
		cout << "after the " << trips << " trip: \n";
		cout << "five gallon container has " << container_5_gal.getOunces() << " ounces in it." << endl;



	// loop until it reaches 5 gallons
	} while (container_5_gal.getOunces() < FIVEGALLON_TO_OUNCES);

	cout << "filled the 5 gallon after " << trips << " trips " << endl;
	cout << "Container at camp currently has: " << endl << container_5_gal.to_string();


	cout << "Completed Satisfactorily." << endl;

	//TODO: comment out when turning it in
	system("PAUSE");

} //end of main