#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 3

int main(void) {
	int a = 0, b = 0;						//반복문에 사용될 변수들
	int strike = 0, ball = 0;				//숫자야구에 사용될 strike, ball 변수
	int comNum[MAX], userNum[MAX];			//컴퓨터의 3자리값, 사용자가 입력하는 3자리값 배열

	srand(time(NULL));						//난수값을 다르게 하는 코드
	for (a = 0; a < MAX; a++) {				//컴퓨터에 3자리 랜덤값 입력하는 과정
		comNum[a] = rand() % 10;			//0~9 사이의 난수값만을 받아 넣음.
		for (b = 0; b < a; b++) {			//중복값을 받지 않기 위한 반복문
			if (comNum[b] == comNum[a]) {	//기존 배열에 중복값이 있는지 비교
				a--;						//중복값이 있으면 a값(인덱스)을 줄여 난수값을 입력받지 않음.
				break;
			}
		}
	}

	printf("컴퓨터가 생각한 3자리 랜덤값 표시 : %d %d %d\n", comNum[0], comNum[1], comNum[2]);
	while (1) {
		strike = 0;														//반복을 돌 때마다 strike와 ball 변수 0으로 초기화
		ball = 0;
		//사용자에게 값 입력받음.
		for (a = 0; a < MAX; a++) {
			printf("중복되지 않는 3자리 랜덤값 중 %d번째 : ", a + 1);
			scanf_s("%d", &userNum[a]);
		}
		//숫자가 맞는지 검증
		for (a = 0; a < MAX; a++) {
			for (b = 0; b < MAX; b++) {
				if (comNum[a] == userNum[b] && a == b)					//값이 같고 위치도 똑같은 상황(strike)
					strike++;
				else if (comNum[a] == userNum[b] && a != b)				//값이 같지만 위치가 같지 않은 상황(ball)
					ball++;
			}
		}
		if (strike == 3) {												//3strike일 때(= 정답을 맞췄을 때)
			printf("축하합니다! 숫자 3자리를 모두 맞췄습니다.\n");
			break;														//while 반복문을 빠져 나감
		}
		else {															//정답이 아닐 때
			printf("컴퓨터의 랜덤 3자리 숫자를 맞추지 못했습니다.");
			printf("strike : %d, ball : %d\n", strike, ball);			//strike와 ball을 출력하고 다시 while문 반복
		}
	}
	return 0;
}