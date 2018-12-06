/*
* BinaryTree.cpp
*
*  Created on: Jul 18, 2018
*      Author: David
*/

#include "BinaryTree.h"
#include <iostream>

using namespace std;

/**
* Helper function used by insertNode.  The user never gets direct access to
* the nodes within the binary tree, just the value of the nodes.  Note that
* the arguments nodePtr and newNode are *&.  That allows us to update the
* value of nodePtr.  If nodePtr is the head of the binary tree, and we are
* inserting the first node, then this construct allows us to seamlessly
* change the value of the binary tree's root pointer in this function.  A
* similar consideration applies to the left and right pointers for the
* various nodes.
* @param	nodePtr	The pointer to the "current" node in the tree.  If this
* 					is nullptr, then the new node goes right here.  Otherwise,
* 					we keep looking for the spot in the tree.
* @param	newNode	The pointer to the new node that you want to insert.
*/
void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);     // Search the left branch
	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

/**
* Add a new node to the binary tree to preserve the sort order.
* This only works for strings at present, but we could easily have made
* a template out of the TreeNode and then the binary tree could manage
* nodes with any sort of value.
* @param	item	The string that you want to add to the binary tree.
*/
void BinaryTree::insertNode(string item)
{
	TreeNode *newNode = nullptr;	// Pointer to a new node.

									// Create a new node and store item in it.
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

/**
* Deallocate the space from this node down.  We need to essentially delete
* the nodes from the bottom up since it is impossible to find the children
* once the parent has been deleted.  Hence the recursive approach.
* @param	nodePtr	Starting place for the deletion.
*/
void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

/**
* Look for a particular value in the tree and indicate whether that value exists
* in the tree or not.  The == operator must be defined for whatever type you want
* to store in the TreeNodes.
* @param	item	The string value that you are searching for.
* @return			True if we could find it, false otherwise.
* @Note			We could have done this recursively, but iteratively works
* 					just as well.
*/
bool BinaryTree::searchNode(string item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

/**
* Helper function uses recursion to search for a node at a desired index
* @param current the current TreeNode we are staring at
* @param index the remaining indices left to traverse
* @returns the desired TreeNode, or nullptr if failed search
*/
BinaryTree::TreeNode* BinaryTree::findIndex(TreeNode current, int& index) const {
	if (current.left != nullptr) {	//if current has a left child
		//keep going left!
		findIndex(*(current.left), index);
	} //end of if
	//We only reach this point if we've exhausted all left children in current sub-tree
	if (index == 0) { //if current is the (leftmost) node we seek
		//return the found node
		return &current;
	} else { //We still might need to search, but we'd go right now, ...
			//...as all left children in this sub-tree are done.
		--index; //decrement index counter
		//first check if this non-leaf node is the one we want:
		if (index == 0) //the one we want
			return &current; //return it!
		else if (current.right != nullptr) //if current has right child, keep searching, but on right side now
			findIndex(*(current.right), index); 
		else //if (current.right == nullptr && index != 0) it doesn't exist in this tree!!
			return nullptr;
	} //end of if-else
} //end of findIndex function

/*
* Finds the desired node and returnd its contents
* @param index the index to search for
* @return the string in the node that is at the desired index
*/
string BinaryTree::operator[](int index) {
	TreeNode* treeNodePtr = findIndex(*root, index);
	cout << "We made it past the findIndex function call!" << endl;
//	cout << "The value is: " << treeNodePtr -> value << endl; //CRASHES
	if (treeNodePtr == nullptr)
		return "Error -- that's not a valid index";
	else
		return treeNodePtr -> value;
} //end of operator[]
