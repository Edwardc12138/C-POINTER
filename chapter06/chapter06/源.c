#include <stdio.h>
#include <stdlib.h>
#include "BitArray.h"

// 查找source中匹配chars中字符的第一个字符并返回指向这个字符的指针
const char *find_char(const char *source, const char *chars) {
	// 指针为空或字符串为空字符串
	if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0') {
		return NULL;
	}
	for (;*source != '\0';++source) {		// 遍历源字符串
		for (;chars != '\0';++chars) {		// 遍历给定的字符集合
			if (*source == *chars) {		// 存在匹配的字符
				return source;				// 返回指向源字符串中这个字符的指针
			}
		}
	}
	return NULL;	// 未找到
}

// 判断字符串是否相等
int mystrcmp(const char *source, const char *str) {
	if (source == NULL && str == NULL) {
		return 0;
	}
	int len = 0;
	for (;*source != '\0' && *str != '\0';++source, ++str) {	// 两个字符串都没有结束
		if (*source != *str) {		// 两个字符串内容不相同
			return 0;				// 返回0
		}
		++len;
	}
	if (*str != '\0') {		// 子字符串未遍历结束
		return 0;			// 返回0
	}
	return len;				// 两个字符串相等,返回相等长度
}

// 删除str中substr部分
int del_substr(char *str, const char *substr) {
	if (str == NULL || substr == NULL) {
		return 0;
	}
	int len = 0;
	for (;*str != '\0';++str) {		// 遍历str字符串
		if (!len) {
			len = mystrcmp(str, substr);
		}
		else {
			*(str - 1) = *(str + len - 1);	// 将相同部分之后的元素复制到前面
		}
	}
	if (len) {		// 返回长度,则删除成功
		return 1;
	}
	return 0;
}

//逆置字符串的字符
void reverse_string(char *str) {
	if (str == NULL) {
		return;
	}
	int len = 0;
	char *tmp = str;
	while (*tmp != '\0') {
		++tmp;
		++len;
	}
	// 首尾交换
	for (int left = 0, right = len - 1; left < right;++left, --right) {
		char ch = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = ch;
	}
}

// Eratosthenes筛选法求质数
// 数组表示该位是不是质数,1表示是,0表示不是
// 偶数只有2是质数,所以数组中只存奇数
// arr[n]对应数字2*n+3

// 使用字符数组
void Prame(char *arr, const int size) {
	if (arr == NULL) {
		return;
	}
	// 将所有元素值设为TRUE
	for (int i = 0; i < size; ++i) {
		*(arr + i) = 1;
	}
	// 剔除偶数,在对应的元素上置0
	for (int curr = 0; curr < size; ++curr) {
		if (*(arr + curr)) {	// 该位置未被剔除
			int span = 2 * curr + 3;	// 判断的步长
			for (int del = curr + span; del < size; del += span) {
				*(arr + del) = 0;			// 剔除该位置
			}
		}		
	}
}

// 使用位数组
void PrameUseBit(char *arr, int size) {
	if (arr == NULL) {
		return;
	}
	size *= 8;					// 函数修改部分
	// 将所有元素值设为TRUE
	for (int i = 0; i < size; ++i) {
		set_bit(arr, i);		// 函数修改部分
	}
	// 剔除偶数,在对应的元素上置0
	for (int curr = 0; curr < size; ++curr) {
		if (test_bit(arr,curr)) {	// 该位置未被剔除 // 函数修改部分
			int span = 2 * curr + 3;	// 判断的步长
			for (int del = curr + span; del < size; del += span) {
				clear_bit(arr, del);	// 剔除该位置 // 函数修改部分
			}
		}		
	}
}

// 统计每1000个数有多少个质数并打印
void CountPrame(char *arr, int size) {
	if (arr == NULL) {
		return;
	}
	PrameUseBit(arr, size);		// 筛选质数
	size *= 8;
	int count = 2;		// 数组中没有2,0~1000加上1
	int frist = 1;		// 第一次执行循环标志
	for (int curr = 1; curr < size; ++curr) {
		if (!frist) {	// 第一次不输出
			if (!(curr % 1000)) {		// 每隔1000个数输出一次计数
				printf("%d ", count);
				count = 0;				// 计数清零
			}
		}
		else {
			frist = 0;
		}
		if (test_bit(arr, curr)) {
			++count;
		}
	}
}

int main() {
	// 6.每隔1000个元素有多少质数
	char arr[125000];
	CountPrame(arr, 125000);

	// 5.使用位数组函数
	//char arr[1000];
	//PrameUseBit(arr, 1000);
	//printf("2");
	//for (int i = 0; i < 8000; ++i) {	// 循环次数需更改
	//	if (test_bit(arr,i)) {			// 判断条件需更改
	//		printf(" %d", 2 * i + 3);
	//	}
	//}

	// 4.Eratosthenes筛选法
	//char arr[1000];
	//Prame(arr, 1000);
	//printf("2");
	//for (int i = 0; i < 1000; ++i) {
	//	if (arr[i] == 1) {
	//		printf(" %d", 2 * i + 3);
	//	}
	//}


	// 3.编写函数,逆置字符串
	//char arr[] = "i have a pen!";
	//reverse_string(arr);
	//printf("%s\n", arr);

	// 2.编写一个函数,删除一个字符串的一部分
	//char str[] = "i have a pen";
	//del_substr(str, "have ");
	//printf("%s\n", str);

	// 1.编写一个函数,它在一个字符串中搜索,查找所有在一个给定字符集合中出现的字符
	//char chars[] = "acghi";	//给定的字符集合
	//int str[20];
	//printf("请输入: ");
	//gets(str);
	//char *p = find_char(str, chars);
	//if (p != NULL) {
	//	printf("%c\n", *p);
	//}
	//else {
	//	printf("未找到\n");
	//}

	system("pause");
	return 0;
}