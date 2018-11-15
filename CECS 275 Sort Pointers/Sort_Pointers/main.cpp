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
Person& arrQuickSort(Person *ptr[], int size, int *fctPtr);
Person& arrQuickSort(Person *ptr[], int start, int end, int *fctPtr);
void swap(Person *value1, Person *value2);
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
Person& arrQuickSort(Person *ptr[], int size, int *fctPtr) {
	*ptr = arrQuickSort(ptr, 0, size - 1, fctPtr);
	return *ptr;
}

/**
 * Quick sort helper function
 */
Person& arrQuickSort(Person *ptr[], int start, int end, int *fctPtr) {

	// set the partition ( end of the array )
	Person partition = *(ptr[end]);

	// set the compare function
	partition.setCompFunc(fctPtr);
	int comp_result;

	// terminating recursion
	if (end - start <= 1) {

		// get the compare result
		comp_result = partition.compare(*(ptr[start]));

		// if the partition < start
		if (comp_result == 1) {
			// swap the ptr
			swap(ptr[start], ptr[end]);
		} // end of if
		// if it  is same or less than keep the pointer same

	} else { //  when it is not a terminating iteration

		// get the partition index
		int p_i = end;
		int bot_i = start;
		int top_comp_result;
		int bot_comp_result;
		while (p_i != bot_i) {
			// compare the partition with the one right below
			top_comp_result = partition.compare(*(ptr[p_i - 1]));

			// if the partition < p_i-1
			if (top_comp_result == 1) {
				swap(ptr[p_i - 1], ptr[p_i]);

				// update the partition index
				--p_i;
			}
			// if it is same just update the partition index
			else if (top_comp_result == 0) {
				--p_i;
			}
			// if partition > p_i-1
			else {
				// get the compare between the bottom index and the top index
				bot_comp_result = (*ptr[bot_i]).compare(*ptr[p_i - 1]);
				
				// if the bot < p_i-1 or if it is equal
				if (bot_comp_result >= 0) {

					// update bottom index
					++bot_i;
				}
				// if bot> p_i-1
				else {
					swap(ptr[p_i - 1], ptr[bot_i]);
					++bot_i;
				}
			}

		}
		// sort the lower bounds
		arrQuickSort(ptr, start, p_i - 1, fctPtr);

		// sort the higher bounds
		arrQuickSort(ptr, p_i + 1, end, fctPtr);
	}
	return *ptr;
}

/**
 * Exchange two elements in an array.  Note that these are passed in by
 * reference, not value so that the source copy is manipulated.
 * @param	value1		The first value to be swapped.
 * @param	value2		The second value to be swapped.
 */
void swap(Person *value1, Person value2) {
	Person temp = value1;
	value1 = value2;
	value2 = temp;
}