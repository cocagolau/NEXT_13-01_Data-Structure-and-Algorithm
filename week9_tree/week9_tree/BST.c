/*
	날짜: 13년 5월 4일 오후 4시 50분 ~ 
	이름: 서동규
	내용: 자구알 실습, BST 연습 및 구현
*/

#include <stdio.h>
#include< stdlib.h>

typedef struct node {
	int data;
	struct node *parent;
	struct node *rightChild;
	struct node *leftChild;
}node_t;

typedef struct tree {
	node_t *root;
}tree_t;


// 함수 선언부	
tree_t *makeSampleBST (void);
tree_t *createBST (void);
node_t *createBstNode (int list[], int listSize);
void bstInsertNode (tree_t *tree, node_t *givenNode);
void bstTransplant (tree_t *tree, node_t *rmNode, node_t *mvNode);
void bstDeleteNode (tree_t *tree, node_t *node);
void bstDeleteNode (tree_t *tree, node_t *node);

void printBSTWithInorder (node_t *node);

node_t *bstSearch (node_t *node, int key);
void printSearchResult (node_t *node);
node_t *bstMinimumBelow (node_t *node);
node_t *bstMaximumBelow (node_t *node);
node_t *bstSuccessorOf (node_t *node);

//HW# c2
int bstNodeNum (node_t *node);
//HW# 12장 3-1
void *recursiveInsertion (tree_t *tree, int list[], int listSize, int num);

//HW# c4
void *swapTree (node_t *node);
//HW# c7
//HW# c8



