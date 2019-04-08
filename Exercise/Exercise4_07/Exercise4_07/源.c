#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 将数组元素奇数放在前半部分,偶数放在后半部分
void Parity(int arr[], int size) {
	if (arr == NULL) {
		return;
	}

	int div = 0;	// 奇偶分界点
	for (int curr = 0; curr < size; ++curr) {
		if (arr[curr] % 2) {			// 奇数将其放到前面
			Swap(&arr[div], &arr[curr]);
			++div;
		}
	}
}

// 在一个从左到右和从上到下都是递增的二维数组里面查找数字
// 未找到返回-1,找到返回位置
int FindNum(int *arr, int max_row, int max_col, int num) {
	if (arr == NULL || max_row < 0 || max_col < 0) {
		return -1;
	}

	int curr_col = max_col;
	// 从二维数组的第一行最后一列开始查找
	for (int row = 0; row < max_row; ++row) {
		for (int col = curr_col - 1; col >= 0; --col) {
			int curr = row * max_col + col;	// 当前数
			if (num < *(arr + curr)) {		// 待查找数比当前数小
				--curr_col;					// 这一列排除
				continue;
			}
			else if (num > *(arr + curr)) {	// 待查找数比当前数大
				break;						// 这一行排除
			}
			else {
				return curr;
			}
		}
	}
	return -1;
}

int main() {
	// 1
	//int arr[] = { 5,4,6,8,9,7,1,2,3,45,13 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//Parity(arr, size);
	//for (int curr = 0; curr < size; ++curr) {
	//	printf("%d ", arr[curr]);
	//}
	//printf("\n");

	// 2
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	printf("%d\n", FindNum((int*)arr, 3, 3, 7));


	system("pause");
	return 0;
}