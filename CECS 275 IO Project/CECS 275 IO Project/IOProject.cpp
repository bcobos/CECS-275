/**
 * @authors Bernardo Cobos, Dong Jae Shin
 * @date (due) 9/27/18
 * This program reads in and manipulates a file with information on a country's popolation, size, and name
 * Input: A text file with appropriate data
 * Output: Prompt to edit data, and finally a text file (of user's choice) with final data. 
*/

#include <iostream>
#include <string>
#include <fstream> //stream class to both read and write from/to files
#include <iomanip> //for formatting
#include <cstring>
#include <cmath> //for use of abolute value funx=ction

//pulling in only what we need from namespace std:
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

//Function declarations:
int getChoice(int min, int max);
void changeCountryStatistics(string countryChoice, string name[], int countryPops[], int countryAreas[], unsigned int numCountries);
void addCountry(string name[], int countryPops[], int countryAreas[], unsigned int& numCountries);
void deleteCountry(string countryNames[], int countryPops[], int countryAreas[], unsigned int& numCountries);
void printCurrentCountries(std::ostream& out, string name[], int population[], int size[], int numCountries);
void sort(string nameArray[], int popArray[], int sizeArray[], unsigned int numCountries);
int findCountry(string countryName, const string countryNamesList[], unsigned int numCountries);

//Bounds of number of countries needed for this program:
const int MIN_COUNTRIES = 0; //Minimum # of countries allowed for the purposes of this program
const int MAX_COUNTRIES = 195; //Maximum # of countries allowed for the purposes of this program
const int MIN_POP = 0; //Smallest allowable population for a country
const int MAX_POP = 100000000; //Largest allowable population for a country
const int MIN_AREA = 0; //Smallest allowable area for a country
const int MAX_AREA = 100000000; //Largest allowable area for a country

int main() {
	//Declaring arrays/allocating sizes:
	string name[MAX_COUNTRIES]; //array holding country names
	int population[MAX_COUNTRIES]; //array holding populations of countries
	int size[MAX_COUNTRIES]; //array holding sizes (in square miles) of countries

	//Reading in the file (and checking that it exists):
	ifstream inputFile;
	string inputFileName; //this will hold the name of the file we read in
	do {
		//Prompt user for the file name:
		cout << "Please enter the file name to read: " << endl;
		getline(cin, inputFileName);
		inputFile.open(inputFileName); //attempt to open the file.
    	//If this one fails to open, prompt user for appropriate file name again:
		if (!inputFile.is_open())	cout << "Error, please enter an existing file name." << endl; 
	} while (!inputFile.is_open()); //If it didn't open, try again

	//Parse the file one line at a time to get data
	string line; //This will hold a line of country data as a string
	unsigned int lineCounter = 0; //This will count the index of the country data that we are saving
	while (inputFile >> line) { //read in a line; stop when there are no more lines
		//Parse the line to get data out:
		size_t breaker_index = line.find('|');
		name[lineCounter] = line.substr(0, breaker_index); //get the name of the country
		line = line.substr(breaker_index + 1); //cut off the processed part of the line string, keep the tail
		breaker_index = line.find('|');
		population[lineCounter] = std::stoi(line.substr(0, breaker_index)); //takes substring, converts to int type
		line = line.substr(breaker_index + 1); //cut off the processed part of the line string. What remains is now country size (as a string)
		size[lineCounter] = std::stoi(line); 

		lineCounter++;  //update index: store next line's info at next array's entries

		if (lineCounter == MAX_COUNTRIES) { //make sure not to overfill the arrays
			cout << "BEWARE! Max number of countries has been reached. Please delete a country before adding any more. " << endl;
			break; 
		}
	} //end of while loop
	//Note: upon exiting the loop, lineCounter now holds the number of countries whose data we have.
	unsigned int numCountries = lineCounter; //will track the number of countries in the arrays, even when updated

	//Prompt user if they want to change any country's statistics, add a country, or delete a country:
	//Define menu choice literals here before loop:
	const int CHANGE_COUNTRY_STATS = 1;
	const int ADD_COUNTRY = 2;
	const int DELETE_COUNTRY = 3;
	const int LIST_COUNTRIES = 4;
	const int EXIT_LIST_EDITING = 5;
	int userChoice; //int that will have user's menu choice:
	do { //Main menu, prompt for choices and process
		//List menu options:
		cout << "1 - Change an existing country" << endl
			<< "2 - Add a new country" << endl
			<< "3 - Delete a country" << endl
			<< "4 - List the defined countries" << endl
			<< "5 - Exit" << endl;
		//prompt for choice and make sure it is appropriate:
		userChoice = getChoice(CHANGE_COUNTRY_STATS, EXIT_LIST_EDITING);
		//process choice -- switch statement calling appropriate function:
		switch (userChoice) {
			case CHANGE_COUNTRY_STATS:{ //bracketing so that countryChoice only exists in this scope
				sort(name, population, size, numCountries);
				string junk; //junk clears newline from buffer so that cin can take countryChoice in properly
				getline(cin, junk);
				cout << "Please input the name of the country you'd like to edit (CASE SENSITIVE): " << endl;
				string countryChoice;
				getline(cin, countryChoice);
				changeCountryStatistics(countryChoice, name, population, size, numCountries);
				break;
				} //end of case "CHANGE_COUNTRY_STATS"
			case ADD_COUNTRY: 
				addCountry(name, population, size, numCountries);
				break;
			case DELETE_COUNTRY:
				deleteCountry(name, population, size, numCountries);
				break;
			case LIST_COUNTRIES:
				printCurrentCountries(cout, name, population, size, numCountries);
				break;
			case EXIT_LIST_EDITING:
				//Nothing for us to do here. We'll exit the loop and be on our way.
				break;
			default:
				cout << "Something broke. Please see the programmers to complain." << endl;
		} //end if switch statement

	} while (userChoice != EXIT_LIST_EDITING); 

	//Sort the data by alphabetical country order
	sort(name, population, size, numCountries);

	//Open the output file:
	ofstream outputFile;
	outputFile.open("output.txt");

	//Write to the output file:
	printCurrentCountries(outputFile, name, population, size, numCountries);
	cout << "The file contents have been written to output.txt successfully. " << endl;

	//Close input and output files:
	inputFile.close();
	outputFile.close();

	cout << "Completed successfully" << endl;
	return 0;
} //end of main function

