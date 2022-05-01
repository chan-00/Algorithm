#include<iostream>
#include "Algorithm_Operate.h"

using std::cout;
using std::cin;
using std::endl;

int main(void) {
	char str[50];

	cout << "연산 식을 입력하세요." << endl << "=> ";
	cin >> str;

	RearOperate rear(str, 10);
	cout << "<후위 연산 전>" << endl;
	rear.Print();
	cout << "<후위 연산 후>" << endl;
	rear.rearPrint();

	return 0;
}