#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *a, char *b) {
	char ch = *a;
	*a = *b;
	*b = ch;
}

// 字符串循环左移k个字符
void LoopLeftShift(char *str, int k) {
	if (str == NULL) {
		return;
	}

	int len = strlen(str);

	// 执行k*strlen(str)次
	//for (int i = 0; i < k; ++i) {		
	//	for (int curr = 1; curr < len; ++curr) {
	//		Swap(&str[curr - 1], &str[curr]);
	//	}
	//}

	// 2
	char str_tmp[1024];
	while (k > 0) {
		int n = min(k, 1024);
		strncpy(str_tmp, str, n);
		for (int curr = n; curr <= len; ++curr) {
			Swap(&str[curr - n], &str[curr]);
		}
		strncat(str, str_tmp, n);
		k -= 2;
	}

	// 3

}

// 判断一个字符串是不是另一个字符串移动后的结果
int IsEqual(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL) {
		return -1;
	}
	int len = strlen(str1);
	if (len != strlen(str2)) {
		return 0;
	}
	for (int i = 0; i < len; ++i) {
		LoopLeftShift(str1, 1);
		if (!strcmp(str1, str2)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	//char str[] = "abcdefgh";
	//LoopLeftShift(str, 3);
	//printf("%s\n", str);

	char str1[] = "abcd";
	char str2[] = "ABCD";
	printf("%d\n", IsEqual(str1, str2));

	system("pause");
	return 0;
}