#pragma once
/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 11/15/18
* This program is practice with operator overloading, memory management, and exception handling
* Input: None
* Output: Result of adding to a container object and of playing with exceptions
*/

#include <string>
#include <iostream>

using std::string;

class String {
private:
	//Private member variables:
	int numElements;
	int arraySize;
	string** strArrPtr;
	
	//Private member functions:
	void resizeIfNecessary();
//	~String(); //The destructor being private does not allow creation of the object...

public:
	//Constructors:
	String();
	String(int numElementsIn);
	//Public member functions:
	string& operator[](int index);
	void add(string newElement);
	int getNumElements();
	int getSize();
	~String();

	//IndexOutOfBoundsException Class:
	class IndexOutOfBoundsException {
	private:
		int outOfBoundsIndex;
		string message;
	public:
		IndexOutOfBoundsException(int badIndex, string newMessage);
		int getIndex();
		string getMessage();
	}; //end of IndexOutOfBoundsException nested class
}; //end of String class
