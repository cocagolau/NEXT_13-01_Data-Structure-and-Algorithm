/*
	날짜: 13년 5월 2일 오후 5시 31분 ~ 4일 오후 4시 42분
	이름: 서동규
	내용: 자구알 실습, tree 연습 및 구현
*/

#include <stdio.h>
#include< stdlib.h>


typedef struct node {
	char data;
	struct node *parent;
	struct node *rightChild;
	struct node *leftChild;
}node_t;

typedef struct tree {
	node_t *root;
}tree_t;


/* dstTree 중 6번째 Node 값을 강제로 변경하기 위해
   해당 주소값을 임시 저장하기 위한 변수 */
static node_t *dstSixthNode = (node_t*) NULL;

// 함수 선언부	
tree_t *makeSampleTree (void);
void printSampleTree (tree_t *tree);
void printTreeWithInorder (node_t *node);
void printTreeWithPreorder (node_t *node);
void printTreeWithPostorder (node_t *node);
node_t * copyTree (node_t *rootOfSrcTree);
int equalTrees (node_t * first, node_t * second);


int main (void) {

	tree_t *tree = (tree_t*) NULL, *newTree = (tree_t*) NULL;
	int verifyTrees;

	tree = makeSampleTree ();

	
	/* SampleTree 출력함수 */
	printf ("Sample Tree \n");
	printSampleTree (tree);
	printf ("\n");

	/* Inorder 방식으로 출력 */
	printf ("  Inorder : ");
	printTreeWithInorder (tree->root);

	/* Preorder 방식으로 출력 */
	printf (" Preorder : ");
	printTreeWithPreorder (tree->root);

	/* Postorder 방식으로 출력 */
	printf ("Postorder : ");
	printTreeWithPostorder (tree->root);

	/* newTree에 Tree를 복사 */
	newTree = (tree_t*) malloc (sizeof(tree_t));
	newTree->root = copyTree (tree->root);

	/* newTree를 Inorder 방식으로 출력 */
	printf ("\n");
	printf ("newTree With Inorder : ");
	printTreeWithInorder (newTree->root);

	/* 두 Tree가 동일한지 검증, 동일할 경우1, 다를경우 0 */
	printf ("----------------------------------- \n");
	printf ("Equal Trees \n");

	printf ("%7s, %7s : ", "tree", "newTree");
	verifyTrees = equalTrees (tree->root, newTree->root);
	printf ("%s \n", (verifyTrees)?"Same":"Different");
	
	printf ("%7s, %7s : ", "NULL", "newTree");
	verifyTrees = equalTrees ((node_t*) NULL, newTree->root);
	printf ("%s \n", (verifyTrees)?"Same":"Different");

	printf ("%7s, %7s : ", "tree", "NULL");
	verifyTrees = equalTrees (tree->root, (node_t*) NULL);
	printf ("%s \n", (verifyTrees)?"Same":"Different");

	printf ("   After Change the Data of dstSixthNode : ");
	dstSixthNode->data = '+';                                // dstTree의 6번째 Node의 data 강제 변환
	verifyTrees = equalTrees (tree->root, newTree->root);
	printf ("%s \n", (verifyTrees)?"Same":"Different");


	/* 메모리 해제 */
	free (newTree->root);
	free (newTree);
	newTree = (tree_t*) NULL;

	free (tree->root);
	free (tree);
	tree = (tree_t*) NULL;

	return 0;
}


tree_t *makeSampleTree (void) {
	
	tree_t *tree = (tree_t*) NULL;
	node_t *tempNode, *curNode;

	tree = (tree_t*) malloc (sizeof(tree_t));
	tempNode = (node_t*) malloc (sizeof(node_t) * 9);
	tree->root = tempNode;

	tempNode->data = '+';
	tempNode->parent = (node_t*) NULL;
	tempNode->leftChild = (tempNode+1);
	tempNode->rightChild = (tempNode+2);

	(tempNode+1)->data = '*';
	(tempNode+1)->parent = tempNode;
	(tempNode+1)->leftChild = (tempNode+3);
	(tempNode+1)->rightChild = (tempNode+4);

	(tempNode+2)->data = 'E';
	(tempNode+2)->parent = tempNode;
	(tempNode+2)->leftChild = (node_t*) NULL;
	(tempNode+2)->rightChild = (node_t*) NULL;

	(tempNode+3)->data = '*';
	(tempNode+3)->parent = (tempNode+1);
	(tempNode+3)->leftChild = (tempNode+5);
	(tempNode+3)->rightChild = (tempNode+6);

	(tempNode+4)->data = 'D';
	(tempNode+4)->parent = (tempNode+1);
	(tempNode+4)->leftChild = (node_t*) NULL;
	(tempNode+4)->rightChild = (node_t*) NULL;

	(tempNode+5)->data = '/';
	(tempNode+5)->parent = (tempNode+3);
	(tempNode+5)->leftChild = (tempNode+7);
	(tempNode+5)->rightChild = (tempNode+8);

	(tempNode+6)->data = 'C';
	(tempNode+6)->parent = (tempNode+3);
	(tempNode+6)->leftChild = (node_t*) NULL;
	(tempNode+6)->rightChild = (node_t*) NULL;

	(tempNode+7)->data = 'A';
	(tempNode+7)->parent = (tempNode+5);
	(tempNode+7)->leftChild = (node_t*) NULL;
	(tempNode+7)->rightChild = (node_t*) NULL;

	(tempNode+8)->data = 'B';
	(tempNode+8)->parent = (tempNode+5);
	(tempNode+8)->leftChild = (node_t*) NULL;
	(tempNode+8)->rightChild = (node_t*) NULL;


	return tree;
}

