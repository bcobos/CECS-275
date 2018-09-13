/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 9/13/18
* Purpose: to find a set number of primes using student-created square root functions
* Inputs: number primeCount of primes desired
* Outputs: The first primeCount prime numbers and their square roots
*/

//Problems with lab:
//confusion on wording with algorithm for sqrt
//exception throwing confusion
//for some reason, our sqrt overloading was not working.. talked with Bernardo talked about this, and we could not figure it out together

#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

///Function Declarations///
long sqrtL(const long&);
double sqrtD(const double&);
bool primeTest(int);

int main() {
	unsigned int primeCount; //The number of primes that the user decides they will like to find
	cout << "Enter the number of prime numbers to find: ";
	cin >> primeCount;
	cout << endl;
	int primeSuspect = 0; //the int that we will check/increment to find our primes
	unsigned int numPrimesFound = 0; //counter for the running total number of primes
	while (numPrimesFound <= primeCount) {
		if (primeTest(primeSuspect)) {
			double root;
			try { //TODO check that you're doing exception handling correctly
				root = sqrtD(static_cast<double>(primeSuspect)); //HEY! WE CAN DO THIS AS A CONSOLE OUTPUT!! SIMPLER!
			} //end of try block
			catch (string exceptionString) {
				cout << "An exception occurred " << exceptionString << endl;
			} //end of catch exception block
			cout << std::left;
			cout << setw(20) << "Next prime number is: " << std::right << setw(20) << primeSuspect << " and its square root is: " << root << endl;
		}	//end of if statement: test for primes/printing of their information
	}	//end of while loop printing data on prime numbers found

	cout << "Completed successfully" << endl;
	return 0;
}	//end of main function

	///Function Definitions///

	/**
	* Gives integer approximation of a square root
	* This function takes in a long integer and returns an approximation of its square root, as a long integer
	* @param number the value we will take the square root of
	* @returns an approximation of number's square root, as a long int
	*/
long sqrtL(const long& number) {
	if (number < 0) {
		string exceptionString = "ERROR: You cannot get square roots of a negative number.";
		throw exceptionString;
	}	//end of exception check

	double measure = sqrtD(static_cast<double>(number)); 
	
	//non-<cmath> ugly floor function:
	int intRoot = 0;
	while (measure > 0) {
		measure--;
		intRoot++;
	}
	intRoot--; //end of floor function...

	return intRoot;
}	//end of long sqrt function

	/**
	* Gives double precision approximation of a square root
	* This function takes in a double and returns an approximation of its square root, as a double
	* @param number the value we will take the square root of
	* @returns an approximation of number's square root, as a double
	*/
double sqrtD(const double& number) {
	const double TOLERANCE = 0.000001;
	if (number < 0) {
		string exceptionString = "ERROR: You cannot get square roots of a negative number.";
		throw exceptionString;
	}	//end of exception check
	double root = number / 2.0;
	double difference = number - (root*root);
	if (difference < 0)	//absolute value
		difference = -difference;
	while (difference >= TOLERANCE) {
		root = ((root + (number/root)) / 2.0) ; //note I haven't yet verified if/why this works
		difference = number - (root*root);
	}
	return root;
}	//end of double sqrt function

	/**
	* Tests for primacy of the input
	* Takes in a value, checks potential divisors up to the square root of the value to check if it's prime
	* @param potentialPrime the number we are checking for primacy
	* @returns true if the value is prime
	*/
bool primeTest(int potentialPrime) {
	bool isPrime = true;
	int intRoot = sqrt(potentialPrime); //note this SHOULD do the integer version of sqrt

	for (int i = 2; i < intRoot; ++i) {
		if (potentialPrime % i == 0) {
			isPrime = false;
			break;
		}
	}
	return isPrime;
}	//end of primeTest function
