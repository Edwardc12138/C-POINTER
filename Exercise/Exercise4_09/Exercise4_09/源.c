#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����ָ��,ָ������,ת�Ʊ�

// ��
int Add(int a, int b) {
	return a + b;
}

// ��
int Sub(int a, int b) {
	return a - b;
}

// ��
int Mul(int a, int b) {
	return a * b;
}

// ��
int Div(int a, int b) {
	return a / b;
}

int main() {
	int input = 1;
	int(*p[5])(int a, int b) = { 0, Add, Sub, Mul, Div };	// ת�Ʊ�
	while (input) {
		system("cls");
		printf("****************************\n");
		printf("*** 1:Add ******** 2:Sub ***\n");
		printf("*** 3:Mul ******** 4:Div ***\n");
		printf("********** 0:Exit **********\n");
		printf("****************************\n");
		
		printf("��ѡ��: ");
		scanf("%d", &input);
		while (input < 0 || input > 4) {
				printf("��������!������: ");
				scanf("%d", &input);
		}
		if (!input) {
			return;
		}

		int a, b;
		printf("���������: ");
		scanf("%d %d", &a, &b);
		printf("%d\n", (*p[input])(a, b));
		system("pause");
	}

	return 0;
}