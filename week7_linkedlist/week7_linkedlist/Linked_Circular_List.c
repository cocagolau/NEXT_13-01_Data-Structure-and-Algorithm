/*
	�ۼ��� : 13�� 4�� 20�� ����6�� 40��
	�ۼ��� : 131036 ������
	��  �� : Linked_List ���� �� �Լ� ����    
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

void insertNodeAtFront (list_t *list, node_t *node);
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
void deleteNode(list_t *list, node_t *prevN, node_t *targetN);

void printAllNodes (list_t *list);
int inputKey (void);
int searchNodeAndprevNode(list_t *list, int key, node_t **prevNode, node_t **Node);

node_t *invert_linked_list(node_t *head);
node_t *concatenate (node_t *head1, node_t *head2);


// main
int main (void) {
	node_t *tempNode=NULL, *prevNode, *Node;
	list_t *list = NULL, *listB=NULL;
	int key;
	int i, node_num, searchResult;

	/* ù��° list ���� */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* �޸� �Ҵ� */
	list = createList();

	/* Node�� list�� �տ� ���������� ���� �� ��� */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node ����
		insertNodeAtFront (list, tempNode);      // ������ Node�� List �տ� ����
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);
	printf ("\n");

	

	/* �޸� ���� */
	freeNode (list);
	free (list);    // list ����
	list = NULL;

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

// list�� �� �տ� Node�߰�
void insertNodeAtFront (list_t* list, node_t* node) {
	if (list==NULL || node==NULL) return;

	if (list) {
		node->next = list->head;
		list->head = node;
	}
	else {
		node->next = list->head;
		list->head = node;
	}

	return;
}

/* Node�� prevNode�� �˻��ϴ� �Լ�
   �Է� : *list, *key, **prevNode, **Node
   ��� : NULL - list�� ���� ���� ��
           -1  - list�� ���Ұ� �ϳ��� ��
		    1  - list�� ���Ұ� �ΰ� �̻� �� ��  */
int searchNodeAndprevNode (list_t *list, int key, node_t **prevNode, node_t **Node) {

	node_t* curNode;

	if (list==NULL) return NULL;

	*prevNode = (node_t*) NULL;
	*Node = (node_t*) NULL;

	curNode = list->head;

	// list�� ���Ұ� �Ѱ��� ��
	if (curNode != NULL && curNode->data == key) {
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

// list�� nodeA �տ� nodeB �߰�
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (list==NULL || nodeB==NULL) return;

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

	if (list == NULL || list->head == NULL) return;

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

	if (list==NULL || targetN==NULL) return;

	if (prevN) // �� Node�� �����
		prevN->next = targetN->next;
	else  // �� Node�� �������
		list->head = targetN->next;

	free(targetN);
	targetN = NULL;
		
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

	node_t *newHead = NULL, *tempNode;

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
	int i = 1;

	if (head1==NULL && head2==NULL) return (node_t*) NULL;
	if (head2==NULL) return head1;

	curNode = head1;
	while (curNode->next) {
		curNode = curNode->next;
		printf("test %d\n",i);
		i++;
	}
	curNode->next = head2;
	head2 = NULL;

	return head1;
}