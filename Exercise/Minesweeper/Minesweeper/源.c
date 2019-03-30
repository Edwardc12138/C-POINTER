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
	// 打印列标号
	printf("   |");
	for (int col = 0; col < max_col; ++col) {
		if (col < 10) {				// 单个数直接输出
			printf(" %d |", col);
		}
		else {						// 两位以上的数减少一个空格以对齐
			printf("%d |", col);
		}
	}
	printf("\n");
	// 打印每行
	for (int row = 0; row < max_row;++row) {
		// 打印行分割线
		for (int col = 0; col <= max_col; ++col) {
			printf("---|");
		}
		printf("-\n");
		// 打印行标号
		if (row < 10) {			// 单个数直接输出
			printf(" %d", row);
		}
		else {					// 两位以上的数减少一个空格以对齐
			printf("%d", row);
		}
		// 打印每行的字符数组
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

// 玩家扫雷
// 显示地图,行边界,列边界,位置行,位置列
void PlayerAction(char* show_map, int max_row, int max_col, int* row_out, int* col_out) {
	printf("请输入排雷位置的行,列: ");
	while (1) {
		scanf("%d,%d", row_out, col_out);
		if (*row_out < 0 || *row_out >= max_row || *col_out < 0 || *col_out >= max_col) {	// 超出边界
			printf("非法位置!请重新输入: ");
			continue;
		}
		if (*(show_map + *row_out * max_col + *col_out) != '*') {							// 位置已排除
			printf("当前位置以排除!请重新输入: ");
			continue;
		}
		break;
	}
}

// 结果判定
// 地雷图,行边界,列边界,位置行,位置列
int ResultJudge(char* mine_map, int max_row, int max_col, int row, int col) {
	if (*(mine_map + row * max_col + col) == '@') {
		return 0;		// 踩到雷
	}
	int sum = max_row * max_col;
	for (int curr = 0; curr < sum; ++curr) {
		if (*(mine_map + curr) == '*') {
			return 1;	// 继续游戏
		}
	}
	return 2;			// 游戏胜利
}

// 更新地图
// 显示地图,地雷图,行边界,列边界,位置行,位置列
void UpdateMap(char* show_map, char* mine_map, int max_row, int max_col, int row, int col) {
	if (row < 0 || col < 0 || row >= max_row || col >= max_col
		|| *(mine_map + row * max_col + col) != '*') {
		return;
	}
	int count = 48;	// 周围有几颗雷
	// mine_map[row - 1][col - 1]是否是雷
	if (row > 0 && col > 0 && *(mine_map + (row - 1) * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row - 1][col]是否是雷
	if (row > 0 && *(mine_map + (row - 1) * max_col + col) == '@') {
		++count;
	}
	// mine_map[row - 1][col + 1]是否是雷
	if (row > 0 && col < (max_col - 1) && *(mine_map + (row - 1) * max_col + (col + 1)) == '@') {
		++count;
	}
	// mine_map[row][col - 1]是否是雷
	if (col > 0 && *(mine_map + row * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row][col + 1]是否是雷
	if (col < (max_col - 1) && *(mine_map + row * max_col + (col + 1)) == '@') {
		++count;
	}
	// mine_map[row + 1][col - 1]是否是雷
	if (row < (max_row - 1) && col > 0 && *(mine_map + (row + 1) * max_col + (col - 1)) == '@') {
		++count;
	}
	// mine_map[row + 1][col]是否是雷
	if (row < (max_row - 1) && *(mine_map + (row + 1) * max_col + col) == '@') {
		++count;
	}
	// mine_map[row + 1][col + 1]是否是雷
	if (row < (max_row - 1) && col < (max_col - 1) && *(mine_map + (row + 1) * max_col + (col + 1)) == '@') {
		++count;
	}
	if (count == 48) {	// 周围没雷的赋为空格
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

// 游戏主体
void Game(char* show_map, char* mine_map, int max_row, int max_col, int number_of_mines) {
	InitMap(show_map, max_row, max_col);					// 初始化显示地图
	InitMap(mine_map, max_row, max_col);					// 初始化地雷图
	Lay_Mines(mine_map, max_row, max_col, number_of_mines);	// 布雷

	int result;
	while (1) {
		int row, col;		// 玩家输入的位置行,列
		system("cls");
		PrintMap(show_map, max_row, max_col);						// 打印地图
		PlayerAction(show_map, max_row, max_col, &row, &col);		//玩家排雷
		UpdateMap(show_map, mine_map, max_row, max_col, row, col);	//更新地图
		result = ResultJudge(mine_map, max_row, max_col, row, col);
		if (!result) {												//踩到雷
			*(mine_map + row * max_col + col) = 'X';				//标记踩到的雷
			break;
		}
		else if (result == 2) {										//游戏胜利
			break;
		}
		
	}

	system("cls");
	PrintMap(mine_map, max_row, max_col);					// 打印地图
	if (result == 2) {
		printf("恭喜您获得胜利!\n");
	}
	else {
		printf("您失败了!\n");
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