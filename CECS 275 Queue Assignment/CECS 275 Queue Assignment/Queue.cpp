#include "Queue.h"

/**
* If queue capacity is reached, doubles the available space
*/
void Queue::growBufferIfNecessary() {

	// update to newSize
	int newSize = currentSize * 2;

	// double the size
	string* tempBuffer = new string[newSize];
	
	// copy the content of the array
	for (int i = 0; i < currentSize; ++i) {
		tempBuffer[i] = buffer[(head + i) % currentSize];
	} // end of for loop
	
	// get rid of the content of the buffer
	delete buffer;

	// relocate the tempbuffer to buffer
	buffer = tempBuffer;

	// get rid of the content of the temp buffer
	delete tempBuffer;

	// update the size
	currentSize = newSize;

} //end of growBufferIfNecessary member function

/**
* Queue default constructor
*/
Queue::Queue() {
	// creating dynamic memory 
	buffer = new string[10]; 
	head = 0;
	tail = 0;
	capacity = 0;
	currentSize = 0;
	currentPeek = 0;

} //end of default constructor

/**
* Queue constructor
* @param newSize the size to initialize the queue to
*/
Queue::Queue(int newSize) {

	// allocate the memory
	buffer = new string[newSize];
	head = 0;
	tail = 0;
	capacity = 0;
	currentSize = 0;
	currentPeek = 0;

} //end of Queue int-parameter constructor

/**
* Queue copy constructor
* @param other the other Queue to create a DEEP copy of
*/
Queue::Queue(const Queue& other) {
	this -> buffer = other.buffer;
	this -> head = other.head;
	this -> tail = other.tail;
	this -> capacity = other.capacity;
	this -> currentSize = other.currentSize;
	this -> currentPeek = other.currentPeek;

} //end of Queue copy constructor

/**
* Queue destructor
*/
Queue::~Queue() {
	// re-create the dynamic allocation 
	buffer = new string;
	// delete the pointer
	delete buffer;
	// re-locate the left over pointer to null pointer
	buffer = nullptr;
} //end of Queue destructor

/**
* Adds an std::string to the back of the queue
* @param newString the new element to add to the string queue
*/
void Queue::add(string newString) {

	// update tail.
	// tail is update before the changing the content of the bueffer,
	// because as the contents that are added are declared on the next tail
	// instead of current tail.
	// refrence is in the requirement table (check push 5, ie second row of operation)

	if (++tail % capacity == 0) {
		tail = 0;
	} else {
		++tail;
	} // end of if
	// NOTE: above code could be replaced with bottom line
	// tail = (tail + 1) % capacity;


	// change the content of the current pointer
	buffer[tail] = newString;

	// update currentSize only if it is less than capacity
	if (currentSize < capacity) {
		++currentSize;
	} // end of if
} //end of add member function

/**
* Removes an element from the front of the queue
* @return the removed string
*/
string Queue::remove() {

	// NOTE: no point of removing the content the current head index
	//		 because the head index is keeping the track of
	//		 "valid" content of the array.
	//		 Though the previous value is still stored in the previous head
	//		 we will consider it "not valid", because the head index is updated.
	//		 i.e. the previous content that is not indexed by current head value
	//		 is no longer valid for us.

	// get the content of the current head
	string temp = buffer[head];

	
	// update current size
	if (currentSize > 0) {
		--currentSize;
	} // end of if

	// update head only if it is less than the capacity
	if (++head % capacity == 0) {
		head = 0;
	} else {
		++head;
	} // end of if

	// NOTE: above code could be replaced with bottom line
	// head = (head + 1) % capacity;

	return temp;
} //end of Queue remove member function

/**
* Takes a look at what's at the front of the line
* @returns the string at the front of the queue
*/
string Queue::peek() {

	// return the current index of head in the array
	return buffer[head];
} //end of peek Queue member function


// NOTE TO BERNARDO:
// I just made peek increment, because I think it is a better way of coding
// instead of creating the peekNext
/**
* Increments the peek value
*/
void Queue::peekInc() {
	++currentPeek;
} //end of peekInc Queue member function


/**
* Resets peek variable back to the current starting index (front of queue)
*/
void Queue::peekReset() {
	currentPeek = head;
} //end of peekReset member function

/**
* Checks whether we're at the back of the queue
* @returns true if there is an available string after the currentPeek index slot
*/
bool Queue::peekHasNext() {
	bool next = false;

	// if tail - head is positive the peek value will increment
	// if tail - head is positive the peek value will decrement
	// if the head and tail are the same value there is no next peek
	int checkNext = tail - head;
	
	// if checkNext is positive peek value will increment to check with tail
	if (checkNext > 0) {
		// if the nextpeek value is less than or equal to tail there is a peek value
		if (currentPeek + 1 <= tail) next = true;
	} else if (checkNext < 0) { // if checkNext is negative peek value will decrement to check with tail
		// if the nextpeek value is greater than or equal to tail there is a peek value
		if (currentPeek - 1 >= tail) next = true;
	}

	return next;

} //end of Queue peekHasNext member function

/**
* Updates the currentPeek index to the next one up

* @returns a string??.... I think the instructions must be wrong.
* ...I think it shouldn't actually return anything, as it's just updating a value
* NOTE how this gets used in 1) and 2) in Main.cpp!!

*/
string Queue::peekNext() {
	// NOTE TO BERNARDO:
	//	I think this is supposed to return string, because the member function
	//	peek would only return the content of the head.
	//	Therefore, peekNext will take care of the other peeking method.
	//	I think this could be the only reason why he would put it  like this.
	//	Since this is not like an array and it is more like linked list, I
	//	would say peeking a value would be using the "harder way."
	//	I know that it does not make any sense, but I'm trying to put myself
	//	in professor's shoe.

	// I guess the functionality of this is getting the next peek value?????
	// confused...


	// update currentPeek value
	currentPeek = (currentPeek + 1) % capacity;

	// get the content of the current peek
	string temp = buffer[currentPeek];

	return temp;
} //end of peekNext Queue member function