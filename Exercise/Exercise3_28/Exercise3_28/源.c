#include <stdio.h>
#include <stdlib.h>

//递归方法求斐波那契
int FibRec(int n) {
	if (n < 1) {
		return -1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return FibRec(n - 1) + FibRec(n - 2);
}

//优化递归求斐波那契 未完
int FibRec2(int n, int prev1, int prev2) {
	if (n < 1) {
		return -1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
}

//非递归求斐波那契
int FibNoRec(int n) {
	if (n < 1) {
		return -1;
	}
	int curr, prev1 = 1, prev2 = 1;
	for (int i = 2; i < n; ++i) {
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return curr;
}

//n的正k次方
int _Pow(int n, int k) {
	if (k == 0) {	//任何数的0次方都是1
		return 1;
	}
	return n * _Pow(n, k - 1);
}

//求n的k次方
double Pow(int n, int k) {
	if (n == 0) {
		return 0;		//无意义
	}
	if (k < 0) {		//负幂
		k = 0 - k;
		return (double)1 / _Pow(n, k);
	}
	return _Pow(n, k);	//正幂
}

//计算n的各位之和
int DigitSum(int n) {
	if (n < 0) {
		return -1;	//错误
	}
	if (n == 0) {
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}

//逆置字符串的字符
void Reverse(char* left, char* right) {
	if (left >= right) {		//前后指针比较大小,确定退出条件
 		return;
	}
	char tmp = *left;			//交换前后指针
	*left = *right;
	*right = tmp;
	Reverse(++left, --right);
}

void reverse_string(char * string) {
	int len = 0;			//存储字符串长度
	char* tmp = string;
	while (*tmp != '\0') {	//计算字符串长度
		++tmp;
		++len;
	}
	Reverse(string, string + len - 1);	//调用递归
}

//递归strlen
int StrLenRec(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + StrLenRec(++str);
}

//非递归strlen
int StrLenNoRec(char* str) {
	int len = 0;
	while (*str != '\0') {
		++str;
		++len;
	}
	return len;
}

//递归n的阶乘
int FactorialRec(int n) {
	if (n < 1) {
		return -1;	//错误
	}
	if (n == 1) {
		return 1;
	}
	return n * FactorialRec(n - 1);
}

//非递归n的阶乘
int FactorialNoRec(int n) {
	if (n < 1) {
		return -1;	//错误
	}
	int result = 1;
	for (int curr = 1; curr <= n; ++curr) {
		result *= curr;
	}
	return result;
}

//打印正整数每一位
void Print(int n) {
	if (n < 0) {
		return -1;	//错误
	}
	if (n == 0) {
		return;
	}
	Print(n / 10);	//去掉个位
	printf("%d ", n % 10);	
}

int main() {
	//Print(1729);
	//printf("\n");

	//printf("递归: %d\n", FactorialRec(10));
	//printf("非递归: %d\n", FactorialNoRec(10));

	//char str[] = "i have a pen!";
	//printf("递归: %d\n", StrLenRec(str));
	//printf("非递归: %d\n", StrLenNoRec(str));

	char str[] = "abc";
	printf("%s\n", str);
	reverse_string(str);
	printf("%s\n", str);

	//printf("%d\n", DigitSum(1729));

	//printf("%.3lf\n", Pow(-1, -3));

	//printf("递归: %d\n", FibRec(40));
	//printf("非递归: %d\n", FibNoRec(40));

	system("pause");
	return 0;
}