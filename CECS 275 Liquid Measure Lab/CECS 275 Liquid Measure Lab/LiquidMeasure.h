#pragma once

#include <string>
#include <sstream>
#include <iomanip>

using std::string;

const int QUARTS_PER_GALLON = 4;
const int CUPS_PER_QUART = 4;
const int OUNCES_PER_CUP = 8;

class LiquidMeasure {
private:
	//Member variables:
	int gallons;
	int quarts;
	int cups;
	int ounces;
	static int liquidMeasure_track;

	//Member functions:
	void simplify();
	
public:

	// constructor
	LiquidMeasure(int, int, int, int);

	// default constructor
	LiquidMeasure();

	// Member Functions
	static int getLM();
	int getOunces() const;
	string to_string() const;

	//Operator overloading:
	LiquidMeasure operator+(LiquidMeasure) const;
	LiquidMeasure operator-(LiquidMeasure) const;
	bool operator<(LiquidMeasure) const;
	bool operator>(LiquidMeasure) const;
	bool operator==(LiquidMeasure) const;
	bool operator<=(LiquidMeasure) const;
	bool operator>=(LiquidMeasure) const;

	//Casting: 
	//note: const at the end says, "don't modify the contents of the (LiquidMeasure) object this function is a member of"
	operator double() const;
	operator int() const;

}; //end of LiquidMeasure class
