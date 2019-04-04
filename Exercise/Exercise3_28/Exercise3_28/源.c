#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

//逆置字符串的字符
void reverse_string(char * string) {
	int len;
	if ((len = StrLenNoRec(string)) == 0) {
		return;
	}
	char ch = *string;
	*string = *(string + len - 1);
	*(string + len - 1) = '\0';
	reverse_string(string + 1);
	*(string + len - 1) = ch;
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

//int main() {
	//Print(1729);
	//printf("\n");

	//printf("递归: %d\n", FactorialRec(10));
	//printf("非递归: %d\n", FactorialNoRec(10));

	//char str[] = "i have a pen!";
	//printf("递归: %d\n", StrLenRec(str));
	//printf("非递归: %d\n", StrLenNoRec(str));

	//char str[] = "i have a pen";
	//printf("%s\n", str);
	//reverse_string(str);
	//printf("%s\n", str);

	//printf("%d\n", DigitSum(1729));

	//printf("%.3lf\n", Pow(-1, -3));

	//printf("递归: %d\n", FibRec(40));
	//printf("非递归: %d\n", FibNoRec(40));

//	system("pause");
//	return 0;
//}

// 已知n个整数x1,x2,x3.....xn,以及一个整数k(k < n),从n个整数中任选K个数
// 相加,可分别得到一系列的和,例如当n=4,k=3,4个整数分别为3,7,12,19时,可
// 得全部的组合与他们的和为:
// 3 + 7 + 12 = 22
// 3 + 7 + 19 = 29
// 7 + 12 + 19 = 38
// 3 + 12 + 19 = 34
// 现在要求你计算出和为素数共有多少种

//是否是质数
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = sqrt(n);
	for (int i = 2; i <= square_n; ++i) {	//从2除到n的平方根,之后的不用判断
		if (n % i == 0) {
			return 0;	//不是质数
		}
	}
	return 1;			//是质数
}

int Func(int* arr, int n, int k, int curr, int sum) {
	static count = 0;
	if (k == 0) {
		printf("%d ", sum);
		count += IsPrime(sum);
		return 0;
	}

	for (; curr < n; ++curr) {
		Func(arr, n, k - 1, curr + 1, sum + *(arr + curr));
	}
	return count;
}

//int Func2(int* arr, int n, int k, int sum) {
//	static count = 0;
//	if (k == 0) {
//		printf("%d ", sum);
//		count += IsPrime(sum);
//		return 0;
//	}
//
//	for (int curr = 0; curr < k - 1; ++curr) {
//		Func2(arr + curr + 1, n - 1, k - 1,  sum + *(arr + curr));
//	}
//	return count;
//}

int main() {
	int arr[] = { 3,7,12,19 };	
	printf("\n%d\n", Func(arr, 4, 3, 0, 0));

	system("pause");
	return 0;
}