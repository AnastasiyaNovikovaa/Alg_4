﻿
#include "pch.h"
#include <iostream>
#include "SortClass.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <windows.h>

//using namespace std;


int main()
{
	int punkt;
	std::cout << "Hello! Laboratory work number 4\n";
	std::cout << "1. HeapSort\n";
	std::cout << "2. BinarySearch\n";
	std::cout << "3. QuickSort\n";
	std::cout << "4. BubbleSort\n";
	std::cout << "5. BogoSort\n";
	std::cout << "6. CountingSort\n";

	int *Ptr1 = NULL;
	char *Ptr6 = NULL;
	Array Array;            //объект массив типа массив (справа объект - слева тип)
	int N =10;
	Array.Create(Ptr1, N);      //выделяю память для N элементов
	Array.Fill(Ptr1, N); //Записываю в каждый элемент значение
 
	Array.Show(Ptr1, N);
	std::cout << "\n";
    std::cout << "Enter the number:";
	std::cin >> punkt;
    switch (punkt) {
		case 1:
		{
			Array.heapSort(Ptr1, N);
			std::cout << "Our random sorted with help heapSort array:\n";
			Array.Show(Ptr1, N);
			std::cout << "\n";

			break;
		}
		case 2:
		{   Array.bubble_sort(Ptr1, N);
		    std::cout << "Array after BubbleSort:\n";
		    Array.Show(Ptr1, N); 
			std::cout << " binarySearch array\n";
			int searchelem;
			std::cout << " Enter the searchelem:";
			std::cin >> searchelem;
			Array.binarySearch(Ptr1, N,searchelem);
			Array.Delete(Ptr1);
			break;
		}

		case 3:
		{
			std::cout << " QuickSort array\n";
			clock_t t = clock();
			Array.quickSort(Ptr1,N);
			t = clock() - t;
			printf("It took me %d clicks (%f seconds).\n", t, ((float)t / CLOCKS_PER_SEC));
			Array.Show(Ptr1, N);
			Array.Delete(Ptr1); 
			break;
		}

		case 4:
		{
			std::cout << " BubbleSort array\n";
			clock_t t = clock();
			t = clock();
			Array.bubble_sort(Ptr1, N);
			t = clock() - t;
			printf("It took me %d clicks (%f seconds).\n", t, ((float)t / CLOCKS_PER_SEC));
			Array.Show(Ptr1, N);
			Array.Delete(Ptr1); 
			break;
		}
		case 5:
		{
			std::cout << " BogoSort array\n";
			Array.Bogo_sort(Ptr1, N);
			Array.Show(Ptr1, N);
			Array.Delete(Ptr1); 
			break;
		}

		case 6:
		{
			Array.CharCreate(Ptr6, N);      //выделяю память для N элементов
			Array.CharFill(Ptr6, N);
			std::cout << "Our char array:\n";
			Array.CharShow(Ptr6, N);
			std::cout << "\n";
			std::cout << " CountingSort array:\n";
			Array.CountingSort(Ptr6, N);
			Array.CharShow(Ptr6, N);

			break;
		}

		default:
			std::cout << "Повторите ввод!" << std::endl;
			system("pause");
		}


	std::cout << "\n";
	system("PAUSE");
	return 0;


}


