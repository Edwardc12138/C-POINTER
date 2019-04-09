#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 函数指针,指针数组,转移表

// 加
int Add(int a, int b) {
	return a + b;
}

// 减
int Sub(int a, int b) {
	return a - b;
}

// 乘
int Mul(int a, int b) {
	return a * b;
}

// 除
int Div(int a, int b) {
	return a / b;
}

int main() {
	int input = 1;
	int(*p[5])(int a, int b) = { 0, Add, Sub, Mul, Div };	// 转移表
	while (input) {
		system("cls");
		printf("****************************\n");
		printf("*** 1:Add ******** 2:Sub ***\n");
		printf("*** 3:Mul ******** 4:Div ***\n");
		printf("********** 0:Exit **********\n");
		printf("****************************\n");
		
		printf("请选择: ");
		scanf("%d", &input);
		while (input < 0 || input > 4) {
				printf("输入有误!请重输: ");
				scanf("%d", &input);
		}
		if (!input) {
			return;
		}

		int a, b;
		printf("输入操作数: ");
		scanf("%d %d", &a, &b);
		printf("%d\n", (*p[input])(a, b));
		system("pause");
	}

	return 0;
}