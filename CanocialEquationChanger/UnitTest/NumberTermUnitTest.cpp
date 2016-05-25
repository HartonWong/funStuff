#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CanocialEquationChanger\NumberTerm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:
		bool exceptionThrown = false;

		TEST_METHOD(emptyNumberTerm)
		{
			try
			{
				NumberTerm standardTerm("", false);
			}
			catch(...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(standardCoefficient)
		{
			for (float coefficient = -2; 
				coefficient < 2; 
				coefficient = coefficient + 0.5f)
			{
				// Append coefficient into the string
				std::stringstream numberTermStream;
				numberTermStream << coefficient;

				const std::string numberTerm
					= numberTermStream.str() + "xy";

				// Create the actual term
				NumberTerm standardTerm(numberTerm, false);

				const float actualCoefficient =
					standardTerm.viewCoefficient();

				// Check coefficient
				Assert::AreEqual(
					coefficient,
					actualCoefficient,
					actualCoefficient / 1000);
			}
		}

		TEST_METHOD(coefficientOnRhsOfEquation)
		{
			for (float coefficient = -2; 
				coefficient < 2; 
				coefficient = coefficient + 0.5f)
			{
				// Append coefficient into the string
				std::stringstream numberTermStream;
				numberTermStream << coefficient;

				const std::string numberTerm
					= numberTermStream.str() + "yx";

				// Create the actual term
				NumberTerm standardTerm(numberTerm, true);

				const float actualCoefficient =
					standardTerm.viewCoefficient();

				// Check coefficient
				Assert::AreEqual(
					coefficient * -1.0f,
					actualCoefficient,
					actualCoefficient / 1000);
			}
		}

		TEST_METHOD(standardVariable)
		{
			for (int exponentForX = -2; 
				exponentForX < 2; 
				exponentForX++)
			{
				for (int exponentForY = -5; 
					exponentForY < -5; 
					exponentForY++)
				{
					const std::string numberTerm =
						"x^" +
						std::to_string(exponentForX) +
						"y^" +
						std::to_string(exponentForY);

					// Create the actual term
					NumberTerm standardTerm(numberTerm, false);

					// Check variables
					const NumberTerm::Map& varMap =
						standardTerm.viewVariablesMap();

					// Check coefficient
					Assert::AreEqual(
						exponentForX,
						varMap.find('x')->second,
						0.01);

					Assert::AreEqual(
						exponentForY,
						varMap.find('y')->second,
						0.01);
				}
			}
		}

		// Expected Exception testing
		TEST_METHOD(nonIntergerExponent)
		{
			try
			{
				NumberTerm standardTerm("x^.", false);
			}
			catch (...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);

			try
			{
				NumberTerm standardTerm("x^8.5", false);
			}
			catch (...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(otherSymbolUsedAfterVariable)
		{
			try
			{
				NumberTerm standardTerm("x.8", false);
			}
			catch (...)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

	};
}