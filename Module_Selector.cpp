/**
* @author Adam Kavanagh B00631162 <kavanagh-a1@email.ulster.ac.uk>
*
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
* @copyright Adam Kavanagh 2017
*
* This source file is the one that connects everyone else's code. It
* displays the module options and asks the user which one they wish 
* to use. Depending on which module the user selects, the corresponding
* function is called from the designated source file.
*
* If it works don't fix it. It's all a bit messed up, but it's a special kind
* of messed up and I like it that way.
*
*/

/**
* Calling in the header file for each persons code.
* 
* The main functions in each source file needs to be renamed a_main, b_main etc
* so not to conflict with the main in this file.
*/

#include "Module_Selector.h"
#include "EEE154.h"
#include "MEC121.h"
#include "BME303.h"
#include "MEC104.h"
#include "BME_101.h"
#include <iostream>

using namespace std;

/**
* The purpose of this function is to display to the user the modules available for this course.
* The user then enters the number corresponding with the option they wish to use.
*/

void Module_Selector::Module_Choice()
{
	/**
	* Do while loop created so the code runs at least once. The while at the end dictates whether the
	* code runs again based on the statements provided.
	*/

	do
	{
		//Stating the modules available for the user to select from and asking them to pick one.
		cout << "This is the Equation Database for Biomedical Engineering." << "\n\n";
		cout << "These are the modules available within the database:" << "\n";
		cout << "1. Electrical Technology (EEE154)";
		cout << "\n2. Mechanical Technology (MEC121)";
		cout << "\n3. Analytical Science (BME303)";
		cout << "\n4. Biomedical Engineering 1 (BME101)";
		cout << "\n5. Manufacturing Processes (MEC104)";
		cout << "\n6. Exit";
		cout << "\n\n" << "Please select a module to view the equations within it: ";
		cin >> Module_Selection; // Used to store user selection 

		//Defining the objects required to call the functions 
		EEE154 object1;
		MEC121 object2;
		BME303 object3;
		MEC104 m;
		BME101 Solver;

		switch (Module_Selection) //Switch based on the user's selection
		{ //Place function from each persons code into the corresponding cases.
		case 1:
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			object1.equation_choice(); //calling the function using corresponding object
			break;
		case 2:
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			object2.User_select();
			break;
		case 3:
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			object3.selectnow();
			break;
		case 4:
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			Solver.enterOption();
			Solver.doCalculations();
			break;
		case 5:
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			m.equation_selection();
			break;
		case 6:
			cout << "\n";
			cout << "- - - - - - - - - - - - - SHUTDOWN COMPLETE - - - - - - - - - - - - -" << "\n\n";
			break;
		default: //if the user enters something outside of the cases provided then this case is run.
			cout << "\n" << "Incorrect selection, restart program and try again" << "\n\n";
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		}
		//Runs when each person's code has been executed and is used to ask the user if they want to use an equation from another module. 
		if (Module_Selection == 1 || Module_Selection == 2 || Module_Selection == 3 || Module_Selection == 4 || Module_Selection == 5)
		{
			cout << "Would you like to select another module to view the equations from that module? [Y/N]: " << flush;
			cin >> mainYN; // @param mainYN is used to store whether the user wishes to select another module.
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
		} //while loop will run as long as the user selects a module and the user wants to select another module to use. 
	} while ((Module_Selection == 1 || Module_Selection == 2 || Module_Selection == 3 || Module_Selection == 4 || Module_Selection == 5 || Module_Selection == 6) && (mainYN == 'Y' || mainYN == 'y'));
};

int main(void); //Defining main function

int main(void) //Creating main function and calling the Module_Choice function which acts as the main interface.
{
	Module_Selector mainObject;

	mainObject.Module_Choice();

	return(0);
};