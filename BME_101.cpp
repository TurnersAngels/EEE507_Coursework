/** 
*
*@Author Robert Kelly	<kelly-r34@email.ulster.ac.uk>	
*@License:<https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE> 
*@Copyright <Robert Kelly>
*
*------------------------------------------------------------------File Overview----------------------------------------------------------------------------------------
*
*This source file is being used as part of a group project to build an equation solver program, it is to be used along with the header file BME101.h where all associated
*functions and variables are listed in the class BME 101, within  this source file the functions will be written and sequenced so the user can easily use the equation
*solver with clear instructions and safeguards built in to overcome human errors (user stupidity).
*
*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*BME101::BME101() is a constructor calling the class BME101, it sets all the variables to a safe value of zero before the they are used within the functions.
*
*------------------------------------------------------------------Main Functionality-----------------------------------------------------------------------------------
*
*BME101 Solver creates an object called Solver in the main running the function:
*@return BME101::enterOption is a function displaying text to the user via cout asking for an input based on what option they would like to select.
*@param mOption stores this input (integer @see BME_101.h variable param comments) and changes it in the memory from the intial value zero.
*The if statment of option>=5 warns the user of an invalid entry and asks them to restart via cout
*After a valid option has been entered and stored as @param mOption mentioned above Solver then runs the function:
@return doCalculatioins this function consists of a switch statement taking the variable mOption's (switch(mOption)), 
*integer value as stored from user input in enterOption
*
*------------------------------------------------------------------Case 0 Execution-----------------------------------------------------------------------------------
*
*If @param mOption = 0 from @return enterOption: case 0 is activated and breaks this causes the program to exit 
*A default of the switch statement will cause an error message to be displayed to the screen and ask to restart the program when case != 0,1,2,3,4.
*
*------------------------------------------------------------------Case 1 Execution-----------------------------------------------------------------------------------
*
*If @param mOption = 1 from @return enterOption: case 1 is activated.
*The associated variables are reset to zero as a safeguard to user input insuring the equations can be calculated correctly.
*@return enterStress
*@return enterForce
*@return enterArea
*These functions now run and all perform the same operation of provding the user with information via cout to supply an input of a known or unknown variale.
*The input option is then stored with the associated namesake variable
*@param mStress
*@param mForce
*@param mArea
*Following the inputs above the program will then follow if and else if statements to perform the appropiate equation variation depending on the unknown variable.
*The unknown is displayed to the screen via cout but this value is not stored. cout also tells the user what variation of the equation was used.
*Within the if statements there is a small amout of safeguarding towards user input error by displaying error messages with cout if it is not possible to enter zero
*based on the unknown variable inputs stored at the corresponding @param m(VariableName).
*After the equation is completed the program will retun to the main screen.
*
*------------------------------------------------------------------Case 2 Execution-----------------------------------------------------------------------------------
*
*If @param mOption = 2 from @return enterOption: case 2 is activated.
*This runs the same way in which @see Case 1 execution does only using different functions and variables listed below:
*@return enterStrain
*@return enterChangeInLength
*@return enterOriginalLength
*@param mStrain
*@param mChangeInLength
*@param mOriginalLenth
*
*------------------------------------------------------------------Case 3 Execution-----------------------------------------------------------------------------------
*
*If @param mOption = 3 from @return enterOption: case 3 is activated.
*This runs the same way in which @see Case 1 execution does only using different functions and variables listed below:
*@return enterElasticModulus
*@return enterStress
*@return enterStrain
*@param mElasticModulus
*@param mStress
*@param mStrain
*
*------------------------------------------------------------------Case 4 Execution-----------------------------------------------------------------------------------
*
*If @param mOption = 4 from @return enterOption: case 4 is activated.
*This runs the same way in which @see Case 1 execution does only using different functions and variables listed below:
*@return enterNetForce
*@return enterAttractiveForce
*@return enterRepulsiveForce
*@param mNetForce
*@param mAttractiveForce
*@param mRepulsiveForce
*
*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "BME_101.h"
#include <iostream>

using namespace std;

BME101::BME101()  
//Initializing all member functions to a useable safe value of zero within constructor
{
    mOption = 0;
    mStress = 0;
    mForce = 0;
    mArea = 0;
    mStrain = 0;
    mChangeInLength =0;
    mOriginalLength = 0;
    mElasticModulus = 0;
    mNetForce = 0;
    mAttractiveForce = 0;
    mRepulsiveForce = 0;
}

void BME101::enterOption () 
//Allowing the user to select an option assigned via numbers 0-4 with each option explained via cout function
//the value entered by the user will be taken by the cin function and stored as mOption which is used by the switch statement to determine which case should be used
{
    cout << "Please select one of the options (1-4) where two variables are known followed by return or enter 0 to exit the program.\n";
    cout << "1. Stress, Force, Area \n";
    cout << "2. Strain, Change in Length, Original Length \n";
    cout << "3. Elastic (Young's) Modulus, Stress, Strain \n";
    cout << "4. Net Force, Attractive Force, Repulsive Force \n";
    cout << "0. Exit Program \n";
    cout << "Option: \n";
    cin  >> mOption;

	//if statement 
	if (mOption >= 5)
	{
		cout << "This is an invalid option please restart.";
		cout << "\n";
	}
    cout << "\n";
}

void BME101::enterStress ()
{
    cout << "Please enter known Stress Value, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mStress;
    cout << "\n";
}

void BME101::enterForce ()
{
    cout << "Please enter known Applied Force, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mForce;
    cout << "\n";
}

void BME101::enterArea ()
{
    cout << "Please enter known Area, if the value is unknown please enter zero : \n";
	cout << " \n";
    cin  >> mArea;
    cout << "\n";
}

void BME101::enterStrain ()
{
    cout << "Please enter known Strain, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mStrain;
    cout << "\n";
}

void BME101::enterChangeInLength ()
{
    cout << "Please enter known Change In Length, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mChangeInLength;
    cout << "\n";
}

void BME101::enterOriginalLength ()
{
    cout << "Please enter known Original Length, if the value is unknown please enter zero : \n";
	cout << " \n";
    cin  >> mOriginalLength;
    cout << "\n";
}

void BME101::enterElasticModulus ()
{
    cout << "Please enter known Elastic Modulus, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mElasticModulus;
    cout << "\n";
}

void BME101::enterNetForce ()
{
    cout << "Please enter known Net Force, if the value is unknown please enter zero:  \n";
	cout << "\n";
    cin  >> mNetForce;
    cout << "\n";
}

void BME101::enterAttractiveForce ()
{
    cout << "Please enter known Attractive Force, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mAttractiveForce;
    cout << "\n";
}

void BME101::enterRepulsiveForce ()
{
    cout << "Please enter known Repulsive Force, if the value is unknown please enter zero: \n";
	cout << " \n";
    cin  >> mRepulsiveForce;
    cout << "\n";
}
//function doCalculations with switch statement @see Case0, Case1, Case2, Case3, Case4 Execution comments
void BME101::doCalculations () 
{
	switch (mOption)
    {
        case 0 :
            break;
			
        case 1 :
            mStress = 0;
            mForce = 0;
            mArea = 0;
            enterStress();
            enterForce();
            enterArea();

            if (mStress == 0)
            {
                if (mArea == 0)
                {
                    cout << "The area cannot be zero \n";
                }
                else
                {
                    double stress = mForce / mArea;
                    cout << "The Stress is: " << stress << "\n";
					cout << "Equation Used: Stress = Force / Area \n";
					cout << "\n";
                }
            }


            if (mForce == 0)
            {
                double force = mStress * mArea;
                cout << "The Force is: " << force << "\n";
				cout << "Equation Used: Force = Stress * Area";
				cout << "\n";
            }


            if (mArea == 0)
            {
                if (mStress == 0)
                {
                    cout << "The stress cannot be zero \n";
                }
                else
                {
                    double area = mForce / mStress;
                    cout << "The Area is: " << area << "\n";
					cout << "Equation Used: Area = Force / Stress";
					cout << "\n";
                }
            }


            break;
			
        case 2 :
            mStrain = 0;
            mChangeInLength = 0;
            mOriginalLength = 0;
            enterStrain();
            enterChangeInLength();
            enterOriginalLength();

			
            if (mStrain == 0)
            {
                if (mOriginalLength == 0)
                {
                    cout << "The Original Length cannot be zero \n";
                }
                else
                {
                    double strain = mChangeInLength / mOriginalLength;
                    cout << "The Strain is: " << strain << "\n";
					cout << "Equation Used: Strain = Change in Length / Original Length";
					cout << "\n";
                }
            }


            if (mChangeInLength == 0)
            {
                double ChangeInLength = mStrain * mOriginalLength;
                cout << "The Change In Length is: " << ChangeInLength << "\n";
				cout << "Equation Used: Change in Length = Strain * Original Length";
				cout << "\n";
            }


            if (mOriginalLength == 0)

			{
            
                if (mStrain == 0)
                {
                    cout << "The Strain cannot be zero \n";
                }
                else
                {
                    double OriginalLength = mChangeInLength / mStrain;
                    cout << "The Original Length is: " << OriginalLength << "\n";
					cout << "Equation Used: Original Length = Change in Length / Strain";
					cout << "\n";
				}
            }

            break;
			
        case 3 :
            mElasticModulus = 0;
            mStress = 0;
            mStrain = 0;
			enterElasticModulus();
            enterStress();
            enterStrain();


            if (mElasticModulus == 0)
			{
            if (mStrain == 0)
                {
                    cout << "The Strain cannot be zero \n";
                }
                else
                {
                    double ElasticModulus = mStress / mStrain;
                    cout << "The Elastic (Young's) Modulus is: " << ElasticModulus << "\n";
					cout << "Equation Used: Stress = Elastic (Young's) Modulus = Stress / Strain";
					cout << "\n";
                }
            }

            if (mStress == 0)
            {
                double Stress = mElasticModulus * mStrain;
                cout << "The Stress is: " << Stress << "\n";
				cout << "Equation Used: Stress = Elastic (Young's) Modulus * Strain";
				cout << "\n";
            }

            if (mStrain == 0)
            {
                if (mElasticModulus == 0)
                {
                    cout << "The Elastic (Young's) Modulus cannot be zero \n";
					                }
                else
                {
                    double Strain = mStress / mElasticModulus;
                    cout << "The Strain is: " << Strain << "\n";
					cout <<"Equation Used: Strain = Stress / Elastic (Young's) Modulus";
					cout << "\n";
                }
            }
            break;
			
        case 4 :
            mNetForce = 0;
            mAttractiveForce = 0;
            mRepulsiveForce = 0;
            enterNetForce();
            enterAttractiveForce();
            enterRepulsiveForce();


            if (mNetForce == 0)
            {
                double NetForce = mAttractiveForce + mRepulsiveForce;
                cout << "The Net Force is: " << NetForce << "\n";
				cout << "Equation Used: Net Force = Attractive Force + Repulsive Force";
				cout << "\n";
				
            }
            if (mAttractiveForce == 0)
            {
                double AttractiveForce = mNetForce - mRepulsiveForce;
                cout << "The Attractive Force is: " << AttractiveForce << "\n";
				cout << "Equation Used: Attractive = Net Force - Repulsive Force";
				cout << "\n";
            }
            if (mRepulsiveForce == 0)
            {
                double RepulsiveForce = mNetForce - mAttractiveForce;
                cout << "The Repulsive Force is: " << RepulsiveForce << "\n";
				cout << "Equation Used: Repulsive Force = Net Force - Attractive Force";
				cout << "\n";
                
            }
            break;

        default :
			{
            cout << "An invalid option has been selected please restart the program";
			}
            break;
    }
}

int d_main(void);

int d_main(void)
{
	BME101 Solver;
	Solver.enterOption();
	Solver.doCalculations();		
	
	
	return(0);
}
