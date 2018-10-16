/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date October 11, 2018
* This program defines a simple soda struct for a simulated vending machine
* Input: Soda name, soda quantity, and soda price for a vanding machine
* Outout: TODO
*/
#include "Soda.h" //THE HEADER FILE. not cpp.
//it's not until the linker step that the .cpp file (with declarations) will be pulled in!
//all the preprocessor needs right now is the declaration
//HOW DOES THIS WORK? ie how does the linker then know to pull in proper .cpp file?

int getInt(int, int);
double getDouble(double, double);

int main() {

	// Go through a loop

	// prompt the user for the soda name, price each and qunatity
	// be sure that the price is between .25 and 1.5
	// besure that quantity is between 1 and 100 inclusive



	// user input that will check for break in the while loop
	string exit = "";
	// name of the soda that user inputed
	string soda = "";

	double cost;
	int quantity;
	bool firstIteration = true;
	// super loop until the break asserted from the user
	while(1) {

		// prompt the user to get the soda name
		cout << "Enter the soda name or 'N/A'  to exit: " << endl;
		
		if (firstIteration) {
			firstIteration = false;
		}
		else { //only flush buffer after first iteration
			//flush buffer
			string junk;
			getline(cin, junk);
		} //end of if else checking if first iteration

		getline(cin, soda);
//		exit = soda.substr(0, soda.size() - 1); //THIS WORKS ON ECLIPSE
		exit = soda; //THIS WORKS ON VISUAL STUDIO
		if (exit == "N/A") break;

		cout << "Enter the price for each of these sodas: " << endl;
		cost = getDouble(0.05, 1.5);

		cout << "Enter the number of sodas in inventory: " << endl;
		quantity = getInt(1,100);

		Soda newSoda = Soda(soda, cost, quantity);
		cout << newSoda.to_string() << endl;

	}


	cout << "Completed Successfully" << endl;
	system("Pause"); //TODO: DELETE THIS LINE

	return 0;
}	//End of main function

/**
 * Helps prompt user for an int, for use as a soda quantity
 * Validates the amount/type of user input
 * @param min the minimum allowable int value
 * @param max the maximum allowable int value
 * @returns the user's input, if it's an allowable int
*/
int getInt(int min, int max) {
	cout << "Please enter an integer between " << min << " and " << max << endl;

	int userChoice;
	bool validChoice;
	do { //take input/check it is valid
		cin >> userChoice; //take in user choice from console

		if (cin.fail()) { //checking if user input is an int
			validChoice = false;
			cin.clear(); //clear cin fail flags. NOTE this MUST come before getline buffer-clearing!!
			string junk;
			getline(cin, junk); //clear buffer if it's clogged
			cout << "Error, input not an integer. " << endl;
		} //end of if statement 
		else if (userChoice < min || userChoice > max) { //checking if user choice is out of range
			validChoice = false;
			cout << "Error, input not in range. " << endl;
		} //end of else if 
		else { //everything okay
			validChoice = true;
		} //end of else statement 

	} while (!validChoice); //continue to prompt user for input if input type is not an int

	return userChoice; //return the choice once it's valid	
} //end of getInt function






  /**
  * Helps prompt user for a double, for use as a soda unit price
  * Validates the amount/type of user input
  * @param min the minimum allowable double value
  * @param max the maximum allowable double value
  * @returns the user's input, if it's an allowable double
  */
double getDouble(double min, double max) {
	cout << "Please enter a double between " << min << " and " << max << endl;

	double userChoice;
	bool validChoice;
	do { //take input/check it is valid
		cin >> userChoice; //take in user choice from console

		if (cin.fail()) { //checking if user input is a double
			validChoice = false;
			cin.clear(); //clear cin fail flags. NOTE this MUST come before getline buffer-clearing!!
			string junk;
			getline(cin, junk); //clear buffer if it's clogged
			cout << "Error, input not a double. " << endl;
		} //end of if statement 
		else if (userChoice < min || userChoice > max) { //checking if user choice is out of range
			validChoice = false;
			cout << "Error, input not in range. " << endl;
		} //end of else if 
		else { //everything okay
			validChoice = true;
		} //end of else statement 

	} while (!validChoice); //continue to prompt user for input if input type is not an int

	return userChoice; //return the choice once it's valid	
} //end of getDouble function