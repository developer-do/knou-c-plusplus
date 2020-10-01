#pragma once
class CharStack
{
	enum { size = 20 }; // ������ ũ��
	int top;			// ������ �����͸� ����Ű�� ������
	char buf[size];		// ������ �������
public:
	CharStack() : top{size} {} // ������

	bool chkEmpty() const { // ���ؿ� �����Ͱ� ������ true
		return top == size;
	}

	bool chkFull() const { // ������ ���� �� ������ true
		return !top;
	}

	bool push(char ch);		// ���ÿ��� �����͸� ����
	char pop();				// ���ÿ��� �����͸� ����
};

