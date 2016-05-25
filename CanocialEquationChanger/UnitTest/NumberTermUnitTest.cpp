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

		TEST_METHOD(emptyNumberTerm)
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

	};
}