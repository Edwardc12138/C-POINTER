#include <stdio.h>
#include <stdlib.h>

// 1
void Func1() {
	for (int a = 1; a <= 5; ++a) {
		for (int b = 1; b <= 5; ++b) {
			for (int c = 1; c <= 5; ++c) {
				for (int d = 1; d <= 5; ++d) {
					for (int e = 1; e <= 5;++e) {
						if (/*a != b && a != c && a != d && a != e &&
							b != c && b != d && b != e &&
							c != d && c != e &&
							d != e*/
							a * b * c * d * e == 120) {		// a b c d e五个数互不相同
							if ((b == 2) ^ (a == 3) &&		// a说的条件
								(b == 2) ^ (e == 4) &&		// b说的条件
								(c == 1) ^ (d == 2) &&		// c说的条件
								(c == 5) ^ (d == 3) &&		// d说的条件
								(e == 4) ^ (a == 1)) {		// e说的条件
								printf("a = %d b = %d c = %d d = %d e = %d\n", a, b, c, d, e);
								//return;
							}
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

	//
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
	// 我的想法
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
	if (n < 1) {
		return;
	}

	printf("1\n");		// 输出第一个1
	for (int row = 2; row <= n; ++row) {
		int s = 1;
		printf("1 ");	// 每行第一个1
		for (int col = 1; col <= row - 2; ++col) {
			printf("%d ", s = (row - col) * s / col);
		}
		printf("1\n");	// 每行最后一个1
	}
}

int main() {
	//Func1();
	Func2();
	//PrintPascalsTriangle(10);

	system("pause");
	return 0;
}