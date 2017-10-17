#include "Stack.h"

Node* createNode(char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(data)+1);
	strcpy(newNode->data, data);
	newNode->nextNode = NULL;
	return newNode;
}

void destroyNode(Node* node) {
	free(node->data);
	free(node);
}

void createStack(LinkedListStack** stack) { //왜 포인터의 포인터지?
	//printf("%p",stack);
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->head = NULL;
	(*stack)->top = NULL;
}

void destroyStack(LinkedListStack* stack) {
	while (stack -> head != NULL) {//stack의 해드가 널일떄까지
		Node* poped = pop(stack);
		destroyNode(poped);
	}
	free(stack);
}

void push(LinkedListStack* stack, Node* node) {
	if (stack->head == NULL) {
		stack->head = node;
	}
	else {
		/*Node* current = stack->head;
		while (current->nextNode != NULL) {
			current = current->nextNode;
		}
		current->nextNode = node;*/
		stack->top->nextNode = node;
	}

	stack->top = node;
}

Node* pop(LinkedListStack* stack) {
	Node* oldTop = stack->top;
	if (stack->head == stack->top) {
		stack->head = NULL;
		stack->top = NULL;
	}
	else {
		Node* current = stack->head;
		while (current->nextNode != stack->top) {//스택의 탑과 같으면 중지
			current = current->nextNode;
		}
		stack->top = current;
		current->nextNode = NULL;
	}
	return oldTop;
}

int getCount(LinkedListStack* stack) {
	if (stack->head == NULL) {
		return 0;
	}else{
		int count = 1;
		Node* current = stack->head;
		while (current->nextNode != NULL) {
			current = current->nextNode;
			count++;
		}
		return count;
	}
}

void showAll(LinkedListStack* stack) {
	if (stack->head != NULL) {
		Node* current = stack->head;
		while (current != NULL) {
			printf("값은 : %s\n", current->data);
			current = current->nextNode;
		}
	}
}

void main() {

	Node* test;
	LinkedListStack* stack;
	createStack(&stack);

	test = createNode("1층");
	push(stack,test);
	test = createNode("2층");
	push(stack, test);
	test = createNode("3층");
	push(stack, test);
	test = createNode("4층");
	push(stack, test);
	test = createNode("5층");
	push(stack, test);
	test = createNode("6층");
	push(stack, test);
	showAll(stack);
	destroyStack(stack);
}