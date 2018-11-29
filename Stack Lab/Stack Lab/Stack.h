#pragma once
/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 11/29/18
* This program is practice in stacks
* Input: A string to parse
* Output: Whether the syntax is valid or not
*/
#include <list>

using std::list;

class Stack {
private:
	list<char> backingStore; //Note this is a composition (hard "has-a") relationship!
	//not an aggregation because backingStore is ESSENTIAL to the Stack class

public:
	//No constructor -- all interfacing comes from push and pop.
	void push(char newChar);
	char pop(); //pops and returns what was popped
	bool isEmpty();

}; //end of Stack class