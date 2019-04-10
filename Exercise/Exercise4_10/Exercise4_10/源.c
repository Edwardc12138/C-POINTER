#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// �ҳ�������ֻ���������ֹ�һ�ε�����
int FindNum(int *arr, const int size, int *out_a, int *out_b) {
	if (arr == NULL) {
		return -1;
	}
	int flag = 1;
	for (int curr = 0; curr < size; ++curr) {
		int next = curr + 1;
		for (; next < size; ++next) {
			if (arr[curr] == arr[next]) {
				swap(&arr[++curr], &arr[next]);
				break;
			}
		}
		if (next != size) {
			continue;
		}
		if (flag) {
			*out_a = arr[curr];
			flag = 0;
		}
		else {
			*out_b = arr[curr];
			return 1;
		}
	}
	return 0;
}

// ����ˮ,һԪһƿ,������ƿ��һƿ
int Drink(int money) {
	if (money < 0) {	// ûǮ
		return 0;
	}
	// һԪһƿ
	int sum = money;			// �ܹ�����ƿ
	int empty_bottle = money;	// ��ǰ�ж��ٿ�ƿ��
	while (empty_bottle > 1) {
		// ��ƿ��һƿ
		sum += empty_bottle / 2;
		// ��ƿ������ʣ���ƿ�����»��Ŀ�ƿ
		empty_bottle = empty_bottle % 2 + empty_bottle / 2;
	}
	return sum;
	//return 2 * money - 1;
}

char* Strcpy(char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int curr = 0;
	for (; src[curr] != '\0'; ++curr) {
		dest[curr] = src[curr];
	}
	dest[curr] = '\0';
	return dest;
}

char* Strcat(char *dest, char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int i = 0;
	for (; dest[i] != '\0'; ++i);
	Strcpy(dest + i, src);
	return dest;
}

int main() {
	// 4
	char str1[1024] = "i have a pen! ";
	char str2[] = "i have an apple!";
	Strcat(str1, str2);
	printf("%s\n", str1);

	// 3
	//char str1[] = "i have a pen!";
	//char str2[1024];
	//Strcpy(str2, str1);
	//printf("%s\n", str2);

	// 2
	//int money;
	//printf("��ˮһԪһƿ,������ƿ���Ի�һƿ\n���ж���Ǯ: ");
	//scanf("%d", &money);
	//printf("�������Ժ� %d ƿ��ˮ\n", Drink(money));

	// 1
	//int arr[] = { 1, 6, 5, 4, 6, 5, 1, 8, 2, 8 };
	//int a = 0, b = 0;
	//if (FindNum(arr, sizeof(arr) / sizeof(arr[0]), &a, &b)) {
	//	printf("%d %d\n", a, b);
	//}

	system("pause");
	return 0;
}