/** 
 * Prompts a user for a menu choice and verify that is it an appropriate option
 * @param min the minimum valid value for menu choice
 * @param max the maximum valid value
 * @returns int with the user's choice, once an appropriate choice is entered
*/
int getChoice(int min, int max) {
	cout << "Please enter an integer between " << min << " and " <<  max << endl;

	int userChoice;
	bool validChoice;
	do { //take input/check it is valid
		cin >> userChoice; //take in user choice from console

		if (cin.fail()) { //checking if user input is an int
			validChoice = false;
			cin.clear(); //clear cin fail flags. NOTE this MUST come before getline buffer-clearing!!
			string junk;
			getline(cin, junk); //clear buffer if it's clogged
			cout << "Error, input not an integer. " << endl;
		} //end of if statement 
		else if (userChoice < min  || userChoice > max) { //checking if user choice is out of range
			validChoice = false;
			cout << "Error, input not in range. " << endl;
		} //end of else if 
		else { //everything okay
			validChoice = true;
		} //end of else statement 

	} while (!validChoice); //continue to prompt user for input if input type is not an int

	return userChoice; //return the choice once it's valid
} //end of getChoice function

/**
* Prompts user for desired changes and updates the appropriate country statistics
* Neither country population nor size can be set to < 0
* A country's name cannot be changed
*/
void changeCountryStatistics(string countryChoice, string countryNames[], int countryPops[], int countryAreas[], unsigned int numCountries) {
	int index = findCountry(countryChoice, countryNames, numCountries);
	if (index == -1)	cout << "Error! That country is not in the list. " << endl;
	else { //if (index != 1), then index holds the index of the country we seek within countryNames
		//Prompt user for what they would like to change about the country stats:
		const int POPULATION = 1;
		const int AREA = 2;
		cout << "What would you like to change about the country? " << endl
			<< "1 - Population " << endl
			<< "2 - Area (in sq mi) " << endl;
		int userChoice = getChoice(POPULATION, AREA);
		if (userChoice == POPULATION) { //wants to edit Population
			cout << "Please enter a new population for " << countryNames[index] << endl;
			int newPopulation = getChoice(MIN_POP, MAX_POP);
			countryPops[index] = newPopulation;
			cout << countryNames[index] << "'s population is now " << countryPops[index] << endl;
		} //end of if (user choice population)
		else { //else (userChoice == 2) -- wants to edit Area
			cout << "Please enter a new area for " << countryNames[index] << endl;
			int newArea = getChoice(MIN_AREA, MAX_AREA);
			countryAreas[index] = newArea;
			cout << countryNames[index] << "'s area is now " << countryAreas[index] << endl;
		} //end of else (user choice area)
	} //end of else (checking if failed to find country)
} //end of changeCountryStatistics function

