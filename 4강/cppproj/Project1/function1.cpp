#include <iostream>
using namespace std;

int main() {
    double a[50], b[100];
    //...... // 생략: a와 b에 각각 50개와 100개의 데이터 입력

    for (int i = 0; i < 100; i++) {
        if (i < 50) {
            a[i] = i;
        }
        b[i];
    }

    double sum = 0, sqSum = 0;
    for (int i = 0; i < 50; i++) {
        sum += a[i];
        sqSum += a[i] * a[i];
    }

    cout << sqSum / 50 - sum * sum / (50 * 50) << endl; // 분산
    sum = sqSum = 0;
    for (int i = 0; i < 100; i++) {
        sum += b[i];
        sqSum += b[i] * b[i];
    }

    cout << sqSum / 100 - sum * sum / (100 * 100) << endl;
}