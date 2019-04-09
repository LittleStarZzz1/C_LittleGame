#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu(){
	printf("===============\n");
	printf("1. 开始游戏\n");
	printf("2. 退出游戏\n");
	printf("===============\n");
	printf("请输入您的选择: \n");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];
void Init(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			chess_board[row][col] = ' ';
		}
	}
}
void Print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("| %c | %c | %c |\n",chess_board[row][0],chess_board[row][1],
			chess_board[row][2]);
		if (row != MAX_ROW){
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove(){
	printf("请玩家落子!\n");
	//用x表示玩家落子
	while (1) {
		printf("请输入一组坐标(row,col): \n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0){
			printf("你的呢输入有误!\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("您输入的位置已有棋子!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
int Isfull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
int CheckGameOver(){
	//返回'x'表示玩家胜利
	//返回'o'表示电脑胜利
	//返回'q'表示和棋
	//返回' '表示既未分出胜负,,也不是和棋,游戏继续
	//检查所有行
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//检查所有列
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//检查对角线
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (Isfull()){
		return 'q';
	}
	return ' ';
}
void ComputerMove(){
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
void Game(){
	//创建棋盘,并进行初始化
	Init();
	char winner;
	while (1){
		system("cls");
		//打印棋盘
		Print();
		//让玩家落子,提示玩家输入一个落子位置的坐标
		PlayerMove();
		//检测游戏是否结束
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
		//电脑落子(生成一对随机数)
		ComputerMove();
		//检测游戏是否结束
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	Print();
	if (winner == 'x'){
		printf("恭喜你!你赢了\n");
	}
	else if (winner == 'o'){
		printf("真遗憾!下次一定会赢的!\n");
	}
	else if (winner == 'q'){
		printf("真厉害!竟然平局了!]\n");
	}
	else {
		printf("好像出错了!\n");
	}

}

int main(){
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