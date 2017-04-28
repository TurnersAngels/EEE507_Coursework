/**
*@Author <Robert Kelly>	<B00642804>	<kelly-r34@email.ulster.ac.uk>	
*@License <https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE>
*@Copyright <Robert Kelly>
*
*------------------------------------------------------------------File Overview------------------------------------------------------------------------------------------
*
*This header file is going to be used along with a source file BME_101.cpp as part of a group project.
*This allows several people to write and edit independant code for it to be combined and/or changed out at a later point. 
*The header file defines the class BME101, within the class there is a public access specifier containing the constructor BME101.
*The private access specifier declares each possible variable associated with the source file and prevents it from being edited by accident or changed by human error.
*
*------------------------------------------------------------------Function Declaration-----------------------------------------------------------------------------------
*@return enterOption Is a function declared in the public specifier and will have information displayed to the user via cout and ask for an input via cin
*
*@return enterStress
*@return enterForce
*@return enterArea
*@return enterStrain
*@return enterChangeInLength
*@return enterOriginalLength
*@return enterElasticModulus
*@return enterNetForce
*@return enterAttractiveForce
*@return enterRepulsiveForce
*These functions above are all declared in the public specifier of the class BME101. They will show the user information via cout and ask for an input via cin.
*
*------------------------------------------------------------------Variable Declaration-----------------------------------------------------------------------------------
*
*@param moption is an integer variable declared in the private specifier named with the corresponding function it is intended to be used with
*
*@param mStress
*@param mForce
*@param mArea
*@param mStrain
*@param mChangeInLength
*@param mOriginalLength
*@param mElasticModulus
*@param mNetForce
*@param mAttractiveForce
*@param mRepulsiveForce
*The above parameters are all double variables named with the corresponding function it is intended to be used with. They are all listed within the private specifier.
*
*/

#include <iostream>
#ifndef BME_101_h
#define BME_101_h

class BME101;

class BME101
{
	    public:
		BME101();
		void enterOption ();
        void enterStress ();
        void enterForce ();
        void enterArea ();
        void enterStrain ();
        void enterChangeInLength ();
        void enterOriginalLength ();
        void enterElasticModulus ();
        void enterNetForce ();
        void enterAttractiveForce ();
        void enterRepulsiveForce ();
		void doCalculations ();
	
private:
		int mOption;
        double mStress;
        double mForce;
        double mArea;
        double mStrain;
        double mChangeInLength;
        double mOriginalLength;
        double mElasticModulus;
        double mNetForce;
        double mAttractiveForce;
        double mRepulsiveForce;
};
#endif 