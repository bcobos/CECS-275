/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 11/29/18
* This program is practice in stacks
* Input: A string to parse for opening and closing tokens
* Output: Whether the syntax is valid or not
*/
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool validate(string);

int main() {
	string userInput;
	bool isValid;

	do { //Prompt user for a string to validate until "null" is entered...
		cout << "Please give me a text string to validate, or lowercase \"null\" to exit. " << endl;
		getline(cin, userInput);
		if (userInput != "null") {
			isValid = validate(userInput);
			if (isValid)
				cout << "Valid Syntax" << endl;
			else
				cout << "Invalid Syntax" << endl;
		} //end of if statement
	} while (userInput != "null");

	cout << "Completed successfully." << endl;

	//TODO: comment out this line before turning in.
	//system("PAUSE");
} //end of main

/**
* @param str a string to validate
* @returns true if all open tokens have a corresponding close token
*/
bool validate(string str) {
	bool isValid = true; //consider validated until we find a mistake.
	string openers = "([{/<";
	string closers = ")]}\\>";
	int openersCount = openers.size();
	Stack stack;

	//Loop through the whole string and get characters
	int stringSize = str.size();
	char currentChar;
	for (int i = 0; i < stringSize; ++i) {
		currentChar = str[i];
		//Then check if currentChar is an opener or closer -- those are the only ones we care about
		for (int j = 0; j < openersCount; ++j) {
			//Check if it's one of the characters we care about. If not, ignore.
			if (currentChar == openers[j] || currentChar == closers[j]) {
				if (currentChar == openers[j])  //Is an opener
					stack.push(currentChar); //add it to the stack
				else { //is a closer
					//pop and check that currentChar matches the most recent opener
					char topOfStack;
					if (stack.isEmpty()) { //can't have a corresponding opener if there was nothing before it!
						isValid = false;
						break;
					} else //otherwise we can check what came before it, and continue...
						topOfStack = stack.pop();
					if (topOfStack != openers[j]) { //checking if closer-opener pair is NOT a match
						//(j is closer index; corresponds to respective opener)
						isValid = false;
						break; //break out, as our work here is done.
					} //end of if
				} //end of else
			} //end of if
		} //end of inner for loop
		if (!isValid) break; //if we have already found a mismatch, break out -- we're done
	} //end of for loop
	if (!stack.isEmpty()) //if there was an opener with no corresponding closer...
		isValid = false; //...then this syntax was not valid.
	return isValid;	
} //end of validate funtion