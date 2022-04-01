#include<stdio.h>

int BubbleSort(int arr[10], int n);
int InsertSort(int arr[10], int n);
int SelectionSort(int arr[10], int n);


int main(void) {
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };				//오름차순으로 배열되어 있는 숫자
	int arr2[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };		//평범한 배열 숫자
	int arr3[10] = { 99, 23, 84, 50, 49, 62, 71, 15, 36, 7 };		//부분 내림차순 정렬이 되어 있는 배열
	int arr4[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };		//완전히 내림차순으로 이미 정렬이 되어 있는 배열

	
	printf("\n === Bubble Sort Start === \n\n");
	BubbleSort(arr2, 10);
	printf("\n === Bubble Sort End === \n\n");
	

	printf("\n === Insert Sort Start === \n\n");
	InsertSort(arr1, 10);
	printf("\n === Insert Sort End === \n\n");

	
	printf("\n === Selection Sort Start === \n\n");
	SelectionSort(arr3, 10);
	printf("\n === Selection Sort End === \n\n");
	

	return 0;

}


int BubbleSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;
	int temp = 0;
	int flag = 1;
	int count = 0;

	for (a = 0; a < n - 1; a++) {
		flag = 1;
		for (b = 0; b < n - 1 - a; b++) {
			if (arr[b] < arr[b + 1]) {
				temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
				flag = 0;
			}
			count++;
		}

		for (c = 0; c < n; c++) {
			printf(" %3d ", arr[c]);
		}
		printf("\n");

		if (flag == 1) {
			printf("count : %d\n", count);
			return 1;
		}
	}
	printf("count : %d\n", count);

	return 0;
}


int InsertSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;
	int temp = 0;
	int count = 0;

	for (a = 1; a < n; a++) {
		for (b = a; b > 0; b--) {
			if (arr[b - 1] < arr[b]) {
				temp = arr[b];
				arr[b] = arr[b - 1];
				arr[b - 1] = temp;

			}
			count++;
		}

		for (c = 0; c < n; c++) {
			printf(" %2d ", arr[c]);
		}
		printf("\n");

	}
	printf("count : %d\n", count);

	return 0;

}



int SelectionSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;
	int temp = 0;
	int index = 0;
	int count = 0;

	for (a = 1; a < n; a++) {
		index = a;
		for (b = a; b > 0; b--) {
			if (arr[index] > arr[b]) {
				index = b;
			}
			count++;
		}
		temp = arr[a];
		arr[a] = arr[index];
		arr[index] = temp;

		for (c = 0; c < n; c++) {
			printf(" %2d ", arr[c]);
		}
		printf("\n\n");
	}
	printf("count : %d\n", count);

	return 0;

}