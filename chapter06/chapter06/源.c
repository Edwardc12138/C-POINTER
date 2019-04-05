#include <stdio.h>
#include <stdlib.h>

// ����source��ƥ��chars���ַ��ĵ�һ���ַ�������ָ������ַ���ָ��
char *find_char(const char *source, const char *chars) {
	// ָ��Ϊ�ջ��ַ���Ϊ���ַ���
	if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0') {
		return NULL;
	}
	for (;*source != '\0';++source) {		// ����Դ�ַ���
		for (;chars != '\0';++chars) {		// �����������ַ�����
			if (*source == *chars) {		// ����ƥ����ַ�
				return source;				// ����ָ��Դ�ַ���������ַ���ָ��
			}
		}
	}
	return NULL;	// δ�ҵ�
}

// �ж��ַ����Ƿ����
int mystrcmp(const char *source, const char *str) {
	if (source == NULL && str == NULL) {
		return 0;
	}
	int len = 0;
	for (;*source != '\0' && *str != '\0';++source, ++str) {	// �����ַ�����û�н���
		if (*source != *str) {		// �����ַ������ݲ���ͬ
			return 0;				// ����0
		}
		++len;
	}
	if (*str != '\0') {		// ���ַ���δ��������
		return 0;			// ����0
	}
	return len;				// �����ַ������,������ȳ���
}

// ɾ��str��substr����
int del_substr(char *str, const char *substr) {
	if (str == NULL || substr == NULL) {
		return 0;
	}
	int len = 0;
	for (;*str != '\0';++str) {		// ����str�ַ���
		if (!len) {
			len = mystrcmp(str, substr);
		}
		else {
			*(str - 1) = *(str + len - 1);	// ����ͬ����֮���Ԫ�ظ��Ƶ�ǰ��
		}
	}
	if (len) {		// ���س���,��ɾ���ɹ�
		return 1;
	}
	return 0;
}

//�����ַ������ַ�
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

// Eratosthenesɸѡ��������
void Prame(char *begin, char *end) {
	for (char *p = begin + 1; p != end; ++p) {

	}
}

int main() {
	// 4.

	// 3.��д����,�����ַ���
	//char arr[] = "i have a pen!";
	//reverse_string(arr);
	//printf("%s\n", arr);

	// 2.��дһ������,ɾ��һ���ַ�����һ����
	//char str[] = "i have a pen";
	//del_substr(str, "have ");
	//printf("%s\n", str);

	// 1.��дһ������,����һ���ַ���������,����������һ�������ַ������г��ֵ��ַ�
	//char chars[] = "acghi";	//�������ַ�����
	//int str[20];
	//printf("������: ");
	//gets(str);
	//char *p = find_char(str, chars);
	//if (p != NULL) {
	//	printf("%c\n", *p);
	//}
	//else {
	//	printf("δ�ҵ�\n");
	//}

	system("pause");
	return 0;
}