// news360.cpp : Defines the entry point for the console application.
//

// standard library class
#include "stdafx.h"		// precompiled header
#include <iostream>		// For cout,cin
#include <stdio.h>      // For printf, scanf, puts, NULL
#include <string>		// String class
#include <sstream>		// String stream to convert float to string
#include <fstream>		// For file parsing


// Custom class 
#include "Evaluator.h"	// Number Term utility class

//--------------------forward function declaration
void screenStay(void);
//-------------------------------------------------


int main()
{
	// Repeat process until user press Ctrl+C to terminate
	// the progrma
	while (true)
	{
		bool isUserInputValid = false;
		std::string mode;
		std::cout << "Would you like to perform this in interactive mode or file mode?" << std::endl;
		std::cout << "Answer 'interactive' for interactive mode, 'file' for file mode" << std::endl;
		std::getline(std::cin, mode);

		std::string equation = "";

		if (mode == "file")
		{
			std::cout << "Which .txt you want to used? " << std::endl;

			// Parse in file
			std::string fileName = "";
			std::getline(std::cin, fileName);

			bool isFileOperationSuccessful = true;

			std::ifstream infile(fileName);

			if (!infile)
			{
				std::cout << "ERROR: File does not exist" << std::endl;
				isFileOperationSuccessful = false;
			}

			// Create an output file
			std::ofstream outputFile;
			if (!outputFile)
			{
				std::cout << "ERROR: File could not be created" << std::endl;
				isFileOperationSuccessful = false;
			}

			if (isFileOperationSuccessful)
			{
				outputFile.open("outputFile.out");

				while (std::getline(infile, equation))
				{
					// Check for invalid user input
					try
					{
						// Split the whole string equation into
						// mulitple NumberTerm objects 
						Evaluator individualEquationEvaluator(equation);

						isUserInputValid = true;

						outputFile << individualEquationEvaluator.viewCanonicalEquation();

					}
					catch (const std::invalid_argument& e)
					{
						outputFile << equation;
						outputFile << "\t -->ERROR:";
						outputFile << e.what();
						outputFile << "\n";
					}
				}

				outputFile.close();
				std::cout << "Done. Output is in output.out \n\n";
			}
			else
			{
				std::cout << "File operation fails. Please try again" << std::endl;
			}
		}
		else if (mode == "interactive")
		{
			std::cout << "Please type in the equation you want to change into canonical form: " << std::endl;
			std::getline(std::cin, equation);

			while (!isUserInputValid)
			{
				// Check for invalid user input
				try
				{
					// Split the whole string equation into
					// mulitple NumberTerm objects 
					Evaluator individualEquationEvaluator(equation);

					isUserInputValid = true;

					std::cout << "Answer: " +
						individualEquationEvaluator.viewCanonicalEquation();

					// Add an extra new line to better visual representation
					std::cout << "\n";
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << e.what();
					std::cout << "Please enter your equation again " << std::endl;
					std::getline(std::cin, equation);
				}
			}
		}
		else
		{
			std::cout << "Invalid option, please enter again " << std::endl;
		}

	}

	return 0;
}

//---------------------------------------------------screenStay
// Implementation Note:
//	 To ensure the console application won't 
//   close itself after displaying the answer
//-------------------------------------------------------------
void screenStay(void)
{
	using namespace std;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}