#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1.实现无符号数比特位的逆置
unsigned int reverse_bit(unsigned int value) {
	int total_bits = sizeof(unsigned int) * 8;	//总共有多少位
	int val_reverse = 0;
	for (int bit = 0; bit < total_bits; ++bit, value /= 2) {
		val_reverse = val_reverse * 2 + (value % 2);
	}
	return val_reverse;
}

// 2.两个数的平均值
double Average(double a, double b) {
	return a - (a - b) / 2;
}

// 3.找到一组数中只出现过一次的数
int FindAlong(int arr[], int n) {
	for (int curr = 0; curr < n; ++curr) {		// 遍历数组
		int tmp = ~arr[curr];					// 对当前数取反
		int next = curr + 1;
		for (; next < n; ++next) {				// 从下一个位置判断是否存在与当前值相等的数
			if ((~(tmp ^ arr[next])) == 0) {	// 取反的当前数与之后的数异或在取反结果为0,则这两个数相等
				int a = arr[curr + 1];			// 交换与当前数相同的数与当前位置的下一位置的数
				arr[curr + 1] = arr[next];
				arr[next] = a;
				++curr;							// 跳过下一个循环
				break;
			}
		}
		if (next == n) {						// 未找到
			return arr[curr];					// 返回当前数
		}
	}
	return -1;
}

// 4
// 逆置[left, right]之间的数组元素
void ReverseArr(char* left, char* right) {
	for (; left < right; ++left, --right) {
		char ch = *left;
		*left = *right;
		*right = ch;
	}
}


void ReverseStr(char str[]) {
	int len = 0;
	for (int curr = 0; str[curr] != '\0'; ++curr) {
		++len;
	}
	ReverseArr(str, str + len - 1);	// 整体逆置
	for (int left = 0; left < len; ++left) {
		int right = left;
		for (; right < len && str[right] != ' '; ++right);	//找到每个单词
		if (right - left < 2) {			//单词长度小于1,不做改变
			left = right;
			continue;
		}
		if (right == len) {				// 最后一个单词逆置
			ReverseArr(str + left, str + right - 1);
			return;
		}
		ReverseArr(str + left, str + right - 1);	// 每一个单词逆置
		left = right;
	}
}

int main() {
	// 1
	//unsigned int val;
	//printf("请输入: ");
	//scanf("%u", &val);
	//printf("逆置后: %u\n", reverse_bit(val));

	// 2
	//double a, b;
	//printf("请输入: ");
	//scanf("%lf %lf", &a, &b);
	//printf("平均值: %f\n", Average(a, b));

	// 3
	//int arr[] = { 12,45,56,45,12,23,56 };
	//printf("%d\n", FindAlong(arr, sizeof(arr) / sizeof(arr[0])));

	char arr[] = "student a am i";
	printf("%s\n", arr);
	ReverseStr(arr);
	printf("%s\n", arr);

	system("pause");
	return 0;
}