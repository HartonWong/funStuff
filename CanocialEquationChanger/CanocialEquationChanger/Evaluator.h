#pragma once
#include <string>
#include "NumberTerm.h"	// Number Term utility class

class Evaluator
{
	typedef std::string string;

public:
	//-----------------------------------------------------------//
	//------------------Public Function -------------------------//
	//-----------------------------------------------------------//

	//------------------------------------------------- constructor
	//	Description:
	//		Convert the whole string equation into canocial equation
	//
	//-------------------------------------------------------------
	Evaluator(const string equation);

	//---------------------------------------------------Destructor
	// Description:
	//		Clear out private member variables, if required.	
	//--------------------------------------------------------------
	virtual ~Evaluator();

	//------------------------------------------ viewNumberTermList
	//	Description:
	//		Return the number list term for testing purpose
	//-------------------------------------------------------------
	const NumberTerm::List viewNumberTermList(void) const;

	//--------------------------------------- viewCanonicalEquation
	//	Description:
	//		Return the Canonical Equation to caller
	//-------------------------------------------------------------
	const string viewCanonicalEquation(void) const;

private:
	//-----------------------------------------------------------//
	//------------------Private Function ------------------------//
	//-----------------------------------------------------------//

	//-------------------------------------------default constructor
	//	Description:
	//		Abort when called
	//-------------------------------------------------------------

	Evaluator();

	//-----------------------------------splitEquationIntoNumberTerms
	//	Description:
	//		Change the equation into canonical form
	//		Check if same term exist, if so, add/minus the coefficient
	//	Argument:
	//		equation	-	the whole equation string that includes
	//						multiple number terms
	//-------------------------------------------------------------
	void splitEquationIntoNumberTerms(
		const string equation);

	//----------------------------------------------combineEquation 
	//	Description:
	//		Combine every like term in NumberTerm::List
	//      
	//	Argument:
	//		None
	//-------------------------------------------------------------
	void combineEquation();

	//----------------------------------------- convertListToString
	//	Description:
	//		Convert NumberTerm::List into 1 equation string
	//      
	//	Argument:
	//		None
	//-------------------------------------------------------------
	const string convertListToString();

	//----------------------------------------- addNumberTermToList
	//	Description:
	//		Add the number term string to the number term list
	//	Argument:
	//		numberTermString-	The number term string to be converted
	//								into NumberTerm object
	//		isRhsOfEquation	-	Required by NumberTerm construction
	//-------------------------------------------------------------
	void addNumberTermToList(
		const string		numberTermString,
		const bool			isRhsOfEquation);

	//-----------------------------------------------------------//
	//------------------Private Member Variables ----------------//
	//-----------------------------------------------------------//
	
	// The Return equation string
	string m_nCanonicalEqString;

	// The list that hold individuals number terms
	NumberTerm::List m_nNumberTermList;
};

