#ifndef __AlgorithmOperate__
#define __AlgorithmOperate__

//스택 역할을 하는 클래스
class Stack {
private:
	char* stackArr;									//연산자를 저장할 스택 역할의 공간(동적할당 할 것.)
	int top;										//스택에서의 현 위치를 알려주는 top 변수
	int stackLen;									//스택의 길이값

public:
	//생성자
	Stack(int cStackLen);

	//멤버변수 접근
	int getTop();									//top 변수값을 얻어 냄

	//스택의 기능 함수
	bool isFull();									//스택이 가득 찼는지 확인
	bool isEmpty();									//스택이 비어 있는지 확인
	void push(char cOperate);						//스택에서의 push 역할
	char pop();										//스택에서의 pop 역할
	void resetStack();								//스택 배열 초기화하기
	void Print();									//스택 내용 출력하는 함수

	//소멸자
	~Stack();
};

//스택 클래스를 멤버변수로 갖고 있는 클래스(후위 연산이 이뤄지는 곳)
class RearOperate {
private:
	Stack* stack;									//스택 클래스
	char* str;										//연산식(중위) 문자열을 받는 변수
	int strLen;										//str 문자열의 길이값을 담을 변수

public:
	//생성자
	RearOperate(const char* cstr, int stackLen);

	//멤버변수 접근(get은 반환형 포인터로 외부에서 변경의 요지가 있어 제외했습니다.)
	void setStr(const char* cstr);					//str 문자열 변경
	void setStack(int stackLen);					//stack 새로 설정하는 함수

	//클래스의 기능 함수들
	void rearPrint();								//후위 연산으로 출력
	void Print();									//현재 식(str)을 출력

	//소멸자
	~RearOperate();
};

#endif