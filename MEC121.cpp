/**
* @author Alexander Martin <martin-a35@email.ulster.ac.uk>
* @license  (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE) for README.md
* @copyright cfms6 2017
*
* @param Force - the variable for user input  of force in newtons
* @param Mass - the variable for user input of mass in kg
* @param Acc - the variable for user input of for acceleration
* @param Work - the variable for user input for Work
* @param Dist - User input for the distance variable
* @param Vel - the variable for user input of velocity
* @param Power - the variable for user input of power
*
* @return User_select function for the selction of chapter -runs do while loop and contains switch statements to choose between chapters
* @return Force_Eq - function for calcultaing chapter 1's variables/eqs, again using switch statements to choose formula, and then input variables
* @return Work_Eq - function for calcultaing chapter 2's variables/eqs, again using switch statements to choose formula, and then input variables
* @return Power_Eq - function for calcultaing chapter 3's variables/eqs, again using switch statements to choose formula, and then input variables
*
* @todo what if user enters zero. looking at try/throw/catch route- finding it difficult within class
* @todo if user inputs a character in chapter menu's, program runs infitinely-obviously undesired. *fixed*
* @todo create a main function and create a pause/wait then call main menu function to return to main menu
*/

#include "MEC121.h"

#include <iostream>
using namespace std;

//constructor 
MEC121::MEC121()
{
	Force = 0.0;
	Mass = 0.0;
	Acc = 0.0;
	Work = 0.0;
	Dist = 0.0;
	Power = 0.0;
	Vel = 0.0;

};

void MEC121::User_select()

{

	// want it to execute at least once  
	do
	{
		cout << "Welcome to the Mechanical Technology (MEC121) 'tutorial' (Cheatsheet)." << '\n'
			<< "Select the appropriate chapter title" << '\n'
			<< "1 - Force" << '\n'
			<< "2 - Work done" << '\n'
			<< "3 - Power" << endl;

		//need to stop it running if char/string entered, and fix so only an interger can be entered

		cin >> Selection;

		/*when a char is entered into an int this was making code run without stopping- after much reading apparently -
		when cin has a defined expected input, and this is not met eg cin expecting an int and getting a char, this places cin in
		a fail state- so by setting up a while loop for when cin is in this failed state I can set it to integer only inputs- no other input type will be accepted
		by having this while loop contained, it allows the code to function as norm when the user selects an integer
		acknowledment should go to SoloLearn programming app which has good info on c++, as well as the lectures (obviously)*/

		while (cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "Please type in the chapter number only" << '\n';
			cout << "Enter a chapter number (1,2 or 3).\n";
			cin >> Selection;
		}


		switch (Selection) {

		case 1:
			cout << "You have selected, Force , is this correct? Y/N " << '\n';

			//M_repeat-is for menu repeat. auto setting this to false, unless input is N/n

			M_repeat = false;

			/*I have added the Yes/No option incase wrong selection was made. rather than having multiple statements I have used
			the not equal function, so if anything other than Y is entered it will return to main menu.
			fully aware of the limitations, such as what if an integer is entered. working on this.
			wanted a different way than how others within group had executed the same outcome
			added the &&  so that if user enters capital or non caps 'y' the program can follow the user*/

			cin >> YesNo;

			//obvious problem here - if anyother letter other than n or y is pressed it'll be seen as not equal to y and therefore repeat.
			if (YesNo == 'Y' && YesNo != 'y') {
				cout << "Returned to main menu" << '\n';
				M_repeat = true; // this will repeat the main menu, if just using break, then program exits
				break;
			}
			else if (YesNo == 'Y' && YesNo == 'y') {
				M_repeat = false;
				break;
			}
			//runs force equations function
			MEC121::Force_Eq();
			break;

		case 2:
			cout << "You have selected Work done is this correct? Y/N" << '\n';
			M_repeat = false;
			cin >> YesNo;
			if (YesNo != 'Y' && YesNo != 'y') {
				cout << "Returned to main menu" << '\n';
			//	M_repeat = true;
				break;
			}
			//runs Work equations function
			MEC121::Work_Eq();
			break;

		case 3:
			cout << "You have selected Power is this correct? Y/N " << '\n';
			M_repeat = false;

			//I have added the Yes/No option incase wrong selection was made. rather than having multiple statements I have used
			//the not equal function, so if anything other than Y is entered it will return to main menu.
			//fully aware of the limitations, such as what if an integer is entered. working on this. 

			cin >> YesNo;
			if (YesNo != 'Y' && YesNo != 'y') {
				cout << "Returned to main menu" << '\n';

				//M_repeat = true;
				break;
			}
			//runs force power function
			MEC121::Power_Eq();
			break;

		default:
			cout << "Returned to main menu" << '\n';
			cout << "Please enter the chapter number" << '\n';
			
			M_repeat = true;
			break;

		}
	}
	//repeating the chapter select loop for when the default condition - ie 1 2 or 3 is not selected
	while ((M_repeat == true) && (YesNo != 'Y' || YesNo != 'y'));
};
//ISSUE: it can only repeat what is in the loop it has no way to the main menu! ***FIXED***

