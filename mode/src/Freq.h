/*
 * Freq.h
 *
 *  Created on: Oct 23, 2018
 *      Author: Chris
 */

#ifndef FREQ_H_
#define FREQ_H_

struct Freq {

	public:
		// Member variables
		int value, frequency;

		// Member functions

		// default constructor
		Freq(){
			value = 0;
			frequency = 0;
		}

		//constructor:
		Freq(int elements,  int n_elements){
			value = elements;
			frequency = n_elements;
		}
};



#endif /* FREQ_H_ */
