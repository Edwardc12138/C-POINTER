#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��� n * n �˷��ھ���
void PrintMul(int n) {
	if (n < 1) {	//n < 1,�����
		return;
	}
	for (int row = 1; row <= n; row++)	//����˷��ھ���
	{
		for (int col = 1; col <= row; col++)
			printf("%d*%d=%d\t", col, row, col*row);
		printf("\n");
	}
}

//������������
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//�ж��Ƿ�������,1��ʾ��,0��ʾ��
int IsLeapYear(int year) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			return 1;
		}
	}
	else {
		if (year % 4 == 0) {
			return 1;
		}
	}
	return 0;
}

//��ʼ����������
void Init(int arr[], int cap) {
	for (int curr = 0; curr < cap; ++curr) {
		arr[curr] = curr;
	}
}

//�������
void Empty(int arr[], int cap) {
	for (int curr = 0; curr < cap; ++curr) {
		arr[curr] = 0;
	}
}

//��������
void Reverse(int arr[], int cap) {
	for (int left = 0, right = cap - 1; left <= right; ++left, --right) {
		Swap(&arr[left], &arr[right]);
	}
}

//��ӡ����
void PrintArr(int arr[], int size) {
	for (int curr = 0; curr < size; ++curr) {
		printf("%d ", arr[curr]);
	}
	printf("\n");
}

//�Ƿ�������
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = sqrt(n);
	for (int i = 2; i <= square_n; ++i) {	//��2����n��ƽ����,֮��Ĳ����ж�
		if (n % i == 0) {
			return 0;	//��������
		}
	}
	return 1;			//������
}

int main() {
	//5.�ж�����
	printf("����������: ");
	int num;
	scanf("%d", &num);
	if (IsPrime(num)) {
		printf("������\n");
	}
	else {
		printf("��������\n");
	}

	//4.�������
	//int arr[20];
	//int size = sizeof(arr) / sizeof(arr[0]);
	//Init(arr, size);
	//printf("��ʼ������: ");
	//PrintArr(arr, size);
	//Reverse(arr, size);
	//printf("  ��������: ");
	//PrintArr(arr, size);
	//Empty(arr, size);
	//printf("  �������: ");
	//PrintArr(arr, size);

	//3.�ж�����
	//int year,
	//	leap_year;
	//printf("���������: ");
	//scanf("%d", &year);
	//if (IsLeapYear(year)) {
	//	printf("��\n");
	//}
	//else {
	//	printf("����\n");
	//}

	//2.����������
	//int a = 12, b = 45;
	//Swap(&a, &b);
	//printf("a=%d b=%d\n", a, b);

	//1.����˷��ھ���
	//printf("��������Ҫ��ӡ���ٵĳ˷��ھ���: ");
	//int n;
	//scanf("%d", &n);
	//PrintMul(n);

	system("pause");
	return 0;
}