// ɨ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������ͼ
#define MAX_ROW_LEVEL0 9
#define MAX_COL_LEVEL0 9
#define NUMBER_OF_MINES0 10
// �м���ͼ
#define MAX_ROW_LEVEL1 16
#define MAX_COL_LEVEL1 16
#define NUMBER_OF_MINES1 40
// �߼���ͼ
#define MAX_ROW_LEVEL2 16
#define MAX_COL_LEVEL2 30
#define NUMBER_OF_MINES2 99

// �˵�
int Menu() {
	printf("*********************************\n");
	printf("********** MineSweeper **********\n");
	printf("*********************************\n");
	printf("***** ��ʼ:1 ******* �˳�:0 *****\n");
	printf("*********************************\n");
	printf("������: ");
	int choice;
	scanf("%d", &choice);
	while (choice != 1 && choice != 0) {
		printf("��������!������: ");
		scanf("%d", &choice);
	}
	return choice;
}

// �Ѷ�ѡ��
int Level() {
	printf("ѡ���Ѷ�: 0.����  1.�м�  2.�߼�\n");
	int choice;	
	scanf("%d", &choice);
	while (choice != 0 && choice != 1 && choice != 2) {
		printf("��������!������: ");
		scanf("%d", &choice);
	}
	return choice;
}

// ��ʼ����ͼ
// ��ͼ,�б߽�,�б߽�
void InitMap(char* map, int max_row, int max_col) {
	int sum = max_row * max_col;	// ѭ������
	for (int curr = 0; curr < sum;++curr) {
		*(map + curr) = '*';
	}
}

// ����
// ����ͼ,�б߽�,�б߽�,������
void Lay_Mines(char* mine_map, int max_row, int max_col, int number_of_mines) {
	srand((unsigned int)time(NULL));
	while (number_of_mines > 0) {
		int row = rand() % max_row;
		int col = rand() % max_col;
		char* mine_position = mine_map + row * max_col + col;
		if (*mine_position == '@') {	// �жϵ�ǰλ���Ƿ������,@��ʾ��
			continue;
		}
		*mine_position = '@';	// ��ǰλ����Ϊ����
		--number_of_mines;
	}
}

// ��ӡ��ͼ
// ��ͼ,�б߽�,�б߽�
void PrintMap(char* map, int max_row, int max_col) {
	//��ӡ�б��
	printf("   |");
	for (int col = 0; col < max_col; ++col) {
		printf(" %d |", col);
	}
	printf("\n");
	//��ӡÿ��
	for (int row = 0; row < max_row;++row) {
		//��ӡ�зָ���
		for (int col = 0; col <= max_col; ++col) {
			printf("---|");
		}
		printf("-\n");
		//��ӡ�б��
		printf(" %d", row);
		//��ӡÿ�е��ַ�����
		for (int col = 0; col < max_col;++col) {
			printf(" | %c", *(map + row * max_col + col));
		}
		printf(" |\n");
	}
	for (int col = 0; col <= max_col; ++col) {
		printf("---|");
	}
	printf("-\n");
}

// ��Ϸ����
void Game(char* show_map, char* mine_map, int max_row, int max_col, int number_of_mines) {
	InitMap(show_map, max_row, max_col);	// ��ʼ����ʾ��ͼ
	InitMap(mine_map, max_row, max_col);	// ��ʼ������ͼ
	Lay_Mines(mine_map, max_row, max_col, number_of_mines);	// ����
	while (1) {
		PrintMap(show_map, max_row, max_col);
		system("pause");
	}
}

int main() {
	while (1) {
		if (Menu() == 0) {	// 0�˳���Ϸ
			break;
		}

		int level = Level();
		if (level == 0) {			// ����,9*9,10����,
			char show_map[MAX_ROW_LEVEL0][MAX_COL_LEVEL0],	// ��ʾ��ͼ
				mine_map[MAX_ROW_LEVEL0][MAX_COL_LEVEL0];	// ����ͼ
			Game(show_map, mine_map, MAX_ROW_LEVEL0, MAX_COL_LEVEL0, NUMBER_OF_MINES0);
		}
		else if (level == 1) {		// �м�,16*16,40����
			char show_map[MAX_ROW_LEVEL1][MAX_COL_LEVEL1],	// ��ʾ��ͼ
				mine_map[MAX_ROW_LEVEL1][MAX_COL_LEVEL1];	// ����ͼ
			Game(show_map, mine_map, MAX_ROW_LEVEL1, MAX_COL_LEVEL1, NUMBER_OF_MINES1);
		}
		else {						// �߼�,16*30,99����
			char show_map[MAX_ROW_LEVEL2][MAX_COL_LEVEL2],	// ��ʾ��ͼ
				mine_map[MAX_ROW_LEVEL2][MAX_COL_LEVEL2];	// ����ͼ
			Game(show_map, mine_map, MAX_ROW_LEVEL2, MAX_COL_LEVEL2, NUMBER_OF_MINES2);
		}
	}
	return 0;
}