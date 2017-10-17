#include "stack.h";

void main() {

	LinkedListStack* stack;
	createStack(&stack);
	push(stack, createNode(10));
	push(stack, createNode(20));
	Node* node2 = createNode(30);
	push(stack, node2);
	pop(stack);
	push(stack, node2);
	destroyStack(stack);
	printf("!!");

}