#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ж��Ƿ�������
int IsLeapYear(int year) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			return 1;
		}
	}
	else {
		if (year % 4 == 0) {
			return 1;
		}
	}
	return 0;
}

int hunger;	//������

//�Ƿ񼢶�
int hungry() {
	if (hunger > 0) {	//����
		return 1;
	}
	else {
		return 0;
	}
}

//�Ժ���
void eat_hanberger() {
	hunger -= 20;		//����һ����������20����ֵ
}

//��������ƽ����
double Square(double n) {
	if (n <= 0) {
		return -1;	//δ����ȡ
	}
	double result = 1;
	double tmp;
	do {
		tmp = result;
		result = (tmp + n / tmp) / 2;
	//����С��0.01���ؽ��,��������ǵ�һ�δ�1��ʼ,������С��0
	} while ((tmp - result) >= 0.01 || (tmp - result) < 0);
	return result;
}

//�ж�һ�����Ƿ�������
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = Square(n);
	for (int i = 2; i <= square_n; ++i) {	//��2����n��ƽ����,֮��Ĳ����ж�
		if (n % i == 0) {
			return 0;	//��������
		}
	}
	return 1;			//������
}

//�ж�����������
int TriangleType(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0 ||
		(a + b) <= c || (b + c) <= a || (c + a) <= b) {
		return -1;	//����������
	}
	if (a == b && b == c) {
		return 0;	//�ȱ�������
	}
	if (a == b || b == c || a == c) {
		return 1;	//����������
	}
	return 2;		//���ȱ�������
}

//�����ַ���
void copy_n(char dst[], char src[], int n) {
	//if (n < 0) {	//�ַ������Ȳ���С��0
	//	return;
	//}

	//int flag = 1;	//�ַ���������־
	//for (int i = 0; i < n; ++i) {	//�ַ�������,ѭ��δ����,�ں��油'NUL'
	//	if (flag) {
	//		if (src[i] == '\0') {
	//			flag = 0;
	//		}
	//		dst[i] = src[i];
	//	}
	//	else {
	//		dst[i] = '\0';
	//	}
	//}
	//if (flag) {
	//	dst[n] = '\0';
	//}

	int src_index = 0;
	for (int i = 0; i < n; ++i) {
		if ((dst[i] = src[src_index]) != 0) {	//n��Ҫ�������ַ�����,������ֲ�'\0'
			++src_index;
		}
	}
	if (src_index == n && dst[n - 1] != 0) {	//n��Ҫ�������ַ�����,��dst[n]�����'\0'
		dst[n] = 0;
	}
}


//������src�����ƫ��start��λ�ÿ�ʼ,��ิ��len����NUL�ַ���dst��
int substr(char dst[], int dst_cap, char src[], int src_size, int start, int len) {
	if ((dst_cap - 1) < len ||		//dst����û���㹻�ռ����ɳ�Ϊlen�����ַ���
		(src_size - 1) < start ||	//startƫ���Գ����ַ�����Χ
		start < 0 || len < 0) {
		strcpy(dst, "");
		return 0;
	}
	int curr = 0;
	for (; curr <= len && src[curr + start] != '\0'; ++curr) {
		dst[curr] = src[curr + start];
	}
	dst[curr] = '\0';
	return curr - 1;				//�����ַ�������
}

//ȥ���ַ����ж���Ŀո�
void deblank(char str[]) {
	//int count = 0;	//ͳ��ÿ�γ��ֿո�Ĵ���	
	//for (int curr = 0; str[curr] != '\0'; ++curr) {	//�����ַ���
	//	if (str[curr] == ' ') {						//�����ո�ͳ�Ƽ�1
	//		++count;
	//	}
	//	else if (count < 2) {						//ֻ��һ���ո�,ͳ������
	//		count = 0;
	//	}
	//	else {
	//		int next = curr;
	//		for (; str[next] != '\0'; ++next) {		//����ǰ�±�֮����ַ���������ǰ�ƶ�count-1��
	//			str[next - count + 1] = str[next];
	//		}
	//		str[next - count + 1] = str[next];		//��'\0'��ǰ��count-1��
	//		curr -= (count - 1);					//����ǰ�±���ǰ�ƶ�count-1��
	//		count = 0;								//ͳ������
	//	}
	//}

	char buff[128];
	int buff_sub = 0;
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		if (str[curr] == ' ' && str[curr + 1] == ' ') {	//���鵱ǰ����һλ��Ϊ�ո������һ��ѭ��
			continue;
		}
		buff[buff_sub] = str[curr];
		++buff_sub;
	}
	buff[buff_sub] = '\0';
	strcpy(str, buff);
}

