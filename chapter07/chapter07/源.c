#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>	// 可变参数列表
#include <string.h>

// 厄密多项式
int hermite(const int n, const int x) {
	if (n <= 0) {
		return 1;
	}
	if (n == 1) {
		return 2 * x;
	}
	int ret;
	int curr = 2 * x;	// 初始第 1 项
	int prev = 1;		// 初始第 0 项
	for (int i = 2; i <= n; ++i) {
		ret = 2 * x * curr - 2 * (i - 1) * prev;
		prev = curr;	// 前一项
		curr = ret;		// 前前一项
	}
	return ret;
}

// M 和 N 的最大公约数
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

// 将字符数字转换为整型
int ASCIIToInteger(char *str) {
	if (str == NULL) {
		return 0;
	}

	int sign = 1;	// 默认是正数
	int ret = 0;
	int i = 0;		// 默认不跳过符号位

	if (str[0] == '-') {	// 负数
		sign = -1;	// 符号
		i = 1;		// 循环开始位置
	}

	for (; str[i] != '\0'; ++i) {	// 跳过符号位
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
		ret = ret * 10 + (str[i] - '0') ;
	}
	return ret * sign;
}

// 返回任意数目整型参数的最大值,-1结尾
int max_list(int num, ...) {
	int input;
	va_list var_arg;
	// 准备访问可变参数
	va_start(var_arg, num);
	// 添加取自可变参数列表的值
	while ((input = va_arg(var_arg, int)) != -1) {
		if (num < input) {
			num = input;
		}
	}
	va_end(var_arg);
	return num;
}

// 假设打印int型数据
void PrintInteger(int num) {
	printf("%d", num);
}

// 假设打印float型数据
void PrintFloat(double num) {
	printf("%f", num);
}

// 模拟printf
void Printf(char *str, ...) {
	if (str == NULL) {
		return;
	}

	va_list var;
	va_start(var, str);
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		if (str[curr] == '%') {
			if (str[++curr] == 'd') {		// 整型
				PrintInteger(va_arg(var, int));
			}
			else if (str[curr] == 'f') {	// 浮点
				PrintFloat(va_arg(var, double));	// 不能用float
			}
			else if (str[curr] == 's') {	// 字符串循环putchar
				char *output = va_arg(var, char*);
				for (int i = 0; output[i] != '\0';++i) {
					putchar(output[i]);
				}
			}
			else if (str[curr] == 'c') {	// 字符直接putchar
				putchar(va_arg(var, char));
			}
		}
		else {
			putchar(str[curr]);
		}
	}
	va_end(var);
}

// 将三位以下无符号数转换为单词
void three_to_str(unsigned int num, char*buffer) {
	if (buffer == NULL) {
		return;
	}

	// 个位,0 ~ 19 第一个为空,方便计算取下标
	char *one_to_nineteen[20] = { "","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE",
		"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN",
		"SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN" };
	// 十位20,30,40 ... 90,空字符作用同上
	char *ten_place[10] = { "","","TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY" };

	if ((num / 100) != 0) {		// 百位
		strcat(buffer, one_to_nineteen[num / 100]);
		strcat(buffer, " HUNDERD");
		if (num % 100 != 0) {
			strcat(buffer, " AND ");
		}
	}

	if ((num % 100) > 19) {		// 十位
		strcat(buffer, ten_place[num / 10 % 10]);
		if ((num % 10) != 0) {	// 个位
			strcat(buffer, "-");
			strcat(buffer, one_to_nineteen[num % 10]);
		}
	}
	else if ((num % 100) > 0) {		// 0 ~ 19
		strcat(buffer, one_to_nineteen[num % 100]);
	}
}

// 将无符号数转换为单词形式
void written_amount(unsigned int amount, char *buffer) {
	if (amount == 0) {
	}
	if (amount == 0) {
		strcpy(buffer, "ZERO");
		return;
	}

	strcpy(buffer, "");	// 重置buffer

	char *level_of_num[4] = { ""," THOUSAND "," MILLION "," BILLION " };	// 数量级
	int level = 0;
	int thousand = 1;
	for (int tmp = amount; (tmp /= 1000) > 0; ++level) {	// 三个数一分段
		thousand *= 1000;
	}

	// high 最高三位,每次除一千,再减一千,从最高位向下每次拿三位
	while (amount > 0) {
		int high = amount / thousand;	// 每次的最高位
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
	// 6.编写函数,将无符号整型转换为单词形式
	unsigned int n;
	char buf[1024] = { 0 };
	while (1) {
		printf("请输入: ");
		scanf("%u", &n);
		written_amount(n, buf);
		printf("%s\n", buf);
	}

	// 5.实现一个简化的printf函数,它能够处理%d,%f,%s,和%c格式码
	//   假设已经存在函数print_integer和print_float,用于打印相对应的类型
	//   另外两种,使用putchar来打印
	//float a = 11.1f;
	//Printf("%f", a);
	//printf("%f", 11.1f);
	//Printf("first: %d\nnext: %f\nnext: %s\nlast: %c\n", 10, 11.111, "hahaha", 'A');

	// 4.编写函数,检查任意数目的整型参数,并返回其中的最大值,参数列表以-1结尾表示结束
	//printf("max = %d\n", max_list(0, 2, 9, 3, -1));

	// 3.编写函数,将一个包含一个或多个数字的字符串转换为整数并返回这个整数
	//   如果包含任何非数字字符,则返回0
	//char str[] = "-456789";
	//printf("%d\n", ASCIIToInteger(str));

	// 2.计算 M 和 N 的最大公约数
	//int m, n;
	//printf("请输入两个数: ");
	//scanf("%d %d", &m, &n);
	//printf("最大公约数: %d\n", gcd(m, n));

	// 1.Hermite Polynomials (厄密多项式) 计算Hn(x)的值
	//int n, x;
	//printf("请输入n,x: ");
	//scanf("%d %d", &n, &x);
	//printf("H%d(%d) = %d\n", n, x, hermite(n, x));

	system("pause");
	return 0;
}