/*this is the force chapter equations function
using a do/while loop and switch statements, it is set to ask user for the unknown variable- based on selection 1,2 or 3, 
users selection is saved as Formula_selection variable and then used to swtich between statements.
user input within states is saved as variables. Using cout the answer is shown in command line.
The remain 2 functions, work and power, perform tasks in same way, so I will not repeat comment-redundant.
*/

void MEC121::Force_Eq()
// want it to execute at least once  
{
	do
	{
		cout << "Select Your Unknown Variable" << '\n'
			<< " 1 - Force" << '\n'
			<< " 2 - Mass" << '\n'
			<< " 3 - Acceleration" << '\n'
			<< " 4 - Exit chapter" << endl;

		cin >> Formula_Selection;

		switch (Formula_Selection) {

		case 1:
			cout << "Please enter Mass and Acceleration " << '\n';
			cout << "Mass is equal to (in kg)" << '\n';
			cin >> Mass;
			cout << "Acceleration is equal to (m/s^2)" << '\n';
			cin >> Acc;

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Mass is equal to (in kg)" << '\n';
				cin >> Mass;
				cout << "Acceleration is equal to (m/s^2)" << '\n';
				cin >> Acc;
			}
			//Because I am using force multiple times as a variable, instead of just declaring a function for force outside of class,
			//I am doing so within it
			Force = Mass * Acc;
			cout << "The Force is " << Force << " Newtons" << '\n';

			break;

		case 2:
			cout << "Please enter Force and Acceleration " << '\n';
			cout << "Force is equal to (in newtons)" << '\n';
			cin >> Force;
			cout << "Acceleration is equal to (m/s^2)" << '\n';
			cin >> Acc;

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Force is equal to (in newtons)" << '\n';
				cin >> Force;
				cout << "Acceleration is equal to (m/s^2)" << '\n';
				cin >> Acc;
			}

			// what if user divides by zero - could use a throw/catch to prevent
			//would have prefered to use try throw and catch, just could not get it to work cleanly- 
			//used while loop so that the user would have to enter a num != 0 otherwise after a couple of iterations of a if statement
			//code continues -
			while (Acc == 0) {
				cout << "Please check your input for acceleration" << endl;
				cout << "Acceleration is equal to (in m/s^2)" << '\n';
				cin >> Acc;
			}
			//stores Mass as 
			Mass = Force / Acc;
			cout << "The Mass is " << Mass << " kg" << '\n';
			break;

		case 3:
			cout << "Please enter Force and Mass " << '\n';
			cout << "Force is equal to (in newtons)" << '\n';
			cin >> Force;
			cout << "Mass is equal to (in kg)" << '\n';
			cin >> Mass;

			//  See case 2 for explanation
			while (Mass == 0) {
				cout << "Please check your input for acceleration" << endl;
				cout << "Acceleration is equal to (in m/s^2)" << '\n';
				cin >> Mass;
			}

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Force is equal to (in newtons)" << '\n';
				cin >> Force;
				cout << "Mass is equal to (in kg)" << '\n';
				cin >> Mass;
			}

			Acc = Force / Mass;
			cout << "The Acceleration is " << Acc << " m/s^2" << '\n';
			break;

			//returns user back to chapter selection ie - force work done & power
		case 4:
			cout << "Chapter Exit" << '\n';
			if (Formula_Selection == 4) { break; }
			break;

		default:

			cout << "Give it another try, please select a Chapter number" << '\n';
			M_repeat = true;
			break;

		}
		/*this is used to allow for escape back to the module selector main, in the main group file, or to stay 
		within this class(MEC121*/
		cout << "Would you like to like to like to try another Eq from this module(MEC121) ?" << endl;
		cin >> YesNo;
		break;

		//while loop used to return within chapter- this allows user to rerun a different formual from within the function
	} while ((Formula_Selection != 1 || Formula_Selection != 2 || Formula_Selection != 3) && (YesNo == 'Y' || YesNo == 'y'));
}; 

