/**
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
*
* Manufacturing processes module
*
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
*@license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
*@copyright Luke Herron 2017
* https://github.com/luke959/mec104/ for README.md
*
*Part of a larger project which enables you to select an equation you wish
*to calculate from the manufacturing processes module
*and varients of that equation depending on values that are given to you.
* See MEC140_test.cpp for relevant test
*/

// MEC104.cpp : Defines the entry point for the console application.

//Including the associated header file for this source file which has the class MEC104
//defined within, along with all the variables and functions used below.

#include <iostream>
#include "MEC104.h"

using namespace std;
MEC104 m;

/**
*Gives cases 1, 2, 3 of which are equations
*
*@param select a case number for equation selection
*@return equation_selection() A selected 'equation'
*/

void MEC104::equation_selection()
{

/**
* Do while loop created so the code runs at least once. The while at the end dictates whether the
* code runs again based on the statements provided.
*/

	do
	{
		cout << "Enter operator. 1 for MRR, 2 for SCS or 3 for MP: ";
		cin >> m.equationselection;

//Switch statement depending upon what the
//user has entered, the corresponding case will be run. The user is then asked to select the
//known variables. Once the user has entered their known variables another function is called
// which contains the algorithms to calculate the known variable.

/**
*Gives cases 1, 2, 3 of which are equations
*
*@param select a case number for equation selection
*/

		switch (m.equationselection)
		{
		case 1:
			m.mrr_equation_variant(); //get MRR varient
			switch (m.mrr_varient)
			{
			case 1:
				m.get_mrr_variables();
				m.calculate_mrr(m.feedRate, m.depthOfCut, m.widthOfCut);
				break;
			case 2:
				m.get_feedrate_variables();
				m.calculate_feedrate(m.feedRate, m.depthOfCut, m.widthOfCut);
				break;
			}
/**
*Gives cases of which are varients of the selected equation
*
*@param select a case number for equation varient selection
*/
			break;
		default:
			cout << "Error! operator is not correct" << endl;
			break;

		case 2:
			m.scs_equation_variant();  //get SCS varient
			switch (m.scs_varient)
			{
			case 1:

				cout << "Enter diameter in mm: ";
				cin >> m.diameter;

				cout << "Enter spindle speed in RPM: ";
				cin >> m.spindleSpeed;

				m.calculate_scs(m.pi, m.diameter, m.spindleSpeed);
				break;

			case 2:
				cout << "Enter SCS in mm/min: ";
				cin >> m.SCS;

				cout << "Enter diameter in mm: ";
				cin >> m.diameter;

				m.calculate_spindlespeed(m.SCS, m.pi, m.diameter);
				break;

			default:
				cout << "Error! operator is not correct" << endl;
				break;
			}
			break;
		

		case 3:
			m.mp_equation_variant(); //get the mp equation varient
			switch (m.mp_varient)
			{
			case 1:
				cout << "Enter unit power factor: ";
				cin >> m.unitPowerFactor;

				cout << "Enter material removal rate: ";
				cin >> m.MRR;

				m.calculate_mp(m.unitPowerFactor, m.MRR);
				break;

			case 2:
				cout << "Enter material removal rate: ";
				cin >> m.MRR;

				cout << "Enter milling power: ";
				cin >> m.MP;

				m.calculate_upf(m.MP, m.MRR);
				break;

			case 3:
				cout << "Enter unit power factor: ";
				cin >> m.UPF;

				cout << "Enter milling power: ";
				cin >> m.MP;

				m.calculate_mp_mrr(m.UPF, m.MP);
				break;

			default:
				cout << "Error! operator is not correct" << endl;
				break;
			}
			break;

		
		}
		cout << "Run again? [Y/N]: " << flush;


	} while (cin >> m.yn && (m.yn == 'Y' || m.yn == 'y'));

}

void MEC104::mrr_equation_variant() //get mrr equation varient
{
	cout << "You have selected MRR" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1. MRR= Feed rate x depth x width" << endl;
	cout << "2. Feed rate= MRR / (Depth x width)" << endl;
	cin >> mrr_varient;
}

