﻿#include "pch.h"
#include "CppUnitTest.h"
#include "..\12.4\12.4IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* test;
			test = new Elem;
			test->info = -2;
			test->link = new Elem;
			test->link->info = -2;
			test->link->link = new Elem;
			test->link->link->info = 3;
			test->link->link->link = new Elem;
			test->link->link->link->info = -2;
			test->link->link->link->link = test;

			Assert::AreEqual(3, Count(test, -2));
		}
	};
}
