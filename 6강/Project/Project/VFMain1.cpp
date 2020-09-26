#include <iostream>
using namespace std;
#include "VecF.h"


int main() {
    float a[3] = { 1,2,3 };
    VecF v1(3, a); // 1,2,3을 저장하는 벡터
    VecF v2(v1);   // v1을 복사하여 v2를 만듦
    v1.print();
    cout << endl;
    //v2.print();
    //cout << endl;
    return 0;
}