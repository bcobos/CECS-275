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
#include "PartialSolution.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
//////////////////////// Code for incremental debugging ////////////////////////
//	Dictionary::initialize();
//	cout << Dictionary::getDictionarySize() << endl;
//	int helloIndex = Dictionary::locateStart("hello", true);
//	cout << helloIndex << endl;
//	cout << Dictionary::wordList[helloIndex] << endl; //Note in order to see this, temporarly set wordList to public.

////	PartialSolution ps = PartialSolution("h", "lel"); 
//	PartialSolution ps = PartialSolution("hell", "");
//	ps.extend(); //vectors should be/have hl, he, he. unused are el, ll, le respectively
//	cout << ps.examine() << endl; 
//	vector<string> solnList = {};
//	ps.solvePartial(solnList);
//	for (auto& x : solnList) {
//		cout << x << endl;
//	}

//////////////////////// Beginning of actual main function /////////////////////
	//Prompt for input:
	string userString;
	do {
		cout << "Please enter a lowercase string to unscramble, or null to end... " << endl;
		cin >> userString; //note this should be a single word, no whitespace. Will this include newline character?
//		getline(cin, userString);
		//TODO: Now, unscramble (using PartialSolution::solvePartial), and display all solutions:
		PartialSolution parSol = PartialSolution(userString, "");
		vector<string> solutionList = {};
		parSol.solvePartial(solutionList);
		for (string& solution : solutionList) {
			cout << "Next solution: " << solution << endl;
		} //end of range-based for loop

		//(we won't do the "Continue (Y/N)" part; that's redundant.)
	} while (userString != "null");

	cout << "Completed succesfully." << endl;

	//TODO: DELETE THE FOLLOWING BEFORE TURNING IN
	system("PAUSE");

	return 0;
} //end of main