int main (void) { 

	tree_t *BST;
	tree_t *Bst1, *Bst2, *Bst3;
	node_t *searchResult, *tempNode, *tempNode1;
	node_t *rootNode1, *rootNode2, *rootNode3;
	int list1[6] = {1,2,3,4,5,6};
	int list2[6] = {6,5,4,3,2,1};
	int list3[15] = {8, 4, 2, 1, 3, 6, 5, 7, 12, 10, 9, 11, 13, 14, 15};
	int list3_delete[10] =  {7,6,5,9,12,8,4,15,13,9};
	int i, listSize1 = sizeof(list1)/sizeof(int), listSize2 = sizeof(list2)/sizeof(int), listSize3 = sizeof(list3)/sizeof(int);
	int nodeNum;
	int inputList[9] = {6,4,2,3,8,5,1,9,7};
	int inputListSize = sizeof(inputList)/sizeof(int);

	BST = makeSampleBST ();

	/* Inorder 방식으로 출력 */
	printf ("<Inorder> : ");
	printBSTWithInorder (BST->root);
	printf ("\n");

	/* BST에서 Key값 검색 */
	printf ("<Key Value Search Result> \n");

	printf ("key:%3d > ", 12);
	searchResult = bstSearch (BST->root, 12);
	printSearchResult (searchResult);

	printf ("key:%3d > ", 2);
	searchResult = bstSearch (BST->root, 2);
	printSearchResult (searchResult);

	printf ("key:%3d > ", 7);
	searchResult = bstSearch (BST->root, 7);
	printSearchResult (searchResult);
	printf ("\n");

	/* Tree의 Node 중에서 가장 작은 data를 가진 Node 주소 검색 */
	printf ("<Minimum Node Search Result> \n");
	searchResult = bstMinimumBelow (BST->root);
	printSearchResult (searchResult);
	printf ("\n");

	/* Tree의 Node 중에서 가장 큰 data를 가진 Node 주소 검색 */
	printf ("<Maximum Node Search Result> \n");
	searchResult = bstMaximumBelow (BST->root);
	printSearchResult (searchResult);
	printf ("\n");

	/*  요청된 Node의 Successor 출력 */
	printf ("<BST Successor Of> \n");
	printf ("%2d : ", 2);
	searchResult = bstSearch (BST->root, 2);
	searchResult = bstSuccessorOf (searchResult);
	printSearchResult (searchResult);

	printf ("%2d : ", 9);
	searchResult = bstSearch (BST->root, 9);
	searchResult = bstSuccessorOf (searchResult);
	printSearchResult (searchResult);

	printf ("%2d : ", 12);
	searchResult = bstSearch (BST->root, 12);
	searchResult = bstSuccessorOf (searchResult);
	printSearchResult (searchResult);

	printf ("%2d : ", 15);
	searchResult = bstSearch (BST->root, 15);
	searchResult = bstSuccessorOf (searchResult);
	printSearchResult (searchResult);

	printf ("%2d : ", 19);
	searchResult = bstSearch (BST->root, 19);
	searchResult = bstSuccessorOf (searchResult);
	printSearchResult (searchResult);
	printf ("\n");


	
	// Bst 1 생성 후 출력, 삭제
	/* tree 생성 */
	Bst1 = createBST ();

	/* tree Node생성 */
	tempNode = createBstNode (list1, listSize1);
	rootNode1 = tempNode; // 메모리 해제를 위한 임시 포인터

	/* Tree에 Node 연결 */
	for (i=0; i<listSize1; i++)
		bstInsertNode (Bst1, tempNode+i);

	/* newTree Inorder방식으로 출력 */
	printf ("<BST 1> \n");
	printBSTWithInorder (Bst1->root);
	printf ("\n");

	/* input순서로 Deletion */
	printf ("<Bst1 Deletion> \n");
	for (i=0; i<listSize1; i++) {
		tempNode = bstSearch (Bst1->root, i+1);
		bstDeleteNode (Bst1, tempNode);
		printBSTWithInorder (Bst1->root);
		printf ("\n");
	}
	


	// Bst 2 생성 후 출력, 삭제
	/* tree 생성 */
	Bst2 = createBST ();

	/* tree Node생성 */
	tempNode = createBstNode (list2, listSize2);
	rootNode2 = tempNode; // 메모리 해제를 위한 임시 포인터

	/* Tree에 Node 연결 */
	for (i=0; i<listSize2; i++)
		bstInsertNode (Bst2, tempNode+i);

	/* newTree Inorder방식으로 출력 */
	printf ("<BST 2> \n");
	printBSTWithInorder (Bst2->root);
	printf ("\n");

	/* input순서로 Deletion */
	printf ("<Bst2 Deletion> \n");
	for (i=listSize2; i>0; i--) {
		tempNode = bstSearch (Bst2->root, i);
		bstDeleteNode (Bst2, tempNode);
		printBSTWithInorder (Bst2->root);
		printf ("\n");
	}



	// Bst 3 생성 후 출력, 삭제
	/* tree 생성 */
	Bst3 = createBST ();

	/* tree Node생성 */
	tempNode = createBstNode (list3, listSize3);
	rootNode3 = tempNode;

	/* Tree에 Node 연결 */
	for (i=0; i<listSize3; i++)
		bstInsertNode (Bst3, tempNode+i);

	/* newTree Inorder방식으로 출력 */
	printf ("<BST 3> \n");
	printBSTWithInorder (Bst3->root);
	printf ("\n");

	/* HW# c4, swapTree */
	swapTree (Bst3->root);
	printBSTWithInorder (Bst3->root);
	printf ("\n");



	/* input순서로 Deletion */
	printf ("<Bst3 Deletion> \n");
	for (i=0; i<10; i++) {
		tempNode = bstSearch (Bst3->root, list3_delete[i]);
		bstDeleteNode (Bst3, tempNode);
		printBSTWithInorder (Bst3->root);
		printf ("\n");
	}
	printf ("\n");


	// BST 출력 및 삭제
	/* original BST */
	printf ("<Original BST> \n");
	printBSTWithInorder (BST->root);
	printf ("\n");
	
	/* BST nodeNum */
	printf ("<BST Node Num> : ");
	tempNode = bstMinimumBelow (BST->root);
	nodeNum = bstNodeNum (tempNode);
	printf ("%d \n", nodeNum);
	printf ("\n");


	/* bst Transplant */
	printf ("<bst Transplant> : 15->17 \n");
	tempNode = bstSearch (BST->root, 15);
	tempNode1 = bstSearch (BST->root, 17);
	bstTransplant (BST, tempNode, tempNode1);
	printBSTWithInorder (BST->root);

	printf ("<bst Transplant> : 5->2 \n");
	tempNode = bstSearch (BST->root, 5);
	tempNode1 = bstSearch (BST->root, 2);
	bstTransplant (BST, tempNode, tempNode1);
	printBSTWithInorder (BST->root);
	printf ("\n");

	/* BST3의 key값 17 node 삭제 */
	printf ("<Bst Deletion> : 17 \n");
	tempNode = bstSearch (BST->root, 17);
	bstDeleteNode (BST, tempNode);
	printBSTWithInorder (BST->root);
	
	/* BST3의 key값 12 node 삭제  */
	printf ("<Bst Deletion> : 12 \n");
	tempNode = bstSearch (BST->root, 12);
	tempNode1 = tempNode;  // 이후 메모리 해제를 위해 임시 변수 할당
	bstDeleteNode (BST, tempNode);
	printBSTWithInorder (BST->root);
	printf ("\n"); 

	/* BST3의 key값 18 node 삭제  */
	printf ("<Bst Deletion> : 18 \n");
	tempNode = bstSearch (BST->root, 18);
	bstDeleteNode (BST, tempNode);
	printBSTWithInorder (BST->root);
	printf ("\n"); 
	
	/* BST3의 key값 19 node 삭제  */
	printf ("<Bst Deletion> : 19 \n");
	tempNode = bstSearch (BST->root, 19);
	bstDeleteNode (BST, tempNode);
	printBSTWithInorder (BST->root);
	printf ("\n"); 

	/* BST3의 key값 2 node 삭제  */
	printf ("<Bst Deletion> : 2 \n");
	tempNode = bstSearch (BST->root, 2);
	bstDeleteNode (BST, tempNode);
	printBSTWithInorder (BST->root);
	printf ("\n"); 


	/* 메모리 해제 */
	free (rootNode1);
	free (Bst1);
	Bst1 = (tree_t*) NULL;

	free (rootNode2);
	free (Bst2);
	Bst2 = (tree_t*) NULL;

	free (rootNode3);
	free (Bst3);
	Bst3 = (tree_t*) NULL;
	
	/* tempNode1로 메모리 해제 */
	free (tempNode1);
	free (BST);
	BST = (tree_t*) NULL;
	

	return 0;
}


