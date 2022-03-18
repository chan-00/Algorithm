// ���ڿ� ���� ���α׷�
// int ���� + int ������ ����� �ִ� +21�� 4õ ����..( 10���� �� 10�ڸ� )
// 10�ڸ� �̻��� ������ ������ �Է� ���ڿ�( char [] )�� �޾� ������ ó��

#include <stdio.h>
#include <string.h>
#define MAX 30						// ���ڿ� �ִ� ũ�� ����

// ���ڿ� ���� '0' ���� �ʱ�ȭ
void strin(char arg[MAX]) {
	int a = 0;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';				// ���ڿ� ���� '0'���� �ʱ�ȭ
	}
}

//	�Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
void strmvstr(char arg[MAX], int len) {
	int a = 0;
	char temp[MAX] = { 0, };
	strin(temp);						// temp ���ڿ� ���� '0'���� �ʱ�ȭ

	for (a = 0; a < len; a++) {
		temp[MAX - len + a] = arg[a];	// �������� ���ڿ��� �������� ���ڿ��� ��ġ �̵�
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0;						// ��ȯ�� ��� ����
	int b = 0;
	int value;
	int resultIndex;
	int lenup = 0, lendn = 0;		// �Է� ���ڿ� ����
	char up[MAX] = { 0, };			// 0���� MAX���� �ڸ���
	char dn[MAX] = { 0, };
	char re[MAX + 1] = { 0, };		// 10�ڸ� + 10�ڸ� ����� �ִ� 11�ڸ�

	strin(up);						// ���� ���ڿ� ���� '0'���� �ʱ�ȭ
	strin(dn);						// �Ʒ��� ���ڿ� ���� '0'���� �ʱ�ȭ

	printf(" Input UP : ");	// ���� ���ڿ� �Է�
//	scanf("%s", up);		// ǥ�� �Է� �Լ�
	scanf_s("%s", up, sizeof(up));	// ���־�Ʃ��� �Է� �Լ�

	printf(" Input DN : ");	// �Ʒ��� ���ڿ� �Է�
//	scanf("%s", dn);		// ǥ�� �Է� �Լ�
	scanf_s("%s", dn, sizeof(up));	// ���־�Ʃ��� �Է� �Լ�

	lenup = strlen(up);				// ���� �Էµ� ���ڿ� ����
	strmvstr(up, lenup);			// �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ

	for (a = 0; a < MAX; a++) {
		printf(" %c", up[a]);
	}	printf("\n\n");

	lendn = strlen(dn);				// ���� �Էµ� ���ڿ� ����
	strmvstr(dn, lendn);			// �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ

	for (a = 0; a < MAX; a++) {
		printf(" %c", dn[a]);
	}	printf("\n\n");

	// ���� ����
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
		printf(" %d", re[a]);		// ���� ��� Ȯ��
	}

	return 0;
}