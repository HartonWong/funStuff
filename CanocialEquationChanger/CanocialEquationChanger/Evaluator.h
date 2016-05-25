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
	//		
	//-------------------------------------------------------------
	Evaluator(const string equation);

	//---------------------------------------------------Destructor
	// Description:
	//		Clear out private member variables, if required.	
	//--------------------------------------------------------------
	virtual ~Evaluator();

	//--------------------------------------------- viewCanonicalEquation
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

	//------------------------------------------------- 
	//	Description:
	//		
	//      
	//	Argument:
	//		
	//-------------------------------------------------------------
	NumberTerm::List splitEquationIntoNumberTerms(
		const string equation);

	//------------------------------------------------- 
	//	Description:
	//		
	//      
	//	Argument:
	//		
	//-------------------------------------------------------------
	void combineEquation(
		NumberTerm::List&	numberTermList);

	//------------------------------------------------- 
	//	Description:
	//		
	//      
	//	Argument:
	//		
	//-------------------------------------------------------------
	const string convertListToString(
		const NumberTerm::List&	numberTermList);

	//------------------------------------------------- 
	//	Description:
	//		
	//      
	//	Argument:
	//		
	//-------------------------------------------------------------
	void addNumberTermToList(
		NumberTerm::List&	numberTermList,
		const string		numberTermString,
		const bool			isRhsOfEquation);

	//-----------------------------------------------------------//
	//------------------Private Member Variables ----------------//
	//-----------------------------------------------------------//
	string m_nCanonicalEqString;
};

