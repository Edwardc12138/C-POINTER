#include <stdio.h>
#include <math.h>

//输出图案,n表示输出n行
void printfGrap(unsigned int n) {
	int len = 1,		//每行的长度
		mid = n / 2;
	//前半部分递增输出
	for (int i = 0; i < mid; ++i, len += 2) {
		for (int j = 0; j < len; ++j) {
			putchar('*');
		}
		putchar('\n');
	}
	//如果是偶数行,后半部分起始长度需要减2
	if ((n % 2) == 0) {
		len -= 2;
	}
	//后半部分递减输出
	for (int i = mid; i < n; ++i, len -= 2) {
		for (int j = 0; j < len; ++j) {
			putchar('*');
		}
		putchar('\n');
	}
}

//求一个数各位的立方和
int cubicSum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += pow((n % 10), 3);
		n /= 10;
	}
	return sum;
}

//求aaa...a的值,a = x,n为位数
int comb(int x, int n) {
	int result = 0;
	for (int i = 0; i <= n; ++i) {
		result += x * pow(10, i);
	}
	return result;
}

//求Sn = a + aa + aaa + ...+ a...a的值,a = x, n 为多少项
int func(int x, int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += comb(x, i);
	}
	return sum;
}

int main() {
	//1.输出图案
	//printfGrap(11);

	//2.三位数的水仙花
	//printf("三位数的水仙花数: ");
	//for (int i = 100; i < 1000; ++i) {
	//	if (i == cubicSum(i)) {
	//		printf("%d ", i);
	//	}		
	//}
	//printf("\n");

	//求Sn=2+22+222+2222+22222
	printf("Sn = %d\n", func(2, 5));

	system("pause");
	return 0;
}