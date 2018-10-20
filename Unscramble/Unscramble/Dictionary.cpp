/* Source (cpp) file for Dictionary class */
#include "Dictionary.h"

//Initializing static variables:
vector<string> Dictionary::wordList = {};
unsigned int Dictionary::wordListSize = 0;

/**
 * Reads a list of dictionary words in from wordlist.txt
 * and saves them to the wordList vector.
 * @returns the number of dictionary words found in the file
 */
int Dictionary::initialize() {
	//Open the dictionary file: 
	ifstream dictInFileStream = ifstream("wordlist.txt");

	//Read words in from list, save them to wordList, and save count:
	string nextWord;
	while (dictInFileStream >> nextWord) { //TODO: might this give a problem for compound-like words?
		wordList.push_back(nextWord);
	} //end of while loop
	wordListSize = wordList.size();

	//Close the dictonary file:
	dictInFileStream.close();

	//Return word count:
	return wordListSize;
} //end of initialize function

/**
 * Looks for a word or word fragment in a subsection of the dictionary list
 * @param key the string to compare to dictionary words
 * @param low the lowest index in word list to search
 * @param high the highest index in word list to search
 * @param exact a flag to indicate whether this function is looking for an exact match or a beginning fragment of a word
 * @return location of the word, if found. On fail, returns -1
 */
int Dictionary::locateStart(string key, int low, int high, bool exact) {
	//TODO think this process out more on paper before continuing!!
	int result = -1; //set to fail by default. 
	if (exact) {
		//Check for failure first:
		if (low > high)
			return result; //return result failure
		//Full Binary Search:
		int mid = (low + high) / 2;
		if (key < wordList[mid])	//if key is lower in dictionary than current word
			return locateStart(key, low, mid, true);
		else if (key > wordList[mid])	//key higher in dictionary than current word
			return locateStart(key, mid, high, true);
		else //otherwise key == wordList[mid] and we've found our result
			result = mid;
			return result;
	} //end of if
	else { //if we're not looking for an exact match
		//Want to check if there's something in the dictionary...
		//...whose first letters match all of key 
		//NOTE: Isn't the "exact" case just a special case of this? Where length is the same?... 
		//NO, actually. ex: key = hell, accidentally get "hello" position first, returns that.
		if (low > high)
			return result; //return result failure
		//Binary Search of just substring:
		int mid = (low + high) / 2;
		int strLen = key.length();
		string searchSubstr = wordList[mid].substr(0, strLen);
		if (key < searchSubstr)
			return locateStart(key, low, mid, false);
		else if (key > searchSubstr)
			return locateStart(key, mid, high, false);
		else { //otherwise key == searchSubstr and we've foound a word that starts with key
			result = mid;
			return result;
		} //end of else	
//	return result;
} //end of locateStart member function

/*
 * Begins binary search f dictionary for a string, using overloaded locateStart to do the heavy lifting
 * @param key the string we aare trying to match to a dictionary word
 * @param exact boolean flag for whether we're trying to exactly match a word or only find a beginning fragment
 * @returns the index of our desired word in the dictionary. Upon failure, returns -1
 */
int Dictionary::locateStart(string key, bool exact) {
	int result;
	result = locateStart(key, 0, wordListSize-1, exact);
	return result;
} //end of locateStart member funcion

/**
 * Gives number of words in wordList. If wordList is empty, fills it first.
 * @returns current size of dictionary
 */
int Dictionary::getDictionarySize() {
	if (wordList.size() == 0)	
		initialize();
	return wordListSize;
} //end of getDictionarySize member function