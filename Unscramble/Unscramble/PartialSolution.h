#pragma once
/* Declarations for the PartialSolution class */

#include <string>
#include <vector>
#include "Dictionary.h"

using std::string;
using std::vector;

class PartialSolution {
private:
	string unscrambled;	//partial solution
	string unused;		//letters from OG word that haven't yet been used
	//Note, we CAN initialize the following here, since these are const.
	static const int ABANDON = 0; 
	static const int ACCEPT = 1;
	static const int CONTINUE = 2;

public:
	PartialSolution(string, string);
	vector<PartialSolution> extend();
	int examine();
	void solvePartial(vector<string>&);

}; //end of PartialSolution class