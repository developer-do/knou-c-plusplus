#include <iostream>

using namespace std;

int main() {
	float fArray[4];
	int i = 0;
	fArray[i] = 10.0f;
	cin >> fArray[1] >> fArray[2] >> fArray[3];
	cout << fArray[1] * fArray[2];
	return 0;
}