/**
 * Prompts user for country name and statistics and adds it to the lists
 * @param name the current array of country names	
 * @param countryPops the current array of country populations
 * @param countryAreas the current list of country areas
 * @param numCountries the current number of countries on the lists
*/
void addCountry(string name[], int countryPops[], int countryAreas[], unsigned int& numCountries) {
	if (numCountries < MAX_COUNTRIES) {
		//Prompting for choices:
		cout << "Please enter the name of your new country" << endl;
		string newCountryName;
		cin >> newCountryName;
		cout << "Please enter the population of your new country" << endl;
		int newCountryPop = getChoice(MIN_POP, MAX_AREA);
		cout << "Please enter the size (in sq mi) of your new country" << endl;
		int newCountrySize = getChoice(MIN_AREA, MAX_AREA);

		//Processing choices:
		name[numCountries] = newCountryName;
		countryPops[numCountries] = newCountryPop;
		countryAreas[numCountries] = newCountrySize;

		//Updating country count:
		++numCountries;

		cout << newCountryName << " has been added successfully." << endl;
	} //end of if statement
	else
		cout << "Error: Max number of countries already reached. Please delete a country if you wish to continue. " << endl;

} //End of addCountry function

/**
 * Deletes a country from the lists and updates lists as appropriate
 * @param countryNames the current array of country names
 * @param countryPops the current array of country populations
 * @param countryAreas the current list of country areas
 * @param numCountries the current number of countries on the lists
 */
void deleteCountry(string countryNames[], int countryPops[], int countryAreas[], unsigned int& numCountries) {
	//Prompt user for which country they would like to delete:
	cout << "Which country would you like to delete? Please give name (case sensitive): " << endl;
	string countryChoice;
	cin >> countryChoice;

	//Check that the country is in the list:
	sort(countryNames, countryPops, countryAreas, numCountries); //pre-sort before searching
	int index = findCountry(countryChoice, countryNames, numCountries);
	if (index == -1)	cout << "Error: your choice is not in the list" << endl;
	else { //if in the list, proceed to delete from all arrays
		for (int i = index; i < numCountries - 1; ++i) {
			//Overwrite "current" entry with "next" entry... 
			//...last entry doesn't need to be updated, as it will effectively be forgotten (until it's overwritten later)
			countryNames[i] = countryNames[i + 1];
			countryPops[i] = countryPops[i + 1];
			countryAreas[i] = countryAreas[i + 1];
		} //end of for loop
		--numCountries; //bring count down
		cout << countryChoice << " has been deleted successfully. " << endl;
	} //end of else
} //end of deleteCountry function

/**
 * Prints the current country names and statistics to a stream
 * @param out the stream to write out to
 * @param name the the current array of country names
 * @param population the current array of country populations
 * @param size the current list of country areas
 * @param numCountries the current number of countries on the lists
*/
void printCurrentCountries(std::ostream& out, string name[], int population[], int size[], int numCountries) {
	//Write to the output file:
	const int WIDTH = 30;
	//write header:
	out << std::left << std::setw(WIDTH) << "Country Name"
		<< std::setw(WIDTH) << "Country Population"
		<< std::setw(WIDTH) << "Country Area (in sq mi)" << endl
		<< "======================================================================================" << endl;
	//write data body:
	for (size_t i = 0; i < numCountries; ++i) {
		out << std::setw(WIDTH) << name[i]
			<< std::setw(WIDTH) << population[i]
			<< std::setw(WIDTH) << size[i]
			<< endl;
	} //end of for loop
} //end of printCurrentCountries function

/**
 * Bubble-sorts arrays so that countries are listed alphabetically
 * @param nameArray the string array that holds country names
 * @param popArray the int array that holds country populations
 * @param sizeArray the int array that holds country area 
 * @param numCountries the number of elements in these arrays
*/
void sort(string nameArray[], int popArray[], int sizeArray[], unsigned int numCountries) {
	//placeholders for switching purposes:
	string tempName;
	int tempPop;
	int tempSize;

	//bubble sort algorithm:
	bool swapped = false;
	do { //loop until we've made a pass that doesn't swap any elements
		swapped = false; //nothing's been swapped yet
		for (size_t i = 0; i < numCountries - 1; ++i) {
			if (nameArray[i].compare(nameArray[i + 1]) > 0) { //if out of order
				//swap all:
				tempName = nameArray[i];
				nameArray[i] = nameArray[i+1];
				nameArray[i+1] = tempName;
				tempPop = popArray[i];
				popArray[i] = popArray[i+1];
				popArray[i+1] = tempPop;
				tempSize = sizeArray[i];
				sizeArray[i] = sizeArray[i+1];
				sizeArray[i+1] = tempSize;
				//mark that we swapped:
				swapped = true;
			} //end of if statement
		} //end of for loop
	} while (swapped);
} //end of sort function

