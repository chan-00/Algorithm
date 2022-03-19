//기본 헤더파일 iostream과 문자열 처리 함수 사용을 위한 cstring 헤더 파일
#include<iostream>
#include<cstring>
//숫자를 입력받을 문자 배열과 결과를 출력할 배열의 길이를 나타낼 상수 MAX 정의
#define MAX 50		

//출력문 간단하게 사용하기 위한 using 사용
using std::cout;
using std::cin;
using std::endl;

//곱셈 함수 정의
void Multiple(char* result, char* arg1, char* arg2);

//숫자를 입력받을 문자 배열이 멤버변수로 들어가 있는 객체
//문자 배열과 관련된 처리를 담당하는 함수들이 멤버 함수로 선언되어 있습니다.
class NumStr {
private:
	char* cArg;
	int cLen;
public:
	NumStr(char arg[MAX], int len);				//생성자 함수, 문자 배열의 초기화와 입력 숫자의 삽입을 담당.
	void SetChar(char ch, int index);			//Set, Get 함수 모음 ~
	char GetChar(int index) const;				//~
	void SetStr(char* setArg);					//~
	char* GetStr() const;						//~
	int GetLen() const;							//~ 멤버 변수가 private이기 때문에 간접 접근을 위한 함수들입니다.
	void InitZero();							//멤버변수 cArg 배열의 내용을 문자 0으로 채워 주는 함수입니다.
	void InitZero(char arg[MAX]);				//위 InitZero의 오버로딩 함수로 매개변수를 달리 하여 차이를 주었습니다.
												//이 InitZero 함수는 매개변수로 전달받은 문자 배열의 내용을 문자 0으로 채워주는 함수입니다.
	void RightSort();							//매개변수 cArg의 내용을 오른쪽 정렬로 바꿔 주는 함수입니다.
	void printAll() const;						//cArg 배열의 내용을 모두 출력해 주는 함수입니다.
	~NumStr();									//동적할당한 cArg 배열의 delete를 위한 소멸자 함수
};

int main(void) {
	//숫자를 입력받는 역할인 문자 배열 선언, 초기화
	char input1[MAX] = { 0, }, input2[MAX] = { 0, };

	//결과를 출력할 배열 선언, 초기화
	char result[MAX] = { 0, };

	//반복문에 쓰일 변수 선언
	int a;

	//첫 번째 숫자 입력
	cout << "첫 번째 숫자를 입력하세요. : ";
	cin >> input1;

	//NumStr 객체 생성 후 생성자 함수에 매개변수로 입력한 숫자값(input1), 입력한 값의 길이값을 넘겨 줍니다.
	NumStr ns1(input1, strlen(input1));

	//위의 첫 번째 숫자와 똑같은 매커니즘입니다.
	cout << "두 번째 숫자를 입력하세요. : ";
	cin >> input2;
	NumStr ns2(input2, strlen(input2));

	//객체의 멤버변수에 잘 들어갔는지 확인하기 위한 출력문 함수 호출입니다.
	ns1.printAll();
	ns2.printAll();

	//이 코드에서 가장 핵심인 곱셈 함수 호출입니다.
	//매개변수로 결과값 배열(result), 첫 번째와 두 번째 숫자가 입력된 객체의 멤버변수(문자 배열)를 반환하는 GetStr 함수를 호출하여 넘겨 주었습니다.
	Multiple(result, ns1.GetStr(), ns2.GetStr());

	//결과 배열을 출력하는 반복문
	for (a = 0; a < MAX; a++) {
		cout << (int)result[a] << " ";
	}

	return 0;
}

//곱셈 계산 처리 함수
void Multiple(char* result, char* arg1, char* arg2) {
	//반복문에 사용되는 a, b 변수
	//곱셈값 임시 저장하는 value 변수
	//결과 배열의 변화하는 인덱스 값을 담은 resultIndex 변수
	int a, b, value, resultIndex;

	//이중 for문을 돌며 두 개의 입력한 숫자 배열의 내용을 모두 돌아보게 됩니다.
	for (a = MAX - 1; a > 0; a--) {
		for (b = MAX - 1; b > 0; b--) {
			value = (arg1[b] - '0') * (arg2[a] - '0');							//두 숫자 배열 인덱스의 현 위치 곱셈값
			if (value > 0) {
				resultIndex = a + b - MAX;										//결과 배열의 현재 인덱스
				result[resultIndex + 1] += (value % 10);						//결과 배열에 곱셈값 1의 자리 숫자를 넣는 과정
				result[resultIndex] += (value / 10);							//결과 배열에 곱셈값 10의 자리 숫자를 넣는 과정(올림수)
				result[resultIndex] += (result[resultIndex + 1] / 10);			//현 인덱스에서 오른쪽 인덱스의 올림수가 있을 시 더해 주는 과정
				result[resultIndex + 1] %= 10;									//오른쪽 인덱스에서 올림수를 제외한 1의 자리 숫자만을 남겨 놓는 과정
			}
		}
	}
}

//생성자 함수, cArg 배열 동적할당과 0으로 채우는 함수 호출
//입력값 매개변수를 cArg 배열에 넣어 주고, 오른쪽 정렬 함수 호출
NumStr::NumStr(char arg[MAX], int len):cLen(len) {
	cArg = new char[MAX];
	int a;

	InitZero();
	for (a = 0; a < len; a++) {
		cArg[a] = arg[a];
	}
	RightSort();
}

/*****Set, Get 함수 시작*****/
//private 멤버 변수 접근을 위한 함수들입니다.
void NumStr::SetChar(char ch, int index) {
	cArg[index] = ch;
}

char NumStr::GetChar(int index) const {
	return cArg[index];
}

void NumStr::SetStr(char* setArg) {
	int a;

	for (a = 0; a < MAX; a++) {
		cArg[a] = setArg[a];
	}
}

char* NumStr::GetStr() const {
	return cArg;
}


int NumStr::GetLen() const {
	return cLen;
}
/*****Set, Get 함수 종료*****/

//매개변수가 없는 InitZero 함수
//멤버변수 cArg 배열의 내용을 문자 0으로 채웁니다.
void NumStr::InitZero() {
	int a;

	for (a = 0; a < MAX; a++) {
		cArg[a] = '0';
	}
}

//매개변수가 있는 InitZero 함수(함수 오버로딩)
//매개변수로 받은 문자 배열의 내용을 문자 0으로 채웁니다.
void NumStr::InitZero(char arg[MAX]) {
	int a;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';
	}
}

//오른쪽 정렬 함수
//숫자를 입력받으면 왼쪽 정렬로 되어 있기 때문에 계산을 위해 오른쪽으로 숫자들을 정렬해 주는 함수입니다.
void NumStr::RightSort() {
	int a;
	char temp[MAX] = { 0, };
	InitZero(temp);

	for (a = 0; a < cLen; a++) {
		temp[MAX - cLen + a] = cArg[a];
	}
	for (a = 0; a < MAX; a++) {
		cArg[a] = temp[a];
	}
}

//멤버변수 cArg 배열의 내용을 출력해 주는 함수입니다.
void NumStr::printAll() const {
	int a;

	for (a = 0; a < MAX; a++) {
		cout << cArg[a] << " ";
	}
	cout << "\n\n";
}

//동적할당된 cArg를 delete 해 주는 소멸자 함수입니다.
NumStr::~NumStr() {
	delete[]cArg;
}