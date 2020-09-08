#include <iostream>
#include <cmath>
using namespace std;
double Round(double x, int d = 0);

int main()
{
	double a;
	cout << "값 = ";
	cin >> a;
	cout << "반올림 --> " << Round(a) << endl;
	cout << "           " << Round(a, 1) << endl;
	cout << "           " << Round(a, 2) << endl;
	cout << "           " << Round(a, 3) << endl;
	return 0;
}

// 반올림 함수
// 인수 double x	: 반올림 할 값
//		int d		: 반올림하여 남길 소수 부분의 자릿수
// 반환 반올림한 값 (double)
double Round(double x, int d)
{
	double a = x >= 0 ? 0.5 : -0.5;
	double pow10 = pow(10, d);
	return trunc(x * pow10 + a) / pow10;
}