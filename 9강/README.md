# 9강. 연산자 다중정의 (2)



## 1. 대입 및 이동 대입 연산자

### (1) 대입 연산자의 다중정의 (1/2)

- 대입 연산자 (=)
  - 묵시적인 대입 연산자 : 우측 피연산자 데이터 멤버를 좌측 피연산자에 그대로 복사함
  - 객체에 동적 할당된 메모리를 가리키는 포인터가 포함되어 있을 경우 얕은 복사로 인해 의도하지 않은 공유 상태의 문제가 발생할 수 있음
    - 깊은 복사를 할 수 있는 대인 연산자를 다중정의할 필요가 있음



### (1) 대입 연산자의 다중정의 (2/2)

- 예 : VecF 클래스의 대입 연산자 다중정의

  ```c++
  VecF& VecF:: operator=(const VecF& fv) {
      if (n != fv.n) {				// 벡터의 크기가 다르다면
          delete[] arr;				// 기존 메모리를 반환하고
          arr = new float[n = fv.n];	// 새로 메모리를 할당함
      }
      memcpy(arr, fv.arr, sizeof(float) * n); // 데이터 복사
      return *this;
  }
  ```





### (2) 이동 대입 연산자의 다중정의 (1/2)

- 이동 대입 연산자 (=)
  - 좌측 피연산자에 대입할 우측 피연산자가 r-value일 때 사용됨
    - 대입 후 우측 피연산자의 내용이 더 이상 필요 없는 상황
  - 우측 피 연산자의 내용을 좌측 피연산자로 이동하여 불필요한 복사를 피함으로써 효율성을 높일 수 있음



### (2) 이동 대입 연산자의 다중정의 (2/2)

- 예 : VecF 클래스의 이동 대입 연산자 다중정의

  ```c++
  VecF& VecF::operator=(VecF&& fv) {
      delete[] arr; 	// 기존 메모리를 반환하고
      n = fv.n; 		// 우측 피연산자의 내용을 이동함
      arr = fv.arr;
      fv.arr = nullptr;
      return *this;
  }
  ```



### (3) 대입 및 이동 대입 연산자의 활용

- 예 : VFMain3.cpp

  ```c++
  int main()
  {
  	float a[3] = { 1, 2, 3 };
      float b[3] = { 2, 4, 6 };
      VecF v1(3, a);
      VecF v2(3, b);
      VecF v3(3);
      v3 = v1; // 대입 연산자
      cout << v3 << endl;
      v3 = v1.add(v2); // 이동 대입 연산자
      cout << v1 << " + " << v2 << " = ";
      cout << v3 << endl;
      return 0;
  }
  ```

  ![대입 및 이동 대입 연산자의 활용](./대입 및 이동 대입 연산자의 활용.png)

  ![대입 및 이동 대입 연산자의 활용2](./대입 및 이동 대입 연산자의 활용2.png)

  ![대입 및 이동 대입 연산자의 활용3](./대입 및 이동 대입 연산자의 활용3.png)

  

### (4) std::move 함수의 활용 (1/3)

![두 VecF 객체를 교환하는 함수의 구현1](./두 VecF 객체를 교환하는 함수의 구현1.png)



### (4) std::move 함수의 활용 (2/3)

- std::move 함수
  - 인수로 전달되는 객체의 r-value 참조를 반환
  - 예 : VecF tmp = std::move(v1);
    - v1의 r-value 참조를 구하여 tmp의 초기화에 사용
    - 이동 생성자를 이용하여 tmp 생성
  - 예 : v1 = std::move(v2);
    - v2의 r-value 참조를 구하여 v1에 대입
    - 이동 대입 연산자 실행



### (4) std::move 함수의 활용 (3/3)

![두 VecF 객체를 교환하는 함수의 구현2](./두 VecF 객체를 교환하는 함수의 구현2.png)

![두 VecF 객체를 교환하는 함수의 구현3](./두 VecF 객체를 교환하는 함수의 구현3.png)

![두 VecF 객체를 교환하는 함수의 구현4](./두 VecF 객체를 교환하는 함수의 구현4.png)

![두 VecF 객체를 교환하는 함수의 구현5](./두 VecF 객체를 교환하는 함수의 구현5.png)

![두 VecF 객체를 교환하는 함수의 구현6](./두 VecF 객체를 교환하는 함수의 구현6.png)

- 즉, std::move 는 포인터가 가리키는 주소만 변경해주는 것



