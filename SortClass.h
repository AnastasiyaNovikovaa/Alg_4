#pragma once
#include <stdexcept>
#include <iostream>


class Array  //Наш класс
{
public:
	void Create(int *&Arr, const int N); //Метод выделения памяти под массив
	void Delete(int *Arr);  //Метод освобождения памяти
	void Fill(int *Arr, const int N); //Метод заполнения массива значениями
	void Show(int *Arr, const int N);//Метод отображения массива на экране
	void heapSort(int *Arr, int N);
	int binarySearch(int *Arr, int N, int searchelem);
	int *quickSort(int *Arr,size_t N);
	void bubble_sort(int *Arr, int N);
	void Bogo_sort(int *Arr, int N);
	void CharCreate(char *&Arr, const int N);
	void CharFill(char *Arr, const int N);
	void CharShow(char *Arr, const int N);
	void CountingSort(char* Arr, int N);
};
void Array::Create(int *&Arr, const int N) //Вне класса описываем метод выделения памяти под массив
{
	if (N > 0)
		Arr = new int[N];
	else
		std::cout << "Error in size of array ";
}
void Array::CharCreate(char *&Arr, const int N) //Вне класса описываем метод выделения памяти под массив
{
	setlocale(LC_ALL, "Russian");
	Arr = new char[N];
}
void Array::Delete(int *Arr)    //Вне класса описываем метод освобождения памяти
{
	delete[]Arr;    //очищаем память от массива
	Arr = NULL;   //указываем, что теперь массив должен находится в новом зарезервированном месте и указывает вникуда
}
void Array::Fill(int *Arr, const int N)    // определяем функцию заполнения рандомного массива
{
	for (int i = 0; i < N; i++) Arr[i] = rand() % N + 1;
}
void Array::CharFill(char *Arr, const int N)    // определяем функцию заполнения рандомного массива
{
	char letter;
	std::cout << "Enter an array of char:\n";
	for (int i = 0; i < N; i++)
	{
		std::cin >> letter;
		Arr[i] = letter;
	}
}
void Array::CharShow(char *Arr, const int N)  //определяем функцию отображения массива на экране
{
	for (int i = 0; i < N; i++) std::cout << Arr[i] << "  ";
}
void Array::Show(int *Arr, const int N)  //определяем функцию отображения массива на экране
{
	for (int i = 0; i < N; i++) std::cout << Arr[i] << "  ";
}


 //Функция  формирования кучи
void createheap(int *Arr, int root, int bottom_row)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom_row) && (!done))
	{
		if (root * 2 == bottom_row)    // если мы в последнем ряду, 
			maxChild = root * 2;    // запоминаем левый потомок
		  // иначе запоминаем больший потомок из двух
		else if (Arr[root * 2] > Arr[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (Arr[root] < Arr[maxChild])
		{
			int swap = Arr[root]; // меняем их местами
			Arr[root] = Arr[maxChild];
			Arr[maxChild] = swap;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
// Функция сортировки на куче
void  Array::heapSort(int *Arr, int N)
{
	// Формируем нижний ряд пирамиды
	for (int i = (N / 2) - 1; i >= 0; i--)
		createheap(Arr, i, N - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = N - 1; i >= 1; i--)
	{
		int temp = Arr[0];
		Arr[0] = Arr[i];
		Arr[i] = temp;
		createheap(Arr, 0, i - 1);
	}
}

int Array::binarySearch(int *Arr, int N, int searchelem)
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

void Swap(int& firstelem, int& secondelem)//меняем элементы местами
{
	const int helpswap = firstelem;
	firstelem = secondelem;
	secondelem = helpswap;
}
int partition(int *Arr, int beginindex, int lastindex)
{
	const int last = Arr[lastindex];
	int i = beginindex - 1;
	for (int j = beginindex; j < lastindex; j++)
	{
		if (Arr[j] <= last)
		{
			i++;
			Swap(Arr[i], Arr[j]);
		}
	}
	Swap(Arr[lastindex], Arr[i + 1]);
	return i + 1;
}
int* Sort_part(int* Arr, int beginindex, int lastindex)
{
	if (beginindex < lastindex)
	{
		const int middleIndex = partition(Arr, beginindex, lastindex);
		Sort_part(Arr, beginindex, middleIndex - 1);
		Sort_part(Arr, middleIndex + 1, lastindex);
	}
	return Arr;
}

int* Array::quickSort(int* Arr,size_t N)
{
	const auto toIndex = N - 1;
	return Sort_part(Arr, 0, toIndex);
}
void Array::bubble_sort(int *Arr, int N)
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

void Array::Bogo_sort(int *Arr, int N)
{
	
		correct(Arr, N);
		shuffle(Arr, N);

		bogoSort(Arr, N);
}
void Array::CountingSort(char* Arr, int N)
{
		size_t* SortingArray = new size_t[127*2+1];//т.к. диапазон значений char-ов от -127 до 127
		for (int i = 0; i < 255; i++)
			SortingArray[i] = 0;
		for (int i = 0; i < N; i++)
		{
			int buffer = Arr[i];
			SortingArray[buffer]++;
		}
		int j = 0;

		for (int i = 0; i < 255; i++)
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


