#include "dequeue.h"

int main(){
	Dequeue qu;
	dequeueInit(&qu);
	printf("%d\n", dequeuePush(&qu, 1));//β��
	printf("%d\n", dequeuePush(&qu, 2));//β��	
	printf("%d\n", dequeuePush(&qu, 3));//β��
	printf("%d\n", dequeuePush(&qu, 4));//β��
	printf("%d\n", dequeuePush(&qu, 5));//β��(��������QUEUENUM),����ʧ��
	printf("%d\n", dequeueSize(&qu));//�鿴size��С
	printf("%d\n", dequeueBack(&qu));//�鿴����β����
	printf("%d\n", dequeueFront(&qu));//�鿴����ͷ����
	dequeuePop(&qu);//ͷɾ
	printf("%d\n", dequeueFront(&qu));//��ӡ���Ƿ�ͷɾ�ɹ�
	printf("%d\n", dequeueSize(&qu));//��size�Ƿ����仯
	printf("%d\n", dequeueIsEmpty(&qu));//�ж��Ƿ�Ϊ��,0��ʾ�ǿ�,1��ʾ��
	dequeueDestroy(&qu);
	system("pause");
	return 0;
}

