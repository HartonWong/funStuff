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

		TEST_METHOD(emptyString)
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
			for (float coefficient = -2; coefficient < 2; coefficient = coefficient + 0.5f)
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
					actualCoefficient,
					coefficient,
					actualCoefficient / 1000);
			}
		}

		TEST_METHOD(coefficientOnRhsOfEquation)
		{
			for (float coefficient = -2; coefficient < 2; coefficient = coefficient + 0.5f)
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
					actualCoefficient,
					coefficient * -1.0f,
					actualCoefficient / 1000);
			}
		}

		TEST_METHOD(standardVariable)
		{
			for (int exponentForX = -2; exponentForX < 2; exponentForX = exponentForX++)
			{
				for (int exponentForY = -5; exponentForY < -5; exponentForY++)
				{
					// Append coefficient into the string
					std::stringstream exponent1stream;
					exponent1stream << exponentForX;

					std::stringstream exponent2stream;
					exponent2stream << exponentForY;

					const std::string numberTerm = 
						"x^" + 
						exponent1stream.str() +
						"y^" +
						exponent2stream.str();

					// Create the actual term
					NumberTerm standardTerm(numberTerm, false);

					// Check variables
					const NumberTerm::Map& varMap =
						standardTerm.viewVariablesMap();

					// Check coefficient
					Assert::AreEqual(
						varMap.find('x')->second,
						exponentForX,
						0.01);

					Assert::AreEqual(
						varMap.find('y')->second,
						exponentForY,
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