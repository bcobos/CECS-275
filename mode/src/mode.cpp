/**
 * @authors Dong Jae Shin, Bernardo Cobos
 * @date 10/23/18
 * This program finds mode of an array by using array-pointer duality
 * Inputs: size of a list, numbers to put in the list
 * Output: mode(s) of the list
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "Freq.h"

using namespace std;

vector <Freq> mode(int * arry, int nValues);
int validate_int_input(string, int, int);
int findFreq(Freq current, vector<Freq> frequencies);

int main() {

	const int MAX_LENGTH = 100;
	int elements; //num elements user will put in
	int value; //value of user input
	int validated_value; //appropriate user value validated by functions
	char cont = 'y'; //character used to check if user wants to continue putting values in

	// pre-define the length of the arry
	int arry[MAX_LENGTH];

	// start of do while loop, end when the user inputs n
	do {
		// prompt the user for the number of elements that they want in the list
		cout << "How many elements in the list?: " << endl;
		cin >> elements;

		// validate the integer input
		string sizeErrorMessage = "That is not a valid input, please input a valid input";
		elements = validate_int_input(sizeErrorMessage, elements, MAX_LENGTH);


		// add the numbers to static array
		for(int i = 1; i <= elements; i ++){

			cout << "Enter the next value --> " << endl;
			cin >> value;
			arry[i - 1] = value; //put this value in the array

			validated_value = validate_int_input("please input the correct input",i,i+1);
		} // end of for loop

		//Go thru list of modes, print their stuff
		vector<Freq> modes = mode(arry, elements);
		int vecLength = modes.size();
		for (int i = 0; i < vecLength; ++i) {
			cout << "The next value/frequency is: " << modes[i].value << "/" << modes[i].frequency << endl;
		} //end of for loop.

		cout << "Continue? (y/n)" << endl;
		cin >> cont;
	} while(cont == 'y' || cont == 'Y');


	cout << "Completed successfully" << endl;

	//TODO: delete this before turning in.
//	system("PAUSE");

	return 0;
} //end of main function

/**
 * Prompts user for appropriate input and checks it. 
 * @param prompt the string to display to user upon an error
 * @param elements the user input value
 * @param max the max allowable input
 * @return user input string, if allowable
 */
int validate_int_input(string prompt , int elements, int max) {
	// if cin fails, validate the input
	while(cin.fail() || (elements <= 0) || (elements > max)){

		// clears the buffer
		cin.clear();
		string junk;
		getline(cin, junk);

		// get the correct input
		cout << prompt << endl;
		cin >> elements;
	} //end of while loop

	// return the correct input if the cin failed
	// or return the valid input if the input was
	// valid
	return elements;
} //end of validate_int_input function

/*
 * Finds the mode of an array of ints, and returns a vector of that (those) mode(s)
 * @param arry, an array of ints, in the form of a pointer
 * @param nValues, the number of values in an array
 * @returns a vector of Freq objects giving the value and count of each mode of arry
 */
vector<Freq> mode(int* arry, int nValues){
	vector<Freq> freqsInArray; //will track which values are in array, along with frequencies
	vector <Freq> mode_freq; //output freq

	//loop through all array elements to count frequency of values
	for(int i = 0; i < nValues; i++){
		//create temp Freq object for this array element
		Freq current; //default intialized to 0,0

		// get the content of the array
		current.value = *arry; 

		//find where in the vector this Freq is, if it's in at all
		int index = findFreq(current, freqsInArray); 

		// if the index is not found, set the frequency equal to 1 -- has been counted once
		const int FAIL = -1;
		if (index == FAIL){
			current.frequency = 1; 
			freqsInArray.push_back(current); //add this new Freq to the list
		} else { // the number occurred more than one time
			// update existing Freq frequency of the current iteration
			freqsInArray[index].frequency++;
		} //end of if/else statements

		arry++; 
	} //end of for loop

	//now, go thru array of Freqs and keep only the most frequent one(s) in mode_freq vector
	int numFreqsInArray = freqsInArray.size();
	mode_freq.push_back(freqsInArray[0]); //add first Freq to this list. Next ones will be compared to this
	int maxFreq = freqsInArray[0].frequency;
	for (int i = 1; i < numFreqsInArray; ++i) {
		if (freqsInArray[i].frequency > maxFreq) { //this is highest frequency so far
			mode_freq.clear();
			mode_freq.push_back(freqsInArray[i]);
			maxFreq = freqsInArray[i].frequency;
		}
		else if (freqsInArray[i].frequency == maxFreq) { //tied for max.
			mode_freq.push_back(freqsInArray[i]);
		}
		else { //else this is not the current max...
			   //...do nothing!! It will be forgotten as an unimportant speck in history, just like the rest of us
		} //end of if/else if/else statements
	} //end of for loop

	return mode_freq;
} //end of mode function

/**
 * Checks existence of a Freq object in an array of Freqs
 * @param current the current Freq we're checking for
 * @param frequencies the array of Freqs we're looking in.
 * @returns -1 if Freq not in list' index of the Freq if it is. 
 */
int findFreq(Freq current, vector<Freq> frequencies){
	int vect_length = frequencies.size();
	int index = -1; //Default is the fail value. Change only if found.

	// loop through everything in freq vector
	for (int i = 0; i < vect_length; i++){
		//If the value of this one is the value we're looking for
		if(current.value == frequencies[i].value){
			index = i; //set the output index to be this one
			break; //we're done with our search; break out.
		} //end of if statement
	} //end of for loop
	return index;
} //end of findFreq function