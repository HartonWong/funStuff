#pragma once
#include <string>
#include <list>		//	To use list
#include <map>		//  Using map to save variables

//------------------------------------------------- NumberTerm
//	Description:
//		Split up the string object into corresponding coefficient
//		part and variable part. 
//		Provide basic opertaion of the number term, such as 
//		comparing like term and adding up like terms
//	
//	Note: 
//		Terminology, the word "extract" used in function
//		name implies the string will also be removed from the 
//		passed in string
//-------------------------------------------------------------
class NumberTerm
{
	typedef std::string string;
public:

	typedef std::list<NumberTerm> List;
	typedef std::map<char, int> Map;

	//-----------------------------------------------------------//
	//------------------Public Function -------------------------//
	//-----------------------------------------------------------//

	//------------------------------------------------- constructor
	//	Description:
	//		Create a NumberTerm object using a const string
	//-------------------------------------------------------------
	NumberTerm(	const string numberTerm,
				const bool isRhsOfEquation);

	//---------------------------------------------------Destructor
	// Description:
	//		Clear out private member variables, if required.	
	//--------------------------------------------------------------
	virtual ~NumberTerm();

	//------------------------------------------------- isLikeTerm
	//	Description:
	//		Return if the passed in term is a like term 
	//      to the current term
	//	Argument:
	//		rhs	-	terms to be compared with this object
	//-------------------------------------------------------------
	const bool isLikeTerm(const NumberTerm &rhs) const;

	//--------------------------------------------- viewCoefficient
	//	Description:
	//		Return the const value of coefficient to caller
	//-------------------------------------------------------------
	const float viewCoefficient(void) const;

	//--------------------------------------------- viewVariablesMap
	//	Description:
	//		Return the const reference of variables map to caller
	//-------------------------------------------------------------
	const NumberTerm::Map& viewVariablesMap(void) const;

	//-----------------------------------------------------------//
	//------------------Public Operator Function ----------------//
	//-----------------------------------------------------------//
	friend NumberTerm operator+(const NumberTerm &lhs, const NumberTerm &rhs);

private:
	//-----------------------------------------------------------//
	//------------------Private Function ------------------------//
	//-----------------------------------------------------------//

	//-------------------------------------------default constructor
	//	Description:
	//		To be used privately for operator+
	//-------------------------------------------------------------
	NumberTerm();

	//-------------------------------------------extractCoefficient
	//	Description:
	//		Extract the coefficient from the whole string object
	//		and save such coefficient to member variable
	//	Argument:
	//		numberTerm	-	The whole string object that includes both 
	//						the variables and coefficient
	//-------------------------------------------------------------
	void extractCoefficient( string& numberTerm,
							 const bool isRhsOfEquation);

	//---------------------------------------------extractVariables
	//	Description:
	//		Extract the variables from the whole string object
	//		and save such variables to member variable
	//	Argument:
	//		numberTerm	-	The whole string object that includes both 
	//						the variables and coefficient
	//------------------------------------------------------------
	void extractVariables(string& numberTerm);

	//-----------------------------------addImplicitOneToCoefficient
	//	Description:
	//		Add back the implicit coefficient of 1 even user did not
	//		type in 1 explicitly
	//	Argument:
	//		numberTerm	-	The whole string object that includes both 
	//						the variables and coefficient
	//-------------------------------------------------------------
	void addImplicitOneToCoefficient(string & numberTerm);

	//---------------------------------extractAllNumbersBeforeLetter
	//	Description:
	//		Get all the numbers,including +,-,. sign before the next
	//		letter show up
	//	Argument:
	//		numberTerm	-	the string that contains both number and 
	//						letters
	//-------------------------------------------------------------
	float extractAllNumbersBeforeLetter(string & numberTerm);

	//-----------------------------------------------------------//
	//------------------Private Member Variables ----------------//
	//-----------------------------------------------------------//

	// the floating point coefficient of the number term
	float m_nCoefficient;	

	// the variables part of the number term
	NumberTerm::Map m_nVariables;

};

