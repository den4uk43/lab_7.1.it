#include "pch.h"
#include "CppUnitTest.h"
#include "/ap_labs/lab7.1.it/lab7.1.it/lab7.1.it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodCalc)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Тестова матриця
			//  -4 (не задовольняє)   5 (додатне)       -3 (непарне)
			//   0 (не задовольняє)  -2 (не задовольняє) 4 (додатне)
			a[0][0] = -4; a[0][1] = 5;  a[0][2] = -3;
			a[1][0] = 0;  a[1][1] = -2; a[1][2] = 4;

			int S = 0;
			int k = 0;
			Calc(a, rowCount, colCount, S, k);

			// Перевірка кількості (k = 3) та суми (S = 5 + (-3) + 4 = 6)
			Assert::AreEqual(k, 3);
			Assert::AreEqual(S, 6);

			// Перевірка заміни відповідних елементів нулями
			Assert::AreEqual(a[0][1], 0);
			Assert::AreEqual(a[0][2], 0);
			Assert::AreEqual(a[1][2], 0);

			// Перевірка елемента, який не змінився
			Assert::AreEqual(a[0][0], -4);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
