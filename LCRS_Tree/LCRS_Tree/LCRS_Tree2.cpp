#include "LCRS_Tree.h";

Node* createNode(ElementType newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->leftChild = NULL;
	newNode->rightSibling = NULL;
	newNode->data = newData;
	return newNode;
};
void destroyNode(Node* node) {
	free(node);
};
void addChild(Node* parent, Node* child) {
	if (parent->leftChild == NULL) {
		parent->leftChild = child;
	}else{
		Node* temp = parent->leftChild;
		while (temp->rightSibling != NULL) {
			temp = temp->rightSibling;
		}
		temp->rightSibling = child;
	}
};
void printTree(Node* node, int depth) {
	int i = 0;
	for (int i = 0; i < depth; i++) {
		printf("   ");
	}
	
	printf("%c\n", node->data);

	if (node->leftChild != NULL) 
		printTree(node->leftChild,depth + 1);

	if(node->rightSibling != NULL)
		printTree(node->rightSibling, depth);
};

void printTreeAt(Node* node, int depth, int level) {

	if (depth == level) {
		printf("%c\n", node->data);
	}

	if (node->leftChild != NULL)
		printTreeAt(node->leftChild, depth + 1,level);

	if (node->rightSibling != NULL)
		printTreeAt(node->rightSibling, depth,level);
};

void destroyTree(Node* root) {

	if (root->rightSibling != NULL)
		destroyTree(root->rightSibling);
	
	if (root->leftChild != NULL)
		destroyTree(root->leftChild);
	
	root->leftChild = NULL;
	root->rightSibling = NULL;

	free(root);

};


void main() {
	Node* root = createNode('R');
	Node* d1 = createNode('D');
	Node* d2 = createNode('D');
	Node* c1 = createNode('C');
	Node* c2 = createNode('C');
	Node* c3 = createNode('C');

	addChild(root, d1);
	addChild(root, d2);
	addChild(d1, c1);
	addChild(d1, c2);
	addChild(d2, c3);

	printTreeAt(root, 0,0);
	destroyTree(root);
}