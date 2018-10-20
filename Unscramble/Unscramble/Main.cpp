/**
 * @authors Dong Jae Shin, Bernardo Cobos
 * @date (due) October 25, 2018
 * This program....
 * Input: ...
 * Output: ...
 */
#include <iostream>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
//////////////////////// Code for incremental debugging ////////////////////////
//	Dictionary::initialize();
//	cout << Dictionary::locateStart("hello", true) << endl;
//	cout << Dictionary::getDictionarySize() << endl;

//////////////////////// Beginning of actual main function /////////////////////
	//Prompt for input:
	string userString;
	do {
		cout << "Please enter a lowercase string to unscramble, or null to end... " << endl;
		cin >> userString; //note this should be a single word, no whitespace
		//TODO Now, call unscramble, and display all solutions:

		//(we won't do the "Continue (Y/N)" part; that's redundant.)
	} while (userString != "null");

	cout << "Completed succesfully." << endl;

	//TODO: DELETE THE FOLLOWING BEFORE TURNING IN
	system("PAUSE");

	return 0;
} //end of main