#include <stdio.h>
#include <stdlib.h>

// 查找source中匹配chars中字符的第一个字符并返回指向这个字符的指针
char *find_char(const char *source, const char *chars) {
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
	for (int left = 0, right = len - 1; left < right;++left, --right) {
		char ch = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = ch;
	}
}

// Eratosthenes筛选法求质数
void Prame(char *begin, char *end) {
	for (char *p = begin + 1; p != end; ++p) {

	}
}

int main() {
	// 4.

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