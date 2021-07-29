#include <iostream>
#include <ctime>
using namespace std;

// Array size:
const int N = 20;


// Bubble sort:
void Bubble(int* a)
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


// Cocktail sort:
void Shaker(int* a)
{
	bool b = true;

	for (int k = 0; k < N / 2 && b; k++)
	{
		b = false;

		for (int i = k; i < N - k - 1; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				b = true;
			}

		b = false;

		for (int i = N - k - 1; i > k; i--)
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				b = true;
			}
	}
}


// Paired comparison method:
void Paired(int* a)
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


// Shuttle sort:
void Shuttle(int* a)
{
	for (int i = 0; i < N - 1; i++)
		if (a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
			for (int k = i; a[k] < a[k - 1] && k != 0; k--)
				swap(a[k], a[k - 1]);
		}
}


// Quicksort:
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
	srand(time(0));

	// Creation of an arrayand its copy (a copy is needed to 
	// restore the original order after the next sorting):

	int a[N], a2[N];

	cout << "Initial array:" << endl;
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		a2[i] = a[i];
		cout << a[i] << '\t';
	}
	cout << endl;


	cout << "Bubble:" << endl;
	Bubble(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Shaker:" << endl;
	Shaker(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Paired comparison method:" << endl;
	Paired(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Shuttle sort:" << endl;
	Shuttle(a);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	cout << "Quicksort:" << endl;
	Hoar(a, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\t';
		a[i] = a2[i];
	}
	cout << endl;


	system("pause");
}