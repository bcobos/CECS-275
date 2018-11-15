#include "Person.h"

#include <string>
#include <iostream>
/** 
 * default constructor
 */
Person::Person() {
	lName  = "N/A";
	fName  = "N/A";
	h_feet = 0;
	h_inch = 0;
	person_counter++;
} // end of default constructor

/**
 * full constructor
 */
Person::Person(string newLName, string newFName, int newHFeet, int newHInch) {
	lName  = newLName;
	fName  = newFName;
	h_feet = newHFeet;
	h_inch = newHInch;
	person_counter++;
} //  end of full constructor

Person& Person::operator=(const Person& other) {
	//defending against self-assignment:
	if (this == &other)
		return *this;

	lName = other.lName;
	fName = other.fName;
	h_feet = other.h_feet;
	h_inch = other.h_inch;
	
	return(*this);
}
/**
 * @returns the last name of the person implicitly called
 */
string Person::getLName() const{
	return lName;
} // end of getter getLName

/**
 * @returns the first name
 */
string Person::getFName() const {
	return fName;
} // end of getter getFName

/**
 * @returns height in feet
 */
int Person::get_hf() const {
	return h_feet;
} // end of getter get_hf

/**
 * @returns height in inches
 */
int Person::get_hi() const {
	return h_inch;
} //  end of getter get_hi

/**
 * @param Other person to compare the last name 
 * @returns 1 if the other person is greater than implicit person.
 *			  if they are equal, return 0.  if other person is less 
 *			  than implicit person return -1.
 */
int Person::compLName(Person other) {
	int result;

	// update result 
	if (this->lName < other.lName) result = 1;
	else if (this->lName > other.lName) result = 0;
	else result = -1;

	return result;
} // end of member function compLName

/**
 * @param Other person to compare the first name 
 * @returns 1 if the other person is greater than implicit person.
 *			  if they are equal, return 0.  if other person is less
 *			  than implicit person return -1.
 */
int Person::compFName(Person other) {
	int result;

	// update result
	if (this->fName < other.fName) result = 1;
	else if (this->fName > other.fName) result = 0;
	else result = -1;

	return result;
} // end of member function compFName

/**
 * @param Other person to compare the full name 
 * @returns 1 if the other person is greater than implicit person.
 *			  if they are equal, return 0.  if other person is less
 *			  than implicit person return -1.
 */
int Person::compFullName(Person other) {

	// gets the result of the comparison between the last names
	int result = this->compLName(other);

	// when the last name is equal, compare the firs name
	if (result == 0) {

		// get the result of the comparison between the first names
		int result = this->compFName(other);
	} // end of if

	return result;
} // end of member function compFullName

/**
 * @param Other person to compare the height
 * @returns 1 if the other person is greater than implicit person.
 *			  if they are equal, return 0.  if other person is less
 *			  than implicit person return -1.
 */
int Person::compHeight(Person other) {
	int result;

	// if the both height in feet are equal, break the tie with inches
	if (this->h_feet == other.get_hf()) {
		if (this->h_inch == other.get_hi()) {
			result = 0;
		} // end of else if
		else if (this->h_inch < other.get_hi()) {
			result = 1;
		} // end of else if
		else {
			result = -1;
		} // end of else

	} // end of if. comparing height feet
	else if (this->h_feet < other.get_hf()) {
		result = 1;
	} // end of else if
	else {
		result = -1;
	} // end of else

	return result;
} // end of member function compHeight

/**
 * couts the information about the member variables
 */
void Person::to_string() const {
	std::cout << "Person: Last Name - " << lName;
	std::cout << " First Name - " << fName;
	std::cout << " Height - " << h_feet << "'";
	std::cout << h_inch << '"' <<  std::endl;
} // end of to_string

/**
 * destruct
 */
Person::~Person()
{
	person_counter--;
} // end of destructor

/**
 * sets the pointer to the function
 */
void Person::setCompFunc(int (Person::*newCompFunc)(Person)) {
	this->compFunc = newCompFunc;
} // end of function setCompFunct

/**
 * call the pointed function
 * @param other the other Person to compare
 * @returns according to the function pointed
 */
int Person::compare(Person other) {
	return (this->*compFunc)(other);
}// end of function compare