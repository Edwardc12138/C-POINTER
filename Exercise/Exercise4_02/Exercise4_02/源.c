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
						//if (arr[0] * arr[1] * arr[2] * arr[3] * arr[4] == 120 &&	// �����������ͬ
						if (IsAlong(arr,5) &&
							(arr[1] == 2) ^ (arr[0] == 3) &&		// a˵������
							(arr[1] == 2) ^ (arr[4] == 4) &&		// b˵������
							(arr[2] == 1) ^ (arr[3] == 2) &&		// c˵������
							(arr[2] == 5) ^ (arr[3] == 3) &&		// d˵������
							(arr[4] == 4) ^ (arr[0] == 1)) {		// e˵������
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
	if (n < 1) {
		return;
	}

	// �൱������һά�������ؽ���
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
	//printf("1\n");		// �����һ��1
	//for (int row = 2; row <= n; ++row) {
	//	int s = 1;
	//	printf("1 ");	// ÿ�е�һ��1
	//	for (int col = 1; col <= row - 2; ++col) {
	//		printf("%d ", s = (row - col) * s / col);
	//	}
	//	printf("1\n");	// ÿ�����һ��1
	//}

	// ʹ��һά����
	int arr[1024] = { 0 };
	printf("%d\n", arr[0] = 1);	// ��һ��
	for (int row = 2; row <= n; ++row) {
		printf("1 ");	// ÿ�е�һ��1
		for (int col =  row - 1; col > 1; --col) {
			// ��ǰλ��ֵ�������Լ�����ǰһ����
			printf("%d ", arr[col - 1] += arr[col - 2]);
		}
		printf("%d\n", arr[row - 1] = 1);	// ÿ�����һ��1
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