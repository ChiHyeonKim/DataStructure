#include <stdio.h>
#include <stdlib.h>
#ifndef ELEMENT
#define ELEMENT
typedef int element;
#endif

#ifndef __QUEUE_H
#define __QUEUE_H
typedef struct _queueType{
	element queue;
	struct _queueType *link;
}QueueType, *pQueueType;	//자료형, 포인터 이름 

pQueueType front = NULL;
pQueueType rear = NULL;

void enQueue(element item);
element deQueue();
void queue_Print();
bool is_queue_empty();
#endif
