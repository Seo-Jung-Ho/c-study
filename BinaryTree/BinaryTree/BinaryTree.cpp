#include "BinaryTree.h"

void main() {

	Node* a = createNode('A');
	Node* b = createNode('B');
	Node* c = createNode('C');
	Node* d = createNode('D');
	Node* e = createNode('E');
	Node* f = createNode('F');

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	preorderPrintTree(a);
	printf("\n");
	inorderPrintTree(a);
	printf("\n");
	postorderPrintTree(a);
	printf("\n");
	destroyTree(a);
}