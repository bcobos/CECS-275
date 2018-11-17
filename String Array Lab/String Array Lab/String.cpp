#include "String.h"

///////////STRING CONSTRUCTORS////////////////

/**
* String default constructor sets arraySize and numElements to zero ...
* ...and array pointer to nullptr
*/
String::String() {
	numElements = 0;
	arraySize = 0;
	strArrPtr = nullptr;
} //end of String default constructor

  /**
  * String int constructor sets numElements to zero, ...
  * ...arraySize to the input number of elements, ...
  * ...and allocates strArrPtr's string array's memory dynamically
  */
String::String(int numElementsIn) {
	if (numElementsIn < 0) {
		string errorMessage = "Cannot create an array of negative size, you fool.";
		throw IndexOutOfBoundsException(numElementsIn, errorMessage);
	}
	else if (numElementsIn == 0) {
		arraySize = 0;
		strArrPtr = nullptr;
	}
	else { //array size is greater than zero
		arraySize = numElementsIn;
		strArrPtr = new string*; //initialize pointer (on stack) to new string pointer on heap
		*strArrPtr = new string[arraySize]; //initialize that string pointer to a new string array
	} //end of if/else if/else block
	numElements = 0;
} //end of String single-parameter constructor

////////////////Destructor////////////////

/**
* Destructor for String gets rid of dynamically allocated memory
*/
String::~String(){
	delete[] *strArrPtr;
	delete strArrPtr;
} //end of String destructor

/////////////////String Member Functions////////////////////////

/**
* Adds a new element into the String array
* @param newElement the string we add to the String array
*/
void String::add(string newElement) {
	++numElements;
	resizeIfNecessary();
	(*strArrPtr)[numElements - 1] = newElement;
} //end of add String member function
  /*
  //OLD add function code:
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
  * Checks if we need to resize String array, and does so if necessary
  */
void String::resizeIfNecessary() {
	//Only do something if we need to resize:
	if (numElements > arraySize) { //means we need more space in array first
		//Update arraySize:
		int oldArraySize = arraySize;
		if (arraySize == 0) { //NOTE this also means strArrPtr == nullptr
			++arraySize; //arraySize = 1 now
			//Initialize array and pointer to that array:
			strArrPtr = new string*; //pointer to string pointer (ie to string array)
//			*strArrPtr = new string[arraySize]; //new string (array of size 1) //Later?
		} //end of if
		else //otherwise we're not adding the first element
			arraySize *= 2; //memory already allocated somewhere. Double the array size.

		//Create the new, larger array:
		string* newArray = new string[arraySize]; //new string array on the heap
		
		//Copy the current stuff over:
		//if this is the first add, then nothing will be copied, as oldArraySize == 0.
		for (int i = 0; i < oldArraySize; ++i) { 
			newArray[i] = (*strArrPtr)[i]; //initializing new array's values. Copy.
		} //end of for
//		std::cout << "new array address: " << newArray << "|| current array address: " << *strArrPtr << std::endl;

		//DELETE THE FREAKING MEMORY FROM OLD ARRAY FIRST BEWARE OF MEMORY LEAKS
//		delete[](*strArrPtr); //TODO: This is causing a problem. ...@$#@$ WHY THE FUCK!?

//Attempt #1000: "Desperation"
//		for (int i = 0; i < oldArraySize; ++i) {
//			delete (*strArrPtr + i);
//		}

		//set strArr member array to the new array
		*strArrPtr = newArray;
	} //end of if 
} //end of String::resizeIfNecessary member function

/**
* Overloads [] to check legality of index, and return indexed value if possible
* @param index the index of the string elment we want
* @returns reference to the string at the index value
*/
string& String::operator[](int index){
	if (index < 0 || index >= numElements) {
		string errorMessage("Index is out of bounds -- cannot access an element that isn't initialized");
		throw IndexOutOfBoundsException(index, errorMessage);
	} //end of if (checking bounds)

	return (*strArrPtr)[index];
} //end of String::operator[] overload

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
} //end of String::getSize member function


//////////////////////////////Exception Inner Class Code////////////////////////////////////////////


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
