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
							a * b * c * d * e == 120) {		// a b c d e�����������ͬ
							if ((b == 2) ^ (a == 3) &&		// a˵������
								(b == 2) ^ (e == 4) &&		// b˵������
								(c == 1) ^ (d == 2) &&		// c˵������
								(c == 5) ^ (d == 3) &&		// d˵������
								(e == 4) ^ (a == 1)) {		// e˵������
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
	//	// ÿ��ֻ��һ����˵��
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
		// ֻ��һ����˵��,����3��1��
		//     A˵����A          B˵��C           C˵��D          D˵C��˵
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D') == 3) {
			printf("������ %c\n", muder);
		}
	}
}

// ��ӡ�������,n ����
void PrintPascalsTriangle(int n) {
	// �ҵ��뷨
	//int arr[2][1024] = { 0 };	// arr[0]�洢��һ�е�����,arr[1]�洢��ǰ�е�����
	//arr[0][1] = 1;

	//for (int row = 1; row <= n; ++row) {	// ���n��
	//	for (int col = 1; col <= row; ++col) {	// һ�����n����
	//		arr[1][col] = arr[0][col] + arr[0][col - 1];	// ��ǰ�е�i��������һ�е�i����i-1��֮��
	//		printf("%d ", arr[1][col]);
	//	}
	//	printf("\n");
	//	for (int col = 1; col <= row; ++col) {	// ��ǰ�б�Ϊ��һ��
	//		arr[0][col] = arr[1][col];
	//	}
	//}

	// ʱ��ռ����Ž�
	if (n < 1) {
		return;
	}

	printf("1\n");		// �����һ��1
	for (int row = 2; row <= n; ++row) {
		int s = 1;
		printf("1 ");	// ÿ�е�һ��1
		for (int col = 1; col <= row - 2; ++col) {
			printf("%d ", s = (row - col) * s / col);
		}
		printf("1\n");	// ÿ�����һ��1
	}
}

int main() {
	//Func1();
	Func2();
	//PrintPascalsTriangle(10);

	system("pause");
	return 0;
}