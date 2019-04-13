#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu(){
	printf("==============\n");
	printf("1. ��ʼ��Ϸ\n");
	printf("2. �˳���Ϸ\n");
	printf("==============\n");
	int choice = 0;
	printf("����������ѡ��!\n");
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
	//������ʾ������δ������״̬
	char show_map[MAX_ROW][MAX_COL];
	//������ʾ���׺�û�׵�״̬
	char mine_map[MAX_ROW][MAX_COL];
	//��ʼ����ͼ
	Init(show_map, mine_map);
	while (1){
		system("cls");
		//��ӡ��ͼ(show_map)
		PrintMap(show_map);
		//��ʾ�������һ������,��������Ч��
		int row = 0;
		int col = 0;
		int blank_count = 0;
		printf("������һ������:(row,col)");
		scanf("%d %d", &row, &col);
		//�ж������Ƿ����
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("����������겻����!\n");
			continue;
		}
		//�ж�����λ���Ƿ񱻷���
		if (show_map[row][col] != '*'){
			printf("�����������λ���ѱ�����!\n");
			continue;
		}
		//�ж��Ƿ����
		if (mine_map[row][col] == '1'){
			system("cls");
			PrintMap(mine_map);
			printf("GameOver!\n");
			return;
		}
		//�ж���Ϸ�Ƿ�ʤ��
		++blank_count;
		if (blank_count == MAX_ROW * MAX_COL - MINE_COUNT){
			printf("��Ϸʤ��!\n");
			return;
		}
		//������ҵ�ǰλ���м�����
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
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}
