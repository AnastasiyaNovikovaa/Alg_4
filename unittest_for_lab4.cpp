#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>

#include "../Laba_4_alg/SortClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_for_laba4
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Correct_HeapSort_size10)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 10;

			Massiv.Create(Ptr1, N);
			Ptr1[0] = 1;
			Ptr1[1] = 3;
			Ptr1[2] = 7;
			Ptr1[3] = 15;
			Ptr1[4] = 2;
			Ptr1[5] = 9;
			Ptr1[6] = 10;
			Ptr1[7] = 11;
			Ptr1[8] = 5;
			Ptr1[9] = 8;


			Massiv.heapSort(Ptr1, N);

			Assert::IsTrue(correct(Ptr1,N));
		}
		
		TEST_METHOD(Correct_QuickSort_size_firstelem)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.Create(Ptr1, N);
			Ptr1[0] = 6;
			Ptr1[1] = 2;
			Ptr1[2] = 9;
			Ptr1[3] =1;
			Ptr1[4] = 4;
			Massiv.quickSort(Ptr1, N);

			Assert::IsTrue(Ptr1[0]==1);
		}
		TEST_METHOD(Correct_QuickSort_size15)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 15;
			Massiv.Create(Ptr1, N);
			Massiv.Fill(Ptr1, N);
			Massiv.quickSort(Ptr1,N);

			Assert::IsTrue(correct(Ptr1, N));
		}
	
		TEST_METHOD(Correct_bubble_sort_size15)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 15;
			Massiv.Create(Ptr1, N);
			Massiv.Fill(Ptr1, N);
			Massiv.bubble_sort(Ptr1, N);

			Assert::IsTrue(correct(Ptr1, N));
		}
		
		TEST_METHOD(Correct_Bogo_sort_size15)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.Create(Ptr1, N);
			Massiv.Fill(Ptr1, N);
			Massiv.Bogo_sort(Ptr1, N);

			Assert::IsTrue(correct(Ptr1, N));
		}
		
		TEST_METHOD(Correct_CountingSort_size5)
		{
			char A[5] = { 'a', 'b', 'c','d','e' };
			char *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.CharCreate(Ptr1, N);      //выдел€ю пам€ть дл€ N элементов
			Ptr1[0] = 'c';
			Ptr1[1] = 'a';
			Ptr1[2] = 'd';
			Ptr1[3] = 'e';
			Ptr1[4] = 'b';
			Massiv.CountingSort(Ptr1, N);
			int exit = 1;
			for (int i = 0; i < 5; i++)
			{
				if (A[i] != Ptr1[i])
					exit = 0;
			}
			Assert::IsTrue(exit);

		}
		TEST_METHOD(Correct_CountingSort_firstelem)
		{
			char *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.CharCreate(Ptr1, N);      //выдел€ю пам€ть дл€ N элементов
			Ptr1[0] = 'c';
			Ptr1[1] = 'a';
			Ptr1[2] = 'd';
			Ptr1[3] = 'e';
			Ptr1[4] = 'b';
			Massiv.CountingSort(Ptr1, N);
			Assert::IsTrue(Ptr1[0]=='a');

		}
		TEST_METHOD(SearchElem_size5_found)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.Create(Ptr1, N);
			Ptr1[0] = 5;
			Ptr1[1] = 3;
			Ptr1[2] = 8;
			Ptr1[3] = 1;
			Ptr1[4] = 7;

			Massiv.heapSort(Ptr1, N);
			int searchelem = 5;

			int index = Massiv.binarySearch(Ptr1, N, searchelem);

			Assert::IsTrue(index == 2);

		}
		TEST_METHOD(SearchElem_size5_not_found)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 5;
			Massiv.Create(Ptr1, N);
			Ptr1[0] = 5;
			Ptr1[1] = 3;
			Ptr1[2] = 8;
			Ptr1[3] = 1;
			Ptr1[4] = 7;

			Massiv.heapSort(Ptr1, N);
			int searchelem = 2;

			int index = Massiv.binarySearch(Ptr1, N, searchelem);

			Assert::IsTrue(index == -1);

		}
		TEST_METHOD(Create_size0)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = 0;
			Massiv.Create(Ptr1, N);
			
			try
			{
				Massiv.Create(Ptr1, N);
			}

			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Error in size of array", error.what());
			}
		}
		TEST_METHOD(Create_size_otr)
		{
			int *Ptr1 = NULL;
			Array Massiv;
			int N = -5;
			
			try
			{
				Massiv.Create(Ptr1, N);
			}

			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Error in size of array", error.what());
			}
		};

	};
}