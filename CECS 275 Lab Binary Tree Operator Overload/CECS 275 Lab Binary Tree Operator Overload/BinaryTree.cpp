/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date 12/6/18 - 12/8/18
* Design and implementation of operator[] functionality fot a Binary Search Tree
* Input: Unique strings to put into a Binary Search Tree
* Output: Those strings, in their lexicographical order
*/
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
* @param indexCounter the number of indices left to traverse
* @returns the desired TreeNode, or nullptr if failed search
*/
BinaryTree::TreeNode* BinaryTree::findByIndex(TreeNode* current, int& indexCounter) const {
	//NEW LINE OF THOUGHT
	//Simple: check left subtree, check me, check right. IN THIS ORDER! FOR EVERY NODE!
	//If no node is returned after that, return nullptr
	//A search will only fail if we get to the ROOT of the tree and we're still getting nullptr
	//(note in general nullptr doesn't signal a failed search, only that you are required to keep searching)
	//(which would obviously be a problem at the root)

	// I) SEARCH LEFT:
	TreeNode* nodePtr;
	if (current->left != nullptr) { //if I have a left child, keep going down checking that
		nodePtr = findByIndex(current->left, indexCounter);
		//Then check what gets returned to us:
		if (nodePtr != nullptr) //if we got a real answer in there
			return nodePtr; //just return that answer to my caller/parent
		else { //otherwise our left subtree gave us nothing, telling us to keep searching
			//Don't do anything here! Just continue the overall algorithm -- see if I'm the one
			//(move on to "check me" stage)
		}
	} //end of Search Left if block

	// II) CHECK ME:
	if (indexCounter == 0) //first see if I'm this tree's most desireable node
		return current; //(note this is the ONLY place this check happens. Like a base case)
	//if not, continue the search...
	--indexCounter; //always mark me as traversed HERE, cause we've already checked left subtree by now
	//That is, I came here from a left subtree (or I'm the first element), so I should be counted as the "next" value

	// III) SEARCH RIGHT:
	if (current->right != nullptr) { //Look into right subtree if I have one
		nodePtr = findByIndex(current->right, indexCounter);
		//Then check what gets returned to me:
		if (nodePtr != nullptr) //if we got a real answer in there
			return nodePtr; //just return that answer to my caller
		else { //otherwise our right subtree gave us nothing, telling us to keep searching 
			//I've already been counted, so I can't be the desired node. 
			//(move on to "return control to parent" stage)
		}
	}//end of Search Right if block

	// IV) RETURN CONTROL TO PARENT -- CONTINUE THE SEARCH
	//By now, I have checked my left subtree, myself, and my right subtree (if I had subtrees)
	//Note I'll only reach this part if my left subtree didn't have the node, ...
	//... if I was not the node, and if my right subtree didn't have the node.
	//We need to continue the search. Flag that by returning nullptr to my parent.
	return nullptr;

} //end of findByIndex function

//RECORD OF PAST MISTAKES/FAILURES: 
//===== MISTAKE 1: =====
//	if (current != nullptr) { //something exists on the left
//		//search subtree on the left
//		return findIndex(current->left, index);
//	} //end of if (current != nullptr) block
//	//once here, all left-hand stuff is finished and we've gone OFF the edge
//	if (index == 0) { //found the node in this leftmost corner!
//		return current; //wait wtf right now I'm nullptr this would make no sense
//	} //end of for
//	//otherwise, continue the search...
//	//need to check right subtree, and then backtrack up current tree a bit.
//	else { //note else is unnecessary, as we returned in the if block
//		--index; //decrementing because if we're about to search right subtree,...
//				// ...then we are done counting the things ordered before it
//		return findIndex(current->right, index);
//	} //end of else
//} //end of findIndex function

//===== MISTAKE 2: =====
/*
BinaryTree::TreeNode* BinaryTree::findIndex(TreeNode& current, int& index) const {
	if (current.left != nullptr) {	//if current has a left child
		//keep going left!
		return findIndex(*(current.left), index);
	} //end of if

	//We only reach this point if we've exhausted all left children in current sub-tree
	if (index == 0) { //if current is the (leftmost) node we seek
		//return the found node
		return &current;
	} else { //All left children in this sub-tree are done, but we're not done searching
		--index; //decrement index counter, since we visited a "smallest" index
		if (current.right != nullptr) //if current has right child, keep searching, but on right side now
			return findIndex(*(current.right), index); 
		//first check if this non-leaf node is the one we want:

		//TODO: SOMETHING WRONG HERE: BACKTRACKING UP A LEFT SUBTREE....
		else if (index == 0) //the one we want is our parent -- but we're not there right now... it's above this node...
			return &current; //return ...the thing that called me...!?

		else //if (current.right == nullptr && index != 0)
			//left sub-tree is exhausted, I have no right children, and we never found what we sought
			return nullptr; // so it doesn't exist in this tree!!
	} //end of if-else
} //end of findIndex function
*/

/*
* Finds the desired node and returns its contents
* @param index the index to search for
* @return the string in the node that is at the desired index
*/
string BinaryTree::operator[](int index) {
	//Make sure we're not trying to access a negative index:
	if (index < 0) throw IndexOutOfBoundsException(index);

	//Search the Binary Search Tree:
	TreeNode* treeNodePtr = findByIndex(root, index);

	//Verify the search:
	if (treeNodePtr == nullptr) 
		//This means we ran off the tree before finding a value at the specified index. 
		throw IndexOutOfBoundsException(index);
	else //everything is a-okay.
		return treeNodePtr -> value;
} //end of operator[]
