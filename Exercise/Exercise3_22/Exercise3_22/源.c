#include <stdio.h>

//����������С��ͬ���ַ���������
void arrSwap(char arr1[], char arr2[]) {
	int len = strlen(arr1);
	char tmp;
	for (int i = 0; i < len; ++i) {
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

//����1/1 - 1/2 + 1/3......1/n��ֵ
double func(unsigned int n) {
	int k = 1;		//���ӵ�����
	double sum = 0;	//���
	for (int i = 1; i <= n; ++i) {
		sum += (double) k / i;
		k = 0 - k;
	}
	return sum;
}

//ͳ��1��n֮����ֶ��ٴ�9
int count(unsigned int n) {
	int result = 0;		//����
	for (int i = 1; i <= n; ++i) {
		int num = i;
		while (num) {
			if (num % 10 == 9) {
				++result;
			}
			num /= 10;
		}
	}
	return result;
}

int main() {
	//1.������������
	//char arr1[] = "a b c d e f g";
	//char arr2[] = "h i j k l m n";
	//arrSwap(arr1, arr2);
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);

	//2.����1/1 - 1/2 + 1/3...-1/100��ֵ
	//printf("������Ϊ: %g\n", func(100));

	//3.ͳ��1��100֮����ֹ����ٴ�9
	int n = 100;
	printf("1 �� %d ֮����ֹ� %d �� 9\n", n, count(n));

	system("pause");
	return 0;
}