int main() {
	//�����ϰ7.��д������ַ�����ȥ������Ŀո�
	printf("������: ");
	char input[40];
	gets(input);
	deblank(input);
	printf("%s\n", input);

	//�����ϰ6.��дһ�����ַ�������ȡ���ַ���
	//char input[20], output[20];
	//printf("������: ");
	//gets(input);
	//substr(output, 20, input, strlen(input), 0, 14);
	//printf("���: %s\n", output);

	//�����ϰ5.��ȡ����,�����������ı�������ͬ,���ӡһ��,���಻��ӡ
	//printf("������:\n");
	//char curr[128],	//��ǰ���ı�
	//	prev[128];	//��һ���ı�
	//int need_out = 0;	//�Ƿ����
	//do {
	//	gets(curr);
	//	//if (strcmp("over", curr) == 0) {	//over��ʾ�������
	//	//	break;
	//	//}
	//	if (strcmp(prev, curr) == 0) {		//��ͬ����Ҫ���
	//		need_out = 1;
	//	}
	//	if (strcmp(prev, curr) != 0 && need_out) {	//��ͬʱ����Ҫ���
	//			printf("���: %s\n", prev);
	//			need_out = 0;
	//	}
	//	strcpy(prev, curr);
	//} while (strcmp("over", curr) != 0);	//over��ʾ�������

	//�����ϰ4.��дcopy_n����
	//char arr[20];
	//copy_n(arr, "a b c d e f g h", 5);
	//printf("%s\n", arr);

	//�����ϰ3.���������ж�����������
	//double a, b, c;	//�����ε������߳�
	//int result;
	//printf("�����������߳�: ");
	//scanf("%lf %lf %lf", &a, &b, &c);
	//result = TriangleType(a, b, c);
	//if (result == -1) {
	//	printf("�������߲������������\n");
	//}
	//else if (result == 0) {
	//	printf("���ǵȱ�������\n");
	//}
	//else if (result == 1) {
	//	printf("���ǵ���������\n");
	//}
	//else {
	//	printf("���ǲ��ȱ�������\n");
	//}

	//�����ϰ2.��ӡ1~100֮�������
	//int count = 0;
	//printf("1~100֮�������:\n");
	//for (int i = 1; i <= 1000; ++i) {
	//	if (IsPrime(i)) {
	//		printf("%d ", i);
	//		++count;
	//	}
	//	if (count == 10) {
	//		printf("\n");
	//		count = 0;
	//	}
	//}
	//printf("\n");

	//�����ϰ1.������n��ƽ����
	//double num, result;
	//printf("������: ");
	//while (1) {
	//	scanf("%lf", &num);
	//	result = Square(num);
	//	if (result != -1) {
	//		printf("ƽ����Ϊ: %.3lf\n", result);
	//		break;
	//	}
	//	else {
	//		printf("����������: ");
	//	}
	//}


	//����10.��ȡһ������ֵ,��ӡ���ֵ�еĿհ�
	//int num;
	//printf("������: ");
	//scanf("%d", &num);
	//for (int i = 0; i < num; ++i) {
	//	printf("\n");
	//}

	//����11.�Զ�ȡ��ֵ���м���ͱ���
	//int x, y, a, b;
	//printf("������: ");
	//scanf("%d %d %d %d", &x, &y, &a, &b);
	//if (x < y || a >= b) {
	//	printf("WRONG\n");
	//}
	//else {
	//	printf("RIGHT\n");
	//}

	//����12.�ж�����
	//int year,
	//	leap_year;
	//printf("���������: ");
	//scanf("%d", &year);
	//leap_year = IsLeapYear(year);
	//printf("%d\n", leap_year);

	//����13
	//int which_word;
	//printf("�����ñ���ֵ: ");
	//scanf("%d", &which_word);
	//switch (which_word) {
	//	case 1 :
	//		printf("who?\n");
	//		break;
	//	case 2:
	//		printf("what?\n");
	//		break;
	//	case 3:
	//		printf("when?\n");
	//		break;
	//	case 4:
	//		printf("where?\n");
	//		break;
	//	case 5:
	//		printf("why?\n");
	//		break;
	//	default:
	//		printf("don't know\n");
	//}

	//����14.���ƳԺ���
	//printf("�ö���!��������Ƶļ�����: ");
	//scanf("%d", &hunger);
	//while (hungry()) {
	//	printf("�Ժ���\n");
	//	eat_hanberger();
	//}
	//printf("�Ա���!\n");

	//����15.ʹ��do...while

	//����16.��ӡ�����ܽ�
	//int precipitating, temperature;
	//srand((unsigned int)time(NULL));
	//precipitating = rand() % 2;
	//temperature = rand() % 100 + 1;
	//if (precipitating) {
	//	if (temperature < 32) {
	//		printf("snowing\n");
	//	}
	//	else {
	//		printf("raining\n");
	//	}
	//}
	//else {
	//	if (temperature < 60) {
	//		printf("cold\n");
	//	}
	//	else {
	//		printf("warm\n");
	//	}
	//}

	system("pause");
	return 0;
}