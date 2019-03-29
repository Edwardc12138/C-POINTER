//������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX_ROW 3
#define MAX_COL 3

static char chessboard[MAX_ROW][MAX_COL];		//����

//��ʼ����Ϸ
int Init() {
	printf("********************************\n");
	printf("***** ��ʼ:1 ****** �˳�:0 *****\n");
	printf("********************************\n");
	printf("������: ");
	int choice;
	scanf("%d", &choice);
	while (choice != 1 && choice != 0) {
		printf("��������!������: ");
		scanf("%d", &choice);
	}
	return choice;
}

//��ʼ������
void InitBoard() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chessboard[row][col] = ' ';
		}
	}
}

//��ӡ����
void PrintBoard() {
	for (int row = 0; row < MAX_ROW; ++row) {			//��ӡÿ��
		for (int col = 0; col < MAX_COL; ++col) {		//��ӡÿ��
			printf(" %c ", chessboard[row][col]);		//��ӡ����
			if (col != MAX_COL - 1) {					//��ӡ�����зָ���,���һ�в���ӡ
				printf("|");
			}
		}
		printf("\n");
		if (row != MAX_ROW - 1) {						//��ӡ�����зָ���,���һ�в���ӡ
			for (int col = 0; col < MAX_COL; ++col) {
				printf("---");
				if (col != MAX_COL - 1) {				//�ָ����е��зָ���
					printf("|");
				}
			}			
		}
		printf("\n");
	}
}

//��ǰλ���Ƿ���������
int IsDone(int row, int col) {
	if (chessboard[row][col] != ' ') {
		return 1;	//��������
	}
	return 0;		//������
}

//�������
void PlayerDrop() {
	printf("����������λ����,��: ");
	int row, col;
	scanf("%d,%d", &row, &col);
	while (1) {
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {	//��������
			printf("�Ƿ�λ��!����������λ��: ");
			scanf("%d,%d", &row, &col);
		}
		else if (IsDone(row, col)) {									//��ǰλ��������
			printf("��ǰλ����������!����������λ��: ");
			scanf("%d,%d", &row, &col);
		}
		else {
			chessboard[row][col] = 'X';									//�������
			break;
		}
	}
}

//��������
void ComputerDrop() {
	int row, col;
	srand((unsigned int)time(NULL));
	row = rand() % MAX_ROW;
	col = rand() % MAX_COL;
	while (IsDone(row, col)) {		//��ǰλ��������
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
	}
	chessboard[row][col] = 'O';
}

//�����Ƿ�����
int IsFull() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chessboard[row][col] == ' ') {	//δ����
				return 0;
			}
		}
	}
	return 1;
}

//�ж�ʤ��
char Winner() {
	//ÿ���Ƿ�����
	for (int row = 0; row < MAX_ROW; ++row) {
		if (chessboard[row][0] == chessboard[row][1] && chessboard[row][1] == chessboard[row][2]
			&& chessboard[row][0] != ' ') {
			return chessboard[row][0];
		}
	}
	//ÿ���Ƿ�����
	for (int col = 0; col < MAX_ROW; ++col) {
		if (chessboard[0][col] == chessboard[1][col] && chessboard[1][col] == chessboard[2][col]
			&& chessboard[0][col] != ' ') {
			return chessboard[0][col];
		}
	}
	//�Խ����Ƿ�����
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2]
		&& chessboard[1][1] != ' ') {
		return chessboard[1][1];
	}
	if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0]
		&& chessboard[1][1] != ' ') {
		return chessboard[1][1];
	}
	//�����Ƿ�����
	if (IsFull() == 0) {
		return 'c';
	}
	return 'd';					//ƽ��
}

//��Ϸ
char Game() {
	InitBoard();
	char result;
	while (1) {
		system("cls");
		PrintBoard();			//��ӡ����/��ӡ��������
		PlayerDrop();			//�������
		result = Winner();
		if (result != 'c') {	//��Ϸ�Ƿ����
			break;
		}
		system("cls");
		PrintBoard();			//��ӡ�������
		ComputerDrop();			//��������
		result = Winner();
		if (result != 'c') {	//��Ϸ�Ƿ����
			break;
		}
	}

	system("cls");
	PrintBoard();			//��ӡ����ʱ������
	if (result == 'X') {
		printf("��ʤ����!\n");
		return result;
	}
	else if (result == 'O') {
		printf("��ʧ����!\n");
		return result;
	}
	else {
		printf("ƽ��!\n");
		return result;
	}
}

int main() {
	char res;
	int win_times = 0,		//ʤ������
		fail_times = 0,		//ʧ�ܴ���
		draw_times = 0;		//��ƽ����
	while (1) {
		if (Init() == 0) {		//�˳���Ϸ
			break;
		}
		res = Game();			//��Ϸ
		//ͳ��ʤ��
		if (res == 'X') {
			++win_times;
		}
		else if (res == 'O') {
			++fail_times;
		}
		else {
			++draw_times;
		}
		printf("��ǰս��: ʤ %d �� %d ƽ %d\n", win_times, fail_times, draw_times);
	}
	return 0;
}