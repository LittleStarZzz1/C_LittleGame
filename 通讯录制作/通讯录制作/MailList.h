#ifndef _MAILLIST_H	//如果没有定义_MAILLIST_H就进
#define _MAILLIST_H	//保证该头文件可以被多次引用
enum{
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMPTY_MSG
};
struct MailList {
	char name[50];
	char gender;
	char tel[30];
	char addr[200];
	int age;
};
extern struct MailList g_allMsg[1000];
extern int g_count;
void inputData();
void searchData(char* find);
void outputSearchData(int* data);
void outputData();
int catchOneData(char* find);
void deleteOneData(int n);

#endif  // _MAILLIST_H