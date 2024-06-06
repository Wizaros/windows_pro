#include <iostream>
#include <Windows.h>

using namespace std;
extern "C"  int MinMaxArr_(const int n, const int* arr, int* min, int* max);

int main()
{
	SetConsoleOutputCP(1251);
	int min, max;
	const int n = 10;
	const int arr[n] = { 12, 23, -3, 65, 7, 10, 0, 45, 5, 2 };
	MinMaxArr_(n, arr, &min, &max);

	cout << "Задан массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]= " << arr[i] << "\n";
	}

	cout << "\n\nМинимальное число: " << min << endl;
	cout << "Максимальное число: " << max << endl;

}