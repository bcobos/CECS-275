#pragma once
/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date due 12/6/2018
* This program is practice in the Queue ADT
* Input: None
* Output: Effects of manipulating a queue data structure in a simulation of life
*/
#include <string>
#include <iostream>
using std::string;

class Queue {
private:
	bool queueAvailable; //boolean for whether we can add new strings to the queue
	string* buffer; //pointer to array 
	unsigned int head; //buffer index front of queue
	unsigned int tail; //buffer index back of queue
	unsigned int capacity; //max possible amount in the queue
	unsigned int currentSize; //num elements in Queue at a given time
	unsigned int currentPeek; //index to where currently peeking in queue
	void growBufferIfNecessary();
	
public:
	//Constructors:
	Queue();
	Queue(int);
	Queue(const Queue&);
	//Destructor:
	~Queue();
	//Other member functions:
	void add(string);
	string remove();
	string peek();

	string to_string();
	void closeQueue();
	bool getQueueAvailability();

	//"Iterator" functions:
	void peekReset();
	bool peekHasNext();
	string peekNext();
	class FilledException {
	private:
		string nameOfOffender;
	public:
		FilledException(string name) { nameOfOffender = name; }
		string getName() { return nameOfOffender; }
	}; //end of exception class

}; //end of Queue class