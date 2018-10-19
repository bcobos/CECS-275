//file containing definitions of VendingMachine class

#include "VendingMachine.h"

/**
 * Default constructor
 */
VendingMachine::VendingMachine() {
	locationDescription = "N/A";
	tokenCount = 0;
} //end of default constructor

/**
 * Constructor 
 * @param name the name that will become the location identifier of the VendingMachine
 */
VendingMachine::VendingMachine(string name) { 
	locationDescription = name;
	tokenCount = 0;
} //end of constructor

/**
 * Takes in a soda request, checks that the soda is available in the machine, sells it, and returns true if everything ok
 * @param request the Soda that is being requested by vending machine user
 * @return true if there is a soda in the machine to vend to user
*/
bool VendingMachine::vend(Soda request) {
	bool available = false;
	size_t numSodaTypes = inventory.size();
	for (size_t i = 0; i < numSodaTypes; ++i) { //check every soda in the machine, if there are any
		if (inventory[i].getName() == request.getName()) { //if the requested soda is in the machine 
			available = true;
			//available-- sell one!
			inventory[i].changeQuantity(-1);
			++tokenCount;
			if (inventory[i].getQuantity() == 0) {  //if we are now out of sodas...
				//POTENTIAL ISSUE: If soda was "in" the machine with default quantity zero, we just vended a nonexistent soda
				inventory.erase(inventory.begin() + i);  //...then get rid of this soda from your inventory
			}//end of if
		} //end of if
	} //end of for loop

	return available;
} //end of VendingMaching vend function

/**
 * Adds soda to the vending machine. Checks to see if a type of this soda is already in the Machine.
 * @param toBeAdded the Soda to be added to the machine.
 */
void VendingMachine::stock(Soda toBeAdded) {
	int sz = inventory.size();
	if (sz == 0) { //if the vending machine is completely empty
		this->inventory.push_back(toBeAdded); //Add the soda to inventory
		int delta = toBeAdded.getQuantity();
	} //end of if
	else { //otherwise, machine is not empty
		//First check if we already have this soda in the machine:
		bool inMachine = false;
		for (int i = 0; i < sz; ++i) { //for every soda in current inventory...
			if (toBeAdded.getName() == inventory[i].getName()) { //if soda names match...
				int delta = toBeAdded.getQuantity();
				inventory[i].changeQuantity(delta); //...Add these sodas to our count.
				inMachine = true;
				break;
			} //end of if
		} //end of for
		if (!inMachine) { //otherwise this soda type was not already in the Vending Machine
			this->inventory.push_back(toBeAdded); //Add the soda to inventory
			int delta = toBeAdded.getQuantity();
			inventory[inventory.size() - 1].changeQuantity(delta); //...Add these sodas to our count.
		} //end of else
	} //end of else
} //end of Vending Machine stock function

/**
 * Gives string information about the Vending Machine object
 * @returns string with with location, inventory, and tokenCount information
 */
string VendingMachine::to_string() {
	stringstream ss;
	ss << "Vending Machine Location: " << this->locationDescription << endl;
	ss << "Vending Machine Inventory: " << endl;
	for (auto& soda : inventory)	//print all sodas in inventory
		ss << soda.to_string();
	ss << "Number of tokens in Vending Machine: " << tokenCount << endl << endl;

	return ss.str();
} //end of to_string Vending Machine function