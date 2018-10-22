#include "PartialSolution.h"
/* Definitions for the PartialSolution class */

/*
 * PartialSolution constructor
 * @param unscrambledIn string with unscrambled partial solution
 * @param unusedIn string with remaining scrambled characters from OG scrambled string
 */
PartialSolution::PartialSolution(string unscrambledIn, string unusedIn) {
	this->unscrambled = unscrambledIn;
	this->unused = unusedIn;
} //End of PartialSolution constructor

/*
 * Generates a vector of subsequent PartialSolutions based on current PartialSolution object's member variables
 * @returns the above vector-- each entry using one more letter from current unused string in its unscramble variable
 */
vector<PartialSolution> PartialSolution::extend() {
	vector<PartialSolution> output;
	int unusedLen = unused.length();
	for (int i = 0; i < unusedLen; ++i) {
		string charToUse = unused.substr(i, 1); //will use this character in new partial solution and remove it from new unused
		string newUnscrambled = unscrambled + charToUse;
		string newUnused = (unused.substr(0, i)).append(unused.substr(i + 1, unusedLen - i - 1));
		output.push_back(PartialSolution(newUnscrambled, newUnused));
//		std::cout << "In extend PS function: " << newUnscrambled << "   " << newUnused << std::endl;
	} //end of for
	return output;
} //end of extend member function

/**
 * Checks whether this PartialSolution object is in the Dictionary
 * @returns int code marking status of this PartialSolution object
 */
int PartialSolution::examine() {
	int status; //will mark what the next step is
	const bool EXACT = true;
	const int FAIL = -1;
	if (this->unused == "") { //no more unused characters
		if (Dictionary::locateStart(this->unscrambled, EXACT) != FAIL) //exact unscrambled string is somewhere in the dictionary
			status = ACCEPT;
		else //exact unscrambled string is not in the dictionary
			status = ABANDON;
	} //end of if (no more unused characters)
	else { //there are still unused characters
		if (Dictionary::locateStart(this->unscrambled, !EXACT) != FAIL) //if this word is a subset of something in the Dictionary
			status = CONTINUE;
		else //this partial solution is not a subset of a Dictionary word
			status = ABANDON;
	} //end of else (there are unused characters)
	return status;
} //end of examine member function

/**
 * Keeps a list of full solutions, and searches a vector of previous solutions...
 * ...to make sure we're not looking for a solution we've already found.
 * Ex: oklnl => knoll, with no duplicates (from dual l's)
 * @param solutionList a vector with solutions already found
 */
void PartialSolution::solvePartial(vector<string>& solutionList) {
	int status = this->examine();
	if (status == ABANDON) {
		//Solution is not worth pursuing.
		return;
	} else if (status == ACCEPT) {
		//Found this full solution
		//Check that solution isn't already in the vector:
		for (string& soln : solutionList) {
			if (soln == this->unscrambled)
				return;
		} //end of range-based for loop
		//If you didn't return by here, need to add the solution to list:
		solutionList.push_back(this->unscrambled);
	} else if (status == CONTINUE) {
		//There are words with this partial solition. Continue the search:
		vector<PartialSolution> extensionVec = this->extend();
		for (auto& partialSoln : extensionVec) {
			partialSoln.solvePartial(solutionList);
		} //end of range-based for
	} else //Should never reach this code.
		std::cout << "Problem in PartialSolution::solvePartial function" << std::endl;
} //end of solvePartial member function