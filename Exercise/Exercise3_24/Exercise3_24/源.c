#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

//初始化界面
void InitGame() {
	printf("*****************************************\n");
	printf("********** 1.开始 ***** 0.退出 **********\n");
	printf("*****************************************\n");
	printf("请输入: ");
}

//游戏开始
void GameStart() {
	srand((unsigned int)time(NULL));	//设置随机种子
	int num = rand() % 100 + 1,			//设置游戏答案
		guess_num = 0;					//用户猜的数字
	printf("请输入您的答案: ");
	scanf("%d", &guess_num);
	while (guess_num != num) {
		if (guess_num > num) {
			printf("答案偏大\n");
		}
		else {
			printf("答案偏小\n");
		}
		scanf("%d", &guess_num);
	}
	printf("恭喜你,猜对了!\n");
}

//折半查找. 数组,待查找数,数组长度
int ToFind(int arr[], int num, int n) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num < arr[mid]) {		//小于arr[mid],right向左移
			right = mid - 1;
		}
		else if (num > arr[mid]) {	//大于arr[mid],left向右移
			left = mid + 1;
		}
		else {						//否则返回mid,即为所查
			return mid;
		}
	}
	return -1;						//未查找到
}

int main() {
	//1.猜数字(1~100)
	//while (1) {
	//	int state;
	//	InitGame();
	//	scanf("%d", &state);
	//	while (state != 1 && state != 0) {		//输入字符会进入死循环???
	//		printf("输入有误,请重输: ");
	//		scanf("%d", &state);
	//	}
	//	if (state == 0) {	//退出游戏
	//		break;
	//	}
	//	else {				//开始游戏
	//		system("cls");
	//		GameStart();
	//	}
	//	Sleep(1000);
	//}

	//2.在有序数组中查找数字
	//int arr[] = { 11,12,13,14,15,16,17,18,19,20 };
	//int num;
	//printf("请输入要查询的数: ");
	//scanf("%d", &num);
	//int result = ToFind(arr, num, sizeof(arr) / sizeof(arr[0]));
	//if ( result == -1) {
	//	printf("未找到此数\n");
	//}
	//else {
	//	printf("%d 在数组中的下标为 %d\n", num, result);
	//}

	//3.模拟密码输入三次的场景
	//char arr[20];
	//printf("请输入密码: ");
	//int i;
	//for (i = 0; i < 3; ++i) {
	//	gets(arr);
	//	if (strcmp(arr, "awsxcdery") == 0) {
	//		break;
	//	}
	//	if (i < 2) {
	//		printf("密码错误!您还有 %d 次机会!请重输: ", 2 - i);
	//	}
	//}
	//if (i == 3) {
	//	printf("密码错误!您的账号已被锁定!\n");
	//}
	//else {
	//	printf("密码正确!\n");
	//}

	//4.一直接收输入,小写转大写,大写转小写,其他不做反应
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