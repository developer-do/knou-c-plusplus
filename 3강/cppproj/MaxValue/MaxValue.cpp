#include <iostream>
using namespace std;

int main() {
	int max;
	int data[10] = { 10, 23, 5, 9, 22, 49, 12, 10, 55, 31 };

	max = data[0]; // data�� 0������ max�� ����
	// cout << "������ : " << data[0];	// 0�� ������ ���
	cout << "max ������ : " << max;	// 0�� ������ ���
	for (int i = 1; i < 10; i++) { // ������ 9���� ������ ��
		cout << "\n ���� max ������ " << max;	// i�� ������ ���
		if (max < data[i]) max = data[i]; // i�� ������ ��
	}
	cout << "\n\n�迭�� �ִ� : " << max << endl;
	return 0;
}