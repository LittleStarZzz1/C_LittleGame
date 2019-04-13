#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("==============\n");
	printf("1. 开始游戏\n");
	printf("2. 退出游戏\n");
	printf("==============\n");
	int choice = 0;
	printf("请输入您的选择!\n");
	scanf("%d",&choice);
	return choice;
}
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			mine_map[row][col] = '0';
		}
	}
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		int row = rand() % 9;
		int col = rand() % 9;
		if (mine_map[row][col] == '1'){
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}
void PrintMap(char show_map[MAX_ROW][MAX_COL]){
	printf(" |");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL; ++col){
		printf("--", col);
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%d|", row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", show_map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row, int col, 
	char mine_map[MAX_ROW][MAX_COL], char show_map[MAX_ROW][MAX_COL]){
		int count = 0;
		if (row - 1 >= 0 && col - 1 >= 0 &&
			mine_map[row - 1][col - 1] == '1'){
			++count;
		}
		if (row - 1 >= 0 && mine_map[row - 1][col] == '1'){
			++count;
		}
		if (row - 1 >= 0 && col + 1 < MAX_ROW &&
			mine_map[row - 1][col + 1] == '1'){
			++count;
		}
		if (col - 1 >= 0 && mine_map[row][col - 1] == '1'){
			++count;
		}
		if (mine_map[row][col] == '1'){
			++count;
		}
		if (col + 1 < MAX_COL && mine_map[row][col + 1] == '1'){
			++count;
		}
		if (row + 1 < MAX_ROW && col - 1 >= 0 &&
			mine_map[row + 1][col - 1] == '1'){
			++count;
		}
		if (row + 1 < MAX_ROW && mine_map[row + 1][col] == '1'){
			++count;
		}
		if (row + 1 <= MAX_ROW && col + 1 < MAX_COL &&
			mine_map[row + 1][col + 1] == '1'){
			++count;
		}
		show_map[row][col] = count + '0';
}
void Game(){
	//用来表示翻开和未翻开的状态
	char show_map[MAX_ROW][MAX_COL];
	//用来表示有雷和没雷的状态
	char mine_map[MAX_ROW][MAX_COL];
	//初始化地图
	Init(show_map, mine_map);
	while (1){
		system("cls");
		//打印地图(show_map)
		PrintMap(show_map);
		//提示玩家输入一个坐标,并检验有效性
		int row = 0;
		int col = 0;
		int blank_count = 0;
		printf("请输入一组坐标:(row,col)");
		scanf("%d %d", &row, &col);
		//判断坐标是否合理
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您输入的坐标不合理!\n");
			continue;
		}
		//判断坐标位置是否被翻开
		if (show_map[row][col] != '*'){
			printf("您输入的坐标位置已被翻开!\n");
			continue;
		}
		//判断是否踩雷
		if (mine_map[row][col] == '1'){
			system("cls");
			PrintMap(mine_map);
			printf("GameOver!\n");
			return;
		}
		//判断游戏是否胜利
		++blank_count;
		if (blank_count == MAX_ROW * MAX_COL - MINE_COUNT){
			printf("游戏胜利!\n");
			return;
		}
		//告诉玩家当前位置有几颗雷
		UpdateShowMap(row,col,mine_map,show_map);
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 2){
			printf("Goodbye!\n");
			break;
		}
		else {
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}
