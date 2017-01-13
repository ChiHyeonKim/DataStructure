#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

void main () {

 char c, e;

 printf("***********Command **********\n");
 printf("+<c> : Push c, -:Pop,\n");
 printf("S : Show, Q : Quit\n");
 printf("*****************************\n");

 while (1) {
  printf("\nCommand> ");
  c = getch();
  putch(c);
  c = toupper(c);
  
  switch (c) {
	case '+' :
	e = getch();
	putch(e);
	push(e);
	break;

	case '-' :
	e = pop();
	printf("\n %c \n", e);
	break;

	case 'S' :
	stack_show();
	break;

	case 'Q' :
	printf("\n");
	exit(1);
	
	default :
	break;
	}
	}
}

void push(Element e)
{
	stack[++top] = e;
	
	return e;
}

Element pop()
{
	if(top<0) printf("\nStack is empty!!!");
	else return stack[top--];
}

void stack_show()
{
	int i;
	
	printf("\n");
	
	for(i=0; i<=top; i++){
		printf("%c ", stack[i]);
	}
	
	printf("\n");
}