tree_t *createBST (void) {

	tree_t *newBST;
	newBST = (tree_t*) malloc (sizeof(tree_t));
	newBST->root = (node_t*) NULL;

	return newBST;
}

node_t *createBstNode (int list[], int listSize) {

	int i;
	node_t *tempNode;

	if (!list) return (node_t*) NULL;

	tempNode = (node_t*) malloc (sizeof(node_t)*listSize);
	if (!tempNode) return (node_t*) NULL;

	for (i=0; i<listSize; i++) {
		(tempNode+i)->data = list[i];
		(tempNode+i)->parent = (node_t*) NULL;
		(tempNode+i)->leftChild = (node_t*) NULL;
		(tempNode+i)->rightChild = (node_t*) NULL;
	}

	return tempNode;
}

void bstInsertNode (tree_t *tree, node_t *givenNode) {

	node_t *tempNode, *curNode;

	if (!tree || !givenNode) return;

	if (!(tree->root)) {
		tree->root = givenNode;
	}
	else {
		tempNode = bstSearch (tree->root, givenNode->data);
		
		// 동일 값이 존재하지 않을 경우 <동일값이 들어온 경우는 무시>
		if (!tempNode) {
			curNode = tree->root;

			while (curNode) {
				tempNode = curNode;
				if (curNode->data > givenNode->data)
					curNode = curNode->leftChild;
				else
					curNode = curNode->rightChild;
			}
			
			givenNode->parent = tempNode;
			if (tempNode->data > givenNode->data)
				tempNode->leftChild = givenNode;
			else
				tempNode->rightChild = givenNode;
		}	
	}
	return;
}

void bstTransplant (tree_t *tree, node_t *rmNode, node_t *mvNode) {

	if (mvNode != NULL) mvNode->parent = rmNode->parent;
	
	if (tree->root == rmNode) {
		tree->root = mvNode;
		return;
	}

	if (rmNode->parent->leftChild == rmNode) {
		rmNode->parent->leftChild = mvNode;
	}
	else
		rmNode->parent->rightChild = mvNode;

}

void bstDeleteNode (tree_t *tree, node_t *node) {

	node_t *successor;

	if (!node) return;

	if (!node->leftChild)
		bstTransplant (tree, node, node->rightChild);

	else if (!node->rightChild)
		bstTransplant (tree, node, node->leftChild);

	else {
		successor = bstSuccessorOf (node);

		if (successor == node->rightChild) {
			successor->leftChild = node->leftChild;
			node->leftChild->parent = successor;
			bstTransplant (tree, node, successor);
		}

		else {
			bstTransplant (tree, successor, successor->rightChild);

			successor->leftChild = node->leftChild;
			node->leftChild->parent = successor;
			successor->rightChild = node->rightChild;
			node->rightChild->parent = successor;

			bstTransplant (tree, node, successor);
		}
	}
}


