#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//输出 n * n 乘法口诀表
void PrintMul(int n) {
	if (n < 1) {	//n < 1,不输出
		return;
	}
	for (int row = 1; row <= n; row++)	//输出乘法口诀表
	{
		for (int col = 1; col <= row; col++)
			printf("%d*%d=%d\t", col, row, col*row);
		printf("\n");
	}
}

//交换两个整型
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//判断是否是闰年,1表示是,0表示否
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

//初始化整型数组
void Init(int arr[], int cap) {
	for (int curr = 0; curr < cap; ++curr) {
		arr[curr] = curr;
	}
}

//清空数组
void Empty(int arr[], int cap) {
	for (int curr = 0; curr < cap; ++curr) {
		arr[curr] = 0;
	}
}

//数组逆置
void Reverse(int arr[], int cap) {
	for (int left = 0, right = cap - 1; left <= right; ++left, --right) {
		Swap(&arr[left], &arr[right]);
	}
}

//打印数组
void PrintArr(int arr[], int size) {
	for (int curr = 0; curr < size; ++curr) {
		printf("%d ", arr[curr]);
	}
	printf("\n");
}

//是否是质数
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = sqrt(n);
	for (int i = 2; i <= square_n; ++i) {	//从2除到n的平方根,之后的不用判断
		if (n % i == 0) {
			return 0;	//不是质数
		}
	}
	return 1;			//是质数
}

int main() {
	//5.判断素数
	printf("请输入数字: ");
	int num;
	scanf("%d", &num);
	if (IsPrime(num)) {
		printf("是质数\n");
	}
	else {
		printf("不是质数\n");
	}

	//4.数组操作
	//int arr[20];
	//int size = sizeof(arr) / sizeof(arr[0]);
	//Init(arr, size);
	//printf("初始化数组: ");
	//PrintArr(arr, size);
	//Reverse(arr, size);
	//printf("  逆置数组: ");
	//PrintArr(arr, size);
	//Empty(arr, size);
	//printf("  清空数组: ");
	//PrintArr(arr, size);

	//3.判断闰年
	//int year,
	//	leap_year;
	//printf("请输入年份: ");
	//scanf("%d", &year);
	//if (IsLeapYear(year)) {
	//	printf("是\n");
	//}
	//else {
	//	printf("不是\n");
	//}

	//2.交换两个数
	//int a = 12, b = 45;
	//Swap(&a, &b);
	//printf("a=%d b=%d\n", a, b);

	//1.输出乘法口诀表
	//printf("请输入需要打印多少的乘法口诀表: ");
	//int n;
	//scanf("%d", &n);
	//PrintMul(n);

	system("pause");
	return 0;
}