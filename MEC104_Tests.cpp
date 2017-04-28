/**
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
*@license (https://github.com/TurnersAngels/EEE507_Coursework/blob/master/LICENSE)
*@copyright Luke Herron 2017
*
* Manufacturing processes module
*
*@author Luke Herron <b00641161> <herron-l1@email.ulster.ac.uk>
* https://github.com/luke959/mec104/ for README.md
*/

#include "CppUnitTest.h"
#include "stdafx.h"
#include "../EEE507_CourseWork/MEC104.h"

/** Test code file for module MEC104
* tests that the equations and the equation varients 
* should give an expected output
*/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(UnitTest1)
	{
	public: MEC104 mec;

			TEST_METHOD(calculate_mrr_test)
			{
				Assert::IsTrue(is_equal(24.0, mec.calculate_mrr(2, 3, 4)));
			}

			TEST_METHOD(calculate_scs_test)
			{
				Assert::IsTrue(is_equal(62.8318, mec.calculate_scs(3.14159, 2, 10)));
			}

			TEST_METHOD(calculate_spindle_test)
			{
				Assert::IsTrue(is_equal(0.132629, mec.calculate_spindlespeed(5, 3.14159, 12)));
			}

			TEST_METHOD(calculate_mp_test)
			{
				Assert::IsTrue(is_equal(50, mec.calculate_mp(5, 10)));
			}

			TEST_METHOD(calculate_upf_test)
			{
				Assert::IsTrue(is_equal(4, mec.calculate_upf(20, 5)));
			}

			TEST_METHOD(calculate_mpmrr_test)
			{
				Assert::IsTrue(is_equal(5, mec.calculate_mp_mrr(5, 25)));
			}

/**Comparing floating point values using the == operator is very error prone
*two values thats should be equal may not be due to arithmetic rounding errors.
*the common way to round these is to use an epsilon.
*/
			bool is_equal(double a, double b, const double epsilon = 1e-5)
			{
				double c = a - b;
				return c < epsilon && -c < epsilon;
			}
	};
}