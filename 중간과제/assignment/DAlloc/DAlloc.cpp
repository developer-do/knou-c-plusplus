#include <iostream>
using namespace std;

int main() {
	cout << "�й� : 202034-364443" << endl;
	cout << "�̸� : �赵��" << endl << endl;

	int* intPtr;
	intPtr = new int[4];
	*intPtr = 10;
	*(intPtr + 1) = 20;
	intPtr[2] = 30;
	intPtr[3] = 40;

	for (int* p = intPtr, i = 0; i < 4; i++) {
		cout << *p++ << " ";
	}

	cout << endl;

	delete[] intPtr;

	return 0;
}