#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�ݹ鷽����쳲�����
int FibRec(int n) {
	if (n < 1) {
		return -1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return FibRec(n - 1) + FibRec(n - 2);
}

//�Ż��ݹ���쳲����� δ��
int FibRec2(int n, int prev1, int prev2) {
	if (n < 1) {
		return -1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
}

//�ǵݹ���쳲�����
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

//n����k�η�
int _Pow(int n, int k) {
	if (k == 0) {	//�κ�����0�η�����1
		return 1;
	}
	return n * _Pow(n, k - 1);
}

//��n��k�η�
double Pow(int n, int k) {
	if (n == 0) {
		return 0;		//������
	}
	if (k < 0) {		//����
		k = 0 - k;
		return (double)1 / _Pow(n, k);
	}
	return _Pow(n, k);	//����
}

//����n�ĸ�λ֮��
int DigitSum(int n) {
	if (n < 0) {
		return -1;	//����
	}
	if (n == 0) {
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}

//�ݹ�strlen
int StrLenRec(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + StrLenRec(++str);
}

//�ǵݹ�strlen
int StrLenNoRec(char* str) {
	int len = 0;
	while (*str != '\0') {
		++str;
		++len;
	}
	return len;
}

//�����ַ������ַ�
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

//�ݹ�n�Ľ׳�
int FactorialRec(int n) {
	if (n < 1) {
		return -1;	//����
	}
	if (n == 1) {
		return 1;
	}
	return n * FactorialRec(n - 1);
}

//�ǵݹ�n�Ľ׳�
int FactorialNoRec(int n) {
	if (n < 1) {
		return -1;	//����
	}
	int result = 1;
	for (int curr = 1; curr <= n; ++curr) {
		result *= curr;
	}
	return result;
}

//��ӡ������ÿһλ
void Print(int n) {
	if (n < 0) {
		return -1;	//����
	}
	if (n == 0) {
		return;
	}
	Print(n / 10);	//ȥ����λ
	printf("%d ", n % 10);	
}

//int main() {
	//Print(1729);
	//printf("\n");

	//printf("�ݹ�: %d\n", FactorialRec(10));
	//printf("�ǵݹ�: %d\n", FactorialNoRec(10));

	//char str[] = "i have a pen!";
	//printf("�ݹ�: %d\n", StrLenRec(str));
	//printf("�ǵݹ�: %d\n", StrLenNoRec(str));

	//char str[] = "i have a pen";
	//printf("%s\n", str);
	//reverse_string(str);
	//printf("%s\n", str);

	//printf("%d\n", DigitSum(1729));

	//printf("%.3lf\n", Pow(-1, -3));

	//printf("�ݹ�: %d\n", FibRec(40));
	//printf("�ǵݹ�: %d\n", FibNoRec(40));

//	system("pause");
//	return 0;
//}

// ��֪n������x1,x2,x3.....xn,�Լ�һ������k(k < n),��n����������ѡK����
// ���,�ɷֱ�õ�һϵ�еĺ�,���統n=4,k=3,4�������ֱ�Ϊ3,7,12,19ʱ,��
// ��ȫ������������ǵĺ�Ϊ:
// 3 + 7 + 12 = 22
// 3 + 7 + 19 = 29
// 7 + 12 + 19 = 38
// 3 + 12 + 19 = 34
// ����Ҫ����������Ϊ�������ж�����

//�Ƿ�������
int IsPrime(int n) {
	if (n <= 1) {
		return 0;
	}

	int square_n = sqrt(n);
	for (int i = 2; i <= square_n; ++i) {	//��2����n��ƽ����,֮��Ĳ����ж�
		if (n % i == 0) {
			return 0;	//��������
		}
	}
	return 1;			//������
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