/**
*creating MEC121 class -
*MEC121 class contains variables and functions for my part of project
* @author Alexander Martin b00644672 <martin - a35@email.ulster.ac.uk>
* @license https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE for README.md
* @copyright cfms6 productions
*
*/

#ifndef MEC121_h
#define MEC121_h

#include <iostream>
using namespace std;


class MEC121;

class MEC121
{
public:
	MEC121(); // contructor

			  //Variables-kind of redundant since stated using @param in source
			  //for equations
	double Force, Mass, Acc, Work, Dist, Power, Vel;

	//setting for the loop to return to chapter menu
	bool M_repeat;

	//user input to decide whether to return/or repeat chapter
	char YesNo;

	int Selection, Formula_Selection;

	//Functions
	//need to make prvate but having issues

	/*USer_select is a function used to run loop based on user input for chatper slection */
	
	void User_select();

	/*used to loop sub menu's within chapters, they use loops and to rerun, and to do calculations of variables*/
	void Force_Eq();
	void Work_Eq();
	void Power_Eq();

};

#endif