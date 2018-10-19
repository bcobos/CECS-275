#pragma once
//Header file containing declarations in VendingMachine class
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Soda.h" 

using namespace std;

class VendingMachine { 
private:
	//Member variables
	string locationDescription;
	vector<Soda> inventory;
	unsigned int tokenCount;

public:
	//Member functions
	VendingMachine();	//default constructor
	VendingMachine(string); //constructor
	bool vend(Soda);
	void stock(Soda);
	string to_string();
}; //end of VendingMachine class