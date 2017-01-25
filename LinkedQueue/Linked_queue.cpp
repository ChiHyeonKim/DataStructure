#include "lQueue.h"

extern pQueueType front, rear;

int main()
{
	int num, data, e;

	while(1)
	{
		system("cls"); //system clear
		printf("\n ## 큐구현: 링크드큐## \n\n");
		printf("1) 데이터삽입: enQueue \n");
		printf("2) 데이터삭제: deQueue \n");
		printf("3) 전체출력\n");
		printf("4) 프로그램종료\n\n");
		printf("메뉴선택: ");
		scanf("%d", &num);	
			
		switch(num) {
		case 1 : printf("\n 삽입할데이터입력: ");
		scanf("%d", &data); fflush(stdin); //delete memory garbage 
		enQueue(data);
		break;
		
		case 2 : deQueue(); break;
		
		case 3 : queue_Print(); break;
		
		case 4 : printf("프로그램종료... \n"); return 0;
		
		default : printf("잘못선택하셨습니다. \n"); fflush(stdin);
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
