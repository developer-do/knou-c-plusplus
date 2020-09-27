#include <iostream>
using namespace std;

int main() {
	cout << "학번 : 202034-364443" << endl;
	cout << "이름 : 김도현" << endl;

	int data[10] = { 10, 23, 5, 9, 22, 48, 12, 10, 55, 31 };
	int max{ data[0] };

	cout << "데이터 : " << max;

	for (int i = 1; i < 10; i++) {
		cout << " " << data[i];
		if (max < data[i]) {
			max = data[i];
		}
	}

	cout << endl << endl;
	cout << "배열의 최댓값 : " << max << endl;

	return 0;
}