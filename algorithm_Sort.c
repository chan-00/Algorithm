#include<stdio.h>

//정렬 함수 선언
int BubbleSort(int arr[10], int n);
int InsertSort(int arr[10], int n);
int SelectionSort(int arr[10], int n);
void PrintArr(int arr[10], int n);

//정렬 결과를 쉽게 보기 위해 무한루프를 돌며 정렬시킬 배열과 어떤 정렬로 할 것인지 선택하여 보게 했는데,
//한 번 정렬되어 버린 배열은 이후에 다른 정렬 방법으로 해당 배열의 정렬 결과를 보려 하면 이미 정렬되어 버렸기 때문에,
//매번 반복마다 배열들의 값을 초기화 해 주는 역할을 하는 함수를 하나 선언하였습니다.
void InitArr(int arr1[10], int arr2[10], int arr3[10], int arr4[10], int originArr1[10], int originArr2[10], int originArr3[10], int originArr4[10], int n);

int main(void) {
	int selArr;

	//다양한 입력 상황을 배열로 표현
	int originArr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };				//오름차순으로 배열되어 있는 숫자
	int originArr2[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };		//평범한 배열 숫자
	int originArr3[10] = { 99, 23, 84, 50, 49, 62, 71, 15, 36, 7 };		//부분 내림차순 정렬이 되어 있는 배열
	int originArr4[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };		//완전히 내림차순으로 이미 정렬이 되어 있는 배열

	//위의 원본 배열에서 값을 가져와 초기화할 배열 선언
	int arr1[10];
	int arr2[10];
	int arr3[10];
	int arr4[10];

	//반복하며 입력을 받기 위해 while 무한루프 사용
	while (1) {
		InitArr(arr1, arr2, arr3, arr4, originArr1, originArr2, originArr3, originArr4, 10);

		printf("\n\n\n\n\t<정렬 배열 선택>\n\n");
		printf("1. arr1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }\n");
		printf("2. arr2 { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 }\n");
		printf("3. arr3 { 99, 23, 84, 50, 49, 62, 71, 15, 36, 7 }\n");
		printf("4. arr4 { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 }\n");
		printf("5. 프로그램 종료\n\n");

		printf("어떤 배열을 내림차순 정렬하시겠습니까? : ");
		scanf("%d", &selArr);

		//if 조건식으로 입력한 값에 맞게 정렬할 배열 전달
		if (selArr == 1) {
			PrintArr(arr1, 10);
		}
		else if (selArr == 2) {
			PrintArr(arr2, 10);
		}
		else if (selArr == 3) {
			PrintArr(arr3, 10);
		}
		else if (selArr == 4) {
			PrintArr(arr4, 10);
		}
		else if (selArr == 5) {
			printf("\n프로그램이 종료됩니다.........\n");
			break;
		}
		else {
			printf("메뉴값을 잘못 입력했습니다.\n\n");
		}
	}
	return 0;
}

void InitArr(int arr1[10], int arr2[10], int arr3[10], int arr4[10], int originArr1[10], int originArr2[10], int originArr3[10], int originArr4[10], int n) {
	int a = 0;			//반복문을 돌 변수

	for (a = 0; a < n; a++) {
		arr1[a] = originArr1[a];
		arr2[a] = originArr2[a];
		arr3[a] = originArr3[a];
		arr4[a] = originArr4[a];
	}
}

//정렬 방법 선택 출력하는 함수
void PrintArr(int arr[10], int n) {
	int selSort;

	//어떤 정렬로 할 것인지 입력받음.
	printf("\n\t<정렬 종류 선택>\n\n");
	printf("1. 버블 정렬\n");
	printf("2. 삽입 정렬\n");
	printf("3. 선택 정렬\n");
	printf("어떤 정렬로 하시겠습니까? : ");
	scanf("%d", &selSort);

	//switch문 사용으로 입력한 메뉴값에 맞게 함수 호출, 메뉴값을 제대로 입력하지 않았을 때 default에서 return을 사용하여 함수 종료.
	switch (selSort) {
	case 1:
		printf("\n === Bubble Sort Start === \n\n");
		BubbleSort(arr, 10);
		printf("\n === Bubble Sort End === \n\n");
		break;
	case 2:
		printf("\n === Insert Sort Start === \n\n");
		InsertSort(arr, 10);
		printf("\n === Insert Sort End === \n\n");
		break;
	case 3:
		printf("\n === Selection Sort Start === \n\n");
		SelectionSort(arr, 10);
		printf("\n === Selection Sort End === \n\n");
		break;
	default:
		printf("메뉴값을 잘못 입력했으므로 함수가 종료됩니다.....\n");
		return;
	}
}

