#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 将大写字母转换为小写字母
char ToUp(char ch) {
	if (ch < 'A' || ch > 'Z') {		// 不在A~Z之间的字符直接输出
		return ch;
	}
	char a = 'a';
	return ch + 32;
}

// 字母加密
char Encryption(char ch) {
	if ((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z')) {	// 不在a~z和A~Z之间的字符直接输出
		return ch;
	}
	if (ch < ('A' + 13) || (ch >= 'a' && ch < ('a' + 13))) { // ch在[A,M]和[a,m]之间加13
		return ch + 13;
	}
	return ch - 13;
}

// 无符号数比特位的逆置
unsigned int reverse_bit(unsigned int value) {
	int total_bits = sizeof(unsigned int) * 8;	//总共有多少位
	int val_reverse = 0;
	// 将value的每一个二进制位从低到高提取出来
	for (int bit = 0; bit < total_bits; ++bit, value /= 2) {
		// 再将每一位乘2相加
		val_reverse = val_reverse * 2 + (value % 2);
	}
	return val_reverse;
}

// 将指定位置置1
void set_bit(char bit_array[], unsigned int bit_number) {
	// 将该位在数组上的那个元素找到在去置这个元素的某位
	bit_array[bit_number / 8] |= (1 << (bit_number % 8));
}

// 将指定位清零
void clear_bit(char bit_array[], unsigned int bit_number) {
	// 将该位在数组上的那个元素找到在去清零这个元素的某位
	bit_array[bit_number / 8] &= ~(1 << (bit_number % 8));
}

// 如果value = 0,将指定位清零,否则置1
void assign_bit(char bit_array[], unsigned int bit_number, int value) {
	// 加上判断调用之前的两个函数
	if (value) {
		set_bit(bit_array, bit_number);
	}
	else {
		clear_bit(bit_array, bit_number);
	}
}

// 如果参数中指定的位不是0,函数返回真,否则返回假
int test_bit(char bit_array[], unsigned int bit_number) {
	// 将该位在数组上的那个元素,该元素的需判断的那一位与1或,再与原值相比较
	// 相同该位为1,不同该位为0
	return bit_array[bit_number / 8] == (bit_array[bit_number / 8] | (1 << (bit_number % 8)));
}

// 把value_to_store存储到original_value中[starting_bit,ending_bit]位置
int store_bit_field(int original_value, int value_to_store,
	unsigned int starting_bit, unsigned int ending_bit) {
	// 1.掩码
	unsigned int mask = 0;
	for (int i = ending_bit; i <= starting_bit; ++i) {
		mask |= 1 << i;
	}
	// 2.掩码的反码对源值执行位AND
	original_value &= ~mask;
	// 3.新值左移,与需要存储的位对齐
	value_to_store <<= ending_bit;
	// 4.移位后的值与掩码进行位AND
	value_to_store &= mask;
	// 5.结果与原值进行位OR操作
	return original_value | value_to_store;
}

int main() {
	// 5.编写一个函数,把一个给定的值存储到一个整数中指定的几个位
	int a = 0x0, b = 0xffff, c = 0xffff,
		val_to_a = 0x1, val_to_bc = 0x123;
	printf("%x %x %x\n", a, val_to_a, store_bit_field(a, val_to_a, 4, 4));
	printf("%x %x %x\n", b, val_to_bc, store_bit_field(b, val_to_bc, 15, 4));
	printf("%x %x %x\n", c, val_to_bc, store_bit_field(c, val_to_bc, 13, 9));

	// 4.编写一组函数,实现位数组
	//char arr[4] = { 0 };
	//assign_bit(arr, 8, 1);
	//assign_bit(arr, 8, 0);
	//int i = test_bit(arr, 8);

	// 3.编写函数unsigned int reverse_bit(unsigned int value),实现二进制位逆置
	//unsigned int val;
	//printf("请输入: ");
	//scanf("%u", &val);
	//printf("%u\n", reverse_bit(val));

	// 2.从标准输入读取字符,非字母字符直接输出,字母字符输出时加密
	// 加密规则:每个字母被修改为在字母表上距其13个位置(前或后)的字母
	// 0表示结束
	//char ch;
	//while ((ch = getchar()) != '0') {
	//	printf("%c", Encryption(ch));
	//}

	// 1.从标准输入读取字符,大写转小写,其他字符不变
	// 输入0表示结束
	//char ch;
	//while ((ch = getchar()) != '0') {
	//	printf("%c", ToUp(ch));
	//}

	system("pause");
	return 0;
}