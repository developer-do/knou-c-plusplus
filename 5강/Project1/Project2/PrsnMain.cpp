#include <iostream>
#include "Person.h"
using namespace std;

int main() {
	Person* p1 = new Person("이철수", "서울시 종로구");
	Person* p2 = new Person("박은미", "강원도 동해시");

	p1->print();
	p2->print();

	cout << endl << "주소 변경 : ";

	p2->chAddr("강원도 춘천시");
	p2->print();

	delete p1;
	delete p2;

	return 0;

}