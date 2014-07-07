#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
typedef struct node {
	int data;
	int color;
	struct node *parent;
	struct node *leftChild;
	struct node *rightChild;
} node_t;

typedef struct tree {
	node_t *root;
	node_t *NIL;
} tree_t;

// 함수 선언
tree_t *createRBT (void);

void freeRBT (tree_t *RBT);

void rightRotate (tree_t *RBT, node_t *Node);
void leftRotate (tree_t *RBT, node_t *Node);

void insert (tree_t *RBT, node_t *Node);
void insertFixUP (tree_t *RBT, node_t *Node);

void printRBT (tree_t *RBT);


// 함수 정의
tree_t *createRBT (void) {
	tree_t *newRBT;
	node_t *newNIL;

	newRBT = (tree_t*) malloc (sizeof(tree_t));
	newNIL = (node_t*) malloc (sizeof(node_t));

	newNIL->color = 'NIL';
	newRBT->NIL = newNIL;
	newRBT->root = newRBT->NIL;

	return newRBT;
}
void freeRBT (tree_t *RBT) {
	
	if (!RBT) return;

	if (RBT->NIL) {
		free (RBT->NIL);
		RBT->NIL = (node_t*) NULL;
	}

	free (RBT);
	RBT = (tree_t*) NULL;

	return;
}
void leftRotate (tree_t *RBT, node_t *Node) {

	node_t *tempNode;

	if (!RBT || !Node) return;
	if (Node->rightChild == RBT->NIL) return;

	// 임시 지정
	tempNode = Node->rightChild;

	// 베타노드 변경
	Node->rightChild = tempNode->leftChild;
	if (tempNode->leftChild != RBT->NIL)
		tempNode->leftChild->parent = Node;
	
	// parent 변경
	if (Node->parent == RBT->NIL)
		RBT->root = tempNode;
	else if (Node == Node->parent->leftChild)
		Node->parent->leftChild = tempNode;
	else
		Node->parent->rightChild = tempNode;
	tempNode->parent = Node->parent;

	// x, y 관계 변경
	tempNode->leftChild = Node;
	Node->parent = tempNode;

	return;
}
void rightRotate (tree_t *RBT, node_t *Node) {

	node_t *tempNode;

	if (!RBT || !Node) return;
	if (Node->leftChild == RBT->NIL) return;

	// 임시 지정
	tempNode = Node->leftChild;

	// 베타노드 변경
	Node->leftChild = tempNode->rightChild;
	if (tempNode->rightChild != RBT->NIL)
		tempNode->rightChild->parent = Node;
	
	// parent 변경
	if (Node->parent == RBT->NIL)
		RBT->root = tempNode;
	else if (Node == Node->parent->leftChild)
		Node->parent->leftChild = tempNode;
	else
		Node->parent->rightChild = tempNode;
	tempNode->parent = Node->parent;

	// x, y 관계 변경
	tempNode->rightChild = Node;
	Node->parent = tempNode;

	return;
}

void insert (tree_t *RBT, node_t *Node) {

	node_t *curNode, *tempNode;

	if (!RBT || !Node) return;

	if (RBT->root == RBT->NIL) {
		RBT->root = Node;

		return;
	}

	curNode = RBT->root;
	while (curNode == RBT->NIL) {

		tempNode = curNode;
		if (curNode->data > Node->data)
			curNode = curNode->leftChild;
		else
			curNode = curNode->rightChild;
	}
	
	Node->parent = tempNode;
	if (tempNode->data > Node->data)
		tempNode->leftChild = Node;
	else
		tempNode->rightChild = Node;

	return;
}

void printRBT (tree_t *RBT, node_t *Node) {

	if (!Node || Node == RBT->NIL) return;

	printRBT (RBT, Node->leftChild);
	printf ("%d ", Node->data);
	printRBT (RBT, Node->rightChild);

	return;
}


int main (void) {

	tree_t *RBT = (tree_t*) NULL;
	node_t *temp = (node_t*) NULL;
	node_t *node;
	int i, list[5] = {1,2,3,4,5};


	RBT = createRBT();
	for (i=0; i<2; i++) {
		temp = createNode (RBT, i, 'RED');
		insert (RBT, temp);
	}

	printRBT (RBT, RBT->root);

	freeNode (RBT, RBT->root);
	freeRBT (RBT);


	return 0;
}
