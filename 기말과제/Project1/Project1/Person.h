#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
class Person
{
	char* name;		// �̸��� �����ϴ� ������ ���
	char* addr;		// �ּҸ� �����ϴ� ������ ���
public:
	Person(const char* name, const char* addr);	// ������
	Person(const Person& cp) : name{ cp.name }, addr{ cp.addr } {} // ���� ������
	/* 
	* ��������ڴ� �����ڰ� ��������� �ʾƵ� �����Ϸ��� ���ؼ�
	* �ڵ����� default ��������� ��� ���� �����Ǿ� ����.
	* �� default ��������ڴ� ����� ��� ���縦 �Ѵ� ��� ������ �� �ִ�.
	* �׷��� ������ ���� �����ڰ� ��� ����� ����. 
	* ������ ��������ڸ� �����س��� ����� ������ �����شٸ� ������ ���� �� �� ������ �����ؾ� �Ѵ�.
	*/
	Person(Person&& cp) : name{ cp.name }, addr{ cp.addr } { // �̵�������
		cp.name = nullptr;
		cp.addr = nullptr;
	}
	~Person();	// �Ҹ���
	Person& operator=(const Person& cp);
	Person& operator=(Person&& cp);
	void print() const;		// �̸��� �ּ� ���
	void chAddr(const char* newAddr);	// �ּ� ����
};
#endif


