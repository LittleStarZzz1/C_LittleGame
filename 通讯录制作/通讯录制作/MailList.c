#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MailList.h"
struct MailList g_allMsg[1000];
int g_count;

int menu(){
	int tmp;
	int ret;
	printf("1. �����ϵ����Ϣ\n");
	printf("2. ɾ��ָ����ϵ����Ϣ\n");
	printf("3. ����ָ����ϵ����Ϣ\n");
	printf("4. �޸�ָ����ϵ����Ϣ\n");
	printf("5. ��ʾ������ϵ����Ϣ\n");
	printf("6. ���������ϵ����Ϣ\n");
	printf("������ѡ��:\n");
	ret = scanf("%d", &tmp);
	return ret? tmp : -1;
}
void MailList(){
	int op;
	int ret;
	char str[256] = { 0 };
	int searchRes[1001] = { 0 };
	while (1){
		op = menu();
		switch (op){
		case ADD_MSG:
			inputData();
			break;
		case DELETE_MSG:
			printf("����������Ҫɾ������Ŀ: \n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(str);
			if (ret > 0){
				deleteOneData(ret);
				printf("ɾ���ɹ�!\n");
			}
			else {
				printf("ɾ��ʧ��!\n");
			}
			break;
		case SEARCH_MSG:
			printf("����������Ҫ�������ַ���: \n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("���ҵ�%d������\n", searchRes[0]);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			outputData();
			break;
		case EMPTY_MSG:
			break;
		case -1:
			printf("������������,����������!\n");
			break;
		default:
			printf("������������,����������!\n");
		}
	}
}

int main(){
	MailList();
	system("pasue");
	return 0;
}