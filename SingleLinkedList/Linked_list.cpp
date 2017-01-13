#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	char c, e;
	list_pointer head, p;

	// dummy head 
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;

	printf("*************Command****************\n");	//show
	printf("+<c> : Insert c, -<c> : Delete c\n");
	printf("?<c> : Search c, S : Show, Q : Quit\n");
	printf("************************************\n");
	
	while (1) {
	printf("\nCommand> ");
	c = getch();
	putch(c);
	
	switch (c) {
		case '+' :
		e = getch();
		putch(e);
		list_insert(head, e); break;
		
		case '-' :
		e = getch();
		putch(e);
		list_delete(head, e); break;
		
		case '?' :
		e = getch();
		putch(e);
		p = list_search(head, e);
	
			if (p) {
			printf ("\n %c is in the list. \n", e);
			printf (" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
			}
			
			else printf ("\n %c is not in the list \n", e);
			break;
			
		case 's' :
		list_show(head); break;
		
		case 'q' :
		printf("\n ");
		exit(1);
		
		default : break;
	} //switch statment
	} //while statment
	
	return NULL;
}//main function

void list_insert(list_pointer head, Element e)
{
	list_pointer new_node;	//create new node 
	new_node = (list_pointer)malloc(sizeof(list_node));
	new_node->data = e;
	
	if(list_empty(head))	//head->data is empty
	{
		new_node->link = NULL;
		head->link = new_node;
	}
	
	else	//head->data is not empty
	{
		new_node->link = head->link;	//'head' <-> 'new_node' link
		head->link = new_node;
	}
}

void list_delete(list_pointer head, Element e)
{
	list_pointer pre = head;	//for save previous node 
	list_pointer current = head->link;	//for save current node
	
	while( pre != NULL){
		if( current->data == e ){	//search 
			pre->link = current->link;
			free(current);
		}
		else{	//not search, move link
			pre = pre->link;
			current = current->link;
		}
	}
}

list_pointer list_search(list_pointer head, Element e)
{
	list_pointer temp = head;
	
	printf("\n");
	
	while( temp != NULL){
		if( temp->data == e ){	//serach complete
			
			return temp;
		}
		
		temp = temp->link;
	}
}

int list_empty(list_pointer head)
{
	if(	head->link == NULL ) 
		return true;
	else 
		return false;
}



void list_show(list_pointer head)
{
	list_pointer temp = head;
	
	printf("\n");
	
	if( temp->link == NULL){
		printf("List is Empty\n");
	}
	
	while( temp != NULL){
		printf("%c ", temp->data);
		temp=temp->link;
	}
}
