#include "stdafx.h"
#include "NumberTerm.h"
#include <stdlib.h>     // For ABORT
#include <stdio.h>		// For isalpha
#include <ctype.h>		// For isalpha
#include <sstream>		// String stream to convert string to float

//-----------------------------------------------------------//
//------------------Public Function -------------------------//
//-----------------------------------------------------------//

//---------------------------------------------------------CTOR
// Implementation Note:
//		Extract data to individual member variables
//-------------------------------------------------------------
NumberTerm::NumberTerm(
	const string numberTerm,
	const bool isRhsOfEquation)
{
	string updatedNumberTermString = numberTerm;
	// set the member variable
	extractCoefficient(updatedNumberTermString, isRhsOfEquation);
	extractVariables(updatedNumberTermString);
}

//---------------------------------------------------------DTOR
// Implementation Note:
//		Clear member variables
//-------------------------------------------------------------
NumberTerm::~NumberTerm()
{
	// Nothing to clean up
}

//---------------------------------------------------isLikeTerm
// Implementation Note:
//		Compare if every variables match
//-------------------------------------------------------------
const bool NumberTerm::isLikeTerm(const NumberTerm & rhs) const
{
	return m_nVariables == rhs.m_nVariables;
}

//----------------------------------------------viewCoefficient
// Implementation Note:
//		Provide read-only access of coefficient to caller
//-------------------------------------------------------------
const float NumberTerm::viewCoefficient(void) const
{
	return m_nCoefficient;
}

//---------------------------------------------------viewVariablesMap
// Implementation Note:
//		Return the const reference of variables map to caller
//-------------------------------------------------------------
const NumberTerm::Map& NumberTerm::viewVariablesMap(void) const
{
	return m_nVariables;
}

//-----------------------------------------------------------//
//------------------Public Operator Function ----------------//
//-----------------------------------------------------------//

//----------------------------------------------------Operator+
// Implementation Note:
//		Add the coefficient only
//-------------------------------------------------------------
NumberTerm operator+(const NumberTerm &lhs, const NumberTerm &rhs)
{
	if (lhs.isLikeTerm(rhs) == false)
	{
		// Cannot add two number terms if they are not like terms.
		abort();
	}

	NumberTerm sumNumberTerm;

	// Add the coefficient only
	sumNumberTerm.m_nCoefficient =
		lhs.m_nCoefficient + rhs.m_nCoefficient;

	// Use any one term variables since they are like terms anyway
	sumNumberTerm.m_nVariables = lhs.m_nVariables;

	return sumNumberTerm;
}

//------------------------------------------------------------//
//------------------Private Function--------------------------//
//------------------------------------------------------------//

//--------------------------------------------extractCoefficient
// Implementation Note:
//		Extract the coefficient from the whole string object
//		and save such coefficient to member variable
//-------------------------------------------------------------
void NumberTerm::extractCoefficient( string& numberTerm,
									 const bool isRhsOfEquation)
{
	this->addImplicitOneToCoefficient(numberTerm);

	float coefficient =
		this->extractAllNumbersBeforeLetter(numberTerm);

	// If the term is on the right hand side of
	// the equation, flip the +/- sign
	if (isRhsOfEquation)
	{
		coefficient = coefficient * -1.0f;
	}

	// Save to coefficient to member variable
	m_nCoefficient = coefficient;
}

