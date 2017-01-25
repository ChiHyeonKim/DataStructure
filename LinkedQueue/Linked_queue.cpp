#include "lQueue.h"

extern pQueueType front, rear;

int main()
{
	int num, data, e;

	while(1)
	{
		system("cls"); //system clear
		printf("\n ## ť����: ��ũ��ť## \n\n");
		printf("1) �����ͻ���: enQueue \n");
		printf("2) �����ͻ���: deQueue \n");
		printf("3) ��ü���\n");
		printf("4) ���α׷�����\n\n");
		printf("�޴�����: ");
		scanf("%d", &num);	
			
		switch(num) {
		case 1 : printf("\n �����ҵ������Է�: ");
		scanf("%d", &data); fflush(stdin); //delete memory garbage 
		enQueue(data);
		break;
		
		case 2 : deQueue(); break;
		
		case 3 : queue_Print(); break;
		
		case 4 : printf("���α׷�����... \n"); return 0;
		
		default : printf("�߸������ϼ̽��ϴ�. \n"); fflush(stdin);
		} system("pause");
	} //while
} //main

void enQueue(element item)
{
	pQueueType temp;	//create temp node
	temp = (pQueueType)malloc(sizeof(pQueueType));
	temp->queue = item;	//insert temp data
	temp->link = NULL;	//initialize temp link

	if(front == NULL && rear == NULL){ //first node create case
		front = temp;
		rear = temp;
	}
	
	else{
		if(front->link == NULL)	//front link setting
			front->link = temp;
		rear->link = temp;	//rear link setting
		rear = temp;	//rear setting
	}
	
}

element deQueue()
{
	printf("\n%d<%x, %x>\n", front->queue, front, front->link);	//print delete data
	
	if(front !=NULL) front = front->link;	//front location move
	if(front == NULL){
		printf("\n Queue is empty !!!\n");
	}
}

void queue_Print()
{	
	pQueueType temp = front; //front first location save
	printf("\n");
	
	if( front == NULL){
		printf("Queue is Empty\n");
	}
	
	while( front != NULL){
		printf("%d ", front->queue);
		front=front->link;	//front location move (for print)
	}
	
	front = temp;	//front location move
}

bool is_queue_empty()
{
	if(front->link == NULL){
		return 1;
	}
	else return 0;
} 
