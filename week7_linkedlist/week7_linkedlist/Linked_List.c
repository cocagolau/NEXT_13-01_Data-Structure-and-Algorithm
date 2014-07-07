/*
	�ۼ��� : 13�� 4�� 18�� ����8�� 40��
	�ۼ��� : 131036 ������
	��  �� : Linked_List ���� �� �Լ� ����

	��� ���� ���
	void printAllNodes (list_t *list);

	Node�� List �տ� ����
    void insertNodeAtFront (list_t *list, node_t *node);

	List�� Key���� �˻�
    node_t *searchNode(list_t *list, int *key);

	List�� NodeA �տ� NodeB ����
    void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node ����ü ����
typedef struct node {
	int data;
	struct node *next;
} node_t;

// list ����ü ����
typedef struct list {
	node_t *head;
	int elementsNum;
	int latestKey;
} list_t;

void printAllNodes (list_t *list);
void insertNodeAtFront (list_t *list, node_t *node);
node_t *searchNode(list_t *list, int *key);
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
node_t **createNode(list_t *list, node_t **node, int nodeNum);
list_t *createList(void);


int main (void) {
	//node_t *node[7], *searchResult;   // node�� ����� ���� node_t �����ͺ����� ����
	node_t **node = NULL;
	node_t *searchResult, insert_node;
	list_t *list = NULL;
	int i, key, node_num, *elementsNum;

	/* node�� ���� �Է� */
	printf("Input Node_num : ");
	scanf("%d", &node_num); 
	
	/* �޸� �Ҵ� */
	list = createList();
	elementsNum = &list->elementsNum;  // elementsNum�� �� ���Ҹ� ��� ������ �ּҸ� ����

	node = createNode (list, node, node_num);  // node ����
	

	/* Node�� list�� �տ� ���������� ���� �� ��� */
	for (i=0; i<*elementsNum; i++) {    
		insertNodeAtFront (list, node[i]);
	}
	printAllNodes (list);


	/* list���� key �˻� �� �Ʒ� �������� ���
	   ������� : None
	     ����� : data��  */
	printf("Search Key : ");       //key�� �Է¹���
	scanf("%d", &key);

	searchResult = searchNode (list, &key);

	if(!searchResult)
		printf ("search Result : None\n");
	else
		printf ("search Result : %d \n", searchResult->data);

	/* Node �߰� */
	node = createNode (list, node, 1);
	insertNode(list, node[3], node[(list->latestKey)-1]);
	printAllNodes(list);

	printf ("%d\n", *elementsNum);

	/* �޸� ���� */
	for (i=0; i<*elementsNum; i++) {           // node ����
		free (node[i]);
		node[i] = (node_t*)NULL;
	}
	free (node);
	node = (node_t**) NULL;
	
	free (list);                  // list ����
	list=NULL;

	return 0;
}

// list�� ��ü���� ���
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

// list���� key���� �˻�
node_t * searchNode (list_t *list, int *key) {
	node_t* curNode;

	if (list==NULL || key==NULL) return (node_t*) NULL;

	curNode = list->head;
	while (curNode) {
		if (curNode->data == *key) return curNode;
		curNode = curNode->next;
	}
	return (node_t*) NULL;
}

// list�� nodeA �տ� nodeB �߰�
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB)
{
	if (list==NULL || nodeB==NULL) return;

	if (nodeA) {  // nodeA�� ���� ���
		nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else         // nodeA�� ���� ���
		insertNodeAtFront (list, nodeB);

	return;
}

// list ����
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = NULL;
	list->elementsNum = 0;

	return list;
}

/* Node����
   list, nodeNum <�߰��� ��� ����>�� �Է�
   node�� �ּ� ���
   */
node_t **createNode(list_t *list, node_t **node, int nodeNum) {
	//node_t **tempNode;
	int i, memorySize, *elementsNum, *latestKey;
	int value;

	if (list == NULL || nodeNum == NULL) return (node_t**) NULL;

	elementsNum = &list->elementsNum;
	latestKey = &list->latestKey;
	memorySize = *elementsNum + nodeNum;

	printf("test\n");
	/* list->elementsNum�� ���ο� ���� realloc, malloc ���� */
	if (node)
		node = (node_t**) realloc (node, sizeof(node_t*)*memorySize);
	else
		node = (node_t**) malloc (sizeof(node_t*)*memorySize);
	
	/* �߰��� �迭�����Ϳ� �޸��Ҵ� �� �ּ� ���� */
	for (i=*elementsNum; i<memorySize; i++) {
		node[i] = (node_t*) malloc (sizeof(node_t));

		/* value�� �� �Է� �� node�� ���� */
		printf("input data[%d] : ", i);
		scanf("%d", &value);
		node[i]->data = value;
		value = NULL;  // value �ʱ�ȭ
	}

	/* �������� �� �ֽ�ȭ */ 
	*elementsNum = memorySize;
	*latestKey = memorySize;

	return node;
}

