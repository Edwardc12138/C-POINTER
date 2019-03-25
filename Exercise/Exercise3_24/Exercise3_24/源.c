#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

//��ʼ������
void InitGame() {
	printf("*****************************************\n");
	printf("********** 1.��ʼ ***** 0.�˳� **********\n");
	printf("*****************************************\n");
	printf("������: ");
}

//��Ϸ��ʼ
void GameStart() {
	srand((unsigned int)time(NULL));	//�����������
	int num = rand() % 100 + 1,			//������Ϸ��
		guess_num = 0;					//�û��µ�����
	printf("���������Ĵ�: ");
	scanf("%d", &guess_num);
	while (guess_num != num) {
		if (guess_num > num) {
			printf("��ƫ��\n");
		}
		else {
			printf("��ƫС\n");
		}
		scanf("%d", &guess_num);
	}
	printf("��ϲ��,�¶���!\n");
}

//�۰����. ����,��������,���鳤��
int ToFind(int arr[], int num, int n) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num < arr[mid]) {		//С��arr[mid],right������
			right = mid - 1;
		}
		else if (num > arr[mid]) {	//����arr[mid],left������
			left = mid + 1;
		}
		else {						//���򷵻�mid,��Ϊ����
			return mid;
		}
	}
	return -1;						//δ���ҵ�
}

int main() {
	//1.������(1~100)
	//while (1) {
	//	int state;
	//	InitGame();
	//	scanf("%d", &state);
	//	while (state != 1 && state != 0) {		//�����ַ��������ѭ��???
	//		printf("��������,������: ");
	//		scanf("%d", &state);
	//	}
	//	if (state == 0) {	//�˳���Ϸ
	//		break;
	//	}
	//	else {				//��ʼ��Ϸ
	//		system("cls");
	//		GameStart();
	//	}
	//	Sleep(1000);
	//}

	//2.�����������в�������
	//int arr[] = { 11,12,13,14,15,16,17,18,19,20 };
	//int num;
	//printf("������Ҫ��ѯ����: ");
	//scanf("%d", &num);
	//int result = ToFind(arr, num, sizeof(arr) / sizeof(arr[0]));
	//if ( result == -1) {
	//	printf("δ�ҵ�����\n");
	//}
	//else {
	//	printf("%d �������е��±�Ϊ %d\n", num, result);
	//}

	//3.ģ�������������εĳ���
	//char arr[20];
	//printf("����������: ");
	//int i;
	//for (i = 0; i < 3; ++i) {
	//	gets(arr);
	//	if (strcmp(arr, "awsxcdery") == 0) {
	//		break;
	//	}
	//	if (i < 2) {
	//		printf("�������!������ %d �λ���!������: ", 2 - i);
	//	}
	//}
	//if (i == 3) {
	//	printf("�������!�����˺��ѱ�����!\n");
	//}
	//else {
	//	printf("������ȷ!\n");
	//}

	//4.һֱ��������,Сдת��д,��дתСд,����������Ӧ
	char ch;
	while (ch = getchar()) {
		if (ch >= 'A' && ch <= 'Z') {
			ch += 32;
		}
		else if (ch >= 'a'&& ch <= 'z') {
			ch -= 32;
		}
		putchar(ch);
	}

	system("pause");
	return 0;
}