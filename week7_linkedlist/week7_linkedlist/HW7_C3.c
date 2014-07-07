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
node_t *createNode(int data);
list_t *createList();
void freeNode(list_t *list);

void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);

void printAllNodes (list_t *list);
node_t *concatenate (node_t *head1, node_t *head2);

void mergeList (list_t *ListResult, list_t *ListA, list_t *ListB);


// main
int main (void) {
	node_t *tempNode=(node_t*)NULL;
	list_t *list=(list_t*)NULL, *listB=(list_t*)NULL, *ListResult=(list_t*)NULL;
	int i;
	int arrayA[9] = {95,80,78,56,45,34,23,10,5};
	int arrayB[6] = {76,65,45,43,20,10};

	/* ù��° list ���� */
	printf ("[ListA]\n");
	/* �޸� �Ҵ� */
	list = createList();

	/* Node�� list�� �տ� ���������� ���� �� ��� */
	for (i=0; i<9; i++) {
		tempNode = createNode (arrayA[i]);                // Node ����
		insertNode (list, (node_t*)NULL, tempNode);      // ������ Node�� List �տ� ����
	}
	printAllNodes (list);
	printf ("\n");


	/* �ι�°List, listB ���� */
	printf ("[ListB]\n");
	listB = createList();

	// Node�� listB�� �տ� ���������� ���� �� ���
	for (i=0; i<6; i++) {
		tempNode = createNode (arrayB[i]);                // Node ����
		insertNode (listB, (node_t*)NULL, tempNode);      // ������ Node�� List �տ� ����
	}
	printAllNodes (listB);
	printf ("\n");


	/* ListA�� ListB�� Node�� ListResult�� ������������ ������ */
	ListResult = createList();
	mergeList (ListResult, list, listB);
	printAllNodes (ListResult);

	/* �޸� ���� */
	freeNode (ListResult);
	free (ListResult);    // list ����
	ListResult = (list_t*)NULL;

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


/* list�� nodeA �ڿ� nodeB �߰�
   list or nodeB�� NULL�� ���, ����

   mergeList�� Ư���� ����ؼ�
   �߰��� Node�� next���� �������� ���ϵ��� ����  */
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (!list || !nodeB) return;

	if (nodeA) {  // nodeA�� ���� ���
		//nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else {         // nodeA�� ���� ���
		nodeB->next = list->head;
		list->head = nodeB;
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
node_t *createNode(int data) {

	node_t *newNode;

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

/* mergeList
	�Է�: ListResult, �������� ���ĵ� ListA & ListB
	���: void

	����: ListA�� Node�� ListB�� Node�� ���ϸ� ListResult�� �������� ����
	
	���� ListA�� ù Node���� ListB�� ù Node������ Ŭ ��� ListA�� ListB�� ���� ��ȯ
	�� ����Ʈ�� ���������� ���ϸ� �������� ����   */

void mergeList (list_t *ListResult, list_t *ListA, list_t *ListB) {
	
	/*  ListA�� Node�� �̵��ϴ� ������ Aptr
		ListB�� Node�� �̵��ϴ� ������ Bptr */
	node_t *Aptr, *Bptr, *listTail=(node_t*)NULL;
	list_t *tempList;
	
	// ListA, ListB�� �Ѱ���� �������� ������� ����
	if (!ListA || !ListB) return;

	// ListA�� ù Node���� ListB�� ù Node������ �׻� �۰ų� ������ List ����
	if ( ListA->head->data > ListB->head->data) {
		tempList = ListA;
		ListA = ListB;
		ListB = tempList;
		tempList = (list_t*) NULL;
	}

	// ListResult, listTail�� �ʱⰪ ����
	ListResult->head = ListA->head;
	listTail = ListResult->head;

	// Aptr�� Bptr�� �ʱⰪ�� ����
	Aptr = ListA->head->next;
	Bptr = ListB->head;
	if (listTail->data == Bptr->data) Bptr = Bptr->next;

	// Aptr�� Bptr�� ��� ������ ��� While Loop ����
	printf("Result :");

	while( Aptr && Bptr ){
		// Aptr�� ���� Bptr�� ������ �۰ų� ���� ���, Aptr�� ListResult�� listTail �ڿ� �߰�, Aptr ����
		if (Aptr->data <= Bptr->data) {
			insertNode (ListResult, listTail, Aptr);
			listTail = Aptr;

			if (Aptr->data == Bptr->data) Bptr = Bptr->next; // �� ���� ���� ���, Bptr ����
			Aptr = Aptr->next;
		}

		// Aptr�� ���� Bptr�� ������ Ŭ ���, Bptr�� ListResult�� listTail �ڿ� �߰�, Bptr ����
		else {
			insertNode (ListResult, listTail, Bptr);
			listTail = Bptr;
			Bptr = Bptr->next;
		}
	}

	// Aptr�̳� Bptr�� ���� ���� ���� ��� ListResult�� �̾� ����
	if (Aptr) concatenate (ListResult->head, Aptr);
	if (Bptr) concatenate (ListResult->head, Bptr);

	// ListA, ListB �����޸� ����
	free (ListA); 
	free (ListB);

	return;
}