//See lines 151-156 for explanation
void MEC121::Work_Eq()
// want it to execute at least once  
{
	do
	{
		cout << "Select Your Unknown Variable" << '\n'
			<< " 1 - Work Done" << '\n'
			<< " 2 - Force" << '\n'
			<< " 3 - Distance" << '\n'
			<< " 4 - Exit chapter" << endl;

		cin >> Formula_Selection;

		switch (Formula_Selection) {

		case 1:
			cout << "Please enter Force and distance " << '\n';
			cout << "Force is equal to  (in Newtons)" << '\n';
			cin >> Force;
			cout << "Distance is equal to (in meters)" << '\n';
			cin >> Dist;

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Force is equal to  (in Newtons)" << '\n';
				cin >> Force;
				cout << "Distance is equal to (in meters)" << '\n';
				cin >> Dist;
			}

			//  what if user divides by zero - could use a throw/catch to prevent
			Work = Force * Dist;
			cout << "The Work done is " << Work << '\n';
			break;

		case 2:
			cout << "Please enter Work and distance " << '\n';
			cout << "Work is equal to " << '\n';
			cin >> Work;
			cout << "Distance is equal to" << '\n';
			cin >> Dist;

			//  what if user divides by zero - could use a throw/catch to prevent---just cannot get it to work -_-
			//may have to do If statement
			while (Dist == 0) {
				cout << "Please check your input for Distance" << endl;
				cout << "Distance is equal to (in m)" << '\n';
				cin >> Dist;
			}

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Work is equal to " << '\n';
				cin >> Work;
				cout << "Distance is equal to" << '\n';
				cin >> Dist;
			}

			Force = Work / Dist;
			cout << "The Force is " << Force << " Newtons" << '\n';
			break;

		case 3:
			cout << "Please enter Work and Force " << '\n';
			cout << "Work is equal to " << '\n';
			cin >> Work;
			cout << "Force is equal to" << '\n';
			cin >> Force;


			//preventing user from dividing by zero.
			while (Force == 0) {
				cout << "Please check your input for Force" << endl;
				cout << "Force is equal to (in Newtons)" << '\n';
				cin >> Force;
			}

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignores last input
				cout << "Enter numbers only" << '\n';
				cout << "Work is equal to " << '\n';
				cin >> Work;
				cout << "Force is equal to" << '\n';
				cin >> Force;
			}
			
			Dist = Work / Force;
			cout << "The Distance is " << Dist << " m" << '\n';
			break;

		case 4:
			cout << "Chapter Exit" << '\n';
			if (Formula_Selection == 4) { break; }
			break;

		default:

			cout << "Give it another try, please select a Chapter number" << '\n';
			M_repeat = true;
			break;
		}
		cout << "Would you like to like to like to try another Eq from this module(MEC121) ?" << endl;
		cin >> YesNo;
		break;

		//while loop used to return within chapter- this allows user to rerun a different formual from within the function
	} while ((Formula_Selection != 1 || Formula_Selection != 2 || Formula_Selection != 3) && (YesNo == 'Y' || YesNo == 'y'));
};


