#pragma once
#include <stdexcept>
#include <iostream>
#include "../../Laba3_3(alg)/Laba3_3(alg)/Tree.h"
#include "../../Laba3_3(alg)/Laba3_3(alg)/Tree.cpp"

class Massiv  //Наш класс
{
public:
	void Create(int *&Arr, const int N); //Метод выделения памяти под массив
	void Delete(int *Arr);  //Метод освобождения памяти
	void Fill(int *Arr, const int N); //Метод заполнения массива значениями
	void Show(int *Arr, const int N);//Метод отображения массива на экране
	int* heapSort(int *Arr, int N);
	int binarySearch(int *Arr, int N, int searchelem);
	void quickSort(int *Arr, int left, int N);
	void bubble_sort(int *Arr, int N);
	void Bogo_sort(int *Arr, int N);
	void CharCreate(char *&Arr, const int N);
	void CharFill(char *Arr, const int N);
	void CharShow(char *Arr, const int N);
	void CountingSort(char* Arr, int N);
};
void Massiv::Create(int *&Arr, const int N) //Вне класса описываем метод выделения памяти под массив
{
	if (N > 0)
		Arr = new int[N];
	else
		std::cout << "Error in size of array ";
}
void Massiv::CharCreate(char *&Arr, const int N) //Вне класса описываем метод выделения памяти под массив
{
	setlocale(LC_ALL, "Russian");
	Arr = new char[N];
}
void Massiv::Delete(int *Arr)    //Вне класса описываем метод освобождения памяти
{
	delete[]Arr;    //очищаем память от массива
	Arr = NULL;   //указываем, что теперь массив должен находится в новом зарезервированном месте и указывает вникуда
}
void Massiv::Fill(int *Arr, const int N)    // определяем функцию заполнения рандомного массива
{
	for (int i = 0; i < N; i++) Arr[i] = rand() % N + 1;
}
void Massiv::CharFill(char *Arr, const int N)    // определяем функцию заполнения рандомного массива
{
	char letter;
	std::cout << "Enter an array of char:\n";
	for (int i = 0; i < N; i++)
	{
		std::cin >> letter;
		Arr[i] = letter;
	}
}
void Massiv::CharShow(char *Arr, const int N)  //определяем функцию отображения массива на экране
{
	for (int i = 0; i < N; i++) std::cout << Arr[i] << "  ";
}
void Massiv::Show(int *Arr, const int N)  //определяем функцию отображения массива на экране
{
	for (int i = 0; i < N; i++) std::cout << Arr[i] << "  ";
}

int* Massiv::heapSort(int *Arr, int N)
{
	auto A = new Tree();
	for (int i = 0; i < N; i++)
		A->insert(Arr[i]);
	int i = 0;
	Iterator* biterator1 = A->Bcreate_iterator();

	while (biterator1->has_next())

	{
		Arr[i++] = biterator1->next();
    }
	
	return Arr;
	
}
int Massiv::binarySearch(int *Arr, int N, int searchelem)
{
	
		int left = 0;
		int right = N - 1;
		int search = -1;
		while (left <= right) // пока левая граница не "перескочит" правую
		{
			int mid = (left + right) / 2; // ищем середину отрезка
			if (searchelem == Arr[mid]) { // если ключевое поле равно искомому
				search = mid; // мы нашли требуемый элемент,
				break; // выходим из цикла
			}
			if (searchelem < Arr[mid]) // если искомое ключевое поле меньше найденной середины
				right = mid - 1; // смещаем правую границу, продолжим поиск в левой части
			else // иначе
				left = mid + 1; // смещаем левую границу, продолжим поиск в правой части
		}
		if (search == -1) // если индекс элемента по-прежнему -1, элемент не найден
		{
			std::cout << "Element not found!\n";
			return -1;
		}
		else // иначе выводим элемент, его ключ и значение
		{
			std::cout << "Index in the array: " << search;
			return search;
		}
	
}
void Massiv::quickSort(int *Arr, int left, int N)
{
	int helpelem; // вспомогательный элемент, который в теории нам помогает
	int l_hold = left; //левая граница(Сюзанна)
	int r_hold = N; // правая граница(Владимир)
	helpelem = Arr[left];
	while (left < N) // пока Сюзанна и Владимир не встретятся
	{
		while ((Arr[N] >= helpelem) && (left < N))
			N--; // сдвигаем правую границу(Владимира) 
		if (left != N) // Сюзанна и Владимир все еще не вместе,какая жалость,делаем все,чтобы они были вместе
		{
			Arr[left] = Arr[N]; // сдвиги
			left++; 
		}
		while ((Arr[left] <= helpelem) && (left < N))
			left++; 
		if (left != N) // если все наши усилия напрасны, вызываем Гузееву
		{
			Arr[N] = Arr[left]; 
			N--;  
		}
	}
	Arr[left] = helpelem; 
	helpelem = left;
	left = l_hold;
	N= r_hold;
	if (left < helpelem) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(Arr, left, helpelem - 1);
	if (N > helpelem)
		quickSort(Arr, helpelem + 1, N);
	//когда-то это сработает.А вообще Сюзанне стоит поискать Владимира посговорчивей. 
}
void Massiv::bubble_sort(int *Arr, int N)
{
	int i = 0;
	int buf;
	char swap_cnt = 0;

	if (N == 0)
		std::cout << "array is empty";
	while (i < N)
	{
		if (i + 1 != N && Arr[i] > Arr[i + 1])
		{
			buf = Arr[i];
			Arr[i] = Arr[i + 1];
			Arr[i + 1] = buf;
			swap_cnt = 1;
		}
		i++;
		if (i == N && swap_cnt == 1)
		{
			swap_cnt = 0;
			i = 0;
		}
	}
}
int correct(int *Arr, int N)
{
	if (N <= 0)
		return 0;
	else
	{
		while (--N > 0)
			if (Arr[N - 1] > Arr[N])
				return 0;
		return 1;
	}
}
void shuffle(int *Arr, int N) {
	int i;
	for (i = 0; i < N; ++i)
		std::swap(Arr[i], Arr[(rand() % N)]);
}
void bogoSort(int *Arr, int N)
{
	while (!correct(Arr, N))
		shuffle(Arr, N);
}

void Massiv::Bogo_sort(int *Arr, int N)
{
	
		correct(Arr, N);
		shuffle(Arr, N);

		bogoSort(Arr, N);
}
void Massiv::CountingSort(char* Arr, int N)
{
		size_t* SortingArray = new size_t[127];
		for (int i = 0; i < 127; i++)
			SortingArray[i] = 0;
		for (int i = 0; i < N; i++)
		{
			int buffer = Arr[i];
			SortingArray[buffer]++;
		}
		int j = 0;

		for (int i = 0; i < 127; i++)
		{
			while (SortingArray[i] != 0)
			{
				char c = i;
				Arr[j] = c;
				j++;
				SortingArray[i]--;
			}
		}
}

