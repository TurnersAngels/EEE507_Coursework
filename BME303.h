/**
* @author Laura Fanthorpe <Fanthorpe-L@email.ulster.ac.uk>
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE) For README.md
* @Copyright LaFan Productions 2017
* @param dc distance moved by compounds (cm)
* @param dm distance moved in the mobile phase (cm)
* @param l length (cm)
* @param c concentration (L g-1)
* @param e (L g-1 cm-1)
* @param i image length (cm)
* @param o optical length (cm)
* @param m mass of compound (g)
* @param rm relative molecular mass of compound
* @return selectnow() will return the answer to the problem when inputs are entered
for the specific topic chosen by user
* @todo change if/else if statements to switch/case statements
* @todo include more objects
* @see calculated values displayed when inputs are entered
*/

#pragma once        /** 
* Similiar to ifndef
*/

#ifndef BME303_h
#define BME303_h

/**
* A class is constructed called 'BME303'
*/


class BME303;

class BME303
{

	/**
	* Functions are set to public.
	* To allow functions to be read into
	* the source file.
	*/

public:
	BME303();

	//variables
	double dc;
	double dm;
	double l;
	double c;
	double e;
	double i;
	double o;
	double m;
	double rm;


	//functions
	void selectnow();  //Void so it doesn't return anything

					   //inputs
	int option;
	int no = 0;
	char answer;
};

#endif // BME303_H 

