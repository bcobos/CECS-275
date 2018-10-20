#pragma once
/* Header file for Dictionary class */
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;

class Dictionary { 
private:
	//Member Variables:
	static vector<string> wordList;
	static unsigned int wordListSize;

	//Member Functions: 
	//IS EVERYTHING SUPPOSED TO BE STATIC? (we're never gonna instantiate one). Gonna do it just because it seems right, for now
	static int locateStart(string, int, int, bool);
	//void Initialize(); //...Is this supposed to be here or is it a mistake?

public:
	static int locateStart(string, bool);
	static int getDictionarySize();
	static int initialize(); //Should this be private? That would be weird...


}; //end of Dictionary class declarations