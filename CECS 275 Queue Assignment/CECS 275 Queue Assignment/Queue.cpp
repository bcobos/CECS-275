/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date due 12/6/2018
* This program is practice in the Queue ADT
* Input: None
* Output: Effects of manipulating a queue data structure in a simulation of life
*/
#include "Queue.h"
#include <sstream>

/**
* If queue capacity is reached, doubles the available space
* Note that this already only gets called if necessary...
*... another appropriate name would simply have been growBuffer()
*/
void Queue::growBufferIfNecessary() {	
	// update to newCapacity -- temporary variable
	int newCapacity = capacity * 2; 
	// double the capacity in a new array
	string* tempBuffer = new string[newCapacity];	
	// copy the content of the array
	for (int i = 0; i < currentSize; ++i) {
		tempBuffer[i] = buffer[(head + i) % currentSize]; //modding by currentSize brings things back to zero
	} // end of for loop
	//reset head and currentPeek back to zero index for new array
	head = 0;
	currentPeek = 0;
	//set tail to the new endpoint index
	tail = currentSize - 1;
	// get rid of the old contents of the buffer
	delete [] buffer;
	// relocate the buffer pointer to where the new buffer is
	buffer = tempBuffer;
	// update buffer capacity
	capacity = newCapacity;
} //end of growBufferIfNecessary member function

/**
* Queue default constructor
*/
Queue::Queue() {
	queueAvailable = true;
	head = 0;
	tail = 0; 
	currentSize = 0;
	capacity = 10;
	buffer = new string[capacity]; 
	currentPeek = 0;
} //end of default constructor

/**
* Queue constructor
* @param newSize the size to initialize the queue to
*/
Queue::Queue(int newSize) {
	queueAvailable = true;
	head = 0;
	tail = 0;
	capacity = newSize;
	buffer = new string[newSize];
	currentSize = 0;
	currentPeek = 0;
} //end of Queue int-parameter constructor

/**
* Queue copy constructor
* @param other the other Queue to create a DEEP copy of
*/
Queue::Queue(const Queue& other) {
	//std::cout << "GLYAK!" << std::endl;
	this -> queueAvailable = other.queueAvailable;
	this -> head = other.head;
	this -> tail = other.tail;
	this -> capacity = other.capacity;
	this -> currentSize = other.currentSize;
	this -> currentPeek = other.currentPeek;
	this -> buffer = new string[this->capacity];
	//Finally, deep copy of buffer:
	for (int i = head; i != this->tail; i = (i+1) % this->capacity) {
//		std::cout << this->to_string() << std::endl;
		(this->buffer)[i] = other.buffer[i];
	} // end of for loop
} //end of Queue copy constructor

/**
* Queue destructor
*/
Queue::~Queue() {
	// delete the array values
	delete [] buffer;
	// re-locate the leftover pointer to nullptr
	buffer = nullptr;
} //end of Queue destructor

/**
* Adds an std::string to the back of the queue
* @param newString the new element to add to the string queue
*/
void Queue::add(string newString) {
	if (queueAvailable) { //only add to queue if the queue has not been closed yet
		// update currentSize
		++currentSize;

		// grow buffer if all the queue is filled up
		if (currentSize == capacity) { 
//			std::cout << "Growing queue dynamicaly...\n" << "Contents before growth:\n" << this->to_string() << std::endl;
			growBufferIfNecessary();
			//(note that tail will be reset again in this function if buffer grew)
		} //end of if

	    // add string to tail position
		buffer[tail] = newString;

		// update tail. 
		++tail; //increment tail 
		tail %= capacity; //mod down to capacity, in case of overflow off of buffer

	} //end of if
	else //queue not available to add new strings to
		throw FilledException(newString);
} //end of add member function

/**
* Removes an element from the front of the queue
* @return the removed string
*/
string Queue::remove() {
	// NOTE: no point of removing the content the current head index
	//		 because the head index is keeping the track of
	//		 "valid" content of the array.
	//		 Though the previous value is still stored in the previous head,
	//		 we will consider it "not-valid", because the head index is updated away.
	//		 i.e. the previous content that is not indexed by current head value
	//		 is no longer valid for us.

	// get the content of the current head, to return at end of function
	string temp = buffer[head];
	
	// update current size
	if (currentSize > 0) { //TODO shouldn't we be checking this for EVERYTHING, besides just updating currentSize?
		--currentSize;
	} // end of if

	++head; //increment head (therefore "invalidating" previous head)
	head %= capacity; //cycle it around the buffer, if necessary

	return temp;
} //end of Queue remove member function

/**
* Takes a look at what's at the front of the line
* @returns the string at the front of the queue
*/
string Queue::peek() {
	return buffer[head];
} //end of peek Queue member function

/**
 * Display the content of the queue
 * @return a string with current information about the queue
 */
string Queue::to_string(){
	std::stringstream sstream;
	/*
	sstream << "\nTo_string Function gives:\n";
	sstream << "head: " << head << std::endl;
	sstream << "tail: " << tail << std::endl;
	sstream << "capacity: " << capacity << std::endl;
	sstream << "currentSize: " << currentSize << std::endl;
	sstream << "currentPeek: " << currentPeek << std::endl;
	sstream << "Member strings are: " << std::endl;
	*/

	this->peekReset();
	//first element to the stream
	sstream << this->peek() << std::endl;
	while (this->peekHasNext()) { //while there is a next element
		//input next element to stream
		sstream << this->peekNext() << std::endl;
	} //end of while

	return sstream.str();
} //end of to_string function

/**
* Resets peek variable back to the current starting index (front of queue)
*/
void Queue::peekReset() {
	currentPeek = head;
} //end of peekReset member function

/**
* Checks whether we're at the back of the queue
* @returns true if there is an available string in the queue after the currentPeek index slot
*/
bool Queue::peekHasNext() {
	bool hasNext = true;
	if (currentPeek == tail)	hasNext = false; 
	return hasNext;
/*	//OLD VERSION:
	bool next = false;

	// if (tail-head) is positive the peek value will increment
	// if (tail-head) is negative the peek value will decrement
	// if the head and tail are the same value there is no next peek
	//int checkNext = tail - head;

	// check if all the queue is filled up
	if (currentSize == capacity) {
		// there is always a next. NOTE: WHAT IF WE'RE AT END OF QUEUE? PROBABLY DON'T WANT THIS TO KEEP GOING FOREVER
		next = true;
	} else {
		
		// update current peek
		//++currentPeek;
		// does not need to update current peek.
		// only has to check if there is next peek available.

		// if the next peek is less than the tail, there is next
		if (currentPeek + 1 <= tail) {
			
			next = true;
		}
	}
	return next;
	*/
} //end of Queue peekHasNext member function

/**
* Updates the currentPeek index to the next one up and shows what's in that slot.
* @returns the string in the next queue position
*/
string Queue::peekNext() {
	// update currentPeek value
	currentPeek = (currentPeek + 1) % capacity;

	// return the content of the current peek
	return buffer[currentPeek];
} //end of peekNext Queue member function

/**
* Closes the queue so no other strings may enter
*/
void Queue::closeQueue() {
	queueAvailable = false;
} //end of closeQueue function

/**
* Tells you whether the queue is available to add new strings to
* @returns queueAvailability
*/
bool Queue::getQueueAvailability() {
	return queueAvailable;
} //end of getQueueAvailability function

/**
* Checks whether a queue has no string in it
* @returns false if the queue is empty
*/
bool Queue::isEmpty() {
	return (currentSize == 0);
} //end of isEmpty member function
