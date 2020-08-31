#include <iostream>
using namespace std;

int main()
{
	const double PI{ 3.14159 };
	double redius;

	cout << "원의 반경을 입력하시오 : ";
	cin >> redius;

	double area = redius * redius * PI;
	cout << "원의 면적 = " << area << endl;
	return 0;
}