/**
* @author Adam Kavanagh B00631162 <kavanagh-a1@email.ulster.ac.uk>
*
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
* @copyright Adam Kavanagh 2017
*
* Electrical Technology Module (EEE154)
*
* @todo Current version outputs the calculated values in scientific notation but engineering format
* would be more useful
*
* @todo If a user completes the prompts incorrectly they will be informed that there is a problem and
* they will have to restart the program. An ideal solution would involve a promt telling the user that
* their input is incorrect and to clear their entry and get them to try again instead of having to
* restart the entire program.
*
* @todo Create more equations and possibly work on using multiple equations so solve a complex problem.
*
* @todo GUI for this section of code. However, if a GUI is created for this code then it would remove
* a large amount of complexity from each individuals work (i.e the decision making). Therefore, it may
* not be best for this assignment to create a GUI, but it would be ideal to have one in other circumstances.
*
* @todo Discuss if there would be use in storing the results of the calculations by importing them to a
* text file.
*
* @todo Possibly need a destructor to deallocate the memory the object allocated in this program.
*/

/**
* Including the associated header file for this source file which has the class EEE154
* defined within, along with all the variables and functions used below.
*/

#include "EEE154.h"
#include <iostream>

using namespace std;

EEE154 object1; //Declaring object

/**
* Creating constructor for class variables setting each variable to have a safe value (zero).
*/

EEE154::EEE154() 
{
	v = 0.0;
	i = 0.0;
	r = 0.0;
	p = 0.0;
	q = 0.0;
	t = 0.0;
	equation = 0;
	variables = 0;
}

/**
* The purpose of this function is to display to the user the equations available for this module.
* The user then enters the number corresponding with the option they wish to use.
*
* @return equation_choice() is a decision making function which maximises user input to pinpoint
* which equation they wish to use and the variation to find the unknown variable. What this function
* specifically returns is other functions which deal with the mathematical calculations.
*/

void EEE154::equation_choice()
{
	/**
	* Do while loop created so the code runs at least once. The while at the end dictates whether the
	* code runs again based on the statements provided.
	*/

	do
	{
		cout << "This is the cheat sheet for EEE154 - Electrical Technology";
		cout << "\n\nThese are the equations available for this module:";
		cout << "\n1. Ohm's Law (V = IR)" << "\n2. Power Equaion (P = VI)" << "\n3. Charge Equation (Q = IT)" << "\n4. Exit" << "\n\n";

		/**
		* @param 'equation' is used to store the number the user entered to select the equation they
		* wish to use.
		*/

		cout << "Select an option to continue: ";
		cin >> equation;

		/**
		* Switch statement to evaluate the contents of variable 'equation'. Depending upon what the 
		* user has entered, the corresponding case will be run. The user is then asked to select the
		* known variables. Once the user has enterd their known variables another function is called
		* which contains the algorithms to calculate the known variable.
		*
		* I choose to use switch statements through out my code rather than nested if-else statements
		* because it is marginally more efficient as they don't have to consider logical operators
		* and each segment of code doesn't need to be analysed (i.e. only the relevant code is run).
		*
		* Case 4 is unlike the first three as it is used to exit and not to proceed. The default case
		* is there in case the user input is outside of the operational parameters of the program. 
		*
		* @param 'variables' is used to store the number the user entered to select the combination
		* of known variables. 
		*/

		switch (equation) //Switch based on the user's selection
		{
		case 1:
			cout << "\n" << "Possible combinations of known variables:" << "\n1. V and I" << "\n2. V and R" << "\n3. I and R" << "\n\n" << "Select combination: ";
			cin >> variables;
			EEE154::ohms_eqn();
			break;
		case 2:
			cout << "\n" << "Possible combinations of known variables:" << "\n1. V and I" << "\n2. P and V" << "\n3. P and I" << "\n\n" << "Select combination: ";
			cin >> variables;
			EEE154::power_eqn();
			break;
		case 3:
			cout << "\n" << "Possible combinations of known variables:" << "\n1. I and T" << "\n2. Q and I" << "\n3. Q and T" << "\n\n" << "Select combination: ";
			cin >> variables;
			EEE154::charge_eqn();
			break;
		case 4:
			cout << "\n";
			cout << "- - - - - - - - - - - - - SHUTDOWN COMPLETE - - - - - - - - - - - - -" << "\n\n";
			break;
		default:
			cout << "\n" << "Incorrect selection, restart program and try again" << "\n\n";
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
			break;
		}

		/**
		* The while loop will run as long as the following criteria specified criteria are met.
		* Otherwise the code will only run once and then end.
		*
		* @param 'YN' is used later on @see the other functions within the EEE154 class. Brief
		* summary is that YN is used to store another user input for whether they wish to use
		* another equation from this module. If they answer Y/y then the do while loop continues.
		*/

	} while ((equation == 1 || equation == 2 || equation == 3) && (YN == 'Y' || YN == 'y'));
};

