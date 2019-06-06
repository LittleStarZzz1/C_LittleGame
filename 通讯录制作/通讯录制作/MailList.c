#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MailList.h"
struct MailList g_allMsg[1000];
int g_count;

int menu(){
	int tmp;
	int ret;
	printf("1. 添加联系人信息\n");
	printf("2. 删除指定联系人信息\n");
	printf("3. 查找指定联系人信息\n");
	printf("4. 修改指定联系人信息\n");
	printf("5. 显示所有联系人信息\n");
	printf("6. 清空所有联系人信息\n");
	printf("请输入选项:\n");
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
			printf("请输入您需要删除的条目: \n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			ret = catchOneData(str);
			if (ret > 0){
				deleteOneData(ret);
				printf("删除成功!\n");
			}
			else {
				printf("删除失败!\n");
			}
			break;
		case SEARCH_MSG:
			printf("请输入您需要检索的字符串: \n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("共找到%d条数据\n", searchRes[0]);
			break;
		case CHANGE_MSG:
			break;
		case DISPLAY_MSG:
			outputData();
			break;
		case EMPTY_MSG:
			break;
		case -1:
			printf("您的输入有误,请重新输入!\n");
			break;
		default:
			printf("您的输入有误,请重新输入!\n");
		}
	}
}

int main(){
	MailList();
	system("pasue");
	return 0;
}