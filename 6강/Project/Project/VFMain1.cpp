#include <iostream>
using namespace std;
#include "VecF.h"


int main() {
    float a[3] = { 1,2,3 };
    float b[3] = { 2, 4, 6 };
    VecF v1(3, a); // 1,2,3�� �����ϴ� ����
    VecF v2(3, b);   // v1�� �����Ͽ� v2�� ����
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