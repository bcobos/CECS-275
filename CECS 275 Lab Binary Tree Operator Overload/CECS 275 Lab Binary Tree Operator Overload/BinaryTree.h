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
	struct TreeNode
	{
		string value;           // The value in the node
		TreeNode *left;    // Pointer to left child node
		TreeNode *right;   // Pointer to right child node
	};

	TreeNode *root;       // Pointer to the root node

						  // Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);

	TreeNode* findIndex(TreeNode current, int& index) const;

public:
	// Constructor
	BinaryTree()
	{
		root = nullptr;
	}

	// Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	void insertNode(string item);
	bool searchNode(string item);

	string operator[](int index);

};

#endif /* BINARYTREE_H_ */
