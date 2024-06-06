#include <iostream>
#include <Windows.h>
using namespace std;

extern "C"  int AddFloats(float* a, float* b, float* mnozh, float* div);

int main()
{
    SetConsoleOutputCP(1251);

    float a = 2.5;
    float b = 2.0;
    float mnozh;
    float div;

    float result = AddFloats(&a, &b, &mnozh, &div);

    cout << "Сумма чисел = " << b << endl;
    cout << "Умножение чисел = " << mnozh << endl;
    cout << "Деление чисел = " << div << endl;

    return 0;
}