//버블정렬 함수 정의
int BubbleSort(int arr[10], int n) {
	//변수 선언
	int a = 0, b = 0, c = 0;							//반복문을 돌 때 사용되는 변수들.
	int temp = 0;										//값의 변경이 일어날 때 사용되는 변수
	int flag = 1;										//더이상 정렬이 필요하지 않을 때 함수를 종료시킬 역할을 맡은 변수
	int count = 0;										//정렬 함수가 얼마나 반복되는지 횟수를 세는 변수

	//버블정렬 반복문
	for (a = 0; a < n - 1; a++) {
		flag = 1;										//매번 반복문마다 flag변수 1로 바꿈	
		for (b = 0; b < n - 1 - a; b++) {
			if (arr[b] < arr[b + 1]) {					//내림차순 비교문
				temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
				flag = 0;								//변환이 일어날 때 flag값 0으로 변경
			}
			count++;									//반복 횟수 세는 변수
		}

		//정렬 과정 출력
		for (c = 0; c < n; c++) {
			printf(" %3d ", arr[c]);
		}
		printf("\n");

		//flag가 1일 때 = 위의 반복문에서 변환이 발생하지 않음
		//변환이 발생하지 않음 = 더 이상 정렬이 필요 없음.
		if (flag == 1) {
			printf("count : %d\n", count);
			return 1;									//정렬이 필요 없기 때문에 바로 함수를 종료
		}
	}
	printf("count : %d\n", count);

	return 0;
}


//삽입정렬 함수 정의
int InsertSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;							//반복문을 돌 때 사용되는 변수들.
	int temp = 0;										//값의 변경이 일어날 때 사용되는 변수
	int count = 0;										//정렬 함수가 얼마나 반복되는지 횟수를 세는 변수
	int flag = 1;										//더이상 정렬이 필요하지 않을 때 함수를 종료시킬 역할을 맡은 변수

	//삽입정렬 반복문 시작
	for (a = 1; a < n; a++) {
		flag = 1;
		for (b = a; b > 0; b--) {
			if (arr[b - 1] < arr[b]) {
				temp = arr[b];
				arr[b] = arr[b - 1];
				arr[b - 1] = temp;
			}
			else if (arr[b - 1] > arr[b] && b == a) {	//b == a 조건문은 처음 비교를 했을 때를 의미
				flag = 0;								//처음 비교가 발생하지 않으면 그 부분은 이미 정렬이 되어 있다는 뜻.
			}
			count++;

			if (flag == 0) {							//flag가 0이면 해당 부분은 이미 정렬되어 있으므로 break로 반복을 끝냄.
				break;
			}
		}

		//정렬 과정 출력
		for (c = 0; c < n; c++) {
			printf(" %2d ", arr[c]);
		}
		printf("\n");

	}
	printf("count : %d\n", count);

	return 0;

}


//선택정렬 함수 정의
int SelectionSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;							//반복문을 돌 때 사용되는 변수들.			
	int temp = 0;										//값의 변경이 일어날 때 사용되는 변수
	int index = 0;										//선택정렬에서 선택된 값(내림차순에서는 큰 값)의 위치값을 담을 변수
	int count = 0;										//정렬 함수가 얼마나 반복되는지 횟수를 세는 변수
	int flag = 1;										//더이상 정렬이 필요하지 않을 때 함수를 종료시킬 역할을 맡은 변수

	//선택정렬 반복문 시작
	for (a = 0; a < n - 1; a++) {
		flag = 1;
		index = a;										//현 위치값(a)을 index 변수에 고정
		for (b = a + 1; b < n; b++) {
			if (arr[index] < arr[b]) {					//index 위치보다 반복을 도는 b 변수 위치값이 더 크면 해당 위치값 저장.
				index = b;
			}
			if (arr[b] > arr[b - 1]) {					//현재 배열이 정렬이 필요한지 파악하는 조건문
				flag = 0;								//이 조건문이 성립되었다는 것은 현재 배열이 내림차순 정렬이 되어 있지 않다는 것을 의미하므로 flag 변수값을 0으로 바꿈
			}
			count++;
		}
		if (flag == 0) {								//flag == 0이면 내림차순 정렬 반복을 더 해야 한다는 의미
			//내림차순 값으로 바꾸는 코드
			temp = arr[a];
			arr[a] = arr[index];
			arr[index] = temp;

			//출력 후 반복문을 이어감.
			for (c = 0; c < n; c++) {
				printf(" %2d ", arr[c]);
			}
			printf("\n\n");
		}
		//flag == 1이라는 것은 위의 이중 for문에서 flag값이 0으로 한 번도 바뀌지 않았다는 의미(= 이미 내림차순이 끝난 정렬)
		else if (flag == 1) {
			for (c = 0; c < n; c++) {
				printf(" %2d ", arr[c]);
			}
			printf("\n\n");

			printf("count : %d\n", count);
			return 1;									//더 이상 반복(정렬)이 필요 없기 때문에 바로 함수를 종료
		}
	}
	printf("count : %d\n", count);

	return 0;
}