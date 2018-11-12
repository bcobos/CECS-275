/**
 * @authors Bernardo Cobos, Dong Jae Shin
 * @date Started 11/11/18; Due 11/15/18
 * This Program sorts the array pointer
 * Input: None
 * Output: Sorted pointer array that points to the array of person array
 */

#include <iostream>
#include "Person.h"

// free function initialization
void print_info(Person *ptr[], int size);
Person *arrQuickSort(Person *ptr[], int size, int *fctPtr);

int main() {
	const int NUMBER_OF_PEOPLE = 8;

	// create array of persons
	Person People[NUMBER_OF_PEOPLE] = {Person("Rutz","Michale",6,0), Person("Brown","David",5,10), 
						Person("Brown","Mary",5,6), Person("Canavan","Jean",5,5),
						Person("Burris","Danial",6,0), Person("Rutz","Mary",5,5),
						Person("Canavan","Rod",6,0), Person("Cobos","Bernardo",6,0)};

	// create an array of pointer
	Person *people_ptr[NUMBER_OF_PEOPLE];

	// assign the address of People
	for (int i = 0; i < NUMBER_OF_PEOPLE; ++i) {
		people_ptr[i] = &People[i];
	}

	print_info(people_ptr, NUMBER_OF_PEOPLE);

	std::cout << "Completed Satisfactorily." << std::endl;

	//TODO: comment out when turning it in
	system("PAUSE");

} //end of main

/**
 * prints the contents of the pointers
 */
void print_info(Person *ptr[], int size) {

	for (int i = 0; i < size; ++i) {

		// prints the contents of the pointers
		(*(ptr[i])).to_string();
	} // end of for loop

} // end of free function print_info

/**
 * Quick sort
 */
Person *arrQuickSort(Person *ptr[], int size, int *fctPtr) {

}