void MEC104::scs_equation_variant()//get scs equation varient
{
	cout << "You have selected SCS" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1.SCS= pi x diameter x spindle speed" << endl;
	cout << "2.Spindle Speed= SCS / pi x diameter" << endl;
	cin >> scs_varient;
}

void MEC104::mp_equation_variant()//get mp equation varient
{
	cout << "You have selected MP" << endl;
	cout << "please select the equation variant" << endl;
	cout << "1.MP= UPF x MRR" << endl;
	cout << "2.UPF= MP / MRR" << endl;
	cout << "3.MRR= MP / UPF" << endl;
	cin >> mp_varient;
}

/**
*Function to perform feedrate calculation
*
*@param The user's input feed value
*@param "depth" The user's input depth value
*@param "width" The user's input width value
*@return Returns the result of the 3 input values multiplied
*/

double MEC104::calculate_feedrate(double feed, double depth, double width)
{
	cout << "Result is: " << feed * depth * width << "cc/min" << endl;
	return feed * depth * width;
}

/** 
*Function to perform mmr calculation
*
*@param 'feed'The user's input feed value
*@param "depth" The user's input depth value
*@param "width" The user's input width value
*@return Returns the result of the 3 input values multiplied
*/

double calculate_mrr(double feed, double depth, double width);

double MEC104::calculate_mrr(double feed, double depth, double width)
{
	cout << "Result is: " << feed * depth * width << "cc/min" << endl;
	return (feed * depth * width);
}

/**
*Function to perform scs calculation
*
*@param A constant input pi value
*@param "dia" The user's input diameter value
*@param "spindle" The user's input spindle spped value
*@return Returns the result of the input values multiplied and the pi value
*/

double MEC104::calculate_scs(double pi, double dia, double spindle)
{
	cout << "Result is: " << pi * dia * spindle << "cc/min" << endl;
	return (pi * dia * spindle);
}

/**
*Function to perform spindle speed calculation
*
*@param a constant pi value
*@param "scs" The user's input surface cutting speed value
*@param "dia" The user's input diameter value
*@return Returns the result of the 2 input values divided by a constant pi 
*/

double MEC104::calculate_spindlespeed(double scs, double pi, double dia)
{
	cout << "Result is: " << scs / (pi * dia) << "cc/min" << endl;
	return scs / (pi * dia);
}

void MEC104::get_mrr_variables() //gets the required variables for the mrr calculation from the user 
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;
}

void MEC104::get_feedrate_variables()//gets the required variables for the feedrate calculation from the user
{
	cout << "Enter feed rate in mm/rev: ";
	cin >> feedRate;

	cout << "Enter depth of cut in mm: ";
	cin >> depthOfCut;

	cout << "Enter width of cut in mm: ";
	cin >> widthOfCut;
}

/**
*Function to perform mp calculation
*
*@param 'mp' The user's input unit power value
*@param "mrr" The user's input marterial removal rate value
*@return Returns the result of the 2 input values multiplied
*/

double MEC104::calculate_mp(double upf, double mrr)
{
	cout << "Result is: " << upf * mrr << "Watts" << endl;
	return upf * mrr;
}
/**
*Function to perform upf calculation
*@param "mp" The user's input milling power value
*@param "mrr" The user's input martrial removal rate value
*@return Returns the result of the 2 input values multiplied
*/

double MEC104::calculate_upf(double mp, double mrr)
{
	cout << "Result is: " << mp / mrr << endl;
	return mp / mrr;
}
/**
*Function to perform mrr calculation
*
*@param "mp" The user's input milling power value
*@param "upf" The user's input unit power factor value
*@return Returns the result of the 2 input values divided
*/
double MEC104::calculate_mp_mrr(double upf, double mp)
{
	cout << "Result is: " << mp / upf << endl;
	return mp / upf;
}


// Declaring the main function. The reason it is called e_main(void) is because when other module code
// is pieced together there cannot be more than one int main(void) function.


int e_main(void);

int e_main(void)
{
	m.equation_selection();
	return(0);
}


