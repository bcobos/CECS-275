/**
*
*/
#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {

	int numb = 0;

	BinaryTree tree;
	cout << "Insert how many strings to put into the BST:" << endl;
	cin >> numb;
	string name;
	for (int i = 0; i < numb; ++i) {
		cout << "Insert name:" << endl;
		cin >> name;
		tree.insertNode(name);
	}
	int index;
	cout << "Which index are you looking for: " << endl;
	cin >> index;

	cout << "index " << index << ":" << tree[index] << endl;

	cout << "Completed successfully" << endl;

	//TODO: delete:
	system("PAUSE");
} //end of main