void printSampleTree (tree_t* tree) {
	node_t *curNode = (node_t*) NULL;
	int i;

	curNode = tree->root;
	for (i=0; i<9; i++) {
		printf ("%p - %4c   ", (curNode+i), (curNode+i)->data);
	
		if ((curNode+i)->parent)
			printf ("%p - %4c   ", (curNode+i)->parent, (curNode+i)->parent->data);
		else
			printf ("%p - 없음   ", (curNode+i)->parent);
		

		if ((curNode+i)->leftChild) 
			printf ("%p - %4c   ", (curNode+i)->leftChild, (curNode+i)->leftChild->data);
		else
			printf ("%p - 없음   ", (curNode+i)->leftChild);
		

		if ((curNode+i)->rightChild)
			printf ("%p - %4c\n", (curNode+i)->rightChild, (curNode+i)->rightChild->data);
		else
			printf ("%p - 없음\n", (curNode+i)->rightChild);

	}

	return;
}


void printTreeWithInorder (node_t *node) {

	// recursion 종료 조건
	if (!node) return;

	printTreeWithInorder (node->leftChild);
	printf ("%c ", node->data);
	printTreeWithInorder (node->rightChild);

	// 첫 호출함수에서만 개행
	if (node->data == '+') printf("\n");

	return;
}

void printTreeWithPreorder (node_t *node) {

	// recursion 종료 조건
	if (!node) return;

	printf ("%c ", node->data);
	printTreeWithPreorder (node->leftChild);
	printTreeWithPreorder (node->rightChild);

	// 첫 호출함수에서만 개행
	if (node->data == '+') printf ("\n");

	return;
}

void printTreeWithPostorder (node_t *node) {

	// recursion 종료 조건
	if (!node) return;

	printTreeWithPostorder (node->leftChild);
	printTreeWithPostorder (node->rightChild);
	printf ("%c ", node->data);

	// 첫 호출함수에서만 개행
	if (node->data == '+') printf ("\n");

	return;
}


node_t * copyTree (node_t *rootOfSrcTree) {

	node_t *tempNode = (node_t*) NULL;

	if (!rootOfSrcTree) return (node_t*) NULL;

	// tempNode에 메모리 할당 후 내용 복사
	tempNode = (node_t*) malloc (sizeof(node_t));
	tempNode->data = rootOfSrcTree->data;

	// 6번째 Node 값을 강제 변환하기 위해 주소임시 저장
	if (tempNode->data == '/') dstSixthNode = tempNode;

	// tempNode의 Child에 복사된 메모리를 연결
	tempNode->leftChild = copyTree (rootOfSrcTree->leftChild);
	tempNode->rightChild = copyTree (rootOfSrcTree->rightChild);

	return tempNode;
}

int equalTrees (node_t * first, node_t * second) {
	
	int resultLeft, resultRight;

	// 두 Node가 모두 NULL일 경우는 같음
	if (!first && !second) return 1;

	// 두 Node 중 한 Node만 NULL일 경우는 다름
	if (!first ^ !second) return 0;

	// 두 Node가 모두 존재시 값으로 판단.
	// 두 Node의 값이 다른 경우 다름.
	if (first->data != second->data) return 0;

	// 두 Node의 값이 같은 경우, 하위 Node 검사
	// 두 Node의 값이 다른 경우 다름.
	resultLeft = equalTrees (first->leftChild, second->leftChild);
	if (!resultLeft) return 0;

	resultRight = equalTrees (first->rightChild, second->rightChild);
	if (!resultRight) return 0;

}