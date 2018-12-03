/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date due 12/6/2018
* This program is practice in the Queue ADT
* Input: ...
* Output: ...
*/
#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	//Driver assignment:
	//1) Create and show the original queue
	Queue queue;
	queue.add("Boris Karloff");
	queue.add("Harrison Ford");
	queue.add("Muhatma Ghandi");
	queue.add("Vincent Price");
	queue.add("Diane Keaton");
	cout << "1) Line before we get there: " << endl;
	//Reset iterator
	queue.peekReset();
	//Iterate through all elements until end is reached
	while (queue.peekHasNext()) {
		//Print current element
		cout << queue.peek() << endl;
		//Update iterator
		queue.peekNext();
	} //end of while
	cout << endl;
	//This is quite a roster.

	//2) Add our group to the queue, and show it
	queue.add("Bernardo Cobos");
	queue.add("Chris Dong Jae Shin");
	queue.add("Vinh");
	queue.add("Dave Brown");
	queue.add("Peter Parker");
	cout << "2) After my friends and I arrive: " << endl;
	//Reset iterator
	queue.peekReset();
	//Iterate through all elements until end is reached
	while (queue.peekHasNext()) {
		//Print current element
		cout << queue.peek() << endl;
		//Update iterator
		queue.peekNext();
	} //end of while
	cout << endl;

	//3) Clerk-bro comes out and takes note of the queue
	Queue queueRecord = Queue(queue);
	cout << "3) Store Clerk has recorded the current queue. " << endl;
	cout << endl;

	//4) Clerk-bro issues his warning:
	cout << "4) The queue is now closed. " << endl;
	//TODO: declare the queue closed once that functionality is added to Queue class

	//5) Two scumbags try to enter the queue
	cout << "5) " << endl;
	cout << "Mr. Rogers attempts to enter the queue... " << endl;
	try {
		queue.add("Fred Rogers");
	} //end of try
	catch (Queue::FilledException exc) {
		cout << "The clerk declares: \"You're out of line, " << exc.getName() << "!\"" << endl;
		cout << "(the pun was intentional)" << endl;
	} //end of catch
	cout << "Dr. Seuss attempts to enter the queue. " << endl;
	try {
		queue.add("Theodore Seuss Geisel");
	} //end of try
	catch (Queue::FilledException e) {
		cout << "There's no space for you here, " << e.getName() << "." << endl;
	} //end of catch
	cout << endl;

	//6) Clerk-bro checks on the line every few minutes:
	cout << "6) The store clerk checks the line every few minutes..." << endl;
	//TODO: What's actually being asked for here?
	cout << endl;

	//7) Everyone gets a phone, in the order that they are in line.
	cout << "7) The store clerk begins to sell the phones to the queue in the proper order. " << endl;
	//TODO: maybe we should add a Queue::isEmpty() function to make this part easier...
	//Then we could do something like:
	//while (!queue.isEmpty()) { }
	cout << endl;

	cout << "Completed Successfully." << endl;

	//TODO: comment out this line before turning in.
	system("PAUSE");
} //end of main