/*
	�ۼ��� : 13�� 4�� 20�� ����8�� 40��
	�ۼ��� : 131036 ������
	��  �� : Doubly_Linked_List ���� �� �Լ� ����    
	
	#HW7_C1  �ǽ�
	#HW7_C2  4.2.4��, Node ���� ���� �Լ�
 ============================================ */


#include <stdio.h>
#include <stdlib.h>

// node ����ü ����
typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} node_t;

// list ����ü ����
typedef struct list {
	node_t *head;
} list_t;

// �Լ� ����
node_t *createNode(void);
list_t *createList(void);
void freeNode(list_t *list);
node_t *searchNode (list_t* list, int key);
void insertNode(node_t *node, node_t *newNode);
void deleteNode(list_t *list, node_t *targetN);
void printAllNodes (list_t *list);
int countNode (list_t *list);
int inputKey (void);


// main�Լ�
int main (void) {

	node_t *tempNode=NULL, *searchResult;
	node_t Sentinel;
	list_t *list = NULL;
	int i, key, node_num, listLength;

	/* Sentinel List�� �� ���� */
	Sentinel.data = NULL;
	Sentinel.next = &Sentinel;
	Sentinel.prev = &Sentinel;

	/* ù��° list ���� */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* �޸� �Ҵ� */
	list = createList();
	list->head = &Sentinel;

	/* Node�� list�� �տ� ���������� ���� �� ��� */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node �����޸𸮷� ����
		insertNode (list->head, tempNode);       // ������ Node�� List�� �� �κп� ����
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);


	/* List���� key�� �˻� ��
	     ����� ���� �Ҵ�� Node�� key�� �ڿ� ����
	   ������� ���� �Ҵ�� Node�� ó���� ����     */
	printf ("Function : Search Node and Insert Node \n");
	key = inputKey();
	searchResult = searchNode(list, key);

	tempNode = createNode();
	if (searchResult) insertNode (searchResult, tempNode);   // search �� �����
	else insertNode (list->head, tempNode);                  // search �� �������
	printAllNodes (list);


	/* List���� key�� �˻� �� Node����     */
	printf ("Function : Delete Node \n");
	key = inputKey();
	searchResult = searchNode(list, key);

	if (searchResult) {                      // search �� �����
		deleteNode (list, searchResult);
		printAllNodes (list);
	}
	else printf("Impossible Deletion\n");    // search �� �������


	/* List�� Node ���� ��� */
	listLength = countNode (list);
	printf("List Length : %d\n", listLength);
	

	/* �޸� ���� */
	freeNode (list);
	free (list);    // list ����
	list = NULL;

	return 0;
}

/* Node->data �� ã��
   list or key == NULL, NULL ��ȯ
   key�� ã����,      curNode ��ȯ
   ���� ������           NULL ��ȯ  */
node_t *searchNode (list_t* list, int key) {

	node_t *curNode = list->head->next;

	if (list==NULL || key==NULL) return (node_t*) NULL;
	
	while (curNode != list->head) {
		if (curNode->data == key) return curNode;
		curNode = curNode->next;
	}

	return (node_t*)NULL;
}


/* list�� ��ü���� ��� */
void printAllNodes (list_t* list) {

	node_t* curNode;

	curNode = list->head->next;
	if (!curNode) {
		printf ("None\n");
		return;
	}

	printf("���� Node ��    ����Node �ּ�, ��    ����Node �ּ�, ��\n");
	while (curNode->next!=list->head->next) {
		printf ("%12d     %12p  %2d     %12p  %2d\n", curNode->data, curNode->prev, curNode->prev->data, curNode->next, curNode->next->data);
		curNode = curNode->next;
	}
	printf ("\n");

	return;
}

// list�� �� �տ� Node�߰�
void insertNodeAtFront (list_t* list, node_t* node) {
	
	node_t *Sentinel = list->head;

	if (list==NULL || node==NULL) return;

	node->next = Sentinel->next;
	node->prev = Sentinel;

	Sentinel->next->prev = node;
	Sentinel->next = node;

	return;
}


// list�� node �ڿ� newNode �߰�
void insertNode (node_t *node, node_t *newNode) {
	if (node==NULL || newNode==NULL) return;

	newNode->next = node->next;
	newNode->prev = node;

	node->next->prev = newNode;
	node->next = newNode;

	return;
}


// Node ����
void deleteNode (list_t *list, node_t *targetN) {

	if (list==NULL || targetN==NULL) return;

	targetN->prev->next = targetN->next;
	targetN->next->prev = targetN->prev;
	
	free(targetN);
	targetN = NULL;
		
	return;
}



// list ����
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = NULL;

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

// Node �޸� ����
void freeNode (list_t *list) {

	node_t *curNode, *tempNode;

	if (list == NULL || list->head->next == NULL) return;

	curNode = list->head->next;
	do {
		tempNode = curNode->next;
		free(curNode);
		curNode = tempNode;
	}
	while (curNode!=list->head);

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

/* #HW7_C2, 4.2.4��, Node ���� ���� �Լ� */
int countNode (list_t* list) {

	node_t* curNode;
	int length=0;

	curNode = list->head->next;
	if (!curNode) {
		return 0;
	}

	while (curNode->next!=list->head->next) {
		length += 1;
		curNode = curNode->next;
	}
	return length;
}