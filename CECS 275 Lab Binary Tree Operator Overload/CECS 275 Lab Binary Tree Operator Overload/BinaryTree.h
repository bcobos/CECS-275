/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 12/6/18 - 12/8/18
* Design and implementation of operator[] functionality fot a Binary Search Tree
* Input: Unique strings to put into a Binary Search Tree
* Output: Those strings, in their lexicographical order
*/
/*
* BinaryTree.h
*
*  Created on: Jul 18, 2018
*      Author: David
*/

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include <string>
using namespace std;

class BinaryTree
{
private:
	struct TreeNode	{
		string value;           // The value in the node
		TreeNode *left;    // Pointer to left child node
		TreeNode *right;   // Pointer to right child node
	};

	TreeNode *root;       // Pointer to the root node
	// Private member functions:
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	TreeNode* findByIndex(TreeNode* current, int& index) const;
		
public:
	// Constructor
	BinaryTree() {
		root = nullptr;
	}

	// Destructor
	~BinaryTree() {
		destroySubTree(root);
	}

	void insertNode(string item);
	bool searchNode(string item);
	string operator[](int index);

	//Exception class:
	struct IndexOutOfBoundsException {
		int failedIndex;
		//Constructor:
		IndexOutOfBoundsException(int newIndex) { failedIndex = newIndex; }
		string getMessage() { return "Error: " + to_string(failedIndex) + " is not a valid index."; }
	};
}; //end of BinaryTree class

#endif /* BINARYTREE_H_ */
