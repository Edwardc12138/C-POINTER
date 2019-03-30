// 扫雷
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 初级地图
#define MAX_ROW_LEVEL0 9
#define MAX_COL_LEVEL0 9
#define NUMBER_OF_MINES0 10
// 中级地图
#define MAX_ROW_LEVEL1 16
#define MAX_COL_LEVEL1 16
#define NUMBER_OF_MINES1 40
// 高级地图
#define MAX_ROW_LEVEL2 16
#define MAX_COL_LEVEL2 30
#define NUMBER_OF_MINES2 99

// 菜单
int Menu() {
	printf("*********************************\n");
	printf("********** MineSweeper **********\n");
	printf("*********************************\n");
	printf("***** 开始:1 ******* 退出:0 *****\n");
	printf("*********************************\n");
	printf("请输入: ");
	int choice;
	scanf("%d", &choice);
	while (choice != 1 && choice != 0) {
		printf("输入有误!请重输: ");
		scanf("%d", &choice);
	}
	return choice;
}

// 难度选择
int Level() {
	printf("选择难度: 0.初级  1.中级  2.高级\n");
	int choice;	
	scanf("%d", &choice);
	while (choice != 0 && choice != 1 && choice != 2) {
		printf("输入有误!请重输: ");
		scanf("%d", &choice);
	}
	return choice;
}

// 初始化地图
// 地图,行边界,列边界
void InitMap(char* map, int max_row, int max_col) {
	int sum = max_row * max_col;	// 循环次数
	for (int curr = 0; curr < sum;++curr) {
		*(map + curr) = '*';
	}
}

// 布雷
// 地雷图,行边界,列边界,布雷数
void Lay_Mines(char* mine_map, int max_row, int max_col, int number_of_mines) {
	srand((unsigned int)time(NULL));
	while (number_of_mines > 0) {
		int row = rand() % max_row;
		int col = rand() % max_col;
		char* mine_position = mine_map + row * max_col + col;
		if (*mine_position == '@') {	// 判断当前位置是否存在雷,@表示雷
			continue;
		}
		*mine_position = '@';	// 当前位置设为地雷
		--number_of_mines;
	}
}

// 打印地图
// 地图,行边界,列边界
void PrintMap(char* map, int max_row, int max_col) {
	//打印列标号
	printf("   |");
	for (int col = 0; col < max_col; ++col) {
		printf(" %d |", col);
	}
	printf("\n");
	//打印每行
	for (int row = 0; row < max_row;++row) {
		//打印行分割线
		for (int col = 0; col <= max_col; ++col) {
			printf("---|");
		}
		printf("-\n");
		//打印行标号
		printf(" %d", row);
		//打印每行的字符数组
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

// 游戏主体
void Game(char* show_map, char* mine_map, int max_row, int max_col, int number_of_mines) {
	InitMap(show_map, max_row, max_col);	// 初始化显示地图
	InitMap(mine_map, max_row, max_col);	// 初始化地雷图
	Lay_Mines(mine_map, max_row, max_col, number_of_mines);	// 布雷
	while (1) {
		PrintMap(show_map, max_row, max_col);
		system("pause");
	}
}

int main() {
	while (1) {
		if (Menu() == 0) {	// 0退出游戏
			break;
		}

		int level = Level();
		if (level == 0) {			// 初级,9*9,10个雷,
			char show_map[MAX_ROW_LEVEL0][MAX_COL_LEVEL0],	// 显示地图
				mine_map[MAX_ROW_LEVEL0][MAX_COL_LEVEL0];	// 地雷图
			Game(show_map, mine_map, MAX_ROW_LEVEL0, MAX_COL_LEVEL0, NUMBER_OF_MINES0);
		}
		else if (level == 1) {		// 中级,16*16,40个雷
			char show_map[MAX_ROW_LEVEL1][MAX_COL_LEVEL1],	// 显示地图
				mine_map[MAX_ROW_LEVEL1][MAX_COL_LEVEL1];	// 地雷图
			Game(show_map, mine_map, MAX_ROW_LEVEL1, MAX_COL_LEVEL1, NUMBER_OF_MINES1);
		}
		else {						// 高级,16*30,99个雷
			char show_map[MAX_ROW_LEVEL2][MAX_COL_LEVEL2],	// 显示地图
				mine_map[MAX_ROW_LEVEL2][MAX_COL_LEVEL2];	// 地雷图
			Game(show_map, mine_map, MAX_ROW_LEVEL2, MAX_COL_LEVEL2, NUMBER_OF_MINES2);
		}
	}
	return 0;
}