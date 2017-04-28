/**
* @author Adam Kavanagh B00631162 <kavanagh-a1@email.ulster.ac.uk>
*
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
* @copyright Adam Kavanagh 2017
*
* This is designed as a formula sheet for EEE154 where the user selects the equation
* which they wish to use, select the known variables from the equation and then enter
* their values. The entered values are then used to calculate the unknown variable.
* All of this is run via a command window.
*
* This header file contains the class definition for the module EEE154 which defines
* the variables, their type and also their access specifiers. The same goes for defining
* the functions required for this module, their names, type and access specifiers.
*
* @param v, i, r, p, q, t are all double variables used to store user input of numerical
* data with the objective to perform simple multiplication and division operations. They
* each represent voltage, current, resistance, power, charge and time respectively.
*
* @param equation is an int variable used to store user input for the selection of which
* equation they wish to use. This variable will be utilised by the switch statement within
* the @see equation_choice function to decide which case to run. It is also used as part
* of the while statements for this function as well.
*
* @param variables is similar to equation in its type and purpose. Variables is used to
* store whatever the integer value which relates to a selection of known variables. This
* is then used in the ohms_eqn, power_eqn and charge_eqn as the condition on which the 
* switch statements use to select which case to run. 
*
* @param YN is a character variable used to store user input. Specifically the response
* to the question "Would you like to select another equation from this module? [Y/N]:"
* if the user enters 'Y' or 'y' then the program loops back to the start of the code
* so the user can select another equation to use. If the user selects no then this does
* not satisfy the requirements stated in the while loop and therefore the loop will not 
* run again, causing this section of the code to end.
*
* Function equation_choice() acts as the main interface/starting point for this module.
* It starts by displaying the options available to the user and then asking them to 
* select an option. This selection is stored (@see equation) and used as the condition 
* for the switch statements. The cases in the switch statement will then ask the user for
* more input to ascertain the specific variation of the equation they wish to use. This will
* be stored (@see variables) and used later on (@see ohms_eqn, power_eqn and charge_eqn).
* 
* Functions ohms_eqn, power_eqn and charge_eqn are all designed to be called into 
* equation_choice whenever the user wishes to use each equation. Depending upon what the
* user inputs into variable 'equation' will determine which of these functions are run.
* The purpose of these functions is to use another switch statement and the information 
* stored within the variable 'variables' to be able to load the desired variation of each
* equation.
*
* All of the calculation functions Ohms_calculation_1 etc, are designed to take the numbers
* stored within the variables v, i, r, p, q, t and perform simple multiplication or division
* on them depending on the function being used. Each function is meant to represent a
* variation of each of the three main equations. These functions are then pulled into the 
* the decision making functions (@see ohms_eqn, power_eqn and charge_eqn).
*/

/**
* Checking whether the header has been defined already, if not then it is defined below. 
* However, if it is already defined then this prevents double declaration of the identifiers.
* This can also be achieved by using #pragma once.
*/

#ifndef EEE154_h 
#define EEE154_h

#include <iostream>

class EEE154; //Defining class

class EEE154
{
private: //Setting access specifiers for variables
	double v, i, r, p, q, t;
	int equation, variables;
	char YN;

public: //Setting access specifiers for functions
	void equation_choice();
	void ohms_eqn();
	void power_eqn();
	void charge_eqn();
	double Ohms_calculation_1(double v, double i);
	double Ohms_calculation_2(double v, double r);
	double Ohms_calculation_3(double i, double r);
	double Power_calculation_1(double v, double i);
	double Power_calculation_2(double p, double v);
	double Power_calculation_3(double p, double i);
	double Charge_calculation_1(double i, double t);
	double Charge_calculation_2(double q, double i);
	double Charge_calculation_3(double q, double t);

	EEE154(); //Declaring constructor
};

#endif
