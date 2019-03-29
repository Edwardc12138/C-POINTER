//井字棋
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX_ROW 3
#define MAX_COL 3

static char chessboard[MAX_ROW][MAX_COL];		//棋盘

//初始化游戏
int Init() {
	printf("********************************\n");
	printf("***** 开始:1 ****** 退出:0 *****\n");
	printf("********************************\n");
	printf("请输入: ");
	int choice;
	scanf("%d", &choice);
	while (choice != 1 && choice != 0) {
		printf("输入有误!请重输: ");
		scanf("%d", &choice);
	}
	return choice;
}

//初始化棋盘
void InitBoard() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chessboard[row][col] = ' ';
		}
	}
}

//打印棋盘
void PrintBoard() {
	for (int row = 0; row < MAX_ROW; ++row) {			//打印每行
		for (int col = 0; col < MAX_COL; ++col) {		//打印每列
			printf(" %c ", chessboard[row][col]);		//打印棋子
			if (col != MAX_COL - 1) {					//打印棋盘列分割线,最后一列不打印
				printf("|");
			}
		}
		printf("\n");
		if (row != MAX_ROW - 1) {						//打印棋盘行分割线,最后一行不打印
			for (int col = 0; col < MAX_COL; ++col) {
				printf("---");
				if (col != MAX_COL - 1) {				//分割线行的列分割线
					printf("|");
				}
			}			
		}
		printf("\n");
	}
}

//当前位置是否已有棋子
int IsDone(int row, int col) {
	if (chessboard[row][col] != ' ') {
		return 1;	//已有棋子
	}
	return 0;		//无棋子
}

//玩家落子
void PlayerDrop() {
	printf("请输入落子位置行,列: ");
	int row, col;
	scanf("%d,%d", &row, &col);
	while (1) {
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {	//超出棋盘
			printf("非法位置!请重新输入位置: ");
			scanf("%d,%d", &row, &col);
		}
		else if (IsDone(row, col)) {									//当前位置已落子
			printf("当前位置已有棋子!请重新输入位置: ");
			scanf("%d,%d", &row, &col);
		}
		else {
			chessboard[row][col] = 'X';									//玩家落子
			break;
		}
	}
}

//电脑落子
void ComputerDrop() {
	int row, col;
	srand((unsigned int)time(NULL));
	row = rand() % MAX_ROW;
	col = rand() % MAX_COL;
	while (IsDone(row, col)) {		//当前位置已落子
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
	}
	chessboard[row][col] = 'O';
}

//棋盘是否下满
int IsFull() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chessboard[row][col] == ' ') {	//未下满
				return 0;
			}
		}
	}
	return 1;
}

//判定胜负
char Winner() {
	//每行是否连成
	for (int row = 0; row < MAX_ROW; ++row) {
		if (chessboard[row][0] == chessboard[row][1] && chessboard[row][1] == chessboard[row][2]
			&& chessboard[row][0] != ' ') {
			return chessboard[row][0];
		}
	}
	//每列是否连成
	for (int col = 0; col < MAX_ROW; ++col) {
		if (chessboard[0][col] == chessboard[1][col] && chessboard[1][col] == chessboard[2][col]
			&& chessboard[0][col] != ' ') {
			return chessboard[0][col];
		}
	}
	//对角线是否连成
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2]
		&& chessboard[1][1] != ' ') {
		return chessboard[1][1];
	}
	if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0]
		&& chessboard[1][1] != ' ') {
		return chessboard[1][1];
	}
	//棋盘是否下满
	if (IsFull() == 0) {
		return 'c';
	}
	return 'd';					//平局
}

//游戏
char Game() {
	InitBoard();
	char result;
	while (1) {
		system("cls");
		PrintBoard();			//打印棋盘/打印电脑落子
		PlayerDrop();			//玩家落子
		result = Winner();
		if (result != 'c') {	//游戏是否继续
			break;
		}
		system("cls");
		PrintBoard();			//打印玩家落子
		ComputerDrop();			//电脑落子
		result = Winner();
		if (result != 'c') {	//游戏是否继续
			break;
		}
	}

	system("cls");
	PrintBoard();			//打印结束时的棋盘
	if (result == 'X') {
		printf("您胜利了!\n");
		return result;
	}
	else if (result == 'O') {
		printf("您失败了!\n");
		return result;
	}
	else {
		printf("平局!\n");
		return result;
	}
}

int main() {
	char res;
	int win_times = 0,		//胜利次数
		fail_times = 0,		//失败次数
		draw_times = 0;		//打平次数
	while (1) {
		if (Init() == 0) {		//退出游戏
			break;
		}
		res = Game();			//游戏
		//统计胜负
		if (res == 'X') {
			++win_times;
		}
		else if (res == 'O') {
			++fail_times;
		}
		else {
			++draw_times;
		}
		printf("当前战况: 胜 %d 负 %d 平 %d\n", win_times, fail_times, draw_times);
	}
	return 0;
}