#include <iostream>
#include "Counter.h"
using namespace std;

int main() {
	Counter cnt;	// Counter ��ü�� ����
	//cnt.reset();	// ����⸦ 0���� ����
	
	cout << "������� ���� �� : " << cnt.getValue() << endl;
	cnt.count();	// ����⸦ ���簪���� 1 ������Ŵ 
	cnt.count();	// ����⸦ ���簪���� 1 ������Ŵ 

	cout << "������� ���� �� : " << cnt.getValue() << endl;
	return 0;
}