/**
* The purpose of this function EEE154::ohms_eqn(), and @see EEE154::power_eqn() and EEE154::charge_eqn()
* is that the desired variant of each equation will be selected and the relevant function containing
* the equation will be called. These functions can then be called upon by the first function 
* EEE154::equation_choice.
* 
* @return this function and the other similar functions @see EE154::power_eqn() and EEE154::charge_eqn()
* return the desired function containing the variant of an equation the user as choosen.
*/

void EEE154::ohms_eqn() 
{
	/**
	* Again using the do while loop so the code runs at least once.
	*/

	do
	{
		/**
		* Switch statements being used again only this time it is evaluating the contents of the
		* variable named 'variables'.
		*
		* @param 'variables' as seen above @see EEE154::equation_choice is used to store user input
		* for them to indicate which variables they know. Based upon what the user selects as their
		* known variables will dicate which variables they will be asked to enter and also it will
		* also determine which variation of the equation will be implemented.
		*
		* @param 'v','r' and 'i' are used to store the values for voltage, resistance and current
		* respectively. These variables are used to store user input and also to form equations.
		*
		* Each case will call a specific function related to the selection the user made when they
		* entered what variables they knew. 
		*/

		switch (variables) //Switch based on the user's selection
		{
		case 1:
			cout << "\n" << "Enter value for V: ";
			cin >> object1.v;
			cout << "\n" << "Enter value for I: ";
			cin >> object1.i;
			object1.Ohms_calculation_1(object1.v, object1.i);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 2:
			cout << "\n" << "Enter value for V: ";
			cin >> object1.v;
			cout << "\n" << "Enter value for R: ";
			cin >> object1.r;
			object1.Ohms_calculation_2(object1.v, object1.r);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 3:
			cout << "\n" << "Enter value for I: ";
			cin >> i;
			cout << "\n" << "Enter value for R: ";
			cin >> r;
			object1.Ohms_calculation_3(object1.i, object1.r);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		default:
			cout << "\n" << "Incorrect selection, restart program and try again" << "\n\n";
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		}
		cout << "Would you like to select another equation from this module? [Y/N]: " << flush;
		cin >> YN;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
		break;
	} while (YN == 'Y' || YN == 'y'); //loop runs as long as the user wishes to use another eqn from this module
};

/**
* @see EEE154::ohms_eqn() comments applicable
*/

void EEE154::power_eqn()
{
	do
	{
		switch (variables)
		{
		case 1:
			cout << "\n" << "Enter value for V: ";
			cin >> object1.v;
			cout << "\n" << "Enter value for I: ";
			cin >> object1.i;
			object1.Power_calculation_1(object1.v, object1.i);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 2:
			cout << "\n" << "Enter value for P: ";
			cin >> object1.p;
			cout << "\n" << "Enter value for V: ";
			cin >> object1.v;
			object1.Power_calculation_2(object1.v, object1.p);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 3:
			cout << "\n" << "Enter value for P: ";
			cin >> object1.p;
			cout << "\n" << "Enter value for I: ";
			cin >> object1.i;
			object1.Power_calculation_3(object1.i, object1.p);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		default:
			cout << "\n" << "Incorrect selection, restart program and try again" << "\n\n";
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		}
		cout << "Would you like to select another equation from this module? [Y/N]: " << flush;
		cin >> YN;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
		break;
	} while (YN == 'Y' || YN == 'y');
};

