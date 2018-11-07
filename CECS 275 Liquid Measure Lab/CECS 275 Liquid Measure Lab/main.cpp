/**
 * @authors Bernardo Cobos, Dong Jae Shin
 * @date Started 11/1/18; Due 11/6/18
 * This program overloads operators to give a simple interface for computing Imperial Liquid Measures
 * Input: None
 * Output: Simulation of use of LiquidMeasure for a camping trip
 */

#include <iostream>
#include "LiquidMeasure.h"

//using namespace std;
using std::cout;
using std::endl;

int main() {	
	cout << "We currently have: " << LiquidMeasure::getLM() << " liquid measures defined." << endl;

	// 3 Quarts and 2 Cups
	LiquidMeasure lm1 = LiquidMeasure(0, 3, 2, 0);
	cout << "We currently have: " << LiquidMeasure::getLM() << " liquid measures defined." << endl;
	// display the defined measurement.
	cout << "New container holds: \n" << lm1.to_string() << endl;

	// 2 Quarts and 3 Cups
	LiquidMeasure lm2 = LiquidMeasure(0, 2, 3, 0);
	cout << "We currently have: " << LiquidMeasure::getLM() << " liquid measures defined." << endl;
	// display the defined measurement.
	cout << "New container holds: \n" << lm2.to_string() << endl;

	// 2 Quarts
	LiquidMeasure lm3 = LiquidMeasure(0, 2, 0, 0);
	cout << "We currently have: " << LiquidMeasure::getLM() << " liquid measures defined." << endl;
	// display the defined measurement.
	cout << "New container holds: \n" << lm3.to_string() << endl;

	// 5 gallon container has no water in it
	LiquidMeasure container_5_gal = LiquidMeasure(0, 0, 0, 0);

	const int FIVEGALLON_TO_OUNCES = 5 * QUARTS_PER_GALLON * CUPS_PER_QUART * OUNCES_PER_CUP;
	cout << "We currently have: " << LiquidMeasure::getLM() << " liquid measures defined." << endl;
	cout << "Defined the (currently empty) 5 gallon container: \n" << container_5_gal.to_string() << endl;
	
	// trip counter
	int trips = 0;
	cout << "============ Going to gather water now! ============" << endl;
	do {
		// update the trip counter
		trips++;

		//this only stays true if all three containers aren't necessary to empty into camp container:
		bool iCanGoAlone = true;

		// use all measurement cups only if it does not add up to 5 gallons
		// otherwise only use the combinations measuring cups that are needed that will not yet get the 5 gallon over the limit
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

		// if only two or one cups are needed, go alone. Note this should also be the last trip
		if (iCanGoAlone) {
			cout << "I can go alone for this trip!" << endl;
		}

		// display the container at the camp
		cout << "After trip number " << trips << "... \n";
		// display the ounce content after every trip
		cout << "The five gallon container has " << container_5_gal.getOunces() << " total ounces in it." << endl;
		cout << "Simplified, this is: " << endl << container_5_gal.to_string();
		cout << "~ We still need: ~\n" << (LiquidMeasure(5, 0, 0, 0) - container_5_gal).to_string() << endl;	

	// loop until camp container reaches 5 gallons
	} while (container_5_gal.getOunces() < FIVEGALLON_TO_OUNCES);
	cout << "============ Finished gathering water ============" << endl << endl;
	cout << "Filled the 5 gallon container after " << trips << " trips " << endl;
	cout << "Filled container at camp has: " << endl << container_5_gal.to_string();


	cout << "Completed Satisfactorily." << endl;

	//TODO: comment out when turning it in
	system("PAUSE");

} //end of main
