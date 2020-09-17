#include <iostream>
#include "Counter.h"
using namespace std;

int main() {
	Counter cnt;	// Counter 객체의 정의
	//cnt.reset();	// 계수기를 0으로 지움
	
	cout << "계수기의 현재 값 : " << cnt.getValue() << endl;
	cnt.count();	// 계수기를 현재값에서 1 증가시킴 
	cnt.count();	// 계수기를 현재값에서 1 증가시킴 

	cout << "계수기의 현재 값 : " << cnt.getValue() << endl;
	return 0;
}