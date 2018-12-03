#include "Queue.h"

/**
* If queue capacity is reached, doubles the available space
*/
void Queue::growBufferIfNecessary() {

} //end of growBufferIfNecessary member function

/**
* Queue default constructor
*/
Queue::Queue() {

} //end of default constructor

/**
* Queue constructor
* @param newSize the size to initialize the queue to
*/
Queue::Queue(int newSize) {

} //end of Queue int-parameter constructor

/**
* Queue copy constructor
* @param other the other Queue to create a DEEP copy of
*/
Queue::Queue(const Queue& other) {

} //end of Queue copy constructor

/**
* Queue destructor
*/
Queue::~Queue() {

} //end of Queue destructor

/**
* Adds an std::string to the back of the queue
* @param newString the new element to add to the string queue
*/
void Queue::add(string newString) {

} //end of add member function

/**
* Removes an element from the front of the queue
* @return the removed string
*/
string Queue::remove() {

} //end of Queue remove member function

/**
* Takes a look at what's at the front of the line
* @returns the string at the front of the queue
*/
string Queue::peek() {

} //end of peek Queue member function

/**
* Resets peek variable back to the current starting index (front of queue)
*/
void Queue::peekReset() {

} //end of peekReset member function

/**
* Checks whether we're at the back of the queue
* @returns true if there is an available string after the currentPeek index slot
*/
bool Queue::peekHasNext() {

} //end of Queue peekHasNext member function

/**
* Updates the currentPeek index to the next one up

* @returns a string??.... I think the instructions must be wrong.
* ...I think it shouldn't actually return anything, as it's just updating a value
* NOTE how this gets used in 1) and 2) in Main.cpp!!

*/
string Queue::peekNext() {

} //end of peekNext Queue member function