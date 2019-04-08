#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ������Ԫ����������ǰ�벿��,ż�����ں�벿��
void Parity(int arr[], int size) {
	if (arr == NULL) {
		return;
	}

	int div = 0;	// ��ż�ֽ��
	for (int curr = 0; curr < size; ++curr) {
		if (arr[curr] % 2) {			// ��������ŵ�ǰ��
			Swap(&arr[div], &arr[curr]);
			++div;
		}
	}
}

// ��һ�������Һʹ��ϵ��¶��ǵ����Ķ�ά���������������
// δ�ҵ�����-1,�ҵ�����λ��
int FindNum(int *arr, int max_row, int max_col, int num) {
	if (arr == NULL || max_row < 0 || max_col < 0) {
		return -1;
	}

	int curr_col = max_col;
	// �Ӷ�ά����ĵ�һ�����һ�п�ʼ����
	for (int row = 0; row < max_row; ++row) {
		for (int col = curr_col - 1; col >= 0; --col) {
			int curr = row * max_col + col;	// ��ǰ��
			if (num < *(arr + curr)) {		// ���������ȵ�ǰ��С
				--curr_col;					// ��һ���ų�
				continue;
			}
			else if (num > *(arr + curr)) {	// ���������ȵ�ǰ����
				break;						// ��һ���ų�
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