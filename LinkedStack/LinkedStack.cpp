#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedStack.h"

int main() {
	
	char c, e;
	linked_stack s;

	// 링크드 스택 초기화
	s.top = NULL;
	
	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);

		switch (c) {
			case '+':
			e = getch();
			putch(e);
			push(&s, e);
			break;

			case '-':
			pop(&s);
			break;
			
			case 'S':
			stack_show(&s);
			break;
			
			case 'Q':
			printf("\n");
			exit(1);
			default: break;
		} //switch
		} //while
			
	return 0;
}

void push(linked_stack *s, Element e)
{
	stack_pointer new_node;	//create new node
	new_node = (stack_pointer)malloc(sizeof(stack_node));
	
	new_node->data = e;	//push new node data
	new_node->link = s->top;	//push new link
	s->top = new_node;	//top adress move
}

Element pop(linked_stack *s)
{
	if( s->top == NULL){
		printf("Stack is Empty !!!\n");
	}
	
	else{
		printf("\n%c", s->top->data);
		s->top = s->top->link;	//top adress move
	}
}

void stack_show(linked_stack *s)
{
	stack_pointer temp;	// 'temp' is data for top adress memory
	temp = (stack_pointer)malloc(sizeof(stack_node));	

	temp->link = s->top;	//top adrees memory	
	
	printf("\n");

	if( s->top == NULL){
		printf("Stack is Empty !!!\n");
	}
	
	while( s->top != NULL){
		printf("%c ", s->top->data);
		s->top = s->top->link;	// for next data move, top adress move
	}
	
	s->top = temp->link;	//top adress return
}
