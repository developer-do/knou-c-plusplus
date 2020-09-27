#include <iostream>
using namespace std;

int getMax(const int arr[], int len) {
	int max = INT_MIN;
	for (int i = 0; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	cout << "ÇÐ¹ø : 202034-364443" << endl;
	cout << "ÀÌ¸§ : ±èµµÇö" << endl << endl;

	int data[10] = { 10, 23, 5, 9, 22, 48, 12, 10, 55, 31 };

	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	cout << endl << endl;
	cout << "ÃÖ´ñ°ª = " << getMax(data, 10) << endl;

	return 0;
}