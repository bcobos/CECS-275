#include "LiquidMeasure.h"

// initialize static variable
int LiquidMeasure::liquidMeasure_track = 0;

 /**
  * Default Constrcutor 
  */
LiquidMeasure::LiquidMeasure() {
	gallons = 0;
	quarts = 0;
	cups = 0;
	ounces = 0;
	liquidMeasure_track++;
} // end of default constructor

/**
  * Constrcutor
  */
LiquidMeasure::LiquidMeasure(int newGallons, int newQuarts, int newCups, int newOunces) {
	gallons = newGallons;
	quarts = newQuarts;
	cups = newCups;
	ounces = newOunces;
	liquidMeasure_track++;
} // end of default constructor

 /**
  * Simplifies LiquidMeasure object's current variables to reduced form
  */
void LiquidMeasure::simplify() {
	//Updating up the list:
	cups += (ounces / OUNCES_PER_CUP);
	quarts += (cups / CUPS_PER_QUART);
	gallons += (quarts / QUARTS_PER_GALLON);
	//Cutting everything down to size:
	ounces %= OUNCES_PER_CUP;
	cups %= CUPS_PER_QUART;
	quarts %= QUARTS_PER_GALLON;
} //end of simplify member function

 /**
 * @returns information for this LiquidMeasure object into an std::string
 */
string LiquidMeasure::to_string() const {
	std::stringstream strStream;
	strStream << std::setw(10) << "Gallons: " << gallons << std::endl;
	strStream << std::setw(10) << "Quarts: " << quarts << std::endl;
	strStream << std::setw(10) << "Cups: " << cups << std::endl;
	strStream << std::setw(10) << "Ounces: " << ounces << std::endl;
	return strStream.str();
} //end of to_string member function

 /**
 * @returns the current TOTAL ounces for the LiquidMeasure object
 */
int LiquidMeasure::getOunces() const {
	int totalOunces = 0;
	totalOunces += (cups * OUNCES_PER_CUP); //cups to ounces
	totalOunces += (quarts * CUPS_PER_QUART * OUNCES_PER_CUP); // quarts to ounces
	totalOunces += (gallons * QUARTS_PER_GALLON * CUPS_PER_QUART * OUNCES_PER_CUP); //gallons to ounces
	return totalOunces;
} //end of getOunces member function

 /**
 * Adds all measurements for this object and another, and simplifies
 * @param other the other LiquidMeasure to add this one's to
 * @returns a new LiquidMeasure object with added variables, simplified
 */
LiquidMeasure LiquidMeasure::operator+(LiquidMeasure other) const {
	LiquidMeasure temp = LiquidMeasure();
	temp.gallons = this->gallons + other.gallons;
	temp.quarts = this->quarts + other.quarts;
	temp.cups = this->cups + other.cups;
	temp.ounces = this->ounces + other.ounces;
	temp.simplify();
	return temp; //BE AWARE THIS USES DEFAULT COPY CONSTRUCTOR
} //end of operator+ member operator overload

  /**
  * Subtracts all measurements or another LiquidMeasure object from this one, and simplifies
  * @param other the other LiquidMeasure to subtract from this one
  * @returns a new LiquidMeasure object with subtracted variables, simplified
  */
LiquidMeasure LiquidMeasure::operator-(LiquidMeasure other) const {
	LiquidMeasure temp = LiquidMeasure();
	temp.gallons = this->gallons - other.gallons;
	temp.quarts = this->quarts - other.quarts;
	temp.cups = this->cups - other.cups;
	temp.ounces = this->ounces - other.ounces;
	temp.simplify();
	return temp; //BE AWARE THIS USES DEFAULT COPY CONSTRUCTOR
} //end of operator+ member operator overload

 /**
  * compare the total volume of liquidMeasure for less than operator
  * @param other the other LiquidMeasure to compare from this one
  * @returns true if this LiquidMeasure is less than the other
  */
bool LiquidMeasure::operator<(LiquidMeasure other) const {
	return (this->getOunces() < other.getOunces());
} // end of < operator

 /**
  * compare the total volume of liquidMeasure for greater than operator
  * @param other the other LiquidMeasure to compare from this one
  * @returns true if this LiquidMeasure is greater than the other
  */
bool LiquidMeasure::operator>(LiquidMeasure other) const {
	return (this->getOunces() > other.getOunces());
} // end of > operator

/**
  * compare the total volume of liquidMeasure are equal
  * @param other the other LiquidMeasure to compare from this one
  * @returns true if this LiquidMeasure is same as the other
  */
bool LiquidMeasure::operator==(LiquidMeasure other) const {
	return (this->getOunces() == other.getOunces());
} // end of == operator

/**
  * compare the total volume of liquidMeasure for less than equal to operator
  * @param other the other LiquidMeasure to compare from this one
  * @returns true if this LiquidMeasure is less than the other
  */
bool LiquidMeasure::operator<=(LiquidMeasure other) const {
	return (*this) < other || (*this) == other;
} // end of <= operator

/**
  * compare the total volume of liquidMeasure for greater than operator
  * @param other the other LiquidMeasure to compare from this one
  * @returns true if this LiquidMeasure is greater than the other
  */
bool LiquidMeasure::operator>=(LiquidMeasure other) const {
	return (*this) > other || (*this) == other;
} // end of >= operator

/**
 * Type casting from LiquidMeasure to double
 * @returns total number of gallons, as a decimal (double)
 */
LiquidMeasure::operator double() const {
	const int OUNCES_PER_GALLON = QUARTS_PER_GALLON * CUPS_PER_QUART * OUNCES_PER_CUP;
	return static_cast<double>(getOunces()) / OUNCES_PER_GALLON; 
} //end of LiquidMeasure to double casting

/**
 * Type casting from LiquidMeasure to int.
 * Note as this is function const protected, we can't simpify() here.
 * This function relies on an already-simplified LiquidMeasure object.
 * @returns total whole number count of gallons 
 */
LiquidMeasure::operator int() const {
	//This is easy -- in reduced form, only need to return gallons
	return gallons;
} //end of LiquidMeasure to int casting

/**
 * @returns the Liquid Measure instances counts
 */
int LiquidMeasure::getLM() {
	return liquidMeasure_track;
} // end of getLM