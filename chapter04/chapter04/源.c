#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//判断是否是闰年
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

int hunger;	//饥饿感

//是否饥饿
int hungry() {
	if (hunger > 0) {	//饥饿
		return 1;
	}
	else {
		return 0;
	}
}

//吃汉堡
void eat_hanberger() {
	hunger -= 20;		//假设一个汉堡减少20上网饥饿值
}

int main() {
	//问题10.读取一个整型值,打印这个值行的空白
	//int num;
	//printf("请输入: ");
	//scanf("%d", &num);
	//for (int i = 0; i < num; ++i) {
	//	printf("\n");
	//}

	//问题11.对读取的值进行检验和报告
	//int x, y, a, b;
	//printf("请输入: ");
	//scanf("%d %d %d %d", &x, &y, &a, &b);
	//if (x < y || a >= b) {
	//	printf("WRONG\n");
	//}
	//else {
	//	printf("RIGHT\n");
	//}

	//问题12.判断闰年
	//int year,
	//	leap_year;
	//printf("请输入年份: ");
	//scanf("%d", &year);
	//leap_year = IsLeapYear(year);
	//printf("%d\n", leap_year);

	//问题13
	//int which_word;
	//printf("请设置变量值: ");
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

	//问题14.控制吃汉堡
	//printf("好饿啊!请输入估计的饥饿度: ");
	//scanf("%d", &hunger);
	//while (hungry()) {
	//	printf("吃汉堡\n");
	//	eat_hanberger();
	//}
	//printf("吃饱了!\n");

	//问题15.使用do...while

	//问题16.打印天气总结
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