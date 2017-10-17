#include "BinarySearchTree.h";

Node* createNode(ElementType newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
};

void destroyTree(Node* tree) {

	if (tree->left != NULL)
		destroyTree(tree->left);
	if (tree->right != NULL)
		destroyTree(tree->right);

	tree->left = NULL;
	tree->right = NULL;

	free(tree);
};
Node* searchNode(Node* root, ElementType target) {
	Node* result = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == target)
		return root;
	if (root->data > target)
		return result = searchNode(root->left, target);
	else
		return result = searchNode(root->right, target);
};

//최소값 찾기 ㅋㅋ
Node* searchMinNode(Node* tree) {
	if (tree->left == NULL)
		return tree;
	
	Node* sch = tree->left;
	while (sch->left != NULL){
		sch = sch->left;
	}
	return sch;
};
void insertNode(Node* root, Node* child) {
	Node* parent = root;
	Node* childPos = root->data < child->data ? root->right : root->left;
	while (childPos != NULL) {
		parent = childPos;
		childPos = parent->data < child->data ? parent->right : parent->left;
	}
	if (parent->data > child->data) {
		parent->left = child;
	}
	else {
		parent->right = child;
	}
};
Node* removeNode(Node* tree, Node* parent, ElementType target) {
	if (tree == NULL)
		return NULL;

	Node* removed = NULL;
	if (tree->data > target) {
		removeNode(tree->left, tree, target);
	}
	else if (tree->data < target) {
		removeNode(tree->right, tree, target);
	}
	else {//값을 찾은경우
		  // 삭제해야할 노드의 자식이 없는 경우 그냥 삭제
		removed = tree;
		if (tree->left == NULL && tree->right == NULL) {
			if (parent->left == tree)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		// 삭제해야할 노드의 자식이 두개인경우..
		// 삭제해야할 노드보단 크지만 가장작은 최소값의 노드를 찾음
		// 그 노드를 삭제해야되는 노드의 자리에 연결
		// 만약 그 노드의 자식이 있다면 ( 자식은 오로지 큰 자식 뿐)
		// 최소값노드의 원래 자식에게 연결
		else if(tree->left != NULL && tree->right != NULL) {
			Node* temp = searchMinNode(tree->right);
			removed = removeNode(tree, NULL, temp->data);
			tree->data = temp->data;
		}
		// 삭제해야할 노드의 자식이 하나인경우엔 그 자식과 삭제해야할 노드의 부모를 연결
		else {
			Node* temp = NULL;
			if (tree->left != NULL) {
				temp = tree->left;
			}
			else {
				temp = tree->right;
			}
			if (parent->left == tree)
				parent->left = temp;
			else
				parent->right = temp;
		}
	}
	return NULL;
};
void inorderPrintTree(Node* root,int depth) {

	for (int i = 0; i < depth; i++) {
		printf("   ");
	}

	printf("%d\n", root->data);
	if (root->right != NULL)
		inorderPrintTree(root->right, depth + 1);
	if (root->left != NULL)
		inorderPrintTree(root->left, depth + 1);
};

void main() {
	Node* root = createNode(500);
	Node* n1 = createNode(100);
	Node* n2 = createNode(700);
	Node* n3 = createNode(600);
	Node* n4 = createNode(200);
	Node* n5 = createNode(50);
	Node* n6 = createNode(210);
	Node* n7 = createNode(25);
	Node* n8 = createNode(75);
	Node* n9 = createNode(8);
	Node* n10 = createNode(180);
	insertNode(root, n1);
	insertNode(root, n2);
	insertNode(root, n3);
	insertNode(root, n4);
	insertNode(root, n5);
	insertNode(root, n6);
	insertNode(root, n7);
	insertNode(root, n8);
	insertNode(root, n9);
	insertNode(root, n10);
	inorderPrintTree(root, 0);
	//removeNode(root, NULL, 100);
	inorderPrintTree(root, 0);

	Node* sch = searchNode(root, 100);
	printf("최소값 노드 : %d\n", sch->data);

	/*Node* min = searchMinNode(n2);*/

	destroyTree(root);
	printf("");
}