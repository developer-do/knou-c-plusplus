#include <iostream>
using namespace std;

int main() {
	int max;
	int data[10] = { 10, 23, 5, 9, 22, 49, 12, 10, 55, 31 };

	max = data[0]; // data의 0번값을 max로 가정
	// cout << "데이터 : " << data[0];	// 0번 데이터 출력
	cout << "max 데이터 : " << max;	// 0번 데이터 출력
	for (int i = 1; i < 10; i++) { // 나머지 9개의 데이터 비교
		cout << "\n 현재 max 데이터 " << max;	// i번 데이터 출력
		if (max < data[i]) max = data[i]; // i번 데이터 비교
	}
	cout << "\n\n배열의 최댓값 : " << max << endl;
	return 0;
}