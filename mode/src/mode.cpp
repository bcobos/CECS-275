//============================================================================
// Name        : mode.cpp
// Author      : Dong Jae Shin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "Freq.h"

using namespace std;

vector <Freq> mode(int * arry[], int nValues);
int validate_int_input(string, int, int);
int findFreq(Freq current, vector<Freq> frequencies);
int main() {

	int MAX_LENGTH = 100;
	int elements, value, validated_value;
	char cont = 'y';

	// pre-define the length of the arry
	int arry[MAX_LENGTH];

	// start of do while loop, end when the user inputs n
	do {
		// prompt the user for the number of elements that they want in the list
		cout << "How many elements in the list?: " << endl;
		cin >> elements;

		// validate the integer input
		elements = validate_int_input("That is not a valid input, please input a valid input", elements, MAX_LENGTH);


		// add the numbers to static array
		for(int i = 1; i <= elements; i ++){

			cout << "Enter the next value --> " << endl;
			cin >> value;

			validated_value = validate_int_input("please input the correct input",i,i+1);
		} // end of for loop
	} while(cont == 'y');

	return 0;


}

int validate_int_input(string prompt , int elements, int max){

	// if cin fails, validate the input
	while(cin.fail() || (elements <= 0) || (max < elements)){

		// clears the buffer
		cin.clear();
		string junk;
		getline(cin, junk);

		// get the correct input
		cout << prompt << endl;
		cin >> elements;
	}

	// return the correct input if the cin failed
	// or return the valid input if the input was
	// valid
	return elements;
}


vector<Freq> mode(int * arry, int nValues){

	vector <Freq> mode_freq;
	for(int i = 0; i < nValues; i++){
		Freq current;

		// get the content of the array
		current.value = *arry;

		int index = findFreq(current, mode_freq);

		// if the index is not found set the frequency equal to 0
		const int FAIL = -1;
		if(index == FAIL){
			current.frequency = 1;
			mode_freq.push_back(current);
		} else { // the number occurred more than one time
			// update frequency of the current iteration
			mode_freq[i].frequency++;
		}
		arry ++;
	}
	return mode_freq;

}

int findFreq(Freq current, vector<Freq> frequencies){

	int vect_length = frequencies.size();
	int index = -1;

	// loop through every iteration of the freq
	for(int i = 0; i < vect_length; i++){
		if(current.value == frequencies[i].value){
			index = i;
		}
	}
	return index;
}
