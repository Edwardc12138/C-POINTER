#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1.ʵ���޷���������λ������
unsigned int reverse_bit(unsigned int value) {
	int total_bits = sizeof(unsigned int) * 8;	//�ܹ��ж���λ
	int val_reverse = 0;
	for (int bit = 0; bit < total_bits; ++bit, value /= 2) {
		val_reverse = val_reverse * 2 + (value % 2);
	}
	return val_reverse;
}

// 2.��������ƽ��ֵ
double Average(double a, double b) {
	return a - (a - b) / 2;
}

// 3.�ҵ�һ������ֻ���ֹ�һ�ε���
int FindAlong(int arr[], int n) {
	for (int curr = 0; curr < n; ++curr) {		// ��������
		int tmp = ~arr[curr];					// �Ե�ǰ��ȡ��
		int next = curr + 1;
		for (; next < n; ++next) {				// ����һ��λ���ж��Ƿ�����뵱ǰֵ��ȵ���
			if ((~(tmp ^ arr[next])) == 0) {	// ȡ���ĵ�ǰ����֮����������ȡ�����Ϊ0,�������������
				int a = arr[curr + 1];			// �����뵱ǰ����ͬ�����뵱ǰλ�õ���һλ�õ���
				arr[curr + 1] = arr[next];
				arr[next] = a;
				++curr;							// ������һ��ѭ��
				break;
			}
		}
		if (next == n) {						// δ�ҵ�
			return arr[curr];					// ���ص�ǰ��
		}
	}
	return -1;
}

// 4
// ����[left, right]֮�������Ԫ��
void ReverseArr(char* left, char* right) {
	for (; left < right; ++left, --right) {
		char ch = *left;
		*left = *right;
		*right = ch;
	}
}


void ReverseStr(char str[]) {
	int len = 0;
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		++len;
	}
	ReverseArr(str, str + len - 1);	// ��������
	for (int left = 0; left < len; ++left) {
		int right = left;
		for (; right < len && str[right] != ' '; ++right);	//�ҵ�ÿ������
		if (right - left < 2) {			//���ʳ���С��1,�����ı�
			left = right;
			continue;
		}
		if (right == len) {				// ���һ����������
			ReverseArr(str + left, str + right - 1);
			return;
		}
		ReverseArr(str + left, str + right - 1);	// ÿһ����������
		left = right;
	}
}

int main() {
	// 1
	//unsigned int val;
	//printf("������: ");
	//scanf("%u", &val);
	//printf("���ú�: %u\n", reverse_bit(val));

	// 2
	//double a, b;
	//printf("������: ");
	//scanf("%lf %lf", &a, &b);
	//printf("ƽ��ֵ: %f\n", Average(a, b));

	// 3
	//int arr[] = { 12,45,56,45,12,23,56 };
	//printf("%d\n", FindAlong(arr, sizeof(arr) / sizeof(arr[0])));

	char arr[] = "student a am i";
	printf("%s\n", arr);
	ReverseStr(arr);
	printf("%s\n", arr);

	system("pause");
	return 0;
}