// 문자열 덧셈 프로그램
// int 변수 + int 변수의 결과는 최대 +21억 4천 까지..( 10진수 약 10자리 )
// 10자리 이상의 정수형 변수를 입력 문자열( char [] )로 받아 덧셈을 처리

#include <stdio.h>
#include <string.h>
#define MAX 30						// 문자열 최대 크기 지정

// 문자열 글자 '0' 으로 초기화
void strin(char arg[MAX]) {
	int a = 0;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';				// 문자열 글자 '0'으로 초기화
	}
}

//	입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
void strmvstr(char arg[MAX], int len) {
	int a = 0;
	char temp[MAX] = { 0, };
	strin(temp);						// temp 문자열 글자 '0'으로 초기화

	for (a = 0; a < len; a++) {
		temp[MAX - len + a] = arg[a];	// 좌측정렬 문자열을 우측정렬 문자열로 위치 이동
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0;						// 순환문 사용 변수
	int b = 0;
	int value;
	int resultIndex;
	int lenup = 0, lendn = 0;		// 입력 문자열 길이
	char up[MAX] = { 0, };			// 0에서 MAX까지 자리수
	char dn[MAX] = { 0, };
	char re[MAX + 1] = { 0, };		// 10자리 + 10자리 결과는 최대 11자리

	strin(up);						// 윗줄 문자열 글자 '0'으로 초기화
	strin(dn);						// 아랫줄 문자열 글자 '0'으로 초기화

	printf(" Input UP : ");	// 윗줄 문자열 입력
//	scanf("%s", up);		// 표준 입력 함수
	scanf_s("%s", up, sizeof(up));	// 비주얼스튜디오 입력 함수

	printf(" Input DN : ");	// 아랫줄 문자열 입력
//	scanf("%s", dn);		// 표준 입력 함수
	scanf_s("%s", dn, sizeof(up));	// 비주얼스튜디오 입력 함수

	lenup = strlen(up);				// 실제 입력된 문자열 길이
	strmvstr(up, lenup);			// 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환

	for (a = 0; a < MAX; a++) {
		printf(" %c", up[a]);
	}	printf("\n\n");

	lendn = strlen(dn);				// 실제 입력된 문자열 길이
	strmvstr(dn, lendn);			// 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환

	for (a = 0; a < MAX; a++) {
		printf(" %c", dn[a]);
	}	printf("\n\n");

	// 덧셈 과정
	for (a = MAX - 1; a > 0; a--) {
		for (b = MAX - 1; b > 0; b--) {
			value = (up[a] - '0') * (dn[b] - '0');
			if (value > 0) {
				resultIndex = a + b - MAX;
				re[resultIndex + 1] = re[resultIndex + 1] + (value % 10);
				re[resultIndex] = re[resultIndex] + (value / 10);
				re[resultIndex] = re[resultIndex] + (re[resultIndex + 1] / 10);
				re[resultIndex + 1] = re[resultIndex + 1] % 10;
			}
		}
	}


	for (a = 0; a < MAX; a++) {
		printf(" %d", re[a]);		// 덧셈 결과 확인
	}

	return 0;
}