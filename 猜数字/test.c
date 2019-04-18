#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("===============\n");
	printf("1. 开始游戏\n");
	printf("2. 退出游戏\n");
	printf("===============\n");
	printf("请输入您的选择: \n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int to_guess = rand() % 100 + 1;
	int num;
	while (1){
		printf("请猜一个数字!\n");
		scanf("%d", &num);
		if (num < 0 || num > 100){
			printf("您输入的数不合规则!\n");
		}
		else if (num < to_guess){
			printf("低了!\n");
		}
		else if (num > to_guess){
			printf("高了!\n");
		}
		else {
			printf("恭喜您!猜对了!\n");
			break;
		}
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