#include "stdafx.h"
#include "Evaluator.h"
#include <sstream>		// String stream to convert float to string

//-----------------------------------------------------------//
//------------------Public Function -------------------------//
//-----------------------------------------------------------//
typedef std::string string;

//---------------------------------------------------------CTOR
// Implementation Note:
//		Convert the whole string equation into canocial equation
//-------------------------------------------------------------
Evaluator::Evaluator(const string equation)
{
	// Clear member variable before using it
	m_nNumberTermList.clear();
	
	this->splitEquationIntoNumberTerms(equation);

	// Modify the number term list to combine like terms
	this->combineEquation();

	m_nCanonicalEqString = this->convertListToString();
}
//--------------------------------------------------------DTOR
// Implementation Note:
//		Clear out private member variables, if required.
//-------------------------------------------------------------
Evaluator::~Evaluator()
{
	m_nNumberTermList.clear();
}
//----------------------------------------viewCanonicalEquation
// Implementation Note:
//		Return the const reference of coefficient to caller
//-------------------------------------------------------------
const string Evaluator::viewCanonicalEquation(void) const
{
	return m_nCanonicalEqString;
}
//-----------------------------------------------------------//
//------------------Private Function ------------------------//
//-----------------------------------------------------------//

//---------------------------------splitEquationIntoNumberTerms
// Implementation Note:
//	Change the equation into canonical form
//	Check if same term exist, if so, add/minus the coefficient
//-------------------------------------------------------------
void Evaluator::splitEquationIntoNumberTerms(
	const string equation)
{
	string temporartyStringHolder = "";
	bool isRhsOfEquation = false;

	for (const char& currentChar : equation)
	{
		switch (currentChar)
		{
		case '+':
		case '-':
		{
			if (temporartyStringHolder.empty())
			{
				// Do nothing as this implies the sign is 
				// used to denote positive or negative
				// for the first term
			}
			else
			{
				// Every other number term is seperated by
				// +/- sign, so add this number term
				// to the list
				addNumberTermToList(
					temporartyStringHolder,
					isRhsOfEquation);
			}

			// Reset the temporary string holder to 
			// current char
			temporartyStringHolder = currentChar;
			break;
		}

		case '=':
		{
			addNumberTermToList(
				temporartyStringHolder,
				isRhsOfEquation);

			// Set the flag after add the previous number term 
			// to the list
			isRhsOfEquation = true;

			// Reset the temporary string holder to 
			// empty when change to the rhs
			temporartyStringHolder = "";

			break;
		}
		case ' ':
		case '*':
		{
			// Do nothing
			// Automatically ignore whitespace
			// Automatically ignore * because the
			// system automatically implies muliplication
			// even user did not explicit use the symbol *
			break;
		}
		case '.':
		case '^':
		{
			// Appended expected mathmatical sign
			temporartyStringHolder = temporartyStringHolder + currentChar;
			break;
		}
		default:
		{
			if (isalnum(currentChar))
			{
				// Always append current alphanumeric character 
				// to temporary string holder
				temporartyStringHolder = temporartyStringHolder + currentChar;
			}
			else
			{
				throw std::invalid_argument("Invalid symbol used \n");
			}
			break;
		}
		}
	}

	if (!isRhsOfEquation)
	{
		// After looping through the whole equation, it must 
		// be on the rhs of the equation, or else it 
		// implies there is no equal sign in the equation. 
		throw std::invalid_argument("No equal sign in the equation \n");
	}

	// This add the last term to the number term list
	addNumberTermToList(temporartyStringHolder, isRhsOfEquation);
}

//-------------------------------------------addNumberTermToList
// Implementation Note:
//	Add the number term string to the number term list
//-------------------------------------------------------------
void Evaluator::addNumberTermToList(const string	numberTermString,
									const bool		isRhsOfEquation)
{
	try
	{
		// Create a number Term object for this number term
		NumberTerm numberTerm(numberTermString, isRhsOfEquation);

		// Add this newly created number term object into the list
		// such that we can combine terms later on
		m_nNumberTermList.emplace_back(numberTerm);
	}
	catch(const std::invalid_argument& e)
	{
		throw e;
	}
}

//----------------------------------------------combineEquation
// Implementation Note:
//	Change the equation into canonical form
//	Check if same term exist, if so, add/minus the coefficient
//-------------------------------------------------------------
void Evaluator::combineEquation()
{
	NumberTerm::List::iterator termIter = m_nNumberTermList.begin();
	while (termIter != m_nNumberTermList.end())
	{
		NumberTerm::List::const_iterator comparedTermIter = std::next(termIter, 1);
		while (comparedTermIter != m_nNumberTermList.end())
		{
			if (termIter->isLikeTerm(*comparedTermIter))
			{
				// If a match is found, combine both terms into the
				// current term
				*termIter = *termIter + *comparedTermIter;

				// Remove the compared term from the list since
				// it is already combined to the first term
				comparedTermIter = m_nNumberTermList.erase(comparedTermIter);

				// Don't increment iterator here since removing an entry 
				// automatically increment the iterator
			}
			else
			{
				// Increment the iterator to next one
				comparedTermIter++;
			}
		}
		termIter++;
	}
}

//----------------------------------------------convertListToString
// Implementation Note:
//	
//-------------------------------------------------------------
const string Evaluator::convertListToString()
{
	string wholeEquationString = "";

	for (const NumberTerm& individualTerm : m_nNumberTermList)
	{
		// Append +  if coefficient is positive
		const float coefficient = individualTerm.viewCoefficient();
		if (coefficient > 0.0f)
		{
			wholeEquationString += "+";
		}
		else
		{
			// Do nothing since negative float automatically
			// include negative sign
		}

		// Convert float point coefficient into string
		std::stringstream numberTermStream;
		numberTermStream << coefficient;

		// Append the coefficient to the whole Equation string
		wholeEquationString += numberTermStream.str();

		const NumberTerm::Map variableMap = individualTerm.viewVariablesMap();

		for (const auto& individualVariable : variableMap)
		{
			wholeEquationString += individualVariable.first;

			// Only append exponent index if exponent is not 1
			if (individualVariable.second != 1)
			{
				wholeEquationString += "^";
				wholeEquationString += std::to_string(individualVariable.second);
			}
		}
	}
	wholeEquationString += "= 0 \n";

	return wholeEquationString;
}

//----------------------------------------CTOR
// Implementation Note:
//		Return the const reference of coefficient to caller
//-------------------------------------------------------------
Evaluator::Evaluator()
{
}