#include<iostream>
#include<cstring>
#include "Algorithm_Operate.h"

using std::cout;
using std::cin;
using std::endl;

//Stack 클래스의 생성자(멤버의 초기화)
Stack::Stack(int cStackLen) : top(-1) {
	stackLen = cStackLen;
	stackArr = new char[stackLen];

	for (int a = 0; a < stackLen; a++) {
		stackArr[a] = '0';
	}
}

//top 변수값 반환 함수
int Stack::getTop() {
	return top;
}

//스택이 가득 찼는지
bool Stack::isFull() {
	if (top == (stackLen - 1))
		return true;
	return false;
}

//스택이 비었는지
bool Stack::isEmpty() {
	if (top == -1)
		return true;
	return false;
}

//스택의 push 역할
void Stack::push(char cOperate) {
	if (isFull()) {
		cout << "스택이 가득 차서 더 이상 push를 할 수 없습니다." << endl;
		return;
	}
	stackArr[++top] = cOperate;
}

//스택의 pop 역할
char Stack::pop() {
	if (isEmpty()) {
		cout << "스택이 비어 있어 pop을 할 수 없습니다." << endl;
		return '0';
	}
	//pop을 해 주고 그 자리는 0 문자로 초기화
	char returnStack = stackArr[top--];
	stackArr[top + 1] = '0';
	return returnStack;
}

//스택 배열 초기화하기
void Stack::resetStack() {
	for (int a = 0; a < stackLen; a++)
		stackArr[a] = '0';
	top = -1;
}

//스택 내용 출력하는 함수
void Stack::Print() {
	cout << "스택의 내용 : ";
	for (int a = 0; a < stackLen; a++) {
		cout << stackArr[a];
	}
	cout << endl;
}

//소멸자(동적할당 해제)
Stack::~Stack() {
	delete[]stackArr;
}

//후위 연산 클래스의 생성자(멤버의 초기화)
RearOperate::RearOperate(const char* cstr, int stackLen) {
	//멤버 stack의 동적할당(클래스 생성자 호출)
	stack = new Stack(stackLen);
	//매개변수로 받은 식 문자열의 복사 과정(str 동적할당)
	strLen = strlen(cstr) + 1;
	str = new char[strLen];
	strcpy(str, cstr);
}

//str 문자열 변경
void RearOperate::setStr(const char* cstr) {
	//기존 str의 동적할당 해제 후 stack의 초기화 후, 생성자에서의 str 복사 과정을 따라감
	delete[]str;
	stack->resetStack();

	strLen = strlen(cstr) + 1;
	str = new char[strLen];
	strcpy(str, cstr);
}

//stack 변경
void RearOperate::setStack(int stackLen) {
	//기존의 스택 삭제 후, 새로운 스택을 생성
	delete stack;
	stack = new Stack(stackLen);
}

//후위 연산
void RearOperate::rearPrint() {
	int a;

	for (a = 0; a < strLen; a++) {
		//해당 문자가 숫자(피연산자)일 때
		if (str[a] >= 48 && str[a] <= 57)
			cout << str[a];
		//연산자일 때
		if (str[a] == '+' || str[a] == '-' || str[a] == '*' || str[a] == '/')
			stack->push(str[a]);
		//오른쪽 괄호를 만났을 때
		if (str[a] == ')')
			cout << stack->pop();
	}

	//위의 과정을 거친 후 스택의 top 변수가 -1이 아니면 스택 안의 데이터가 남아 있다는 얘기
	if (stack->getTop() > -1) {
		//스택 안에 남은 것을 모두 pop 해 준다.
		for (a = stack->getTop(); a >= 0; a--)
			cout << stack->pop();
	}
	cout << endl;
}

//현재 str 문자열 출력
void RearOperate::Print() {
	for (int a = 0; a < strLen; a++) {
		cout << str[a];
	}
	cout << endl;
}

//소멸자(동적할당 해제)
RearOperate::~RearOperate() {
	delete stack;
	delete[]str;
}