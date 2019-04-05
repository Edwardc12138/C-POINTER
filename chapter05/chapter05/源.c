#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����д��ĸת��ΪСд��ĸ
char ToUp(char ch) {
	if (ch < 'A' || ch > 'Z') {		// ����A~Z֮����ַ�ֱ�����
		return ch;
	}
	char a = 'a';
	return ch + 32;
}

// ��ĸ����
char Encryption(char ch) {
	if ((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z')) {	// ����a~z��A~Z֮����ַ�ֱ�����
		return ch;
	}
	if (ch < ('A' + 13) || (ch >= 'a' && ch < ('a' + 13))) { // ch��[A,M]��[a,m]֮���13
		return ch + 13;
	}
	return ch - 13;
}

// �޷���������λ������
unsigned int reverse_bit(unsigned int value) {
	int total_bits = sizeof(unsigned int) * 8;	//�ܹ��ж���λ
	int val_reverse = 0;
	// ��value��ÿһ��������λ�ӵ͵�����ȡ����
	for (int bit = 0; bit < total_bits; ++bit, value /= 2) {
		// �ٽ�ÿһλ��2���
		val_reverse = val_reverse * 2 + (value % 2);
	}
	return val_reverse;
}

// ��ָ��λ����1
void set_bit(char bit_array[], unsigned int bit_number) {
	// ����λ�������ϵ��Ǹ�Ԫ���ҵ���ȥ�����Ԫ�ص�ĳλ
	bit_array[bit_number / 8] |= (1 << (bit_number % 8));
}

// ��ָ��λ����
void clear_bit(char bit_array[], unsigned int bit_number) {
	// ����λ�������ϵ��Ǹ�Ԫ���ҵ���ȥ�������Ԫ�ص�ĳλ
	bit_array[bit_number / 8] &= ~(1 << (bit_number % 8));
}

// ���value = 0,��ָ��λ����,������1
void assign_bit(char bit_array[], unsigned int bit_number, int value) {
	// �����жϵ���֮ǰ����������
	if (value) {
		set_bit(bit_array, bit_number);
	}
	else {
		clear_bit(bit_array, bit_number);
	}
}

// ���������ָ����λ����0,����������,���򷵻ؼ�
int test_bit(char bit_array[], unsigned int bit_number) {
	// ����λ�������ϵ��Ǹ�Ԫ��,��Ԫ�ص����жϵ���һλ��1��,����ԭֵ��Ƚ�
	// ��ͬ��λΪ1,��ͬ��λΪ0
	return bit_array[bit_number / 8] == (bit_array[bit_number / 8] | (1 << (bit_number % 8)));
}

// ��value_to_store�洢��original_value��[starting_bit,ending_bit]λ��
int store_bit_field(int original_value, int value_to_store,
	unsigned int starting_bit, unsigned int ending_bit) {
	// 1.����
	unsigned int mask = 0;
	for (int i = ending_bit; i <= starting_bit; ++i) {
		mask |= 1 << i;
	}
	// 2.����ķ����Դִֵ��λAND
	original_value &= ~mask;
	// 3.��ֵ����,����Ҫ�洢��λ����
	value_to_store <<= ending_bit;
	// 4.��λ���ֵ���������λAND
	value_to_store &= mask;
	// 5.�����ԭֵ����λOR����
	return original_value | value_to_store;
}

int main() {
	// 5.��дһ������,��һ��������ֵ�洢��һ��������ָ���ļ���λ
	int a = 0x0, b = 0xffff, c = 0xffff,
		val_to_a = 0x1, val_to_bc = 0x123;
	printf("%x %x %x\n", a, val_to_a, store_bit_field(a, val_to_a, 4, 4));
	printf("%x %x %x\n", b, val_to_bc, store_bit_field(b, val_to_bc, 15, 4));
	printf("%x %x %x\n", c, val_to_bc, store_bit_field(c, val_to_bc, 13, 9));

	// 4.��дһ�麯��,ʵ��λ����
	//char arr[4] = { 0 };
	//assign_bit(arr, 8, 1);
	//assign_bit(arr, 8, 0);
	//int i = test_bit(arr, 8);

	// 3.��д����unsigned int reverse_bit(unsigned int value),ʵ�ֶ�����λ����
	//unsigned int val;
	//printf("������: ");
	//scanf("%u", &val);
	//printf("%u\n", reverse_bit(val));

	// 2.�ӱ�׼�����ȡ�ַ�,����ĸ�ַ�ֱ�����,��ĸ�ַ����ʱ����
	// ���ܹ���:ÿ����ĸ���޸�Ϊ����ĸ���Ͼ���13��λ��(ǰ���)����ĸ
	// 0��ʾ����
	//char ch;
	//while ((ch = getchar()) != '0') {
	//	printf("%c", Encryption(ch));
	//}

	// 1.�ӱ�׼�����ȡ�ַ�,��дתСд,�����ַ�����
	// ����0��ʾ����
	//char ch;
	//while ((ch = getchar()) != '0') {
	//	printf("%c", ToUp(ch));
	//}

	system("pause");
	return 0;
}