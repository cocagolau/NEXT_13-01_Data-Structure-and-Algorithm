/*
	�ۼ��� : 13�� 4�� 18�� ����8�� 40��
	�ۼ��� : 131036 ������
	��  �� : Linked_List ���� �� �Լ� ����    
 	
	#HW7_C1  �ǽ�
	#HW7_C2  4.2.4��, Node ���� ���� �Լ�
 ============================================ */


#include <stdio.h>
#include <stdlib.h>

// node ����ü ����
typedef struct node {
	int data;
	struct node *next;
} node_t;

// list ����ü ����
typedef struct list {
	node_t *head;
} list_t;

// �Լ� ����
node_t *createNode(void);
list_t *createList(void);
void freeNode(list_t *list);

void deepInsertNode (list_t **list, node_t **nodeA, node_t **nodeB);
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
void deleteNode(list_t *list, node_t *prevN, node_t *targetN);

void printAllNodes (list_t *list);
int inputKey (void);
int searchNodeAndprevNode(list_t *list, int key, node_t **prevNode, node_t **Node);

node_t *invert_linked_list(node_t *head);
node_t *concatenate (node_t *head1, node_t *head2);
int countNode (list_t *list);


// main
int main (void) {
	node_t *tempNode=(node_t*)NULL, *prevNode, *Node;
	list_t *list=(list_t*)NULL, *listB=(list_t*)NULL;
	int key;
	int i, node_num, searchResult, listLength=0;

	/* ù��° list ���� */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* �޸� �Ҵ� */
	list = createList();

	/* Node�� list�� �տ� ���������� ���� �� ��� */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node ����
		insertNode (list, (node_t*)NULL, tempNode);      // ������ Node�� List �տ� ����
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);
	printf ("\n");


	/* Node �߰�1
	   Key�� �˻� ��, Key�� �ڿ� ���� ������ Node�� �߰� */
	printf ("Function : insert Node \n");
	key = inputKey ();
	searchResult = searchNodeAndprevNode (list, key, &prevNode, &Node);
	tempNode = createNode ();
	insertNode (list, Node, tempNode);
	printAllNodes(list);
	printf("\n");


	/* Node �߰�2
	   ���� ������ Node�� List�� ó���� �߰�*/
	printf ("Function : insert Node At Front \n");
	tempNode = createNode ();
	insertNode (list, (node_t*)NULL, tempNode);
	printAllNodes (list);
	printf ("\n");


	/* Node ����
	Key�� �˻� ��, Key���� ���� ù��° Node�� ���� */
	printf ("Function : delete Node \n");
	key = inputKey ();
	searchResult = searchNodeAndprevNode (list, key, &prevNode, &Node);
	deleteNode (list, prevNode ,Node);
	printAllNodes (list);
	printf ("\n");

	/* Node ���� �迭 */
	printf ("Function : invert_linked_list \n");
	list->head = invert_linked_list(list->head);
	printAllNodes (list);
	printf ("\n");


	/* �ι�°List, listB ���� */
	printf ("[ListB] Input the number of Nodes : ");
	scanf ("%d", &node_num);
	listB = createList();

	// Node�� listB�� �տ� ���������� ���� �� ���
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node ����
		insertNode (listB,(node_t*)NULL, tempNode);      // ������ Node�� ListB �տ� ����
		tempNode = (node_t*)NULL;
	}
	printAllNodes (listB);
	printf ("\n");


	/* list�� listB�� ���� */
	list->head = concatenate (list->head, listB->head);
	printAllNodes (list);

	if (listB) {
		free (listB);
		listB = (list_t*) NULL;
	}
	

	/* List�� Node ���� ��� */
	listLength = countNode (list);
	printf ("List Length = %d \n\n", listLength);


	/* Node ��ü ���� */
	printf ("Function : delete All Node \n");

	prevNode = list->head;
	while (prevNode) {
		Node = prevNode->next;

		deleteNode (list, (node_t*)NULL ,prevNode);
		printAllNodes (list);

		prevNode = Node;
	}


	/* List�� Node ���� ��� */
	listLength = countNode (list);
	printf ("List Length = %d \n", listLength);


	/* �޸� ���� */
	freeNode (list);
	free (list);    // list ����
	list = (list_t*)NULL;

	return 0;
}

/* list�� ��ü���� ���
   �Է�: *list
   ���: ����           */
void printAllNodes (list_t* list) {

	node_t* curNode;

	curNode = list->head;
	if (!curNode) {
		printf ("None\n");
		return;
	}

	while (curNode) {
		printf ("%d ", curNode->data);
		curNode = curNode->next;
	}
	printf ("\n");

	return;
}