## 2. [] 연산자의 다중정의

### (1) 예 : SafeIntArray 클래스

- 요구사항
  - 배열처럼 지정된 개수의 int 값을 저장할 수 있다.
    - 예 : SafeIntArray a(10); => 10개의 int 값을 저장하는 객체
  - 각각의 값들은 0번부터 시작하는 일련번호를 첨자로 지정하여 액세스한다.
    - 예 : a[5] = 10; => 6번째 위치에 10을 저장함
  - 첨자가 지정된 범위를 벗어날 경우 오류 메시지를 출력한 후 프로그램을 종료한다.
    - 예 : cout << a[11];



### (2) 연산자의 다중정의 (1/3)

- [] 연산자

  - 배열의 첨자를 지정하는 이항 연산자
  - 피연산자 : 배열과 첨자

- 데이터를 저장하기 위해 사용할 [] 연산자

  - SafeIntArray a(10);

  - a[5] = 10;

    ```c++
    int& SafeIntArray::operator[](int i) {
        ......
    }
    ```

    ![데이터를 저장하기 위해 사용할 배열 연산자](./데이터를 저장하기 위해 사용할 배열 연산자.png)

    

### (2) [] 연산자의 다중정의 (2/3)

- const 객체를 위한 [] 연산자

  ![데이터를 읽기만 할 수 있도록  연산자를 정의함](./데이터를 읽기만 할 수 있도록  연산자를 정의함.png)

### (2) [] 연산자의 다중정의 (3/3)

- const 객체를 위한 [] 연산자

  ![데이터를 읽기만 할 수 있도록  연산자를 정의함1](./데이터를 읽기만 할 수 있도록  연산자를 정의함1.png)



### (3) SafeIntArray.h (1, 2 ,3/3)

![SafeIntArray.h](./SafeIntArray.h.png)

![SafeIntArray.h2](./SafeIntArray.h2.png)

![SafeIntArray.h3](./SafeIntArray.h3.png)



### (4) SafeArr.cpp 

![SafeArr.cpp](./SafeArr.cpp.png)





## 3. 문자열 클래스

### (1) C 스타일 문자열 (1/5)

- 문자열의 저장

  ![C 스타일 문자열1](./C 스타일 문자열1.png)

  

### (1) C 스타일 문자열 (2/5)

- 문자열의 저장

  ![C 스타일 문자열2](./C 스타일 문자열2.png)

  

### (1) C 스타일 문자열 (3/5)

![C 스타일 문자열3](./C 스타일 문자열3.png)



### (1) C 스타일 문자열 (4/5)

![C 스타일 문자열4](./C 스타일 문자열4.png)



### (1) C 스타일 문자열 (5/5)

![C 스타일 문자열5](./C 스타일 문자열5.png)





### (2) MyString 클래스 (1/3)

![MyString 클래스1](./MyString 클래스1.png)



### (2) MyString 클래스 (2, 3/3)

![MyString 클래스2](./MyString 클래스2.png)

![MyString 클래스3](./MyString 클래스3.png)



### (3) MyString.h (1, 2/3)

![MyString.h](./MyString.h.png)

![MyString.h2](./MyString.h2.png)

![MyString.h3](./MyString.h3.png)





### (4) MyString.cpp (1/7)

![MyString.cpp](./MyString.cpp.png)

![MyString.cpp2](./MyString.cpp2.png)

![MyString.cpp3](./MyString.cpp3.png)

![MyString.cpp4](./MyString.cpp4.png)

![MyString.cpp5](./MyString.cpp5.png)

![MyString.cpp6](./MyString.cpp6.png)

![MyString.cpp7](./MyString.cpp7.png)



### (5) MSMain.cpp

![MSMain.cpp](./MSMain.cpp.png)



### (6) string

- string 이란?

  ![string](./string.png)

  



## 4. 자료형의 변환

### (1) 묵시적 형 변환

![묵시적 형변환](./묵시적 형변환.png)



### (2) 형 변환 연산자를 정의하는 위치 (1/3)

![형 변환 연산자를 정의하는 위치](./형 변환 연산자를 정의하는 위치.png)

![형 변환 연산자를 정의하는 위치1](./형 변환 연산자를 정의하는 위치1.png)

![형 변환 연산자를 정의하는 위치2](./형 변환 연산자를 정의하는 위치2.png)

![형 변환 연산자를 정의하는 위치3](./형 변환 연산자를 정의하는 위치3.png)

