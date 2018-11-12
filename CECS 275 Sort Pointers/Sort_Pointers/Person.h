#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using std::string;

class Person
{
private:
	string lName;
	string fName;
	int h_feet;
	int h_inch;

	int person_counter;

public:

	//////////////////
	// constructors //
	//////////////////

	// default constructor
	Person();

	// full constructor
	// last Name, first name, height feet, height inches
	Person(string, string, int, int);

	/////////////////////
	// Member Functions//
	/////////////////////
	
	// getters
	string getLName() const;
	string getFName() const;
	int get_hf() const;
	int get_hi() const;

	// compare member functions
	int compLName(Person);
	int compFName(Person);
	int compFullName(Person);
	int compHeight(Person);

	// to_string
	void to_string() const;

	// destructor
	~Person();
};

