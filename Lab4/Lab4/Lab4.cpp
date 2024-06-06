#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
extern "C" unsigned int IntegerLogical_(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
extern "C" unsigned int g_Val1 = 0;
unsigned int IntegerLogicalCpp(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	// Вычисление (((a & b) | c ) ^ d) + g_Val1
	const char nl = '\n';
	cout << "a: " << bitset<8>(a) << nl;
	cout << "b: " << bitset<8>(b) << nl;
	cout << "c: " << bitset<8>(c) << nl;
	cout << "d: " << bitset<8>(d) << nl << nl;

	unsigned int t1 = a & b;
	cout << "t1: " << bitset<8>(t1)<< nl;
	unsigned int t2 = t1 | c;
	cout << "t2: " << bitset<8>(t2) << nl;
	unsigned int t3 = t2 ^ d;
	cout << "t3: " << bitset<8>(t3) << nl << nl;
	unsigned int result = t3 + g_Val1;
	return result;
}
void PrintResult(unsigned int a, unsigned int b, unsigned int c, unsigned
	int
	d, unsigned val1, unsigned int r1, unsigned int r2)
{
	const int w = 8;
	const char nl = '\n';
	//cout << s << nl;
	cout << setfill('0');
	cout << "a = 0x" << hex << setw(w) << a << " (" << dec << a << ")" << nl;
	cout << "b = 0x" << hex << setw(w) << b << " (" << dec << b << ")" << nl;
	cout << "c = 0x" << hex << setw(w) << c << " (" << dec << c << ")" << nl;
	cout << "d = 0x" << hex << setw(w) << d << " (" << dec << d << ")" << nl;
	cout << "val1 = 0x" << hex << setw(w) << val1 << " (" << dec << val1 << ")" << nl;
	cout << "r1 = 0x" << hex << setw(w) << r1 << " (" << dec << r1 << ")" << nl;
	cout << "r2 = 0x" << hex << setw(w) << r2 << " (" << dec << r2 << ")" << nl;
	cout << nl;
	if (r1 != r2)
		cout << "Ошибка сравнения" << nl;
}
int main()
{
	unsigned int a, b, c, d, r1, r2 = 0;
	a = 0x00223344;
	b = 0x00775544;
	c = 0x00555555;
	d = 0x00998877;
	g_Val1 = 7;
	cout << "EXAMPLE 1" << '\n';
	r1 = IntegerLogicalCpp(a, b, c, d);
	r2 = IntegerLogical_(a, b, c, d);
	PrintResult(a, b, c, d, g_Val1, r1, r2);
	a = 0x70987655;
	b = 0x55555555;
	c = 0xAAAAAAAA;
	d = 0x12345678;
	g_Val1 = 23;
	cout << "EXAMPLE 2" << '\n';
	r1 = IntegerLogicalCpp(a, b, c, d);
	r2 = IntegerLogical_(a, b, c, d);
	PrintResult(a, b, c, d, g_Val1, r1, r2);
	return 0;
}
