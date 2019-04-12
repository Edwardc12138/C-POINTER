#include <stdio.h>
#include <stdlib.h>

int IsAlong(int *arr, int n) {
	int ret = 0;
	for (int curr = 0; curr < n; ++curr) {
		ret |= (1 << arr[curr]);
	}
	return ret == 0x3e;
}

// 1
void Func1() {
	int arr[5] = { 0 };
	for (arr[0] = 1; arr[0] <= 5; ++arr[0]) {
		for (arr[1] = 1; arr[1] <= 5; ++arr[1]) {
			for (arr[2] = 1; arr[2] <= 5; ++arr[2]) {
				for (arr[3] = 1; arr[3] <= 5; ++arr[3]) {
					for (arr[4] = 1; arr[4] <= 5;++arr[4]) {
						//if (arr[0] * arr[1] * arr[2] * arr[3] * arr[4] == 120 &&	// 五个数互不相同
						if (IsAlong(arr,5) &&
							(arr[1] == 2) ^ (arr[0] == 3) &&		// a说的条件
							(arr[1] == 2) ^ (arr[4] == 4) &&		// b说的条件
							(arr[2] == 1) ^ (arr[3] == 2) &&		// c说的条件
							(arr[2] == 5) ^ (arr[3] == 3) &&		// d说的条件
							(arr[4] == 4) ^ (arr[0] == 1)) {		// e说的条件
							printf("a = %d b = %d c = %d d = %d e = %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
							return;
						}
					}
				}
			}
		}
	}
}

void Func2() {
	//for (int i = 0; i < 4; ++i) {
	//	int a = 0, b = 0, c = 0, d = 0;
	//	// 每回只有一个人说谎
	//	if (i == 0) {
	//		a = 1;
	//	}
	//	else {
	//		a = 0;
	//	}

	//	if (i == 1) {
	//		c = 0;
	//	}
	//	else {
	//		c = 1;
	//	}

	//	if (i == 2) {
	//		d = 0;
	//	}
	//	else {
	//		d = 1;
	//	}

	//	if (i == 3) {
	//		d = 1;
	//	}
	//	else {
	//		d = 0;
	//	}
	//	if ((a + b + c + d) == 1) {
	//		printf("a = %d b = %d c = %d d = %d\n", a, b, c, d);
	//	}
	//}


	for (char muder = 'A';muder <= 'D'; ++muder) {
		// 只有一个人说谎,条件3真1假
		//     A说不是A          B说是C           C说是D          D说C胡说
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D') == 3) {
			printf("凶手是 %c\n", muder);
		}
	}
}

// 打印杨辉三角,n 行数
void PrintPascalsTriangle(int n) {
	if (n < 1) {
		return;
	}

	// 相当于两个一维数组来回交换
	//int arr[2][1024] = { 0 };	// arr[0]存储上一行的内容,arr[1]存储当前行的内容
	//arr[0][1] = 1;

	//for (int row = 1; row <= n; ++row) {	// 输出n行
	//	for (int col = 1; col <= row; ++col) {	// 一行输出n个数
	//		arr[1][col] = arr[0][col] + arr[0][col - 1];	// 当前行第i个等于上一行第i个和i-1个之和
	//		printf("%d ", arr[1][col]);
	//	}
	//	printf("\n");
	//	for (int col = 1; col <= row; ++col) {	// 当前行变为上一行
	//		arr[0][col] = arr[1][col];
	//	}
	//}

	// 时间空间最优解
	//printf("1\n");		// 输出第一个1
	//for (int row = 2; row <= n; ++row) {
	//	int s = 1;
	//	printf("1 ");	// 每行第一个1
	//	for (int col = 1; col <= row - 2; ++col) {
	//		printf("%d ", s = (row - col) * s / col);
	//	}
	//	printf("1\n");	// 每行最后一个1
	//}

	// 使用一维数组
	int arr[1024] = { 0 };
	printf("%d\n", arr[0] = 1);	// 第一行
	for (int row = 2; row <= n; ++row) {
		printf("1 ");	// 每行第一个1
		for (int col =  row - 1; col > 1; --col) {
			// 当前位置值等于它自己加上前一个数
			printf("%d ", arr[col - 1] += arr[col - 2]);
		}
		printf("%d\n", arr[row - 1] = 1);	// 每行最后一个1
	}
}

int main() {
	// 1
	Func1();

	// 2
	//Func2();

	// 3
	//PrintPascalsTriangle(10);

	system("pause");
	return 0;
}