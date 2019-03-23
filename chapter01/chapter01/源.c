//程序1.1 重排字符
//这个程序从标准输入中读取输入行并在标准输出中打印这些输入行，
//每个输入行的下一行是该行内容的一部分。

//输入的第一行是一串列标号，，串的最后一个以一个负数结尾。
//这些列标号成对出现，说明需要打印的输入行的列范围。
//例如，0 3 10 12 -1表示第0列到第3列，第10列到第12列的内容将被打印。

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20		//所能处理的最大列号
#define MAX_INPUT 1000	//每个输入行的最大长度

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
	int n_columns;			//进行处理的列标号
	int columns[MAX_COLS];	//需要处理的列数
	char input[MAX_INPUT];	//容纳输入行的数组
	char output[MAX_INPUT];	//容纳输出行的数组
	//读取该串列标号
	n_columns = read_column_numbers(columns, MAX_COLS);
	//读取处理打印剩余的输入行
	while (gets(input) != NULL)
	{
		printf("Original input : %s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rearranged line: %s\n", output);
	}
	system("pause");
	return EXIT_SUCCESS;
}

//读取列标号，如果超出规定范围则不予理会
int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;
	//取得列标号，如果所读取的数小于0则停止
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
		num += 1;
	//确认已经读取的标号为偶数个，因为他们是以数对的形式出现的
	//if (num % 2 != 0)
	//{
	//	puts("Last column number is not paired.");
	//	exit(EXIT_FAILURE);
	//}
	//丢弃该行中包含的最后一个数字的那部分内容
	while ((ch = getchar()) != EOF && ch != '\n');
	return num;
}

//处理输入行，将指定列的字符连接在一起，输出行以NUL结尾
void rearrange(char *output, char const *input, int n_columns, int columns[])
{
	int col;		//columns数组的下标
	int output_col;	//输出列计数器
	int len;		//输入行长度
	len = strlen(input);
	output_col = 0;
	//处理每对列标号
	for (col = 0; col < n_columns; col += 2)
	{
		int nchars;
		//如果col不是最后一个则执行之前的程序，否则nchars就为columns[col]到输入行的结尾
		if (col != n_columns - 1)
		{
			//如果后一个比前一个小，交换一下，再执行不就一样了
			if (columns[col] > columns[col + 1])
			{
				int temp = columns[col];
				columns[col] = columns[col + 1];
				columns[col + 1] = temp;
			}
			nchars = columns[col + 1] - columns[col] + 1;
		}
		else
			nchars = len - columns[col];
		//如果输入行结束或输出行数组已满，结束任务
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		//如果输出行数据空间不够，只复制可以容纳的数据
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		//复制相关的数据
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}

//1.1 Hello World!
//int main()
//{
//	printf("Hello World!\n");
//	system("pause");
//	return 0;
//}

//1.2 读取输入，输出打印
//int main()
//{
//	int ch;
//	int flag = 1;
//	int line = 1;
//	while ((ch = getchar()) != EOF)	//EOF -1
//	{
//		if (flag)		//每行先输出行号
//		{
//			printf("%d . ", line);
//			flag = 0;
//		}
//		if (ch == '\n')	//遇到换行符，行号加1
//		{
//			flag = 1;
//			line++;
//		}
//		putchar(ch);
//	}
//	system("pause");
//	return 0;
//}

//1.3 读取输入，输出打印，并计算checksum值
//int main()
//{
//	int ch;
//	char checksum = -1;
//	while ((ch = getchar()) != EOF)
//	{
//		checksum += ch;
//		if (ch == '\n')
//		{
//			printf("\tchecksum: %d", checksum);
//			checksum = -1;
//		}
//		putchar(ch);
//	}
//	system("pause");
//	return 0;
//}

//1.4 读取输入行直至最后一行，打印最长的一行，假定所有输入行均不超过1000个字符
//#define MAX_14 1000
//int main()
//{
//	printf("请输入：\n");
//	char input[MAX_14], output[MAX_14] = "";
//	while (strcmp("over", gets(input)) != 0)	//字符串结束后，下一行以over结束输入
//	{
//		if (strlen(input) > strlen(output))
//			strcpy(output, input);
//	}
//	printf("最常的一行：%s\n", output);
//	system("pause");
//	return 0;
//}