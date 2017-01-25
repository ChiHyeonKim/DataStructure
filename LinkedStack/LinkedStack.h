#define Element char
#define bool unsigned char
#define true 1
#define false 0

typedef struct stack_node *stack_pointer;

typedef struct stack_node {
	Element data;
	stack_pointer link;
} stack_node;

typedef struct {
	stack_pointer top;
} linked_stack;

void push(linked_stack *s, Element e);
Element pop(linked_stack *s);
void stack_show(linked_stack *s);
