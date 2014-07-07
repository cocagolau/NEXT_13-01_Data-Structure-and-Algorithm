/*
	작성일 : 13년 4월 20일 오후6시 40분
	작성자 : 131036 서동규
	내  용 : Linked_List 연습 및 함수 구현    
 ============================================ */


#include <stdio.h>
#include <stdlib.h>

// node 구조체 선언
typedef struct node {
	int data;
	struct node *next;
} node_t;

// list 구조체 선언
typedef struct list {
	node_t *head;
} list_t;

// 함수 선언
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

	/* 첫번째 list 생성 */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* 메모리 할당 */
	list = createList();

	/* Node를 list의 앞에 순차적으로 저장 후 출력 */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node 생성
		insertNodeAtFront (list, tempNode);      // 생성된 Node를 List 앞에 저장
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);
	printf ("\n");

	

	/* 메모리 해제 */
	freeNode (list);
	free (list);    // list 해제
	list = NULL;

	return 0;
}

/* list의 전체원소 출력
   입력: *list
   출력: 없음           */
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

// list의 맨 앞에 Node추가
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

/* Node와 prevNode를 검색하는 함수
   입력 : *list, *key, **prevNode, **Node
   출력 : NULL - list나 값이 없을 때
           -1  - list의 원소가 하나일 때
		    1  - list의 원소가 두개 이상 일 때  */
int searchNodeAndprevNode (list_t *list, int key, node_t **prevNode, node_t **Node) {

	node_t* curNode;

	if (list==NULL) return NULL;

	*prevNode = (node_t*) NULL;
	*Node = (node_t*) NULL;

	curNode = list->head;

	// list의 원소가 한개일 때
	if (curNode != NULL && curNode->data == key) {
		*prevNode = (node_t*)NULL;
		*Node = curNode;
		return -1;
	}

	// list의 원소가 두개 이상일 때
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

// list의 nodeA 앞에 nodeB 추가
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (list==NULL || nodeB==NULL) return;

	if (nodeA) {  // nodeA가 있을 경우
		nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else {         // nodeA가 없는 경우
		nodeB->next = list->head;
		list->head = nodeB;
	}

	return;
}

// list 생성
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = NULL;

	return list;
}

// Node생성
node_t *createNode(void) {

	node_t *newNode;
	int data;

	printf(" - Input data : ");
	scanf("%d", &data);

	newNode = (node_t*) malloc (sizeof(node_t));
	newNode->data = data;

	return newNode;
}

// Node 메모리 해제
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

// Node 삭제
void deleteNode (list_t *list, node_t *prevN, node_t *targetN) {

	if (list==NULL || targetN==NULL) return;

	if (prevN) // 앞 Node가 존재시
		prevN->next = targetN->next;
	else  // 앞 Node가 비존재시
		list->head = targetN->next;

	free(targetN);
	targetN = NULL;
		
	return;
}


/* Input Key */
int inputKey (void) {
	
	int key;

	// key값 입력받음
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