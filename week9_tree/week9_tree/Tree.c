/*
	��¥: 13�� 5�� 2�� ���� 5�� 31�� ~ 4�� ���� 4�� 42��
	�̸�: ������
	����: �ڱ��� �ǽ�, tree ���� �� ����
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


/* dstTree �� 6��° Node ���� ������ �����ϱ� ����
   �ش� �ּҰ��� �ӽ� �����ϱ� ���� ���� */
static node_t *dstSixthNode = (node_t*) NULL;

// �Լ� �����	
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

	
	/* SampleTree ����Լ� */
	printf ("Sample Tree \n");
	printSampleTree (tree);
	printf ("\n");

	/* Inorder ������� ��� */
	printf ("  Inorder : ");
	printTreeWithInorder (tree->root);

	/* Preorder ������� ��� */
	printf (" Preorder : ");
	printTreeWithPreorder (tree->root);

	/* Postorder ������� ��� */
	printf ("Postorder : ");
	printTreeWithPostorder (tree->root);

	/* newTree�� Tree�� ���� */
	newTree = (tree_t*) malloc (sizeof(tree_t));
	newTree->root = copyTree (tree->root);

	/* newTree�� Inorder ������� ��� */
	printf ("\n");
	printf ("newTree With Inorder : ");
	printTreeWithInorder (newTree->root);

	/* �� Tree�� �������� ����, ������ ���1, �ٸ���� 0 */
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
	dstSixthNode->data = '+';                                // dstTree�� 6��° Node�� data ���� ��ȯ
	verifyTrees = equalTrees (tree->root, newTree->root);
	printf ("%s \n", (verifyTrees)?"Same":"Different");


	/* �޸� ���� */
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
			printf ("%p - ����   ", (curNode+i)->parent);
		

		if ((curNode+i)->leftChild) 
			printf ("%p - %4c   ", (curNode+i)->leftChild, (curNode+i)->leftChild->data);
		else
			printf ("%p - ����   ", (curNode+i)->leftChild);
		

		if ((curNode+i)->rightChild)
			printf ("%p - %4c\n", (curNode+i)->rightChild, (curNode+i)->rightChild->data);
		else
			printf ("%p - ����\n", (curNode+i)->rightChild);

	}

	return;
}


void printTreeWithInorder (node_t *node) {

	// recursion ���� ����
	if (!node) return;

	printTreeWithInorder (node->leftChild);
	printf ("%c ", node->data);
	printTreeWithInorder (node->rightChild);

	// ù ȣ���Լ������� ����
	if (node->data == '+') printf("\n");

	return;
}

void printTreeWithPreorder (node_t *node) {

	// recursion ���� ����
	if (!node) return;

	printf ("%c ", node->data);
	printTreeWithPreorder (node->leftChild);
	printTreeWithPreorder (node->rightChild);

	// ù ȣ���Լ������� ����
	if (node->data == '+') printf ("\n");

	return;
}

void printTreeWithPostorder (node_t *node) {

	// recursion ���� ����
	if (!node) return;

	printTreeWithPostorder (node->leftChild);
	printTreeWithPostorder (node->rightChild);
	printf ("%c ", node->data);

	// ù ȣ���Լ������� ����
	if (node->data == '+') printf ("\n");

	return;
}


node_t * copyTree (node_t *rootOfSrcTree) {

	node_t *tempNode = (node_t*) NULL;

	if (!rootOfSrcTree) return (node_t*) NULL;

	// tempNode�� �޸� �Ҵ� �� ���� ����
	tempNode = (node_t*) malloc (sizeof(node_t));
	tempNode->data = rootOfSrcTree->data;

	// 6��° Node ���� ���� ��ȯ�ϱ� ���� �ּ��ӽ� ����
	if (tempNode->data == '/') dstSixthNode = tempNode;

	// tempNode�� Child�� ����� �޸𸮸� ����
	tempNode->leftChild = copyTree (rootOfSrcTree->leftChild);
	tempNode->rightChild = copyTree (rootOfSrcTree->rightChild);

	return tempNode;
}

int equalTrees (node_t * first, node_t * second) {
	
	int resultLeft, resultRight;

	// �� Node�� ��� NULL�� ���� ����
	if (!first && !second) return 1;

	// �� Node �� �� Node�� NULL�� ���� �ٸ�
	if (!first ^ !second) return 0;

	// �� Node�� ��� ����� ������ �Ǵ�.
	// �� Node�� ���� �ٸ� ��� �ٸ�.
	if (first->data != second->data) return 0;

	// �� Node�� ���� ���� ���, ���� Node �˻�
	// �� Node�� ���� �ٸ� ��� �ٸ�.
	resultLeft = equalTrees (first->leftChild, second->leftChild);
	if (!resultLeft) return 0;

	resultRight = equalTrees (first->rightChild, second->rightChild);
	if (!resultRight) return 0;

}