//see line 151-56 for explanation, function works in same way but different variables (x2)
void MEC121::Power_Eq()
// want it to execute at least once  
{
	do
	{
		cout << "Select Your Unknown Variable" << '\n'
			<< " 1 - Power (with which, comes great responsibility)" << '\n'  // a wee nod to my favourite superhero, uncle Ben. 
			<< " 2 - Force" << '\n'
			<< " 3 - Velocity" << '\n'
			<< " 4 - Exit chapter" << endl;

		cin >> Formula_Selection;

		switch (Formula_Selection) {

		case 1:
			cout << "Please enter Force and Velocity " << '\n';
			cout << "Force is equal to (in Newtons) " << '\n';
			cin >> Force;
			cout << "Velocity is equal to (m/s)" << '\n';
			cin >> Vel;

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Force is equal to (in Newtons) " << '\n';
				cin >> Force;
				cout << "Velocity is equal to (m/s)" << '\n';
				cin >> Vel;
			}

			Power = Force * Vel;
			cout << "Power is equal to  " << Power << '\n';
			break;

		case 2:
			cout << "Please enter Power and Velocity " << '\n';
			cout << "Power is equal to " << '\n';
			cin >> Power;
			cout << "Velocity is equal to (m/s)" << '\n';
			cin >> Vel;

			// this loop is to prevent dividing by zero
			while (Vel == 0) {
				cout << "Please check your input for Velocity" << endl;
				cout << "Velocity is equal to (m/s)" << '\n';
				cin >> Vel;
			}

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Power is equal to " << '\n';
				cin >> Power;
				cout << "Velocity is equal to (m/s)" << '\n';
				cin >> Vel;;
			}

			Force = Power / Vel;
			cout << "Force is equal to  " << Force << "Newtons" << '\n';
			break;

		case 3:
			cout << "Please enter Power and Force " << '\n';
			cout << "Power is equal to " << '\n';
			cin >> Power;
			cout << "Force is equal to" << '\n';
			cin >> Force;

			// this loop is to prevent dividing by zero
			while (Force == 0) {
				cout << "Please check your input for Force" << endl;
				cout << "Force is equal to" << '\n';
				cin >> Force;
			}

			while (cin.fail())   //preventing letters and chars being entered - far from perfect
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Enter numbers only" << '\n';
				cout << "Power is equal to " << '\n';
				cin >> Power;
				cout << "Force is equal to" << '\n';
				cin >> Force;
			}

			//velocity var stores answer
			Vel = Power / Force;
			cout << "Velocity is equal to " << Vel << " m/s" << '\n';
			break;

		case 4:
			cout << "Chapter Exit" << '\n';
			if (Formula_Selection == 4) { break; }
			break;

		default:

			cout << "Give it another try, please select a Chapter number" << '\n';
			M_repeat = true;
			break;

		}
		/*this is used to allow for escape back to the module selector main, in the main group file, or to stay
		within this class(MEC121*/
		cout << "Would you like to like to like to try another Eq from this module(MEC121) ?" << endl;
		cin >> YesNo;
		break;
	}while ((Formula_Selection != 1 || Formula_Selection != 2 || Formula_Selection != 3) && (YesNo == 'Y' || YesNo == 'y'));
};


//need to rename to b_main
int b_main(void);

//need to rename to b_main
int b_main(void)
{
	//object number 2 with reference to the group's main file
	MEC121 object2;
	object2.User_select();

	return (0);
}

/* there was some better ways to perform this projects actions- If I had of had the time to learn/practice more I'd have liked to creat
functions, have seperate source files with functions created and then call in this source file to keep it neater. Also feel I should have
created more objects and perhaps followed the plan for the functions but unfortunitly time got the better of me on this one
To be perfectly honest, I know this code can be a lot better, I haven't used a destructor, i definitely should have created objects, and could have
used inheritance and friendship. I would have like to have broken this into more classes perhaps and have a recall function for previously entered 
eqs.
Should have created more functions and called them in rather than big bulky messy code.In reality the code is probably too long, and split the source file*/