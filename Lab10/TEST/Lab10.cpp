#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

extern "C" int ArraySum(float* array1, float* array2, float* result, int size);
extern "C" int ArraySub(float* array1, float* array2, float* result, int size);
extern "C" int ArrayMnozh(float* array1, float* array2, float* result, int size);
extern "C" int ArrayDiv(float* array1, float* array2, float* result, int size);
extern "C" int TestSum(float* array1, float* array2, float* result, int size);


void PrintArray(float arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}

int main() {
    SetConsoleOutputCP(1251);
    const int size = 4;
    float array1[size] = { 1.0, 2.0, 3.0, 4.0};
    float array2[size] = { 6.0, -7.0, 8.0, 9.0};
    float result[size] = { 0.0, 0.0 ,0.0, 0.0};

    cout << "Сумма" << '\n';
    ArraySum(array1, array2, result, size);
    PrintArray(result, size);

    cout << '\n' <<  "Разность" << '\n';
    ArraySub(array1, array2, result, size);
    PrintArray(result, size);

    cout << '\n' << "Умножение" << '\n';
    ArrayMnozh(array1, array2, result, size);
    PrintArray(result, size);

    cout << '\n' << "Деление" << '\n';
    ArrayDiv(array1, array2, result, size);
    PrintArray(result, size);

    return 0;
}