/**
* @see EEE154::ohms_eqn() comments applicable
*/

void EEE154::charge_eqn()
{
	do
	{
		switch (variables) //Switch based on the user's selection
		{
		case 1:
			cout << "\n" << "Enter value for I: ";
			cin >> object1.i;
			cout << "\n" << "Enter value for T: ";
			cin >> object1.t;
			object1.Charge_calculation_1(object1.i, object1.t);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 2:
			cout << "\n" << "Enter value for Q: ";
			cin >> object1.q;
			cout << "\n" << "Enter value for I: ";
			cin >> object1.i;
			object1.Charge_calculation_2(object1.q, object1.i);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		case 3:
			cout << "\n" << "Enter value for Q: ";
			cin >> object1.q;
			cout << "\n" << "Enter value for T: ";
			cin >> object1.t;
			object1.Charge_calculation_3(object1.q, object1.t);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		default:
			cout << "\n" << "Incorrect selection, restart program and try again" << "\n\n";
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n";
			break;
		}
		cout << "Would you like to select another equation from this module? [Y/N]: " << flush;
		cin >> YN;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << "\n\n";
		break;
	} while (YN == 'Y' || YN == 'y');
};

/**
* Aforementioned the functions below contain unique variations of the three main equations,
* Ohms, power and charge. Each of these functions are designed to perform all the calculations
* necessary and display the information in the correct format.
*
* In this function and the other calculation functions I have used cout.precision(2) and
* scientific to display the answers from the calculations in scientific notation, and
* specifically to two decimal places.
*
* @return the nine functions below return a numerical answer in scientific notation to 2
* decimal places.
*/

double EEE154::Ohms_calculation_1(double v, double i)
{
	cout.precision(2);
	cout << "\n" << "R = " << scientific << v / i << " Ohms" << "\n\n";

	return (v / i);
}

double EEE154::Ohms_calculation_2(double v, double r)
{
	cout.precision(2);
	cout << "\n" << "I = " << scientific << v / r << " Amps" << "\n\n";

	return (v / r);
}

double EEE154::Ohms_calculation_3(double i, double r)
{
	cout.precision(2);
	cout << "\n" << "V = " << scientific << i * r << " Volts" << "\n\n";

	return (i * r);
}

double EEE154::Power_calculation_1(double v, double i)
{
	cout.precision(2);
	cout << "\n" << "P = " << scientific << v * i << " Watts" << "\n\n";

	return (v * i);
}

double EEE154::Power_calculation_2(double p, double v)
{
	cout.precision(2);
	cout << "\n" << "I = " << scientific << p / v << " Amps" << "\n\n";

	return (p / v);
}

double EEE154::Power_calculation_3(double p, double i)
{
	cout.precision(2);
	cout << "\n" << "V = " << scientific << p / i << " Volts" << "\n\n";

	return (p / i);
}

double EEE154::Charge_calculation_1(double i, double t)
{
	cout.precision(2);
	cout << "\n" << "Q = " << scientific << i * t << " Coulombs" << "\n\n";

	return (i * t);
}

double EEE154::Charge_calculation_2(double q, double i)
{
	cout.precision(2);
	cout << "\n" << "T = " << scientific << q / i << " Seconds" << "\n\n";

	return (q / i);
}

double EEE154::Charge_calculation_3(double q, double t)
{
	cout.precision(2);
	cout << "\n" << "I = " << scientific << q / t << " Amps" << "\n\n";

	return (q / t);
}

/**
* Declaring my main function. The reason it is called a_main(void) is because when everyones code
* is pieced together there cannot be more than one int main(void) function without causing conflict.
*/

int a_main(void);

/**
* Getting the function equation_choice()
*/

int a_main(void)
{
	object1.equation_choice();

	return (0);
}