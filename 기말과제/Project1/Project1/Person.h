#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
class Person
{
	char* name;		// 이름을 저장하는 데이터 멤버
	char* addr;		// 주소를 저장하는 데이터 멤버
public:
	Person(const char* name, const char* addr);	// 생성자
	Person(const Person& cp) : name{ cp.name }, addr{ cp.addr } {} // 복사 생성자
	/* 
	* 복사생성자는 개발자가 만들어주지 않아도 컴파일러에 의해서
	* 자동으로 default 복사생성자 라는 것이 제공되어 진다.
	* 즉 default 복사생성자는 멤버대 멤버 복사를 한다 라고 추측할 수 있다.
	* 그렇기 때문에 복사 생성자가 없어도 상관이 없다. 
	* 하지만 복사생성자를 생성해놓고 제대로 설정을 안해준다면 쓰레기 값이 들어갈 수 있으니 유의해야 한다.
	*/
	Person(Person&& cp) : name{ cp.name }, addr{ cp.addr } { // 이동생성자
		cp.name = nullptr;
		cp.addr = nullptr;
	}
	~Person();	// 소멸자
	Person& operator=(const Person& cp);
	Person& operator=(Person&& cp);
	void print() const;		// 이름과 주소 출력
	void chAddr(const char* newAddr);	// 주소 변경
};
#endif