/* Node�� prevNode�� �˻��ϴ� �Լ�
   list�� NULL�� ��� ����

   ��� : NULL: list�� ���� ���� ��
           -1 : list�� ���Ұ� �ϳ��� ��,       *prevNode=NULL,   *node=curNode
		    1 : list�� ���Ұ� �ΰ� �̻� �� ��  *prevNode=curNode  *node=curNode->next    */
int searchNodeAndprevNode (list_t *list, int key, node_t **prevNode, node_t **Node) {

	node_t* curNode;

	if (list==(list_t*)NULL) return NULL;

	*prevNode = (node_t*) NULL;
	*Node = (node_t*) NULL;

	curNode = list->head;

	// list�� ���Ұ� �Ѱ��� ��
	if (curNode != (node_t*)NULL && curNode->data == key) {
		*prevNode = (node_t*)NULL;
		*Node = curNode;
		return -1;
	}

	// list�� ���Ұ� �ΰ� �̻��� ��
	while (curNode->next) {
		if (curNode->next->data == key) {
			*prevNode = curNode;
			*Node = curNode->next;
			return 1;
		}
		curNode = curNode->next;
	}

	return NULL;
}

/* list�� nodeA �ڿ� nodeB �߰�
   list or nodeB�� NULL�� ���, ����   */
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (list==(list_t*)NULL || nodeB==(node_t*)NULL) return;

	if (nodeA) {  // nodeA�� ���� ���
		nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else {         // nodeA�� ���� ���
		nodeB->next = list->head;
		list->head = nodeB;
	}

	return;
}

/* deepInsertNode */
void deepInsertNode (list_t *list, node_t **nodeA, node_t **nodeB) {
	if (list==(list_t*)NULL || nodeB==(node_t**)NULL) return;

	if (nodeA) {  // nodeA�� ���� ���
		(*nodeB)->next = (*nodeA)->next;
		(*nodeA)->next = (*nodeB);
	}
	else {         // nodeA�� ���� ���
		(*nodeB)->next = list->head;
		list->head = (*nodeB);
	}

	return;
}

// list ����
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = (node_t*)NULL;

	return list;
}

// Node����
node_t *createNode(void) {

	node_t *newNode;
	int data;

	printf(" - Input data : ");
	scanf("%d", &data);

	newNode = (node_t*) malloc (sizeof(node_t));
	newNode->data = data;

	return newNode;
}

/* Node �޸� ����
   list or list->head�� NULL�� ���, ����  */
void freeNode (list_t *list) {

	node_t *curNode, *tempNode;

	if (list == (list_t*)NULL || list->head == (node_t*)NULL) return;

	curNode = list->head;
	do {
		tempNode = curNode->next;
		free(curNode);
		curNode = tempNode;
	}
	while (curNode);
	list->head = (node_t*)NULL;

	return;
}

// Node ����
void deleteNode (list_t *list, node_t *prevN, node_t *targetN) {

	if (list==(list_t*)NULL || targetN==(node_t*)NULL) return;

	if (prevN) // �� Node�� �����
		prevN->next = targetN->next;
	else  // �� Node�� �������
		list->head = targetN->next;

	free(targetN);
	targetN = (node_t*)NULL;
		
	return;
}


/* Input Key */
int inputKey (void) {
	
	int key;

	// key�� �Է¹���
	printf ("Search Key : ");      
	scanf ("%d", &key);

	return key;
}

/* invert list */
node_t *invert_linked_list(node_t *head) {

	node_t *newHead = (node_t*)NULL, *tempNode;

	while (head) {
		tempNode = head;
		head = tempNode->next;
		tempNode->next = newHead;
		newHead = tempNode;
	}

	return newHead;
}

node_t *concatenate (node_t *head1, node_t *head2) {

	node_t *curNode;

	if (head1==(node_t*)NULL && head2==(node_t*)NULL) return (node_t*) NULL;
	if (head2==(node_t*)NULL) return head1;

	curNode = head1;
	while (curNode->next) {
		curNode = curNode->next;
	}
	curNode->next = head2;
	head2 = (node_t*)NULL;

	return head1;
}

/* #HW7_C2, 4.2.4��, Node ���� ���� �Լ� */
int countNode (list_t *list) {
	
	node_t* curNode;
	int length = 0;

	curNode = list->head;
	if (!curNode) {
		return 0;
	}

	while (curNode) {
		length += 1;
		curNode = curNode->next;
	}

	return length;
}