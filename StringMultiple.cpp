//�⺻ ������� iostream�� ���ڿ� ó�� �Լ� ����� ���� cstring ��� ����
#include<iostream>
#include<cstring>
//���ڸ� �Է¹��� ���� �迭�� ����� ����� �迭�� ���̸� ��Ÿ�� ��� MAX ����
#define MAX 50		

//��¹� �����ϰ� ����ϱ� ���� using ���
using std::cout;
using std::cin;
using std::endl;

//���� �Լ� ����
void Multiple(char* result, char* arg1, char* arg2);

//���ڸ� �Է¹��� ���� �迭�� ��������� �� �ִ� ��ü
//���� �迭�� ���õ� ó���� ����ϴ� �Լ����� ��� �Լ��� ����Ǿ� �ֽ��ϴ�.
class NumStr {
private:
	char* cArg;
	int cLen;
public:
	NumStr(char arg[MAX], int len);				//������ �Լ�, ���� �迭�� �ʱ�ȭ�� �Է� ������ ������ ���.
	void SetChar(char ch, int index);			//Set, Get �Լ� ���� ~
	char GetChar(int index) const;				//~
	void SetStr(char* setArg);					//~
	char* GetStr() const;						//~
	int GetLen() const;							//~ ��� ������ private�̱� ������ ���� ������ ���� �Լ����Դϴ�.
	void InitZero();							//������� cArg �迭�� ������ ���� 0���� ä�� �ִ� �Լ��Դϴ�.
	void InitZero(char arg[MAX]);				//�� InitZero�� �����ε� �Լ��� �Ű������� �޸� �Ͽ� ���̸� �־����ϴ�.
												//�� InitZero �Լ��� �Ű������� ���޹��� ���� �迭�� ������ ���� 0���� ä���ִ� �Լ��Դϴ�.
	void RightSort();							//�Ű����� cArg�� ������ ������ ���ķ� �ٲ� �ִ� �Լ��Դϴ�.
	void printAll() const;						//cArg �迭�� ������ ��� ����� �ִ� �Լ��Դϴ�.
	~NumStr();									//�����Ҵ��� cArg �迭�� delete�� ���� �Ҹ��� �Լ�
};

int main(void) {
	//���ڸ� �Է¹޴� ������ ���� �迭 ����, �ʱ�ȭ
	char input1[MAX] = { 0, }, input2[MAX] = { 0, };

	//����� ����� �迭 ����, �ʱ�ȭ
	char result[MAX] = { 0, };

	//�ݺ����� ���� ���� ����
	int a;

	//ù ��° ���� �Է�
	cout << "ù ��° ���ڸ� �Է��ϼ���. : ";
	cin >> input1;

	//NumStr ��ü ���� �� ������ �Լ��� �Ű������� �Է��� ���ڰ�(input1), �Է��� ���� ���̰��� �Ѱ� �ݴϴ�.
	NumStr ns1(input1, strlen(input1));

	//���� ù ��° ���ڿ� �Ȱ��� ��Ŀ�����Դϴ�.
	cout << "�� ��° ���ڸ� �Է��ϼ���. : ";
	cin >> input2;
	NumStr ns2(input2, strlen(input2));

	//��ü�� ��������� �� ������ Ȯ���ϱ� ���� ��¹� �Լ� ȣ���Դϴ�.
	ns1.printAll();
	ns2.printAll();

	//�� �ڵ忡�� ���� �ٽ��� ���� �Լ� ȣ���Դϴ�.
	//�Ű������� ����� �迭(result), ù ��°�� �� ��° ���ڰ� �Էµ� ��ü�� �������(���� �迭)�� ��ȯ�ϴ� GetStr �Լ��� ȣ���Ͽ� �Ѱ� �־����ϴ�.
	Multiple(result, ns1.GetStr(), ns2.GetStr());

	//��� �迭�� ����ϴ� �ݺ���
	for (a = 0; a < MAX; a++) {
		cout << (int)result[a] << " ";
	}

	return 0;
}

//���� ��� ó�� �Լ�
void Multiple(char* result, char* arg1, char* arg2) {
	//�ݺ����� ���Ǵ� a, b ����
	//������ �ӽ� �����ϴ� value ����
	//��� �迭�� ��ȭ�ϴ� �ε��� ���� ���� resultIndex ����
	int a, b, value, resultIndex;

	//���� for���� ���� �� ���� �Է��� ���� �迭�� ������ ��� ���ƺ��� �˴ϴ�.
	for (a = MAX - 1; a > 0; a--) {
		for (b = MAX - 1; b > 0; b--) {
			value = (arg1[b] - '0') * (arg2[a] - '0');							//�� ���� �迭 �ε����� �� ��ġ ������
			if (value > 0) {
				resultIndex = a + b - MAX;										//��� �迭�� ���� �ε���
				result[resultIndex + 1] += (value % 10);						//��� �迭�� ������ 1�� �ڸ� ���ڸ� �ִ� ����
				result[resultIndex] += (value / 10);							//��� �迭�� ������ 10�� �ڸ� ���ڸ� �ִ� ����(�ø���)
				result[resultIndex] += (result[resultIndex + 1] / 10);			//�� �ε������� ������ �ε����� �ø����� ���� �� ���� �ִ� ����
				result[resultIndex + 1] %= 10;									//������ �ε������� �ø����� ������ 1�� �ڸ� ���ڸ��� ���� ���� ����
			}
		}
	}
}

//������ �Լ�, cArg �迭 �����Ҵ�� 0���� ä��� �Լ� ȣ��
//�Է°� �Ű������� cArg �迭�� �־� �ְ�, ������ ���� �Լ� ȣ��
NumStr::NumStr(char arg[MAX], int len):cLen(len) {
	cArg = new char[MAX];
	int a;

	InitZero();
	for (a = 0; a < len; a++) {
		cArg[a] = arg[a];
	}
	RightSort();
}

/*****Set, Get �Լ� ����*****/
//private ��� ���� ������ ���� �Լ����Դϴ�.
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
/*****Set, Get �Լ� ����*****/

//�Ű������� ���� InitZero �Լ�
//������� cArg �迭�� ������ ���� 0���� ä��ϴ�.
void NumStr::InitZero() {
	int a;

	for (a = 0; a < MAX; a++) {
		cArg[a] = '0';
	}
}

//�Ű������� �ִ� InitZero �Լ�(�Լ� �����ε�)
//�Ű������� ���� ���� �迭�� ������ ���� 0���� ä��ϴ�.
void NumStr::InitZero(char arg[MAX]) {
	int a;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';
	}
}

//������ ���� �Լ�
//���ڸ� �Է¹����� ���� ���ķ� �Ǿ� �ֱ� ������ ����� ���� ���������� ���ڵ��� ������ �ִ� �Լ��Դϴ�.
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

//������� cArg �迭�� ������ ����� �ִ� �Լ��Դϴ�.
void NumStr::printAll() const {
	int a;

	for (a = 0; a < MAX; a++) {
		cout << cArg[a] << " ";
	}
	cout << "\n\n";
}

//�����Ҵ�� cArg�� delete �� �ִ� �Ҹ��� �Լ��Դϴ�.
NumStr::~NumStr() {
	delete[]cArg;
}