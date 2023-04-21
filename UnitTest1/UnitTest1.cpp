#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.5/Lab_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char ch = 'o';
			bool t = isOperator(ch);
			Assert::AreEqual(t, false);
		}
	};
}
