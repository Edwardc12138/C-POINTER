#include <stdio.h>

//交换两个大小相同的字符数组内容
void arrSwap(char arr1[], char arr2[]) {
	int len = strlen(arr1);
	char tmp;
	for (int i = 0; i < len; ++i) {
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

//计算1/1 - 1/2 + 1/3......1/n的值
double func(unsigned int n) {
	int k = 1;		//分子的正负
	double sum = 0;	//结果
	for (int i = 1; i <= n; ++i) {
		sum += (double) k / i;
		k = 0 - k;
	}
	return sum;
}

//统计1到n之间出现多少次9
int count(unsigned int n) {
	int result = 0;		//次数
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
	//1.交换数组内容
	//char arr1[] = "a b c d e f g";
	//char arr2[] = "h i j k l m n";
	//arrSwap(arr1, arr2);
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);

	//2.计算1/1 - 1/2 + 1/3...-1/100的值
	//printf("计算结果为: %g\n", func(100));

	//3.统计1到100之间出现过多少次9
	int n = 100;
	printf("1 到 %d 之间出现过 %d 个 9\n", n, count(n));

	system("pause");
	return 0;
}