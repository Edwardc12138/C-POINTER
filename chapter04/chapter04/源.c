#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	hunger -= 20;		//����һ����������20��������ֵ
}

int main() {
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