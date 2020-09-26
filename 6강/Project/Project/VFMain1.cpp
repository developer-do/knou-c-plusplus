#include <iostream>
using namespace std;
#include "VecF.h"


int main() {
    float a[3] = { 1,2,3 };
    float b[3] = { 2, 4, 6 };
    VecF v1(3, a); // 1,2,3을 저장하는 벡터
    VecF v2(3, b);   // v1을 복사하여 v2를 만듦
    VecF v3(v1.add(v2));
    VecF v4(v2.add(v3));
    v1.print();
    cout << endl;
    v2.print();
    cout << endl;
    v4.print();
    cout << endl;
    return 0;
}