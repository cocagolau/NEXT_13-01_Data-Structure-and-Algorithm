/*
	작성일 : 13년 4월 18일 오후8시 40분
	작성자 : 131036 서동규
	내  용 : Linked_List 연습 및 함수 구현    
 	
	#HW7_C1  실습
	#HW7_C2  4.2.4번, Node 수를 세는 함수
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

	/* 첫번째 list 생성 */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* 메모리 할당 */
	list = createList();

	/* Node를 list의 앞에 순차적으로 저장 후 출력 */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node 생성
		insertNode (list, (node_t*)NULL, tempNode);      // 생성된 Node를 List 앞에 저장
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);
	printf ("\n");


	/* Node 추가1
	   Key값 검색 후, Key의 뒤에 새로 생성된 Node를 추가 */
	printf ("Function : insert Node \n");
	key = inputKey ();
	searchResult = searchNodeAndprevNode (list, key, &prevNode, &Node);
	tempNode = createNode ();
	insertNode (list, Node, tempNode);
	printAllNodes(list);
	printf("\n");


	/* Node 추가2
	   새로 생성된 Node를 List의 처음에 추가*/
	printf ("Function : insert Node At Front \n");
	tempNode = createNode ();
	insertNode (list, (node_t*)NULL, tempNode);
	printAllNodes (list);
	printf ("\n");


	/* Node 삭제
	Key값 검색 후, Key값을 가진 첫번째 Node를 삭제 */
	printf ("Function : delete Node \n");
	key = inputKey ();
	searchResult = searchNodeAndprevNode (list, key, &prevNode, &Node);
	deleteNode (list, prevNode ,Node);
	printAllNodes (list);
	printf ("\n");

	/* Node 역순 배열 */
	printf ("Function : invert_linked_list \n");
	list->head = invert_linked_list(list->head);
	printAllNodes (list);
	printf ("\n");


	/* 두번째List, listB 생성 */
	printf ("[ListB] Input the number of Nodes : ");
	scanf ("%d", &node_num);
	listB = createList();

	// Node를 listB의 앞에 순차적으로 저장 후 출력
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node 생성
		insertNode (listB,(node_t*)NULL, tempNode);      // 생성된 Node를 ListB 앞에 저장
		tempNode = (node_t*)NULL;
	}
	printAllNodes (listB);
	printf ("\n");


	/* list와 listB를 연결 */
	list->head = concatenate (list->head, listB->head);
	printAllNodes (list);

	if (listB) {
		free (listB);
		listB = (list_t*) NULL;
	}
	

	/* List의 Node 갯수 출력 */
	listLength = countNode (list);
	printf ("List Length = %d \n\n", listLength);


	/* Node 전체 삭제 */
	printf ("Function : delete All Node \n");

	prevNode = list->head;
	while (prevNode) {
		Node = prevNode->next;

		deleteNode (list, (node_t*)NULL ,prevNode);
		printAllNodes (list);

		prevNode = Node;
	}


	/* List의 Node 갯수 출력 */
	listLength = countNode (list);
	printf ("List Length = %d \n", listLength);


	/* 메모리 해제 */
	freeNode (list);
	free (list);    // list 해제
	list = (list_t*)NULL;

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


/* Node와 prevNode를 검색하는 함수
   list가 NULL일 경우 종료

   출력 : NULL: list나 값이 없을 때
           -1 : list의 원소가 하나일 때,       *prevNode=NULL,   *node=curNode
		    1 : list의 원소가 두개 이상 일 때  *prevNode=curNode  *node=curNode->next    */
int searchNodeAndprevNode (list_t *list, int key, node_t **prevNode, node_t **Node) {

	node_t* curNode;

	if (list==(list_t*)NULL) return NULL;

	*prevNode = (node_t*) NULL;
	*Node = (node_t*) NULL;

	curNode = list->head;

	// list의 원소가 한개일 때
	if (curNode != (node_t*)NULL && curNode->data == key) {
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

/* list의 nodeA 뒤에 nodeB 추가
   list or nodeB가 NULL인 경우, 종료   */
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (list==(list_t*)NULL || nodeB==(node_t*)NULL) return;

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

/* deepInsertNode */
void deepInsertNode (list_t *list, node_t **nodeA, node_t **nodeB) {
	if (list==(list_t*)NULL || nodeB==(node_t**)NULL) return;

	if (nodeA) {  // nodeA가 있을 경우
		(*nodeB)->next = (*nodeA)->next;
		(*nodeA)->next = (*nodeB);
	}
	else {         // nodeA가 없는 경우
		(*nodeB)->next = list->head;
		list->head = (*nodeB);
	}

	return;
}

// list 생성
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = (node_t*)NULL;

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

/* Node 메모리 해제
   list or list->head가 NULL인 경우, 종료  */
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

// Node 삭제
void deleteNode (list_t *list, node_t *prevN, node_t *targetN) {

	if (list==(list_t*)NULL || targetN==(node_t*)NULL) return;

	if (prevN) // 앞 Node가 존재시
		prevN->next = targetN->next;
	else  // 앞 Node가 비존재시
		list->head = targetN->next;

	free(targetN);
	targetN = (node_t*)NULL;
		
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

/* #HW7_C2, 4.2.4번, Node 수를 세는 함수 */
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