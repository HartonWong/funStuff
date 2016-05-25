#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CanocialEquationChanger\Evaluator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:
		bool exceptionThrown = false;

		TEST_METHOD(emptyEquation)
		{
			try
			{
				Evaluator standardTerm("");
			}
			catch(...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(exclusiveEquation)
		{
			std::string equationStr = "";

			for (int numberOfTerm = 1; 
				numberOfTerm < 100;
				numberOfTerm++)
			{
				equationStr =	equationStr  +
								"+x^" +
								std::to_string(numberOfTerm);
			}

			equationStr += "=0";

			Evaluator evaluator(equationStr);
			const int listSize = 
				evaluator.viewNumberTermList().size();

			// Ensure 100 entires are made.
			Assert::AreEqual(
				100,
				listSize,
				0.0001);

		}

		TEST_METHOD(invalidSymbol)
		{
			try
			{
				Evaluator standardTerm("!j123-123d=`3");
			}
			catch (...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(noEqualSign)
		{
			try
			{
				Evaluator standardTerm("3123");
			}
			catch (...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}
	};
}