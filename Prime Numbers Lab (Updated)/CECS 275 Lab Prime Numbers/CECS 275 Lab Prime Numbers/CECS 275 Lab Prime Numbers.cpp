/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 9/13/18
* Purpose: to find a set number of primes using student-created square root functions
* Inputs: number primeCount of primes desired
* Outputs: The first primeCount prime numbers and their square roots
*/

//FOR PROFESSOR BROWN: Problems or difficulties with lab:
//confusion on wording with algorithm for sqrt ("set the new square root to ..."). 
//exception throwing confusion
//for some reason, our sqrt overloading was not working.. talked with Bernardo talked about this, and we could not figure it out together...
//...replaced overloaded sqrt functions with sqrtL (long) and sqrtD (double)

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
	int primeSuspect = 2; //the int that we will increment/check to find our primes. Start at 2: first prime.
	cout << "Enter the number of prime numbers to find: ";
	cin >> primeCount;
	cout << endl;
	unsigned int numPrimesFound = 0; //running counter for the total number of primes found

	while (numPrimesFound <= primeCount) { //loop through until we've found as many primes as was specified
		if (primeTest(primeSuspect)) { //check if current ccandidate is prime. If so, output information on it. 
			double root; //will become the (double precision) square root of primeSuspect
			try { 
				root = sqrtD(static_cast<double>(primeSuspect)); //If sqrtD gets passed a negative value, it will throw an exception
			} //end of try block
			catch (string exceptionString) {
				cout << "An exception occurred " << exceptionString << endl;
			} //end of catch exception block

			cout << std::left;
			cout << setw(10) << "Next prime number is: " << std::right << setw(10) << primeSuspect << " and its square root is: " << root << endl;
			numPrimesFound++;
		}	//end of if statement: test for primes/printing of their information
		primeSuspect++;
	}	//end of while loop printing data on prime numbers found

	cout << "Completed successfully" << endl;
	//system("PAUSE");

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
	}	//end of exception check/creation

	/* "Ghetto" algorithm, originally in place due to time constraints: */
	//double measure;
	//try {
	//	measure = sqrtD(static_cast<double>(number));
	//}	//end of try block
	//catch (string exceptionString) {
	//	cout << "An exception occurred " << exceptionString << endl;
	//}	//end of catch exception block
	//int intRoot = floor(measure);

	/* Better algorithm: */
	const double TOLERANCE = 1; //error tolerance
	double root = number / 2.0; //will iteratively converge to the squar root of number, within the tolerance
	double difference = number - (root*root); //difference between current guess squared and the actual number

	if (difference < 0)		difference = -difference; //absolute value

	while (difference >= TOLERANCE) { //keep approximating root until we're "close enough"
		root = ((root + (number / root)) / 2.0); //Newton approximation of square root
		difference = number - (root*root);
		if (difference < 0)		difference = -difference; //absolute value
	}

	return floor(root);
}	//end of long sqrt function

	/**
	* Gives double precision approximation of a square root
	* This function takes in a double and returns an approximation of its square root, as a double
	* @param number the value we will take the square root of
	* @returns an approximation of number's square root, as a double
	*/
double sqrtD(const double& number) {
	if (number < 0) {
		string exceptionString = "ERROR: You cannot get square roots of a negative number.";
		throw exceptionString;
	}	//end of exception check

	const double TOLERANCE = 0.000001;	//error tolerance
	double root = number / 2.0;	//will iteratively converge to the squar root of number, within the tolerance
	double difference = number - (root*root); //difference between current guess squared and the actual number

	if (difference < 0)		difference = -difference; //absolute value

	while (difference >= TOLERANCE) { //keep approximating root until we're "close enough"
		root = ((root + (number/root)) / 2.0) ; //Newton approximation of square root
		difference = number - (root*root);
		if (difference < 0)		difference = -difference; //absolute value
	} //end of while loop

	return root;
}	//end of double sqrt function

	/**
	* Tests for prime-ness of the input
	* Takes in a value, checks potential divisors up to the square root of the value to check if it's prime
	* @param potentialPrime the number we are checking for prime-ness
	* @returns true if the value is prime
	*/
bool primeTest(int potentialPrime) {
	bool isPrime = true;
	int intRoot = sqrtL(potentialPrime); 

	for (int i = 2; i <= intRoot; ++i) {	//loop through potential divisors 
		if (potentialPrime % i == 0) {	//check if i divides potentialPrime
			isPrime = false;
			break;
		} //end of if statement
	}	//end of for loop

	return isPrime;
}	//end of primeTest function
