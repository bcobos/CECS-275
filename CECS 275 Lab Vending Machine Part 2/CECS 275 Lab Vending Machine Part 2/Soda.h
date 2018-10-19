#pragma once //Seems to serve the same purpose as #ifndef, #define, #endif
//Header file contains declaration of soda struct

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//using std::cout;
//using std::cin;
//using std::endl;
//using std::vector;
//using std::string;
using namespace std;

//Note structs default to public visibility... Classes default to private.
class Soda {
private:
	//Member variables
	string name;		//name of the soda
	int quantity;		//# of cans of this soda we have in vending machine inventory
//	double unitPrice;	//price for a single can of this soda. Deleted for second Vending lab.
//	double value; //wait this is actually calculated, not stored. unitPrice * quantity

public:
	//Member functions
	Soda(); //default constructor. 
	Soda(string); //constructor
	string to_string();
	//double value();
	string getName();
	int getQuantity();
	void changeQuantity(int);

}; //end of Soda struct.