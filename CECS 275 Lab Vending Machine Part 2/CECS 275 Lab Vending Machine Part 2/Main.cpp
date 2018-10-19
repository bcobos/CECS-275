/**
 * @authors Bernardo Cobos, Don Jae Shin
 * @date 10/18/18
 * This program simulates a venting machine using class aggregation
 * Input: Soda names and numbers to stock and buy from the machine
 * Output: Available soda options, token count, and validation for purchase. 
 */

#include <iostream>
#include <string>
#include <limits>
#include "VendingMachine.h"

//using namespace std;
using std::string;
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;
int main() {
	cout << "Please enter the vending machine location description: " << endl;
	string location;
	getline(cin, location);
	VendingMachine machine = VendingMachine(location);

	char prompt;
	bool pastFirstIter = false;

	do {
		if (pastFirstIter) { //clear buffer if this isn't the first iteration
				string junk;
				getline(cin, junk);
			} //end of if
			else
				pastFirstIter = true;

		//prompt for soda input:
		cout << "Enter a soda name: " << endl;
		string sodaName;
		getline(cin, sodaName);
		cout << "Enter the number of cans (DO NOT ENTER ZERO CANS): " << endl;
		int numCans;
		cin >> numCans;
		//update vending machine:
		Soda newSoda = Soda(sodaName);
		newSoda.changeQuantity(numCans);
		machine.stock(newSoda);

		//print current machine statistics:
		cout << machine.to_string();
		
//		cin.ignore(10000, '\n');
//		string junk;
//		getline(cin, junk);

		//prompt user if they want to add another soda:
		cout << "Enter another soda? (y/n)" << endl;
		cin >> prompt;
//		cout << prompt << ";";
	} while (prompt != 'n' && prompt != 'N');

	
	//NOW, vend the sodas...
	cout << endl << "Now entering Vend Mode... " << endl;
	do {
		string junk;
		getline(cin, junk);

		cout << "What soda would you like to buy?" << endl;
		string requestName;
		getline(cin, requestName);
		Soda requestSoda = Soda(requestName);
		
		//string junk2;
		//getline(cin, junk);

		cout << "How many of the soda do you want to buy?" << endl;
		int numSodas;
		cin >> numSodas;
		//vend as many of these sodas as you can:
		for (int i = 0; i < numSodas; ++i) {
			if (machine.vend(requestSoda))
				cout << requestName << " vended successfully" << endl;
			else
				cout << "Error! There are not enough of " << requestName
				<< " to complete your request" << endl;
		} //end of for loop

		cout << endl << machine.to_string();

		cout << "Buy another soda? (y/n)" << endl;
		cin >> prompt;
	} while (prompt != 'n' && prompt != 'N');

	cout << "Completed successfully" << endl;
	//system("PAUSE");
	return 0;
} //end of main