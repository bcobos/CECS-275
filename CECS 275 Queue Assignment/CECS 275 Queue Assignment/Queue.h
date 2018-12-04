#pragma once
#include <string>
#include <iostream>
using std::string;

class Queue {
private:
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

	//"Iterator" functions:
	void peekReset();
	bool peekHasNext();
	string peekNext();
	//TODO: Exception class:
	//(we still need to create functionality for how it would be used)
	//note this may involve the creation of a boolean value indicating whether the queue is available to add to
	//then we'd also need getter/setter for that variable...
	class FilledException {
	private:
		string nameOfOffender;
	public:
		FilledException(string name) { nameOfOffender = name; }
		string getName() { return nameOfOffender; }
	}; //end of exception class

}; //end of Queue class