/*
	�ۼ��� : 13�� 6�� 14�� ���� 1��~ 15�� 17��
	�ۼ��� : ������
	���α׷� ���� : Red Black Tree �ǽ� �� ����

	������ : 13�� 6�� 27�� ���� 5�� 30�� ~ 6�� 28�� ���� 10�� 30��
	�������� : deletion debugging
	*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	RED = 0,
	BLACK
}RB_color;

// ����ü ����
typedef struct node {
	int data;
	RB_color color;
	struct node *parent;
	struct node *leftChild;
	struct node *rightChild;
} node_t;

typedef struct tree {
	node_t *root;
	node_t *NIL;
} tree_t;


// �Լ� ����
tree_t *createRBT (void);
node_t *createNode (tree_t *RBT, int num);

void freeRBT (tree_t *RBT);
void freeNode (tree_t *RBT, node_t *Node);

void rightRotate (tree_t *RBT, node_t *Node);
void leftRotate (tree_t *RBT, node_t *Node);

void insertion (tree_t *RBT, node_t *Node);
void insertFixUP (tree_t *RBT, node_t *Node);
void deletion (tree_t *RBT, node_t *Node);
void deleteFixUP (tree_t *RBT, node_t *Node, node_t *ParentOfNode);
node_t *succeccor (tree_t *RBT, node_t *Node);
void transPlant (tree_t *RBT, node_t *rmNode, node_t *mvNode);

int verifyRBT (tree_t *RBT);
int verifyNode (tree_t *RBT, node_t *Node);
int verifyBlackHeight (tree_t *RBT, node_t *Node);


node_t *searchNode (tree_t *RBT, int key);
node_t *minimumNode (tree_t *RBT, node_t *Node);
node_t *successorOf (tree_t *RBT, node_t *Node);

void executeRBT (tree_t *RBT);


/*
	***** Print Function by Lee Hea Jae *****
*/
// �Է¹��� ����� depth �� ��ȯ. depth�� �ش� ��忡�� ��Ʈ�������� edge ���� �ǹ�. 
int getDepth(tree_t* tree, node_t* node) {

	int depth = 0;

	node_t* curNode = node; 

	while(curNode->parent != tree->NIL) 

	{

		depth++;

		curNode = curNode->parent;

	}

	return depth;

}

// �Է¹��� ��尡 �θ��� �����ڽ����� �Ǻ�. 
// �����ڽ��̸� 1, ������ �ڽ��̸� 0 , �θ� nil �̶��(��Ʈ���) 1 

int isTail(tree_t* tree, node_t* node) {

	if(node->parent != tree->NIL) {

		if(	node->parent->rightChild == node )

			return 0;

		else 

			return 1;

	} else 

		return 1;

}
void printNode(tree_t* tree, node_t* node) {

	int i;

	int depth = getDepth(tree,node);

	char color;

	if(node->color==0)

		color = 'R';

	else

		color = 'B';




	if(depth==0) {

		printf("������ ");

		printf("%d(%c)\n",node->data,color);

	} else {

		for(i=0;i<depth-1;i++) {

			if(isTail(tree,node->parent)){

				printf("        ");

			} else

				printf("      ��");

		}

		if(isTail(tree,node)) {

			// ���� ������ �ú��� nil �̶��       ������ NIL (B) �� ������ش�.

			if(node->parent->rightChild == tree->NIL) {

				printf("      ������ NIL(B)\n");

				for(i=0;i<depth-1;i++) {

					if(isTail(tree,node->parent)){

						printf("        ");

					} else

						printf("      ��");

				}

			}

			printf("      ������ ");

		} else

			printf("      ������ ");


		printf("%d(%c)\n",node->data,color);

	}

}
// ��忡 ��Ʈ��带 ������ �˴ϴ�.
void printTree(tree_t* tree, node_t* node) {

	int j;

	if(node!=tree->NIL) {

		printNode(tree,node);

		printTree(tree,node->rightChild);

		printTree(tree,node->leftChild);

		if ((node->parent->leftChild == tree->NIL)&&(node != tree->root)){ 

				for(j=0;j<getDepth(tree,node)-1;j++) {

					if(isTail(tree,node->parent)){

						printf("        ");

					} else

						printf("      ��");

				}

			printf("      ������ NIL(B)\n");

		}

	}

	


	return ;

}




