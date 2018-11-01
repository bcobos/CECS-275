/**
 * @authors Bernardo Cobos, Dong Jae Shin
 * @date 10/30/18
 * This project is practice in dynamic allocatino and freeing space, along with treating pointers as arrays
 * Input: 
 * Output: 
 */

#include <iostream>

using namespace std;

int* reverse(const int[], const int);

int main() {

	const int sz = 10;
	int arr[sz];
	for (int i = 0; i < sz; ++i) {
		arr[i] = i * i;
		cout << "Next element in original order is " << arr[i] << endl;
	} //end of for

	int* revArr = reverse(arr, sz);
	cout << endl;

	for (int i = 0; i < sz; ++i) {
		cout << "Next element in reversed array is " << revArr[i] << endl;
	} //end of for

	cout << endl << "Completed Successfully" << endl;

	//system("PAUSE");
} //end of main

/**
 * Takes in an array and reverses its elements in a copy
 * @param arr the int array to be reversed
 * @param size the number of elements in the array
 * @return a pointer to the new, reversed int array.
 */
int* reverse(const int arr[], const int size) {
	int* copyArr = new int[size]; //new ALWAYS RETURNS A POINTER.

	for (int i = 0; i < size; ++i) {
		copyArr[i] = arr[(size-1) - i];
	} //end of for
	
	return copyArr;
} //end of reverse array