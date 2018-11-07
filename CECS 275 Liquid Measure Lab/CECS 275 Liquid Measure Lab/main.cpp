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
	cout << "We have: " << LiquidMeasure::getLM() << " defined." << endl;
	// display the empty container
	cout << "Container at camp currently has: " << endl << container_5_gal.to_string();
	
	// me and my friend's first trip
	container_5_gal = lm1 + lm2 + lm3;

	// display the content after first trip
	cout << "after the first trip: \n" << container_5_gal.to_string(); 

	cout << "five gallon container has: " << container_5_gal.getOunces() << " ounces in it." << endl;


	// display the defined measurement.
	cout << container_5_gal.to_string();

	cout << "Completed Satisfactorily." << endl;

	//TODO: comment out when turning it in
	system("PAUSE");
} //end of main