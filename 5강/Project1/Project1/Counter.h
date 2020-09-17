#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

class Counter {				// 클래스 Counter의 선언 시작
	int value;				// private
public:
	Counter() : value{0} { }
	void reset() {			// 계수기의 값을 0으로 지움
		value = 0;
	}
	void count() {			// 계수기의 값을 1 증가시킴
		++value;
	}
	int getValue() const {	// 계수기의 현재 값을 반환함
		return value;
	}
};


#endif // COUNTER_H_INCLUDED

