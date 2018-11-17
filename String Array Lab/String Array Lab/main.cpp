/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 11/15/18
* This program is practice with operator overloading, memory management, and exception handling
* Input: None
* Output: Result of adding to a container object and of playing with exceptions
*/

#include "String.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	//Create five std::strings:
	string str0 = "Oh god where am I??";
	string str1 = "May the spirits put him at ease";
	string str2 = "Never forget to smile, children!";
	string str3 = "Here kitty kitty";
	string str4 = "No more Mr. Nice Guy";

	//Add these five strings to the String array:
	//(print out how many elements are in the array and the array size after each addition)
	//create String object first, then use add() member function five times
	String stringContainer = String(); //calling default constructor for creation. Throws no exception.
	stringContainer.add(str0);
	cout << "Added Element." << endl;
//	cout << "element added: " << stringContainer[0] << endl;
	cout << "String object now has " << stringContainer.getNumElements()
		<< " item, and its current capacity is " << stringContainer.getSize() << endl;
	stringContainer.add(str1);
	cout << "Added Element." << endl;
	cout << "String object now has " << stringContainer.getNumElements()
		<< " items, and its current capacity is " << stringContainer.getSize() << endl;
	stringContainer.add(str2);
	cout << "Added Element." << endl;
	cout << "String object now has " << stringContainer.getNumElements()
		<< " items, and its current capacity is " << stringContainer.getSize() << endl;
	stringContainer.add(str3);
	cout << "Added Element." << endl;
	cout << "String object now has " << stringContainer.getNumElements()
		<< " items, and its current capacity is " << stringContainer.getSize() << endl;
	stringContainer.add(str4);
	cout << "Added Element." << endl;
	cout << "String object now has " << stringContainer.getNumElements()
		<< " items, and its current capacity is " << stringContainer.getSize() << endl << endl;

	//Retrieve each element using for loop and operator []
	//Also try to access an out-of-bound element at the end and handle the thrown exception
	cout << "The contents of the String array are as follow: " << endl;
	int numElements = stringContainer.getNumElements();
	for (int i = 0; i <= numElements; ++i) { //NOTE this tries to access all the way up TO numElements
		try {
			cout << "Element " << i+1 << ": \"" << stringContainer[i] << "\"" << endl;
		} catch (String::IndexOutOfBoundsException exceptionObject) {
			cout << exceptionObject.getMessage() << endl;
			cout << "Attempted to access element at index " << exceptionObject.getIndex() << endl;
		} //end of try/catch block
	} //end of for loop
	cout << endl;

	//Attempt to create a new String instance, but with -5 elements in it:
	cout << "Attempting to create a new String with a negative number of elements: " << endl;
	try {
		String stringContBad = String(-5);
	} catch (String::IndexOutOfBoundsException exc) {
		cout << exc.getMessage() << endl;
		cout << "Attempted to create String with array of size " << exc.getIndex() << endl;
	} //end of try/catch block

	cout << "Completed successfully." << endl;

	//TODO: delete
//	system("PAUSE");
} //end of main