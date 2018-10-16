//declarations for Soda struct
#include "Soda.h" //assumed to be in same directory as main()

/**
* Constructor for the Soda class
* Initializes member variables to input parameters
*/
Soda::Soda(string newName) {
	name = newName;
	quantity = 0;
} //end of Soda contructor

/**
 * Default constructor for the Soda class
*/
Soda::Soda() {
	name = "N/A";
//	unitPrice = 0;
	quantity = 0;
} //end of default Soda contructor


/*
 * Returns information on this soda as a string
 * @returns string with info on soda name, price, and quantity
*/
string Soda::to_string() {
	stringstream ss;
	ss << "Soda name: " << name << endl;
	ss << "Soda quantity: " << quantity << endl;
	//	ss << "Soda Price per can: " << unitPrice << endl;

	return ss.str();
} //end of Soda to_string function 

///**
// * @returns calculated overall value of all sodas in the machine
//*/
//double Soda::value() {
//	//PROBLEM: casting result to an int.
//	return unitPrice * static_cast<double>(quantity);
//} // end of Soda value function

/**
 * @returns the name of this soda
*/
string Soda::getName() {
	return this->name;
} //end of getName Soda member function

/**
 * @returns quantity of this soda
*/
int Soda::getQuantity() {
	return this->quantity;
} //end of Soda::getQuantity member function

  /**
  * Updates the quantity of this soda
  * @param delta the change in soda quantity
  */
void Soda::changeQuantity(int delta) {
	//TODO shoud this be chaching current quantity, or is that done outside?
	this->quantity += delta;
} //end of Soda::changeQuantity member function

