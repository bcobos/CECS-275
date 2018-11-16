#include "String.h"

/**
* Checks if we need to resize String array and does so if necessary
*/
void String::resizeIfNecessary(){
	//Only do something if we need to resize:
	if (numElements > arraySize) { 
		//Update arraySize:
		int oldArraySize = arraySize;
		if (arraySize == 0) { //NOTE this also means strArrPtr == nullptr
			++arraySize; //arraySize = 1 now
			//Initialize array and pointer to that array:
			strArrPtr = new string*; //pointer to string pointer (ie to string array)
			*strArrPtr = new string; //new string (array of size 1)
			//numElements = 1;
		} //end of if

		else
			arraySize *= 2;
		//Create the new, larger array:
		string* newArray = new string[arraySize]; //new string array on the heap
		//Copy the current stuff over:
		for (int i = 0; i < oldArraySize; ++i) {
			newArray[i] = (*strArrPtr)[i]; //initializing new array's values
//			std::cout << newArray[i] << std::endl;
		} //end of for

		//DELETE THE FREAKING MEMORY FROM OLD ARRAY FIRST BEWARE OF MEMORY LEAKS
//		delete[] (*strArrPtr); //TODO: This is causing a problem. Fixed by adding *?

		//set strArr member array to the new array
		strArrPtr = &newArray;

	} //end of if 
} //end of String::resizeIfNecessary member function

/**
* Destructor for String gets rid of dynamically allocated memory
*/
String::~String(){
	delete[] *strArrPtr;
	delete strArrPtr;
} //end of String destructor

/**
* String default constructor sets arraySize and numElements to zero ...
* ...and array pointer to nullptr
*/
String::String(){
	numElements = 0;
	arraySize = 0;
	strArrPtr = nullptr;
} //end of String default constructor

/**
* String int constructor sets numelements to zero, ...
* ...arraySize to the input number of elements, ...
* ...and allocates strArrPtr's string array's memory dynamically
* QUESTION: why not set numElements? Probably doing something in add() to add elements...
*/
String::String(int numElementsIn){
	if (numElementsIn < 0) {
		string errorMessage = "Cannot create an array of negative size, you fool.";
		throw IndexOutOfBoundsException(numElementsIn, errorMessage);
	} else if (numElementsIn == 0) { 
		arraySize = 0;
		strArrPtr = nullptr;
	} else { //array size is greater than zero
		arraySize = numElementsIn;
		strArrPtr = new string*; //initialize pointer (on stack) to new string pointer on heap
		*strArrPtr = new string[arraySize]; //initialize that string pointer to a new string array
	} //end of if/else if/else block
	numElements = 0;
} //end of String single-parameter constructor

/**
* Overloads [] to check legality of index, and return indexed value if possible
* @param index the index of the string elment we want
* @returns reference to the string at the index value
*/
string& String::operator[](int index){
	if (index < 0 || index >= arraySize) {
		string errorMessage("Index is out of bounds -- cannot access an element that isn't there");
		throw IndexOutOfBoundsException(index, errorMessage);
	} //end of if (checking bounds)

	return (*strArrPtr)[index];
} //end of String::operator[] overload

/**
* Adds a new element into the String array
* @param newElement the string we add to the String array
*/
void String::add(string newElement) {
	++numElements;
	resizeIfNecessary();
//	(*this)[numElements - 1] = newElement; //NOTE this relies on operator[] overload. Doesn't work.
	(*strArrPtr)[numElements - 1] = newElement;
} //end of add String member function
/*
void String::add(string newElement){
	if (strArrPtr == nullptr) { //adding first element after default constructor
		strArrPtr = new string*; //pointer to string pointer (ie to string array)
		*strArrPtr = new string; //new string (array of size 1)
		arraySize = 1;
		numElements = 1;		
	} //end of if
	else { //everything initialized; just add element.
		//Size adjust:
		++numElements;
		resizeIfNecessary();
	} //end of else
	//Add the new element to the end:
	(*strArrPtr)[numElements - 1] = newElement; //TODO: this line works fine and then causes an error
} //end of String::add member function
*/

/**
* @returns current number of elements
*/
int String::getNumElements(){
	return numElements;
} //end of String::getNumElements member function

/**
* @returns current Array size
*/
int String::getSize(){
	return arraySize;
} //end of Person::getSize member function

/**
* Constructor for String::IndexOutOfBoundsException class
*/
String::IndexOutOfBoundsException::IndexOutOfBoundsException(int badIndex, string newMessage){
	outOfBoundsIndex = badIndex;
	message = newMessage;
} //end of constructor

/**
* @returns the failed index that throws the IndexOutOfBounds exception
*/
int String::IndexOutOfBoundsException::getIndex(){
	return outOfBoundsIndex;
} //end of getIndex function for exception class

/**
* @returns the exception message
*/
string String::IndexOutOfBoundsException::getMessage(){
	return message;
} //end of getMessage exception function
