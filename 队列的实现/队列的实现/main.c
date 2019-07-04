#include "dequeue.h"

int main(){
	Dequeue qu;
	dequeueInit(&qu);
	printf("%d\n", dequeuePush(&qu, 1));//尾插
	printf("%d\n", dequeuePush(&qu, 2));//尾插	
	printf("%d\n", dequeuePush(&qu, 3));//尾插
	printf("%d\n", dequeuePush(&qu, 4));//尾插
	printf("%d\n", dequeuePush(&qu, 5));//尾插(超过容量QUEUENUM),插入失败
	printf("%d\n", dequeueSize(&qu));//查看size大小
	printf("%d\n", dequeueBack(&qu));//查看队列尾数字
	printf("%d\n", dequeueFront(&qu));//查看队列头数字
	dequeuePop(&qu);//头删
	printf("%d\n", dequeueFront(&qu));//打印看是否头删成功
	printf("%d\n", dequeueSize(&qu));//看size是否发生变化
	printf("%d\n", dequeueIsEmpty(&qu));//判断是否为空,0表示非空,1表示空
	dequeueDestroy(&qu);
	system("pause");
	return 0;
}