//---------------------------------------------extractVariables
// Implementation Note:
//		Extract the variables from the whole string object
//		and save such variables to member variable
//-------------------------------------------------------------
void NumberTerm::extractVariables(string& numberTerm)
{
	const int firstIndex = 0;

	// Iterate through the whole variable string
	while(firstIndex < numberTerm.size())
	{
		// Always evalute the first character because
		// this function will removed variable character that
		// has already been processed
		if (isalpha(numberTerm[firstIndex]))
		{
			const char individualVar = numberTerm[firstIndex];

			// Hardcoded number rationale:
			// Peeking the next character is always current index + 1
			const int peekIndex = firstIndex + 1;

			const bool isLastLetterOfTheWholeTerm = 
				peekIndex == numberTerm.size();

			if (isalnum(numberTerm[peekIndex]) ||
				isLastLetterOfTheWholeTerm)
			{
				// Hardcoded number rationale:
				// If this individual variable is immediately
				// followed by another alpha character, or it is 
				// the end of the whole string
				// it implied this individual varable is degree of 1
				m_nVariables[individualVar] = 1;

				// Hardcoded number rationale:
				// Only 1 letter to be removed because next one is 
				// second variable(which will be done in next iteration.)
				numberTerm.erase(firstIndex, 1);
			}
			else
			{
				if (numberTerm[peekIndex] == '^')
				{
					// Erase variable letter and ^ to extract the exponent 
					// number
					// Hardcoded number rationale:
					// Only 2 character to be removed, variable + ^
					numberTerm.erase(firstIndex, 2);

					const bool isPlusMinusSign =
						numberTerm[firstIndex] == '+' ||
						numberTerm[firstIndex] == '-';

					// If non digit number followed after ^ other than
					// +/- sign, because +/- sign can imply positive
					// or negative interger exponent, which is acceptable
					// in this case
					if (!isdigit(numberTerm[firstIndex]) &&
						!isPlusMinusSign)
					{
						// Throw exception if exponent is not interger
						throw std::invalid_argument(
							"Exponent cannot be non-digit character \n");
					}

					float exponent = 
						this->extractAllNumbersBeforeLetter(numberTerm);

					// if exponent is a whole number
					if (exponent == (int)exponent)
					{
						m_nVariables[individualVar] = (int)exponent;
					}
					else
					{
						// Throw exception if exponent is not interger
						throw std::invalid_argument(
							"Exponent must be interger \n");
					}
				}
				else
				{
					throw std::invalid_argument("Only '^' can be used after variable \n");
				}
			}
		}
		else
		{
			// Make sure always to break while loop or else 
			// infinite loop can be possibly caused
			throw std::invalid_argument(
				"Unknown variable error \n");
		}
	}

}

//----------------------------------addImplicitOneToCoefficient
// Implementation Note:
//		Add back the implicit coefficient of 1 even user did not
//		type in 1 explicitly
//-------------------------------------------------------------
void NumberTerm::addImplicitOneToCoefficient(string& numberTerm)
{
	// Add back implicit coefficient to the string
	if (numberTerm[0] == '+' ||
		numberTerm[0] == '-')
	{
		// If the first character is +/-
		// and it is immediately followed by a
		// letter, the coefficient is implied
		// to be 1
		if (isalpha(numberTerm[1]))
		{
			numberTerm.insert(1, "1");
		}
	}

	if (isalpha(numberTerm[0]))
	{
		// If the first charcter is a letter,
		// the coefficient is also implied 
		// to be 1 (unless it is invalid
		// coefficient like sq12r
		numberTerm.insert(0, "1");
	}
}
//--------------------------------extractAllNumbersBeforeLetter
// Implementation Note:
//		
//-------------------------------------------------------------
float NumberTerm::extractAllNumbersBeforeLetter(string& numberTerm)
{
	int coefficientLength = 0;

	for (int index = 0;
		index < numberTerm.size();
		index++)
	{
		if (isdigit(numberTerm[index]) ||
			numberTerm[index] == '.' ||
			numberTerm[index] == '+' ||
			numberTerm[index] == '-')
		{
			coefficientLength++;
		}

		if (isalpha(numberTerm[index]))
		{
			// As soon as a letter show up, the number found
			// is not coefficient. Escape from the for-loop
			break;
		}
	}

	// Extract the coefficient string from the whole string
	const string coefficientString =
		numberTerm.substr(0, coefficientLength);

	if (coefficientLength == 0)
	{
		// there is always a coefficient, the 
		// coefficient is either 1 or other floating 
		// point value
		abort();
	}

	// Convert string into float
	string::size_type sz;

	const float coefficient
		= std::stof(coefficientString, &sz);

	// Remove the coefficient from the string
	numberTerm.erase(0, coefficientLength);

	return coefficient;
}
//---------------------------------------------------------CTOR
// Implementation Note:
//		
//-------------------------------------------------------------
NumberTerm::NumberTerm()
{
	// To be used privately for operator+
}
