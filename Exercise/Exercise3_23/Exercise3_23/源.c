#include <stdio.h>
#include <math.h>

//���ͼ��,n��ʾ���n��
void printfGrap(unsigned int n) {
	int len = 1,		//ÿ�еĳ���
		mid = n / 2;
	//ǰ�벿�ֵ������
	for (int i = 0; i < mid; ++i, len += 2) {
		for (int j = 0; j < len; ++j) {
			putchar('*');
		}
		putchar('\n');
	}
	//�����ż����,��벿����ʼ������Ҫ��2
	if ((n % 2) == 0) {
		len -= 2;
	}
	//��벿�ֵݼ����
	for (int i = mid; i < n; ++i, len -= 2) {
		for (int j = 0; j < len; ++j) {
			putchar('*');
		}
		putchar('\n');
	}
}

//��һ������λ��������
int cubicSum(int n) {
	int sum = 0;
	while (n != 0) {
		sum += pow((n % 10), 3);
		n /= 10;
	}
	return sum;
}

//��aaa...a��ֵ,a = x,nΪλ��
int comb(int x, int n) {
	int result = 0;
	for (int i = 0; i <= n; ++i) {
		result += x * pow(10, i);
	}
	return result;
}

//��Sn = a + aa + aaa + ...+ a...a��ֵ,a = x, n Ϊ������
int func(int x, int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += comb(x, i);
	}
	return sum;
}

int main() {
	//1.���ͼ��
	//printfGrap(11);

	//2.��λ����ˮ�ɻ�
	//printf("��λ����ˮ�ɻ���: ");
	//for (int i = 100; i < 1000; ++i) {
	//	if (i == cubicSum(i)) {
	//		printf("%d ", i);
	//	}		
	//}
	//printf("\n");

	//��Sn=2+22+222+2222+22222
	printf("Sn = %d\n", func(2, 5));

	system("pause");
	return 0;
}