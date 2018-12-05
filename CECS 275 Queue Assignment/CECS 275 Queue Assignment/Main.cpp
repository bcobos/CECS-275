/**
* @authors Bernardo Cobos, Dong Jae Shin
* @date due 12/6/2018
* This program is practice in the Queue ADT
* Input: None
* Output: Effects of manipulating a queue data structure in a simulation of life
*/
#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
	//1) Create and show the original queue
	Queue queue;
//	Queue queue = Queue(1); //An alternative start.
	queue.add("Boris Karloff");
	queue.add("Harrison Ford");
	queue.add("Muhatma Ghandi");
	queue.add("Vincent Price");
	queue.add("Diane Keaton");
	cout << "1) Line before we get there: " << endl;
	cout << queue.to_string() << endl;	
	//This is quite a roster.
	
	//2) Add our group to the queue, and show it
	queue.add("Bernardo Cobos");
	queue.add("Chris Dong Jae Shin");
	queue.add("Vinh");
	queue.add("Dave Brown");
	queue.add("Peter Parker");

	cout << "2) After my friends and I arrive: " << endl;
	cout << queue.to_string() << endl;
	
	//3) Clerk-bro comes out and takes note of the queue
	Queue queueRecord = Queue(queue); //make a copy using copy constructor
	cout << "3) Store Clerk has recorded the current queue. " << endl;
	cout << endl;
	
	//4) Clerk-bro issues his warning:
	cout << "4) The queue is now closed. " << endl;
	queueRecord.closeQueue();
	queue.closeQueue();
	cout << endl;
	
	//5) Two scumbags try to enter the queue...
	cout << "5) " << endl;
	cout << "Mr. Rogers attempts to enter the line... " << endl;
	try {
		queue.add("Fred Rogers");
	} //end of try
	catch (Queue::FilledException exc) {
		cout << "The clerk declares: \"You're out of line, " << exc.getName() << "!\"" << endl;
		cout << "(the pun was intentional)" << endl;
	} //end of catch
	cout << endl;
	cout << "Dr. Seuss attempts to enter the queue... " << endl;
	try {
		queue.add("Theodore Seuss Geisel");
	} //end of try
	catch (Queue::FilledException e) {
		cout << "The clerk screams: \"There's no space for you here, " << e.getName() << "!\"" << endl;
	} //end of catch
	cout << endl;
	
	//6) Clerk-bro checks on the line every few minutes:
	cout << "6) The store clerk checks the line every few minutes..." << endl;
	//What's actually being asked for here?
	for (int i = 0; i < 3; ++i) {
		if (queueRecord.peek() == queue.peek()) 
			cout << "Store clerk checks the line and sees that " 
			<< queue.peek() << " is still at the head of the line." << endl;
		else
			cout << "Store clerk freaks out as he realizes " 
			<< queueRecord.peek() << " has left the line!! " << endl;
//		sleep(200);
	} //end of for loop
	cout << endl;
	
	//7) Everyone gets a phone, in the order that they are in line.
	cout << "7) The store clerk begins to sell the phones to the queue in the proper order. " << endl;
	while (!queue.isEmpty()) { 
		string person = queue.remove();
		cout << person << " has bought an iPhone and has now left the line. " << endl;
	} //end of while loop
	cout << "The queue is now empty. " << endl;
	cout << endl;
	
	cout << "Completed Successfully." << endl;

	//TODO: comment out this line before turning in.
	//system("PAUSE");
} //end of main