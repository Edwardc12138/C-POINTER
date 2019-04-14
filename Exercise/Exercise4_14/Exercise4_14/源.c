#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 字符串拷贝
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

// 字符串拼接
char* Strcat(char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	char *pdest = dest;
	while (pdest[0] != '\0') {	// 将pdest指向dest的末尾
		++pdest;
	}
	int curr = 0;
	for (; src[curr] != '\0'; ++curr) {	// 将src的内容复制到pdest指向的位置
		pdest[curr] = src[curr];
	}
	pdest[curr] = '\0';
	return dest;
}

// 查找字符串
const char* Strstr(const char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	const char *psrc = src;		// 用来比较src之后的字符
	const char *ret = dest;		// 用来存储dest中与src相等的第一个位置
	for (int curr = 0; dest[curr] != 0; ++curr) {
 		if (dest[curr] == psrc[0]) {// 相等,比较下一个字符
			++psrc;
		}
		else if (psrc != src) {		// 进行过比较但不相等
			psrc = src;				// 还原用于比较之后字符的指针
			ret = dest + curr;		// 第一个相同位置跟新
			--curr;					// 下一次从当前位置比较,抵消 ++curr
		}
		else {						// 不相等
			++ret;					// 更新第一个相等位置
		}
		if (psrc[0] == '\0') {		// 字符串完全相等
			return ret;				// 返回第一个相等位置
		}
	}
	return NULL;					// dest中不包含src,返回NULL
}

// 查找字符
const char* Strchr(const char *dest, char ch) {
	if (dest == NULL) {
		return NULL;
	}

	for (int curr = 0; dest[curr] != '\0'; ++curr) {
		if (dest[curr] == ch) {		// 相等
			return dest + curr;		// 返回当前位置
		}
	}
	return NULL;
}

// 比较字符串 str1 < str2 返回正数, > 返回负数, == 返回0
int Strcmp(const char *str1, const char *str2) {
	assert(str1 != NULL && str2 != NULL);

	int curr = 0;
	for (; str1[curr] != '\0' && str2[curr] != '\0'; ++curr) {
		if (str1[curr] < str2[curr]) {
			return 1;
		}
		else if (str1[curr] > str2[curr]) {
			return -1;
		}
	}
	if (str1[curr] < str2[curr]) {
		return 1;
	}
	else if (str1[curr] > str2[curr]) {
		return -1;
	}
	else {
		return 0;
	}
}

// 拷贝内存,不保证内存重叠时拷贝结果的正确性
void* Memcpy(void *dest, const void *src, size_t num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;
	for (size_t curr = 0; curr < num; ++curr) {
		pdest[curr] = psrc[curr];
	}
	return dest;
}

// 拷贝内存,能够保证内存重叠时拷贝的正确性
void* Memmove(void *dest, const void *src, size_t num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;
	if (psrc < pdest && pdest < (psrc + num)) {		// 当待拷贝的内存空间内包含有目标地址时
		for (size_t curr = num; curr > 0; --curr) {	// 从后向前拷贝
			pdest[curr - 1] = psrc[curr - 1];
		}
	}
	else {
		for (size_t curr = 0; curr < num; ++curr) {
			pdest[curr] = psrc[curr];
		}
	}
	return dest;
}

int main() {
	char str1[1024] = "memmove can be very useful......";
	char str2[1024] = "apple pen, pineapple pen, pen pineapple apple pen.";

	//printf("%s\n", Strcpy(str1, str2));
	//printf("%s\n", Strcat(str1, str2));
	//printf("%s\n", Strstr(str1, "pen"));
	//printf("%s\n", Strchr(str1, 'p'));
	//printf("%d\n", Strcmp(str1, str2));
	//printf("%s\n", (char*)Memcpy(str1, str2, 12));
	Memmove(str1 + 20, str1 + 15, 11);
	printf("%s\n", str1);

	system("pause");
	return 0;
}