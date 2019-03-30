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
	// ��ӡ�б��
	printf("   |");
	for (int col = 0; col < max_col; ++col) {
		if (col < 10) {				// ������ֱ�����
			printf(" %d |", col);
		}
		else {						// ��λ���ϵ�������һ���ո��Զ���
			printf("%d |", col);
		}
	}
	printf("\n");
	// ��ӡÿ��
	for (int row = 0; row < max_row;++row) {
		// ��ӡ�зָ���
		for (int col = 0; col <= max_col; ++col) {
			printf("---|");
		}
		printf("-\n");
		// ��ӡ�б��
		if (row < 10) {			// ������ֱ�����
			printf(" %d", row);
		}
		else {					// ��λ���ϵ�������һ���ո��Զ���
			printf("%d", row);
		}
		// ��ӡÿ�е��ַ�����
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

// ���ɨ��
// ��ʾ��ͼ,�б߽�,�б߽�,λ����,λ����
void PlayerAction(char* show_map, int max_row, int max_col, int* row_out, int* col_out) {
	printf("����������λ�õ���,��: ");
	while (1) {
		scanf("%d,%d", row_out, col_out);
		if (*row_out < 0 || *row_out >= max_row || *col_out < 0 || *col_out >= max_col) {	// �����߽�
			printf("�Ƿ�λ��!����������: ");
			continue;
		}
		if (*(show_map + *row_out * max_col + *col_out) != '*') {							// λ�����ų�
			printf("��ǰλ�����ų�!����������: ");
			continue;
		}
		break;
	}
}

// ����ж�
// ����ͼ,�б߽�,�б߽�,λ����,λ����
int ResultJudge(char* mine_map, int max_row, int max_col, int row, int col) {
	if (*(mine_map + row * max_col + col) == '@') {
		return 0;		// �ȵ���
	}
	int sum = max_row * max_col;
	for (int curr = 0; curr < sum; ++curr) {
		if (*(mine_map + curr) == '*') {
			return 1;	// ������Ϸ
		}
	}
	return 2;			// ��Ϸʤ��
}

// ���µ�ͼ
// ��ʾ��ͼ,����ͼ,�б߽�,�б߽�,λ����,λ����
void UpdateMap(char* show_map, char* mine_map, int max_row, int max_col, int row, int col) {
	if (row < 0 || col < 0 || row >= max_row || col >= max_col
		|| *(mine_map + row * max_col + col) != '*') {
		return;
	}
	int count = 48;	// ��Χ�м�����
	// mine_map[row - 1][col - 1]�Ƿ�����
	if (row > 0 && col > 0 && *(mine_map + (row - 1) * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row - 1][col]�Ƿ�����
	if (row > 0 && *(mine_map + (row - 1) * max_col + col) == '@') {
		++count;
	}
	// mine_map[row - 1][col + 1]�Ƿ�����
	if (row > 0 && col < (max_col - 1) && *(mine_map + (row - 1) * max_col + (col + 1)) == '@') {
		++count;
	}
	// mine_map[row][col - 1]�Ƿ�����
	if (col > 0 && *(mine_map + row * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row][col + 1]�Ƿ�����
	if (col < (max_col - 1) && *(mine_map + row * max_col + (col + 1)) == '@') {
		++count;
	}
	// mine_map[row + 1][col - 1]�Ƿ�����
	if (row < (max_row - 1) && col > 0 && *(mine_map + (row + 1) * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row + 1][col]�Ƿ�����
	if (row < (max_row - 1) && *(mine_map + (row + 1) * max_col + col) == '@') {
		++count;
	}
	// mine_map[row + 1][col + 1]�Ƿ�����
	if (row < (max_row - 1) && col < (max_col - 1) && *(mine_map + (row + 1) * max_col + (col + 1)) == '@') {
		++count;
	}
	if (count == 48) {	// ��Χû�׵ĸ�Ϊ�ո�
		*(show_map + row * max_col + col) = 0;
		*(mine_map + row * max_col + col) = 0;
	}
	else {
		*(show_map + row * max_col + col) = count;
		*(mine_map + row * max_col + col) = count;
	}
	
	if (count == 48) {
		UpdateMap(show_map, mine_map, max_row, max_col, row - 1, col - 1);
		UpdateMap(show_map, mine_map, max_row, max_col, row - 1, col);
		UpdateMap(show_map, mine_map, max_row, max_col, row - 1, col + 1);
		UpdateMap(show_map, mine_map, max_row, max_col, row, col - 1);
		UpdateMap(show_map, mine_map, max_row, max_col, row, col + 1);
		UpdateMap(show_map, mine_map, max_row, max_col, row + 1, col - 1);
		UpdateMap(show_map, mine_map, max_row, max_col, row + 1, col);
		UpdateMap(show_map, mine_map, max_row, max_col, row + 1, col + 1);
	}
}

// ��Ϸ����
void Game(char* show_map, char* mine_map, int max_row, int max_col, int number_of_mines) {
	InitMap(show_map, max_row, max_col);					// ��ʼ����ʾ��ͼ
	InitMap(mine_map, max_row, max_col);					// ��ʼ������ͼ
	Lay_Mines(mine_map, max_row, max_col, number_of_mines);	// ����

	int result;
	while (1) {
		int row, col;		// ��������λ����,��
		system("cls");
		PrintMap(show_map, max_row, max_col);						// ��ӡ��ͼ
		PlayerAction(show_map, max_row, max_col, &row, &col);		//�������
		UpdateMap(show_map, mine_map, max_row, max_col, row, col);	//���µ�ͼ
		result = ResultJudge(mine_map, max_row, max_col, row, col);
		if (!result) {												//�ȵ���
			*(mine_map + row * max_col + col) = 'X';				//��ǲȵ�����
			break;
		}
		else if (result == 2) {										//��Ϸʤ��
			break;
		}
		
	}

	system("cls");
	PrintMap(mine_map, max_row, max_col);					// ��ӡ��ͼ
	if (result == 2) {
		printf("��ϲ�����ʤ��!\n");
	}
	else {
		printf("��ʧ����!\n");
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