#include "VendingMachine.h"
//file containing definitions of VendingMachine class

VendingMachine::VendingMachine() {	//default constructor
	locationDescription = "N/A";
	tokenCount = 0;
} //end of default constructor

VendingMachine::VendingMachine(string name) { //constructor
	locationDescription = name;
	tokenCount = 0;
} //end of constructor

/**
 * Takes in a soda request, checks that the soda is available in the machine, and returns true if everything ok
 * @param request the Soda that is being requested by vending machine user
 * @return true if there is a soda inthe machine to vent to user
*/
bool VendingMachine::vend(Soda request) {
	//TODO

} //end of VendinMaching vend function

/**
 * Adds a soda to the vending machine. Checks to see if a type of this soda is already in the Machine.
 * @param toBeAdded the Soda to be added to the machine.
*/
void VendingMachine::stock(Soda toBeAdded) {
	
} //end of Vending Machine stock function

/**
 * Gives string information about the Vending Machine object
 * @returns string with with location, inventory, and tokenCount information
*/
string VendingMachine::to_string() {
	
} //end of to_string Vending MAchine function