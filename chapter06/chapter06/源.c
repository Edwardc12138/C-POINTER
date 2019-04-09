#include <stdio.h>
#include <stdlib.h>
#include "BitArray.h"

// ����source��ƥ��chars���ַ��ĵ�һ���ַ�������ָ������ַ���ָ��
const char *find_char(const char *source, const char *chars) {
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
	// ��β����
	for (int left = 0, right = len - 1; left < right;++left, --right) {
		char ch = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = ch;
	}
}

// Eratosthenesɸѡ��������
// �����ʾ��λ�ǲ�������,1��ʾ��,0��ʾ����
// ż��ֻ��2������,����������ֻ������
// arr[n]��Ӧ����2*n+3

// ʹ���ַ�����
void Prame(char *arr, const int size) {
	if (arr == NULL) {
		return;
	}
	// ������Ԫ��ֵ��ΪTRUE
	for (int i = 0; i < size; ++i) {
		*(arr + i) = 1;
	}
	// �޳�ż��,�ڶ�Ӧ��Ԫ������0
	for (int curr = 0; curr < size; ++curr) {
		if (*(arr + curr)) {	// ��λ��δ���޳�
			int span = 2 * curr + 3;	// �жϵĲ���
			for (int del = curr + span; del < size; del += span) {
				*(arr + del) = 0;			// �޳���λ��
			}
		}		
	}
}

// ʹ��λ����
void PrameUseBit(char *arr, int size) {
	if (arr == NULL) {
		return;
	}
	size *= 8;					// �����޸Ĳ���
	// ������Ԫ��ֵ��ΪTRUE
	for (int i = 0; i < size; ++i) {
		set_bit(arr, i);		// �����޸Ĳ���
	}
	// �޳�ż��,�ڶ�Ӧ��Ԫ������0
	for (int curr = 0; curr < size; ++curr) {
		if (test_bit(arr,curr)) {	// ��λ��δ���޳� // �����޸Ĳ���
			int span = 2 * curr + 3;	// �жϵĲ���
			for (int del = curr + span; del < size; del += span) {
				clear_bit(arr, del);	// �޳���λ�� // �����޸Ĳ���
			}
		}		
	}
}

// ͳ��ÿ1000�����ж��ٸ���������ӡ
void CountPrame(char *arr, int size) {
	if (arr == NULL) {
		return;
	}
	PrameUseBit(arr, size);		// ɸѡ����
	size *= 8;
	int count = 2;		// ������û��2,0~1000����1
	int frist = 1;		// ��һ��ִ��ѭ����־
	for (int curr = 1; curr < size; ++curr) {
		if (!frist) {	// ��һ�β����
			if (!(curr % 1000)) {		// ÿ��1000�������һ�μ���
				printf("%d ", count);
				count = 0;				// ��������
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
	// 6.ÿ��1000��Ԫ���ж�������
	char arr[125000];
	CountPrame(arr, 125000);

	// 5.ʹ��λ���麯��
	//char arr[1000];
	//PrameUseBit(arr, 1000);
	//printf("2");
	//for (int i = 0; i < 8000; ++i) {	// ѭ�����������
	//	if (test_bit(arr,i)) {			// �ж����������
	//		printf(" %d", 2 * i + 3);
	//	}
	//}

	// 4.Eratosthenesɸѡ��
	//char arr[1000];
	//Prame(arr, 1000);
	//printf("2");
	//for (int i = 0; i < 1000; ++i) {
	//	if (arr[i] == 1) {
	//		printf(" %d", 2 * i + 3);
	//	}
	//}


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