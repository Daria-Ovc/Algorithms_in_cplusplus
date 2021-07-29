#include <iostream>
#include <ctime>
using namespace std;

// размер массива
const int N = 20;


// ПУЗЫРЕК
void Puz(int* a)
{
	bool f = 1;
	for (int k = 0; k < N && f; k++)
	{
		f = 0;
		for (int i = 0; i < N - k - 1; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				f = 1;
			}
	}
}


// ШЕЙКЕР
void Sheiker(int* a)
{
	bool b = true;

	for (int k = 0; k < N / 2 && b; k++)  //внешний цикл (количество проходов по массиву)
	{
		b = false; //флажочек

		for (int i = k; i < N - k - 1; i++)   //пузырек вправо
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				b = true;
			}

		b = false;

		for (int i = N - k - 1; i > k; i--)   //пузырек влево
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				b = true;
			}
	}
}


// МЕТОД ПАРНЫХ СРАВНЕНИЙ
void ParSrav(int* a)
{
	bool f = 1;
	while (f)
	{
		f = 0;
		for (int i = 0; i < N - 1; i += 2)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				f = 1;
			}
		for (int i = 1; i < N - 1; i += 2)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				f = 1;
			}
	}
}


// ЧЕЛНОЧНАЯ СОРТИРОВКА
void Chelnoch(int* a)
{
	for (int i = 0; i < N - 1; i++)
		if (a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
			for (int k = i; a[k] < a[k - 1] && k != 0; k--)
				swap(a[k], a[k - 1]);
		}
}


// БЫСТРАЯ СОРТИРОВКА
void Hoar(int* a, int first, int last)
{
	int i = first, j = last;
	int f = a[(i + j) / 2];

	do
	{
		while (a[i] < f)
			i++;
		while (a[j] > f)
			j--;

		if (i <= j)
		{
			if (i < j)
				swap(a[i], a[j]);
			i++;
			j--;

		}
	} while (i <= j);

	if (i < last)
		Hoar(a, i, last);
	if (j > first)
		Hoar(a, first, j);
}



void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	// Создание массива и его копии (копия нужна для восстановления 
	// изначального порядка после работы очередной сортировки)

	int a[N], a2[N];

	cout << "Изначальный массив:" << endl;
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		a2[i] = a[i];
		cout << a[i] << '\t';
	}
	cout << endl;


	//Работа сортировок:


	cout << "Пузырек:" << endl;
	Puz(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Шейкер-сортировка:" << endl;
	Sheiker(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Сортировка парными сравнениями:" << endl;
	ParSrav(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Челночная сортировка:" << endl;
	Chelnoch(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Быстрая сортировка, сортировка Хоара:" << endl;
	Hoar(a, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	system("pause");
}