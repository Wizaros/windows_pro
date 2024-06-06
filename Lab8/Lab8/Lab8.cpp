#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

extern "C" void CalcMatrix(int* row_sums, int* col_sums, const int* x, int nrows, int ncols);

void PrintArray(int arr[], int len, string what)
{
	cout << '\n';
	for (int i = 0; i < len; i++)
		cout << to_string(i + 1) + " " + what + " - " << arr[i] << '\n';
}


int main()
{
	SetConsoleOutputCP(1251);
	const int nrows = 4;
	const int ncols = 5;

	const int arr[nrows][ncols] =
	{
		{1,2,3,4,5},
		{6,7,8,-9,10},
		{-50,12,13,14,15},
		{16,17,18,19,20}
	};

	int row_sums_[nrows];
	int col_sums_[ncols];
	int* row_sums = row_sums_;
	int* col_sums = col_sums_;

	CalcMatrix(row_sums, col_sums, &arr[0][0], nrows, ncols);

	cout << "Сумма строк: ";
	PrintArray(row_sums, nrows, "строка");

	cout << "\nСумма колонок: ";
	PrintArray(col_sums, ncols, "столбец");

	return 0;
}