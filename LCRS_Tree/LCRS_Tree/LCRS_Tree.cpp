//#include "LCRS_Tree.h"
//
//Node* createNode(ElementType newData) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->leftChild = NULL;
//	newNode->rightSibling = NULL;
//	newNode->data = newData;
//	return newNode;
//};
//
//void destroyNode(Node* node) {
//	free(node);
//};
//
//void addChild(Node* parent, Node* child) {
//	if (parent->leftChild == NULL) {
//		parent->leftChild = child;
//	}
//	else {
//		Node* temp = parent->leftChild;
//		while (temp->rightSibling != NULL) {
//			temp = temp->rightSibling;
//		}
//		temp->rightSibling = child;
//	}
//};
//
//void printTree(Node* node, int depth) {
//	int i = 0;
//
//	for (int i = 0; i < depth; i++) {
//		printf("  ");
//	};
//
//	printf("%c\n",node->data);
//	if (node->leftChild != NULL)
//		printTree(node->leftChild, depth + 1);
//
//	if (node->rightSibling != NULL)
//		printTree(node->rightSibling, depth);
//}
//
//void main() {
//
//	Node* a = createNode('A');
//	Node* b1 = createNode('B');
//	Node* b2 = createNode('B');
//	Node* b3 = createNode('B');
//	Node* b4 = createNode('B');
//
//	Node* c = createNode('C');
//	Node* e1 = createNode('E');
//	Node* e2 = createNode('E');
//	Node* e3 = createNode('E');
//
//	addChild(a, b1);
//	addChild(b1, b2);
//	addChild(b1, b3);
//	addChild(b1, b4);
//	addChild(a, c);
//	addChild(c, e1);
//	addChild(c, e2);
//	addChild(c, e3);
//
//	printTree(a,0);
//
//}