// �Լ� ����
tree_t *createRBT (void) {
	tree_t *newRBT;
	node_t *newNIL;

	newRBT = (tree_t*) malloc (sizeof(tree_t));
	newNIL = (node_t*) malloc (sizeof(node_t));

	newNIL->color = BLACK;

	newRBT->NIL = newNIL;
	newRBT->root = newRBT->NIL;

	//printf ("\nNIL: %x, %d \n", newNIL, newNIL->data);

	return newRBT;
}
node_t *createNode (tree_t *RBT, int num) {
	
	node_t *newNode = (node_t*) malloc (sizeof(node_t));
	
	newNode->data = num;
	newNode->color = RED;
	newNode->parent = RBT->NIL;
	newNode->leftChild = RBT->NIL;
	newNode->rightChild = RBT->NIL;

	return newNode;
}
void freeNode (tree_t *RBT, node_t *Node) {

	if (!Node || Node == RBT->NIL) return;

	freeNode (RBT, Node->leftChild); 
	freeNode (RBT, Node->rightChild);
	free (Node);
	Node = (node_t*) NULL;
	return;
}
void freeRBT (tree_t *RBT) {
	
	if (!RBT) return;

	if (RBT->root) {
		freeNode (RBT, RBT->root);
	}
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

	// �ӽ� ����
	tempNode = Node->rightChild;

	// ��Ÿ��� ����
	Node->rightChild = tempNode->leftChild;
	if (tempNode->leftChild != RBT->NIL)
		tempNode->leftChild->parent = Node;
	
	// parent ����
	if (Node->parent == RBT->NIL)
		RBT->root = tempNode;
	else if (Node == Node->parent->leftChild)
		Node->parent->leftChild = tempNode;
	else
		Node->parent->rightChild = tempNode;
	tempNode->parent = Node->parent;

	// x, y ���� ����
	tempNode->leftChild = Node;
	Node->parent = tempNode;

	return;
}
void rightRotate (tree_t *RBT, node_t *Node) {

	node_t *tempNode;

	if (!RBT || !Node) return;
	if (Node->leftChild == RBT->NIL) return;

	// �ӽ� ����
	tempNode = Node->leftChild;

	// ��Ÿ��� ����
	Node->leftChild = tempNode->rightChild;
	if (tempNode->rightChild != RBT->NIL)
		tempNode->rightChild->parent = Node;
	
	// parent ����
	if (Node->parent == RBT->NIL)
		RBT->root = tempNode;
	else if (Node == Node->parent->leftChild)
		Node->parent->leftChild = tempNode;
	else
		Node->parent->rightChild = tempNode;
	tempNode->parent = Node->parent;

	// x, y ���� ����
	tempNode->rightChild = Node;
	Node->parent = tempNode;

	return;
}
void insertion (tree_t *RBT, node_t *Node) {

	node_t *curNode, *tempNode;
	int verifier;

	if (!RBT || !Node) return;

	if (RBT->root == RBT->NIL) {
		RBT->root = Node;
		Node->color = BLACK;
		return;
	}

	curNode = RBT->root;
	while (curNode != RBT->NIL) {

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


	// insertFixUp
	verifier = verifyRBT (RBT);
	if (verifier != 0) {
		insertFixUP (RBT, Node);
	}

	return;
}
void insertFixUP (tree_t *RBT, node_t *Node) {

	node_t *Uncle;
	int i, verifier;
	
	while (Node->parent->color == RED) {
		
		// parent�� ��ġ�� left�� ��츸
		if (Node->parent->parent->leftChild == Node->parent) {
			// Uncle
			Uncle = Node->parent->parent->rightChild;

			// case 1
			if (Uncle->color == RED) {
				Uncle->color = BLACK;
				Node->parent->color = BLACK;
				Node->parent->parent->color = RED;
				Node = Node->parent->parent;
			}

			else {
				// case3, Node�� right�� ���
				if (Node->parent->rightChild == Node) {
					Node = Node->parent;
					leftRotate (RBT, Node);
				}
				// case2
				Node->parent->color = BLACK;
				Node->parent->parent->color = RED;
				rightRotate (RBT, Node->parent->parent);
			}
		}

		// parent�� ��ġ�� right�� ���
		else {
			// Uncle
			Uncle = Node->parent->parent->leftChild;

			// case 1
			if (Uncle->color == RED) {
				Uncle->color = BLACK;
				Node->parent->color = BLACK;
				Node->parent->parent->color = RED;
				Node = Node->parent->parent;
			}
			else {
				// case3, Node�� left�� ���
				if (Node->parent->leftChild == Node) {
					Node = Node->parent;
					rightRotate (RBT, Node);
				}
				// case2
				Node->parent->color = BLACK;
				Node->parent->parent->color = RED;
				leftRotate (RBT, Node->parent->parent);
			}
		}
		// ���� ���� ���
		/*
		verifier = verifyRBT (RBT);
		printf ("%d \n", verifier); */
	}
	RBT->root->color = BLACK;
	

	return;
}
int verifyRBT (tree_t *RBT) {
	/* RBT ����Ȯ�� �Լ�
		Input  : tree_t*, Node_t*, verifier=0, blackHeight=0
		Output : int
		  0 - correct RBT

		  1 - �� ���� Red Ȥ�� Black�� �ƴϴ�
		  2 - Root�� Black�� �ƴϴ�
		  3 - �� leaf�� Black�� �ƴϴ�.
		  4 - ��尡 Red�϶� �ΰ��� Children �� �ϳ��� Black�� �ƴϴ�
		  5 - �� ��忡 ���ؼ� descendant leaves���� �ܼ���ο� ���� ���� black nodes�� �������� �ʴ´�. */

	int verifier;

	if (!RBT) return;
	
	if (RBT->root->color != BLACK) {
		return 2;
	}

	verifier = verifyNode (RBT, RBT->root);
	if (verifier == 1) {
		return 1;
	}

	else if (verifier == 2) {
		return 4;
	}


	verifier = verifyBlackHeight (RBT, RBT->root);
	if (verifier == -1) {
		return 5;
	}
	else if (verifier == -2) {
		return 3;
	}

	return 0;
}
int verifyNode (tree_t *RBT, node_t *Node) {
	/* �Լ� ��
		Input  : tree_t*, Node_t*
		Output : 
			-1 : Input�� NULL�� ���
			 0 : correct
			 1 : ���� ��尡 BLACK Ȥ�� RED�� �ƴ� ���
			 2 : ���� ��尡 RED�� �� �� �� �ϳ��� BLACK�� �ƴ� ���
		*/
	int leftVerifier, rightVerifier;

	if (!RBT || !Node) return;
	// recursion ���� ����
	if (Node == RBT->NIL) return 0;

	leftVerifier = verifyNode (RBT, Node->leftChild);
	rightVerifier = verifyNode (RBT, Node->rightChild);

	if (leftVerifier) return leftVerifier;
	if (rightVerifier) return rightVerifier;

	// ���� ��尡 BLACK Ȥ�� RED�� �ƴϸ� 1��ȯ
	if (Node->color != BLACK && Node->color != RED) return 1;

	// ���� ��尡 RED�� �� Children�� �� �� �ϳ��� BLACK�� �ƴ� ��� 2��ȯ
	if (Node->color == RED) {
		if (Node->leftChild->color != BLACK || Node->rightChild->color != BLACK)
			return 2;
	}

	return 0;
}
int verifyBlackHeight (tree_t *RBT, node_t *Node) {
	/* �Լ� ��
		Input  : tree_t *, node_t *
		Output :
			-2 : leafNode�� Black�� �ƴ� ���
			-1 : subtree�� BlackHeight�� ���� �ٸ� ���
			totalBH : subtree�� BlackHeight�� ���� ���� ��� �� BH ũ��
		*/

	int leftBH, rightBH, totalBH;

	if (!Node) return;
	if (Node == RBT->NIL) {
		// leafNode�� ���� BLACK�� �ƴ� ��� -2��ȯ
		if (Node->color != BLACK) return -2;

		// BLACK�� ��� �ּ� BlackHeight�� 1��ȯ
		return 1;
	}

	leftBH = verifyBlackHeight (RBT, Node->leftChild);
	rightBH = verifyBlackHeight (RBT, Node->rightChild);

	// subtree���� ��ȯ���� ���� �ϳ��� -2�� ��� -2 ��ȯ
	if (leftBH == -2 || rightBH == -2) return -2;

	// subtree���� ��ȯ���� ���� �ϳ��� -1�� ��� -1 ��ȯ
	if (leftBH == -1 || rightBH == -1) return -1;

	// subtree�� BlackHeight���� �ٸ� ��� -1 ��ȯ
	if (leftBH != rightBH) return -1;

	totalBH = leftBH;
	// Node�� ���� Black�� ��� �� BH�� 1 ����
	if (Node->color == BLACK) {
		totalBH++;
	}

	return totalBH;
}
node_t *searchNode (tree_t *RBT, int key) {

	node_t *curNode, *tempNode;

	if (!RBT || RBT->root == RBT->NIL) return;

	curNode = RBT->root;
	while (curNode != RBT->NIL) {
		if (curNode->data == key)
			return curNode;
		else if (curNode->data > key)
			curNode = curNode->leftChild;
		else
			curNode = curNode->rightChild;
	}

	return (node_t*) NULL;
}
node_t *minimumNode (tree_t *RBT, node_t *Node) {

	node_t *curNode, *tempNode = (node_t*) NULL;

	if (!RBT || !Node) return;

	curNode = Node;
	while (curNode != RBT->NIL) {
		tempNode = curNode;
		curNode = curNode->leftChild;
	}
	return tempNode;
}
node_t *successorOf (tree_t *RBT, node_t *Node) {

	node_t *minimum, *curNode;
	if (!RBT || Node == RBT->NIL) return;

	if (Node->rightChild != RBT->NIL) {
		minimum = minimumNode (RBT, Node->rightChild);
		return minimum;
	}
	curNode = Node;
	while (curNode->parent != RBT->NIL) {
		if (curNode->parent->leftChild == curNode)
			return curNode->parent;
		curNode = curNode->parent;
	}

	return (node_t*) NULL;
}
void transPlant (tree_t *RBT, node_t *rmNode, node_t *mvNode) {

	if (!RBT) return;
		
	mvNode->parent = rmNode->parent;

	if (rmNode->parent == RBT->NIL) {
		RBT->root = mvNode;
		return;
	}

	if (rmNode->parent->leftChild == rmNode)
		rmNode->parent->leftChild = mvNode;
	else
		rmNode->parent->rightChild = mvNode;

	return;
}
void deletion (tree_t *RBT, node_t *Node) {

	node_t *successor, *fixUPNode, *parentOfFixUP; // deletion ���� ����
	RB_color rmNodeColor, passColor=RED;
	int verifier;

	if (!RBT || !Node) return;

	rmNodeColor = Node->color;

	if (Node->rightChild != RBT->NIL) {
		if (Node->leftChild != RBT->NIL) {
			successor = successorOf (RBT, Node);
			passColor = successor->color;
			successor->color = rmNodeColor;

			// if successor->color == RED�� ��� violation ����
			if (passColor != RED) {
				// deletion���� ����
				fixUPNode = RBT->NIL;
				if (successor->parent == Node)
					parentOfFixUP = successor;
				else
					parentOfFixUP = successor->parent;
			}
			
			transPlant (RBT, successor, successor->rightChild);
			transPlant (RBT, Node, successor);

			successor->leftChild = Node->leftChild;
			Node->leftChild->parent = successor;

			successor->rightChild = Node->rightChild;
			Node->rightChild->parent = successor;
		}

		else {
			// ����Node�� Color�� RED�� ��� Violation ����
			passColor = Node->color;
			if (passColor != RED) {
				// deletion���� ����
				fixUPNode = Node->rightChild;
				parentOfFixUP = Node->parent;
			}

			transPlant (RBT, Node, Node->rightChild);
		}

	}
	else {
		// ����Node�� Color�� RED�� ��� Violation ����
		passColor = Node->color;
		if (passColor != RED) {
			// deletion���� ����
			fixUPNode = Node->leftChild;
			parentOfFixUP = Node->parent;
		}

		transPlant (RBT, Node, Node->leftChild);
	}

	// ����Node �޸� ����
	free (Node);
	Node = (node_t*) NULL;

	// passColor�� RED�� �ƴ� ��츸 verifyRBT �� deleteFixUP ����
	if (passColor != RED) {
		// deleteFixUp
		verifier = verifyRBT (RBT);
		if (verifier != 0) {
			deleteFixUP (RBT, fixUPNode, parentOfFixUP);
		}
	}
	
	return;
}
void deleteFixUP (tree_t *RBT, node_t *Node, node_t *ParentOfNode) {
	
	node_t *sibling;
	if (!RBT) return;

	/*
	Test Code
	printf ("Text code \n");
	printf (" - %x, %d \n", Node, Node->data);
	printf (" - %x, %d \n", ParentOfNode, ParentOfNode->data);
	printTree (RBT, RBT->root);
	*/
	
	while (Node != RBT->root && Node->color == BLACK) {

		// right Sibling
		if (ParentOfNode->leftChild == Node) {
			sibling = ParentOfNode->rightChild;
		
			// Case5, sibling->color == RED
			if (sibling->color == RED) {
				ParentOfNode->color = RED;
				sibling->color = BLACK;
				leftRotate (RBT, ParentOfNode);
				sibling = sibling->leftChild;
			}

			// Case 1, Childred of Sibling -> color == BLACK
			if (sibling->leftChild->color == BLACK && sibling->rightChild->color == BLACK) {
				sibling->color = RED;

				if (ParentOfNode->color == RED) {
					ParentOfNode->color = BLACK;
					break;
				}
				Node = ParentOfNode;
				ParentOfNode = ParentOfNode->parent;
			}
			else {
				// case 3
				if (sibling->rightChild->color == BLACK) {
					sibling->color = RED;
					sibling->leftChild->color = BLACK;
					rightRotate (RBT, sibling);
					sibling = sibling->parent;
					
				}

				// Case 2
				sibling->color = ParentOfNode->color;
				ParentOfNode->color = BLACK;
				sibling->rightChild->color = BLACK;
				leftRotate (RBT, ParentOfNode);
				break;
			}
		}

		// left Sibling
		else {
			sibling = ParentOfNode->leftChild;

			// Case5, sibling->color == RED
			if (sibling->color == RED) {
				ParentOfNode->color = RED;
				sibling->color = BLACK;
				rightRotate (RBT, ParentOfNode);
				sibling = sibling->rightChild;
			}

			// Case 1, Childred of Sibling -> color == BLACK
			if (sibling->rightChild->color == BLACK && sibling->leftChild->color == BLACK) {
				sibling->color = RED;

				if (ParentOfNode->color == RED) {
					ParentOfNode->color = BLACK;
					break;
				}
				Node = ParentOfNode;
				ParentOfNode = ParentOfNode->parent;
			}
			else {
				// case 3
				if (sibling->leftChild->color == BLACK) {
					sibling->color = RED;
					sibling->rightChild->color = BLACK;
					leftRotate (RBT, sibling);
					sibling = sibling->parent;
				}

				// Case 2
				sibling->color = ParentOfNode->color;
				ParentOfNode->color = BLACK;
				sibling->leftChild->color = BLACK;
				rightRotate (RBT, ParentOfNode);
				break;
			}
		}
	}
	// while�� ����
	Node->color = BLACK;

	return;
}
void executeRBT (tree_t *RBT) {
	/*
		�Լ� ��
		�Է�: tree_t *RBT
		���:
			printRBT ����
			verifyTree ����
	*/

	int verifier;

	// RBT ���
	printTree (RBT, RBT->root);
	printf ("\n");

	// verify RBT
	verifier = verifyRBT (RBT);
	if (verifier == 0)
		printf ("perfect \n");
	else {
		printf ("Incorrect RBT : %d \n", verifier);
		printf ("\n");
	}

	return;
}

// main
int main (void) {

	tree_t *RBT;
	node_t *temp;
	int i, listSize, searchNum;
	int list[15]={10,4,6,2,3,14,1,7,100,23,27,29,30,11,8};

	// RBT ���� 
	RBT = createRBT();

	// Node ���� �� RBT�� ����
	listSize = sizeof(list)/sizeof(int);
	for (i=0; i<listSize; i++) {
		temp = createNode (RBT, list[i]);
		insertion (RBT, temp);
	}

	// printTree & verifyRBT
	executeRBT (RBT);

	// searchNode
	printf ("--- DELETION --- \n");
	printf ("Input Num : ");
	scanf ("%d", &searchNum);
	temp = searchNode (RBT, searchNum);

	if (!temp)
		printf ("No result \n");

	else {
		printf ("key : %d, %x \n", temp->data, temp);

		// deletion
		deletion (RBT, temp);
		// printTree & verifyRBT
		executeRBT (RBT);
	}

	// �޸� ����
	freeRBT (RBT);

	return 0;
}
