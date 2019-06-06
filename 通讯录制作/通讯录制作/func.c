#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "MailList.h"
//���뺯��
void inputData(){
	struct MailList tmp;
	printf("����������: \n");
	scanf("%49s", tmp.name);
	getchar();
	printf("�������Ա�(f/m): \n");
	scanf("%c", &tmp.gender);
	printf("����������: \n");
	scanf("%d", &tmp.age);
	printf("������绰����: \n");
	scanf("%29s", tmp.tel);
	printf("�������ͥסַ: \n");
	scanf("%199s", tmp.addr);
	int i;
	for (i = 0; i < g_count; ++i){
		if (strcmp(g_allMsg[i].name, tmp.name) > 0){
			break;
		}
	}
	int j;
	for (j = g_count; j > i; --j){
		g_allMsg[j] = g_allMsg[j - 1];
	}
	g_allMsg[i] = tmp;
	g_count++;
}
//�ҵ����ӡ,����Ҫ����ֵ
void searchData(char* find, int* searchRes){
	int i;
	int flag;
	int first = 1;
	char age[4] = { 0 };
	char* ret;
	do{
		flag = 1;
		for (i = 0; i < g_count; ++i){
			ret = strstr(g_allMsg[i].name, find);
			if (ret){
				break;
			}

			sprintf(age, "%d", g_allMsg[i].age);
			if (!strcmp(age, find)){
				break;
			}
			ret = strstr(g_allMsg[i].tel, find);
			if (ret){
				break;
			}
			
			ret = strstr(g_allMsg[i].addr, find);
			if (ret){
				break;
			}
			flag = 0;
		}
	} while (0);
	if (flag){
		++searchRes[0];
		searchRes[searchRes[0]] = i;
	}
	
}
void deleteOneData(int n){
	int i;
	for (i = n; i < g_count; ++i){
		g_allMsg[i] = g_allMsg[i + 1];
	}
	--g_count;
}
int catchOneData(char* find){
	int schres[100] = { 0 };
	searchData(find,schres);
	if (schres[0] == 0){
		return -1;
	}
	else if (schres[0] == 1){
		return schres[1];
	}
	else {
		int i;
		outputSearchData(schres);
		printf("��������Ҫɾ���ڼ�������!\n");
		scanf("%d", &i);
		if (i < 1 || i > schres[0]){
			return -1;
		}
		return schres[i];
	}
}

void outputSearchData(int* data){
	int i;
	if (data[0] == 0){
		printf("û�з�������������!\n");
		return;
	}
	printf("  ����    �Ա�  ����   �绰����    ��ͥסַ\n");
	for (i = 1; i <= data[0]; ++i){
		printf("%-10s %3c  %3d  %11s %s\n", g_allMsg[data[i]].name,
			g_allMsg[data[i]].gender, g_allMsg[data[i]].age,
			g_allMsg[data[i]].tel, g_allMsg[data[i]].addr);
	}
}

void outputData(){
	int i;
	if (g_count == 0){
		printf("û������!\n");
		return;
	}
	printf("    ����    �Ա�  ����   �绰����    ��ͥסַ\n");
	for (i = 0; i < g_count; ++i){
		printf("%2d %-10s %3c  %3d  %11s %s\n", 
			i,
			g_allMsg[i].name, 
			g_allMsg[i].gender, 
			g_allMsg[i].age, 
			g_allMsg[i].tel, 
			g_allMsg[i].addr);
	}
}







