#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>	// �ɱ�����б�
#include <string.h>

// ���ܶ���ʽ
int hermite(const int n, const int x) {
	if (n <= 0) {
		return 1;
	}
	if (n == 1) {
		return 2 * x;
	}
	int ret;
	int curr = 2 * x;	// ��ʼ�� 1 ��
	int prev = 1;		// ��ʼ�� 0 ��
	for (int i = 2; i <= n; ++i) {
		ret = 2 * x * curr - 2 * (i - 1) * prev;
		prev = curr;	// ǰһ��
		curr = ret;		// ǰǰһ��
	}
	return ret;
}

// M �� N �����Լ��
int gcd(int m, int n) {
	if (n <= 0) {
		return -1;
	}
	int r = 1;
	while (r) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

// ���ַ�����ת��Ϊ����
int ASCIIToInteger(char *str) {
	if (str == NULL) {
		return 0;
	}

	int sign = 1;	// Ĭ��������
	int ret = 0;
	int i = 0;		// Ĭ�ϲ���������λ

	if (str[0] == '-') {	// ����
		sign = -1;	// ����
		i = 1;		// ѭ����ʼλ��
	}

	for (; str[i] != '\0'; ++i) {	// ��������λ
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
		ret = ret * 10 + (str[i] - '0') ;
	}
	return ret * sign;
}

// ����������Ŀ���Ͳ��������ֵ,-1��β
int max_list(int num, ...) {
	int input;
	va_list var_arg;
	// ׼�����ʿɱ����
	va_start(var_arg, num);
	// ���ȡ�Կɱ�����б��ֵ
	while ((input = va_arg(var_arg, int)) != -1) {
		if (num < input) {
			num = input;
		}
	}
	va_end(var_arg);
	return num;
}

// �����ӡint������
void PrintInteger(int num) {
	printf("%d", num);
}

// �����ӡfloat������
void PrintFloat(double num) {
	printf("%f", num);
}

// ģ��printf
void Printf(char *str, ...) {
	if (str == NULL) {
		return;
	}

	va_list var;
	va_start(var, str);
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		if (str[curr] == '%') {
			if (str[++curr] == 'd') {		// ����
				PrintInteger(va_arg(var, int));
			}
			else if (str[curr] == 'f') {	// ����
				PrintFloat(va_arg(var, double));	// ������float
			}
			else if (str[curr] == 's') {	// �ַ���ѭ��putchar
				char *output = va_arg(var, char*);
				for (int i = 0; output[i] != '\0';++i) {
					putchar(output[i]);
				}
			}
			else if (str[curr] == 'c') {	// �ַ�ֱ��putchar
				putchar(va_arg(var, char));
			}
		}
		else {
			putchar(str[curr]);
		}
	}
	va_end(var);
}

// ����λ�����޷�����ת��Ϊ����
void three_to_str(unsigned int num, char*buffer) {
	if (buffer == NULL) {
		return;
	}

	// ��λ,0 ~ 19 ��һ��Ϊ��,�������ȡ�±�
	char *one_to_nineteen[20] = { "","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE",
		"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN",
		"SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN" };
	// ʮλ20,30,40 ... 90,���ַ�����ͬ��
	char *ten_place[10] = { "","","TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY" };

	if ((num / 100) != 0) {		// ��λ
		strcat(buffer, one_to_nineteen[num / 100]);
		strcat(buffer, " HUNDERD");
		if (num % 100 != 0) {
			strcat(buffer, " AND ");
		}
	}

	if ((num % 100) > 19) {		// ʮλ
		strcat(buffer, ten_place[num / 10 % 10]);
		if ((num % 10) != 0) {	// ��λ
			strcat(buffer, "-");
			strcat(buffer, one_to_nineteen[num % 10]);
		}
	}
	else if ((num % 100) > 0) {		// 0 ~ 19
		strcat(buffer, one_to_nineteen[num % 100]);
	}
}

// ���޷�����ת��Ϊ������ʽ
void written_amount(unsigned int amount, char *buffer) {
	if (amount == 0) {
	}
	if (amount == 0) {
		strcpy(buffer, "ZERO");
		return;
	}

	strcpy(buffer, "");	// ����buffer

	char *level_of_num[4] = { ""," THOUSAND "," MILLION "," BILLION " };	// ������
	int level = 0;
	int thousand = 1;
	for (int tmp = amount; (tmp /= 1000) > 0; ++level) {	// ������һ�ֶ�
		thousand *= 1000;
	}

	// high �����λ,ÿ�γ�һǧ,�ټ�һǧ,�����λ����ÿ������λ
	while (amount > 0) {
		int high = amount / thousand;	// ÿ�ε����λ
		three_to_str(high, buffer);
		strcat(buffer, level_of_num[level]);
		--level;
		amount -= high * thousand;
		//if ((thousand / 1000) != 0) {
			thousand /= 1000;
		//}
	}
}

int main() {
	// 6.��д����,���޷�������ת��Ϊ������ʽ
	unsigned int n;
	char buf[1024] = { 0 };
	while (1) {
		printf("������: ");
		scanf("%u", &n);
		written_amount(n, buf);
		printf("%s\n", buf);
	}

	// 5.ʵ��һ���򻯵�printf����,���ܹ�����%d,%f,%s,��%c��ʽ��
	//   �����Ѿ����ں���print_integer��print_float,���ڴ�ӡ���Ӧ������
	//   ��������,ʹ��putchar����ӡ
	//float a = 11.1f;
	//Printf("%f", a);
	//printf("%f", 11.1f);
	//Printf("first: %d\nnext: %f\nnext: %s\nlast: %c\n", 10, 11.111, "hahaha", 'A');

	// 4.��д����,���������Ŀ�����Ͳ���,���������е����ֵ,�����б���-1��β��ʾ����
	//printf("max = %d\n", max_list(0, 2, 9, 3, -1));

	// 3.��д����,��һ������һ���������ֵ��ַ���ת��Ϊ�����������������
	//   ��������κη������ַ�,�򷵻�0
	//char str[] = "-456789";
	//printf("%d\n", ASCIIToInteger(str));

	// 2.���� M �� N �����Լ��
	//int m, n;
	//printf("������������: ");
	//scanf("%d %d", &m, &n);
	//printf("���Լ��: %d\n", gcd(m, n));

	// 1.Hermite Polynomials (���ܶ���ʽ) ����Hn(x)��ֵ
	//int n, x;
	//printf("������n,x: ");
	//scanf("%d %d", &n, &x);
	//printf("H%d(%d) = %d\n", n, x, hermite(n, x));

	system("pause");
	return 0;
}