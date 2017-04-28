/**
* @author Adam Kavanagh <kavanagh-a1@email.ulster.ac.uk> <B00631162>
*
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
* @copyright Adam Kavanagh 2017
*
* This project is designed as a formula sheet for modules taken throughout the
* Biomedical Engineering course. This formula sheet does not contain all equations
* but enough to demonstrate the functionality of each individuals class.
*
* This file's purpose is to be able to piece together each individuals code into one
* fully functional database of equations. This involves including header files from
* each person and calling functions from their source files depending on what the user
* selects.
*
* This header file contains the class definition for module selection. This class is 
* designed to be the framework to pull everyone's classes together. Therefore, there
* isn't much computation required as the majority of the work is done in each individuals
* class.
*
* The code below includes the definition of the class and the variables, functions, types 
* and access specificers required.
*
* @param Module_Selection is a int variable used to store user input for which module they
* wish to select and this is then used in the @see Module_Choice function to call the 
* function which is associated with that module. It is also used as part of the while
* loop statements, so as long as an integer value between 1-5 is entered the while loop will
* coninue to run.
* 
* @param mainYN is a character variable which is used to store user input from asking the 
* user whether they wish to choose another module. This is then used as part of the while 
* loop statements. If the user enters Y or y then the loop will continue from the start.
*/

/**
* Checking whether the header has been defined already, if not then it is defined below.
* However, if it is already defined then this prevents double declaration of the identifiers.
* This can also be achieved by using #pragma once.
*/

#ifndef Module_Selector_h
#define Module_Selector_h

#include <iostream>

class Module_Selector; //Defining class

class Module_Selector
{
private: //Setting access specifiers for variables
	int Module_Selection;
	char mainYN;

public: //Setting access specifier for function
	void Module_Choice();
};

#endif 