#include <iostream>
using namespace std;

int main()
{
	const double PI{ 3.14159 };
	double redius;

	cout << "���� �ݰ��� �Է��Ͻÿ� : ";
	cin >> redius;

	double area = redius * redius * PI;
	cout << "���� ���� = " << area << endl;
	return 0;
}