#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using std::string;

class Person
{
private:
	// member variable
	string lName;
	string fName;
	int h_feet;
	int h_inch;

	// fuction pointer
	int(Person::*compFunc)(Person);

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

	//////////////////////
	// Function Pointer //
	//////////////////////

	void setCompFunc(int (Person:: *newCompFunc)(Person));
	int compare(Person other);

	Person& Person::operator=(const Person& other);
	// to_string
	void to_string() const;

	// destructor
	~Person();
};

