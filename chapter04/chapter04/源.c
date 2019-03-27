#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	hunger -= 20;		//假设一个汉堡减少20饥饿值
}

//求正数的平方根
double Square(double n) {
	if (n <= 0) {
		return -1;	//未能求取
	}
	double result = 1;
	double tmp;
	do {
		tmp = result;
		result = (tmp + n / tmp) / 2;
	//精度小于0.01返回结果,或的条件是第一次从1开始,相减结果小于0
	} while ((tmp - result) >= 0.01 || (tmp - result) < 0);
	return result;
}

//判断一个数是否是质数
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = Square(n);
	for (int i = 2; i <= square_n; ++i) {	//从2除到n的平方根,之后的不用判断
		if (n % i == 0) {
			return 0;	//不是质数
		}
	}
	return 1;			//是质数
}

//判断三角形类型
int TriangleType(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0 ||
		(a + b) <= c || (b + c) <= a || (c + a) <= b) {
		return -1;	//不是三角形
	}
	if (a == b && b == c) {
		return 0;	//等边三角形
	}
	if (a == b || b == c || a == c) {
		return 1;	//等腰三角形
	}
	return 2;		//不等边三角形
}

//拷贝字符串
void copy_n(char dst[], char src[], int n) {
	//if (n < 0) {	//字符串长度不能小于0
	//	return;
	//}

	//int flag = 1;	//字符串结束标志
	//for (int i = 0; i < n; ++i) {	//字符串结束,循环未结束,在后面补'NUL'
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
		if ((dst[i] = src[src_index]) != 0) {	//n比要拷贝的字符串长,多出部分补'\0'
			++src_index;
		}
	}
	if (src_index == n && dst[n - 1] != 0) {	//n比要拷贝的字符串短,在dst[n]处添加'\0'
		dst[n] = 0;
	}
}


//从书中src中向后偏移start个位置开始,最多复制len个非NUL字符到dst中
int substr(char dst[], int dst_cap, char src[], int src_size, int start, int len) {
	if ((dst_cap - 1) < len ||		//dst数组没有足够空间容纳长为len个的字符串
		(src_size - 1) < start ||	//start偏移以超出字符串范围
		start < 0 || len < 0) {
		strcpy(dst, "");
		return 0;
	}
	int curr = 0;
	for (; curr <= len && src[curr + start] != '\0'; ++curr) {
		dst[curr] = src[curr + start];
	}
	dst[curr] = '\0';
	return curr - 1;				//返回字符串长度
}

//去除字符串中多余的空格
void deblank(char str[]) {
	//int count = 0;	//统计每次出现空格的次数	
	//for (int curr = 0; str[curr] != '\0'; ++curr) {	//遍历字符串
	//	if (str[curr] == ' ') {						//遇到空格统计加1
	//		++count;
	//	}
	//	else if (count < 2) {						//只有一个空格,统计清零
	//		count = 0;
	//	}
	//	else {
	//		int next = curr;
	//		for (; str[next] != '\0'; ++next) {		//将当前下标之后的字符串内容向前移动count-1个
	//			str[next - count + 1] = str[next];
	//		}
	//		str[next - count + 1] = str[next];		//将'\0'向前移count-1个
	//		curr -= (count - 1);					//将当前下标向前移动count-1个
	//		count = 0;								//统计清零
	//	}
	//}

	char buff[128];
	int buff_sub = 0;
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		if (str[curr] == ' ' && str[curr + 1] == ' ') {	//数组当前和下一位都为空格就跳过一次循环
			continue;
		}
		buff[buff_sub] = str[curr];
		++buff_sub;
	}
	buff[buff_sub] = '\0';
	strcpy(str, buff);
}

int main() {
	//编程练习7.编写程序从字符串中去除多余的空格
	printf("请输入: ");
	char input[40];
	gets(input);
	deblank(input);
	printf("%s\n", input);

	//编程练习6.编写一个从字符串中提取子字符串
	//char input[20], output[20];
	//printf("请输入: ");
	//gets(input);
	//substr(output, 20, input, strlen(input), 0, 14);
	//printf("输出: %s\n", output);

	//编程练习5.读取输入,有连续多行文本内容相同,则打印一行,其余不打印
	//printf("请输入:\n");
	//char curr[128],	//当前行文本
	//	prev[128];	//上一行文本
	//int need_out = 0;	//是否输出
	//do {
	//	gets(curr);
	//	//if (strcmp("over", curr) == 0) {	//over表示输入结束
	//	//	break;
	//	//}
	//	if (strcmp(prev, curr) == 0) {		//相同则需要输出
	//		need_out = 1;
	//	}
	//	if (strcmp(prev, curr) != 0 && need_out) {	//不同时且需要输出
	//			printf("输出: %s\n", prev);
	//			need_out = 0;
	//	}
	//	strcpy(prev, curr);
	//} while (strcmp("over", curr) != 0);	//over表示输入结束

	//编程练习4.编写copy_n函数
	//char arr[20];
	//copy_n(arr, "a b c d e f g h", 5);
	//printf("%s\n", arr);

	//编程练习3.根据输入判断三角形类型
	//double a, b, c;	//三角形的三条边长
	//int result;
	//printf("请输入三条边长: ");
	//scanf("%lf %lf %lf", &a, &b, &c);
	//result = TriangleType(a, b, c);
	//if (result == -1) {
	//	printf("这三条边不能组成三角形\n");
	//}
	//else if (result == 0) {
	//	printf("这是等边三角形\n");
	//}
	//else if (result == 1) {
	//	printf("这是等腰三角形\n");
	//}
	//else {
	//	printf("这是不等边三角形\n");
	//}

	//编程练习2.打印1~100之间的质数
	//int count = 0;
	//printf("1~100之间的质数:\n");
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

	//编程练习1.计算获得n的平方根
	//double num, result;
	//printf("请输入: ");
	//while (1) {
	//	scanf("%lf", &num);
	//	result = Square(num);
	//	if (result != -1) {
	//		printf("平方根为: %.3lf\n", result);
	//		break;
	//	}
	//	else {
	//		printf("请输入正数: ");
	//	}
	//}


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