/**
 * Finds the index of a desired country, or sends a message upon failing to find the country, using a binary search.
 * @param countryName the name of the country we seek
 * @param countryNamesList the array of country names, assumed to be pre-sorted.
 * @param numCountries the number of elements in these arrays
 * @returns index of the desired country, -1 if the country is not found
*/
int findCountry(string countryName, const string countryNamesList[], unsigned int numCountries) {
	int final_index = -1; //will hold index of desired country. Set to fail value by default (-1)

	//////THIS DOESN'T WORK AND I DON'T KNOW WHY ERROR "EXPRESSION DID NOT EVALUATE TO A CONSTANT"//////////
	//////TRYING TO CHANGE EVERYTHING TO UPPERCASE SO THAT WE DON'T HAVE TO HAVE INPUT BE CASE SENSITIVE////
	////input country name string, to uppercase:	
	//char iCNU_cstring[countryName.length()];// = countryName.c_str(); //cstring version of input string.
	//for (size_t i = 0; iCNU_cstring[i] != '\0'; ++i) { //capitalize all characters until we reach null character.
	//	iCNU_cstring[i] = toupper(iCNU_cstring[i]);
	//} //end of for loop
	////convert to std::string: 
	//string inputCountryNameUpper(iCNU_cstring); //The country we are searcing for, all capitalized
	//
	////Initialize binary search:
	//unsigned int lower_index = 0;
	//unsigned int upper_index = numCountries - 1; //start at end of list. ...\
	//											 ...TODO: NOTE this will give problems if numCountries = 0
	//unsigned int mid_index; //integer division means this is floor of midpoint
	//while (lower_index <= upper_index) { //if lower_index > upper_index, then we've searched the whole list... \
	//									 ...and the country name is not in it.
	//	//Step 1: capitalize the string we are curringly comparing to
	//	mid_index = (lower_index + upper_index) / 2; //Updating which index we'll be looking at
	//	char lCNU_cstring[countryNamesList[mid_index].length] = countryNamesList[mid_index].c_str(); //cstring version of... \
	//																								 ...current string.
	//	for (size_t i = 0; lCNU_cstring[i] != '\0'; ++i) { //capitalize all characters until we reach null character.
	//		lCNU_cstring[i] = toupper(lCNU_cstring[i]);
	//	} //end of for loop
	//	//convert to std::string:
	//	string listCountryNameUpper(lCNU_cstring); //The list country we are currently comparing to, all capitalized

	//	//Step 2: compare
	//	int comparison = inputCountryNameUpper.compare(listCountryNameUpper);
	//	if (comparison > 0) { //We shot too high, go down
	//		upper_index = mid_index - 1;
	//	} else if (comparison < 0) { //We shot too low, go up
	//		lower_index = mid_index + 1;
	//	} else { //This means (comparison == 0). Match! We are done.
	//		final_index = mid_index;
	//		break;
	//	} //end of if/else/else if comparing strings
	//} //end of while loop

	//Comparing without capitalization:
	unsigned int lower_index = 0;
	unsigned int upper_index = numCountries - 1; //start at end of list.
	unsigned int mid_index; //integer division means this is floor of midpoint
	while (lower_index <= upper_index) { //if lower_index > upper_index, then we've searched the whole list... \
											 ...and the country name is not in it.
		mid_index = (lower_index + upper_index) / 2; //Updating which index we'll be looking at

		//compare
		int comparison = countryName.compare(countryNamesList[mid_index]);
		if (comparison < 0) { //We shot too high, go down
			upper_index = mid_index - 1;
		} //end of if
		else if (comparison > 0) { //We shot too low, go up
			lower_index = mid_index + 1;
		} //end of else if
		else { //This means (comparison == 0). Match! We are done.
			final_index = mid_index;
			break;
		} //end of if/else/else if comparing strings
	} //end of while loop

	//if we've reached this point without finding the country, final_index will return the fail value
	//otherwise, final_index will return the proper index
	
	return final_index;
} //end of findCountry function