tree_t *makeSampleBST (void) {
	
	tree_t *BST = (tree_t*) NULL;
	node_t *tempNode, *curNode;

	BST = (tree_t*) malloc (sizeof(tree_t));
	tempNode = (node_t*) malloc (sizeof(node_t) * 9);
	BST->root = tempNode;
	
	// level 0
	tempNode->data = 12;
	tempNode->parent = (node_t*) NULL;
	tempNode->leftChild = (tempNode+1);
	tempNode->rightChild = (tempNode+2);

	// level 1
	(tempNode+1)->data = 5;
	(tempNode+1)->parent = tempNode;
	(tempNode+1)->leftChild = (tempNode+3);
	(tempNode+1)->rightChild = (tempNode+4);

	(tempNode+2)->data = 18;
	(tempNode+2)->parent = tempNode;
	(tempNode+2)->leftChild = (tempNode+5);
	(tempNode+2)->rightChild = (tempNode+6);

	// level 2
	(tempNode+3)->data = 2;
	(tempNode+3)->parent = (tempNode+1);
	(tempNode+3)->leftChild = (node_t*) NULL;
	(tempNode+3)->rightChild = (node_t*) NULL;

	(tempNode+4)->data = 9;
	(tempNode+4)->parent = (tempNode+1);
	(tempNode+4)->leftChild = (node_t*) NULL;
	(tempNode+4)->rightChild = (node_t*) NULL;


	(tempNode+5)->data = 15;
	(tempNode+5)->parent = (tempNode+2);
	(tempNode+5)->leftChild = (tempNode+7);
	(tempNode+5)->rightChild = (tempNode+8);

	(tempNode+6)->data = 19;
	(tempNode+6)->parent = (tempNode+2);
	(tempNode+6)->leftChild = (node_t*) NULL;
	(tempNode+6)->rightChild = (node_t*) NULL;

	// level 3
	(tempNode+7)->data = 13;
	(tempNode+7)->parent = (tempNode+5);
	(tempNode+7)->leftChild = (node_t*) NULL;
	(tempNode+7)->rightChild = (node_t*) NULL;

	(tempNode+8)->data = 17;
	(tempNode+8)->parent = (tempNode+5);
	(tempNode+8)->leftChild = (node_t*) NULL;
	(tempNode+8)->rightChild = (node_t*) NULL;


	return BST;
}


void printBSTWithInorder (node_t *node) {

	// recursion 종료 조건
	if (!node) return;

	printBSTWithInorder (node->leftChild);
	printf ("%d ", node->data);
	printBSTWithInorder (node->rightChild);

	return;
}


/* Key값이 있는 Node가 있을 경우 해당 Node주소 반환
                      없는 경우 NULL 값 반환   */
node_t * bstSearch (node_t *node, int key) {

	node_t *tempNodeLeft,  *tempNodeRight, *tempNode;

	if (!node) return (node_t*) NULL;
	if (node->data == key) return node;

	tempNode = bstSearch (node->leftChild, key);
	if (tempNode) return tempNode;

	tempNode = bstSearch (node->rightChild, key);
	if (tempNode) return tempNode;

	return (node_t*) NULL;
}


void printSearchResult (node_t *searchResult) {

	if (searchResult) {
		printf ("%p - %4d   ", searchResult, searchResult->data);
	
		if (searchResult->parent)
			printf ("%p - %4d   ", searchResult->parent, searchResult->parent->data);
		else
			printf ("%p - 없음   ", searchResult->parent);

		if (searchResult->leftChild) 
			printf ("%p - %4d   ", searchResult->leftChild, searchResult->leftChild->data);
		else
			printf ("%p - 없음   ", searchResult->leftChild);

		if (searchResult->rightChild)
			printf ("%p - %4d\n", searchResult->rightChild, searchResult->rightChild->data);
		else
			printf ("%p - 없음\n", searchResult->rightChild);
	}
	else printf ("None \n");

	return;
}


node_t *bstMinimumBelow (node_t *node) {

	if (!(node->leftChild)) return node;

	bstMinimumBelow (node->leftChild);
}


node_t *bstMaximumBelow (node_t *node) {

	if (!(node->rightChild)) return node;

	bstMaximumBelow (node->rightChild);
}


node_t *bstSuccessorOf (node_t *node) {
	
	node_t *tempNode, *curNode;
	
	if (node->rightChild) {
		tempNode = bstMinimumBelow (node->rightChild);
		return tempNode;
	}

	curNode = node;
	while (curNode->parent) {
		if (curNode->parent->leftChild == curNode)
			return curNode->parent;
		curNode = curNode->parent;
	}
	return (node_t*) NULL;
	
}

int  bstNodeNum (node_t *node) {

	int sum = 0;
	node_t *curNode;

	if (!node) return sum;

	curNode = node;
	while (curNode) {
		sum++;
		curNode = bstSuccessorOf (curNode);
	}

	return sum;
}

void *swapTree (node_t *node) {

	node_t *tempNode;

	if (!node) return;
	if (!node->leftChild && !node->rightChild) return;

	tempNode = node->leftChild;
	node->leftChild = node->rightChild;
	node->rightChild = tempNode;
	tempNode = (node_t*) NULL;

	swapTree (node->leftChild);
	swapTree (node->rightChild);
}

void *recursiveInsertion (tree_t *tree, int list[], int listSize, int num) {

	node_t *newNode;


	if (!tree || !list) return (node_t*) NULL;

	if (num == 0) {
		newNode = (node_t*) malloc (sizeof(node_t));
		newNode->parent = (node_t*) NULL;
		newNode->data = list[num];







}