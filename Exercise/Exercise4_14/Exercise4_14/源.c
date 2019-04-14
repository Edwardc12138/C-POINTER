#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// �ַ�������
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

// �ַ���ƴ��
char* Strcat(char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	char *pdest = dest;
	while (pdest[0] != '\0') {	// ��pdestָ��dest��ĩβ
		++pdest;
	}
	int curr = 0;
	for (; src[curr] != '\0'; ++curr) {	// ��src�����ݸ��Ƶ�pdestָ���λ��
		pdest[curr] = src[curr];
	}
	pdest[curr] = '\0';
	return dest;
}

// �����ַ���
const char* Strstr(const char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	const char *psrc = src;		// �����Ƚ�src֮����ַ�
	const char *ret = dest;		// �����洢dest����src��ȵĵ�һ��λ��
	for (int curr = 0; dest[curr] != 0; ++curr) {
 		if (dest[curr] == psrc[0]) {// ���,�Ƚ���һ���ַ�
			++psrc;
		}
		else if (psrc != src) {		// ���й��Ƚϵ������
			psrc = src;				// ��ԭ���ڱȽ�֮���ַ���ָ��
			ret = dest + curr;		// ��һ����ͬλ�ø���
			--curr;					// ��һ�δӵ�ǰλ�ñȽ�,���� ++curr
		}
		else {						// �����
			++ret;					// ���µ�һ�����λ��
		}
		if (psrc[0] == '\0') {		// �ַ�����ȫ���
			return ret;				// ���ص�һ�����λ��
		}
	}
	return NULL;					// dest�в�����src,����NULL
}

// �����ַ�
const char* Strchr(const char *dest, char ch) {
	if (dest == NULL) {
		return NULL;
	}

	for (int curr = 0; dest[curr] != '\0'; ++curr) {
		if (dest[curr] == ch) {		// ���
			return dest + curr;		// ���ص�ǰλ��
		}
	}
	return NULL;
}

// �Ƚ��ַ��� str1 < str2 ��������, > ���ظ���, == ����0
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

// �����ڴ�,����֤�ڴ��ص�ʱ�����������ȷ��
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

// �����ڴ�,�ܹ���֤�ڴ��ص�ʱ��������ȷ��
void* Memmove(void *dest, const void *src, size_t num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;
	if (psrc < pdest && pdest < (psrc + num)) {		// �����������ڴ�ռ��ڰ�����Ŀ���ַʱ
		for (size_t curr = num; curr > 0; --curr) {	// �Ӻ���ǰ����
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