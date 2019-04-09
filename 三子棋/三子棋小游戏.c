#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Menu(){
	printf("===============\n");
	printf("1. ��ʼ��Ϸ\n");
	printf("2. �˳���Ϸ\n");
	printf("===============\n");
	printf("����������ѡ��: \n");
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
	printf("���������!\n");
	//��x��ʾ�������
	while (1) {
		printf("������һ������(row,col): \n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0){
			printf("�������������!\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("�������λ����������!\n");
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
	//����'x'��ʾ���ʤ��
	//����'o'��ʾ����ʤ��
	//����'q'��ʾ����
	//����' '��ʾ��δ�ֳ�ʤ��,,Ҳ���Ǻ���,��Ϸ����
	//���������
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//���������
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//���Խ���
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
	//��������,�����г�ʼ��
	Init();
	char winner;
	while (1){
		system("cls");
		//��ӡ����
		Print();
		//���������,��ʾ�������һ������λ�õ�����
		PlayerMove();
		//�����Ϸ�Ƿ����
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
		//��������(����һ�������)
		ComputerMove();
		//�����Ϸ�Ƿ����
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	Print();
	if (winner == 'x'){
		printf("��ϲ��!��Ӯ��\n");
	}
	else if (winner == 'o'){
		printf("���ź�!�´�һ����Ӯ��!\n");
	}
	else if (winner == 'q'){
		printf("������!��Ȼƽ����!]\n");
	}
	else {
		printf("���������!\n");
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
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}