#pragma once
//Header file containing declarations in VendingMachine class
#include <iostream>
#include <string>
#include <vector>
#include "Soda.h" //??Why doesn't this work?

using namespace std;

class VendingMachine {
private:
	//Member variables
	string locationDescription;
	vector<Soda> inventory;
	int tokenCount;

public:
	//Member functions
	VendingMachine();	//default constructor
	VendingMachine(string); //constructor
	vend()

};