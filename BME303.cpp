/**
* @author Laura Fanthorpe <Fanthorpe-L@email.ulster.ac.uk>
* @license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE) For README.md
* @Copyright LaFan 2017
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


#include "BME303.h" // Reading in from the header file
#include <iostream>
using namespace std;


BME303::BME303() {  //A class was constructed called BME303

					/**
					* Within the class all the variables are declared to 0.0
					* to enable decimal places within the inputs
					*/

	dc = 0.0;
	dm = 0.0;
	l = 0.0;
	c = 0.0;
	e = 0.0;
	i = 0.0;
	o = 0.0;
	m = 0.0;
	rm = 0.0;
}


void BME303::selectnow() // Within the class an object called
						 // 'selectnow()' is created
{
	int option; // user's entered option will be saved in this variable
	int no = 0; //condition to the while loop
	char answer; //user's entered answer will be saved in this variable

				 /**
				 * Displaying Options for the menu
				 * to prompt the user to chose their
				 * desired topic.
				 */

	while (!no)
	{
		cout << "Welcome to BME303 Cheat Sheet \n";
		cout << "\n";
		cout << "Please Select Topic... \n";
		cout << "\n";
		cout << "1. Chromatography \n";
		cout << "2. Spectroscopy \n";
		cout << "3. Light Microscopy \n";
		cout << "4. Basic Analytical Science \n";
		cout << "\n";

		//Prompting user to enter an option according to menu

		cin >> option;  // taking option value as input and saving in variable "option"

						/**
						* The user is directed from the menu to each topic by using 'if/else if' statements.
						*/

		if (option == 1) // Checking if user selected option 1
		{

			/**
			* If the user has choosen topic 1,
			* the following method is used to calculate
			* the retention factor, in chromatography.
			*/


			/**
			* The user is prompted throughout the method
			* to enter values to be entered into an equation
			*/

			cout << "\n" << endl;
			cout << "To calculate the Retention Factor..." << endl;

			cout << "\n" << endl;
			cout << "What's the distance moved by compounds? (cm) \n" << endl;



			double dc;					/**
										* User prompt to enter 'dc' value.
										* 'dc' variable is set as a 'double'
										* to enable values with decimal places
										* to be read in appropriately
										*/

			cin >> dc;					/**
										* 'cin' stores the users input to be used
										* later in the equation
										*/


			cout << "\nWhat's the distance moved by mobile phase? (cm) \n" << endl;


			double dm;					/**
										* User prompt to enter 'dm' value.
										* 'dm' variable is set as a 'double'
										* to enable values with decimal places
										* to be read in appropriately
										*/

			cin >> dm;					/**
										* 'cin' stores the users input to be used
										*  later in the equation
										*/

										/**
										* After the user inputs the values
										* the following equation runs to produce the answer 'Rf'
										* Again, 'double' is used to enable the outcome can be
										* expressed as a value with decimal places.
										*/

			double Rf = dc / dm;

			/**
			* After the calculation is complete it is displayed by
			* 'cout', a message, the output 'Rf' with 'endl' to end the line
			*/

			cout << "\nThe Retention Factor is " << Rf << endl;
			cout << "\n";

			/**
			* The user is then informed, with a thank you message,
			* that the calculation has ended. The can now enter a different module.
			*/

			cout << "Thanks for using the BME303 Cheat Sheet!" << endl;
			cout << "\n" << endl;

		}

		else if (option == 2) // Checking if user selected option 2
		{
			/**
			* Similar to 'option == 1' method.
			* Only differences is the equation and 'cout' messages
			*/

			cout << "\n" << endl;
			cout << "To calculate the absorbance..." << endl;
			cout << "\n" << endl;

			cout << "\nWhat's the length? (cm) \n" << endl;

			double l;

			cin >> l;

			cout << "\nWhat's the concentration? (L g-1) \n" << endl;

			double c;

			cin >> c;

			cout << "\nWhat's the molar absorptivity (L g-1 cm-1) \n" << endl;
			double e;

			cin >> e;

			double Abs = e * l * c;

			cout << "The Absorbance is " << Abs << endl;
			cout << "\n";
			cout << "Thanks for using the BME303 Cheat Sheet!" << endl;
			cout << "\n" << endl;
		}


		else if (option == 3) // Checking if user selected option 3
		{
			/**
			* Similar to 'option == 1' method.
			* Only differences is the equation and 'cout' messages
			*/

			cout << "\n" << endl;
			cout << "To calculate Focal Length..." << endl;

			cout << "\n" << endl;
			cout << "\nWhat's the Image Length? (cm) \n" << endl;

			double i;

			cin >> i;

			cout << "\nWhat's the Optical Length? (cm) \n" << endl;

			double o;

			cin >> o;

			double f = (1 / (1 / i) + (1 / o));

			cout << "The Focal Length is " << f << " cm" << endl;
			cout << "\n";

			cout << "Thanks for using the BME303 Cheat Sheet!" << endl;
			cout << "\n" << endl;
		}

		else if (option == 4) // Checking if user selected option 4
		{
			/**
			* Similar to 'option == 1' method.
			* Only differences is the equation and 'cout' messages
			*/

			cout << "\n" << endl;
			cout << "To calculate the number of moles..." << endl;

			cout << "\n" << endl;
			cout << "\nWhat's the Mass? (g) \n" << endl;

			double m;

			cin >> m;

			cout << "\nWhat's the Relative Molecular Mass? \n" << endl;

			double rm;

			cin >> rm;

			double n = m / rm;

			cout << "The Number of Moles is " << n << endl;
			cout << "\n";

			cout << "Thanks for using the BME303 Cheat Sheet!" << endl;
			cout << "\n" << endl;
		}

		/**
		* The final 'else' statement terminates the program
		* if an invalid input has been entered.
		*/

		else
		{

			/**
			* The following error message is displayed if theres
			* and invalid input, i.e. 1,2,3 or 4.
			* The user is then prompted to restart the module.
			*/

			cout << "\n" << endl;
			cout << "Invalid Option entered \n" << endl;
		}

		/**
		* At the end of each calculation the user is prompt
		* to choose if they want to try again or not
		* again by using 'if/else if' statements.
		*/

		cout << "Would you like to choose again? (Y/N)\n";

		cin >> answer; /**
					   * 'cin' stores the users input to be used
					   * to be redirected to menu again.
					   */

					   /**
					   * If the answer is No, by the user inputting either 'n' or 'N'
					   * the program is stopped.
					   */

		if (answer == 'n' || answer == 'N')
		{
			no++;
		}

		/**
		* Else if the answer is Yes, by the user inputting either 'y' or 'Y'
		* the loop runs the program again displaying the menu of topics
		* for the user to chose from.
		*/

		else if (answer == 'Y' || answer == 'y')
		{
			cout << "\n";
		}
	}

}

/**
* Within the main function the class 'BME303' is called
* along with an object, 'object3' and function 'selectnow()'
*/

int c_main(void);

int c_main(void) {

	BME303 object3;
	object3.selectnow();
	return (0);
}