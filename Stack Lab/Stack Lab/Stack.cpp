/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 11/29/18
* This program is practice in stacks
* Input: A string to parse
* Output: Whether the syntax is valid or not
*/
#include "Stack.h"

/**
* Pushes a character to the top of the Stack
* @param newChar the next character to add to the top of the Stack
*/
void Stack::push(char newChar) {
	backingStore.push_front(newChar);
} //end of push Stack member function

/**
* Pops a character off of the top of the Stack
* @returns the character that was popped off
*/
char Stack::pop() {
	char temp = backingStore.front();
	backingStore.pop_front();
	return temp;
} //end of pop Stack member function

/*
* @returns true if the Stack is currently empty
*/
bool Stack::isEmpty(){
	return (backingStore.size() == 0);
} //end of isEmpty 
