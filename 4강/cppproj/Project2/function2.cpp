#include <iostream>
using namespace std;

double variance(const double arr[], int n) {
	double sum = 0, sqSum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		sqSum += arr[i] * arr[i];
	}
	return sqSum / n - sum * sum / (n * n);
}

int main() {
	double a[50], b[100];

	for (int i = 0; i < 100; i++) {
		if (i < 50) {
			a[i] = i;
		}
		b[i];
	}
	cout << variance(a, 50) << endl;
	cout << variance(b, 100) << endl;
}