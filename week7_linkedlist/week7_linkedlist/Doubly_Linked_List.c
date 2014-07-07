/*
	작성일 : 13년 4월 20일 오후8시 40분
	작성자 : 131036 서동규
	내  용 : Doubly_Linked_List 연습 및 함수 구현    
	
	#HW7_C1  실습
	#HW7_C2  4.2.4번, Node 수를 세는 함수
 ============================================ */


#include <stdio.h>
#include <stdlib.h>

// node 구조체 선언
typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} node_t;

// list 구조체 선언
typedef struct list {
	node_t *head;
} list_t;

// 함수 선언
node_t *createNode(void);
list_t *createList(void);
void freeNode(list_t *list);
node_t *searchNode (list_t* list, int key);
void insertNode(node_t *node, node_t *newNode);
void deleteNode(list_t *list, node_t *targetN);
void printAllNodes (list_t *list);
int countNode (list_t *list);
int inputKey (void);


// main함수
int main (void) {

	node_t *tempNode=NULL, *searchResult;
	node_t Sentinel;
	list_t *list = NULL;
	int i, key, node_num, listLength;

	/* Sentinel List의 값 설정 */
	Sentinel.data = NULL;
	Sentinel.next = &Sentinel;
	Sentinel.prev = &Sentinel;

	/* 첫번째 list 생성 */
	printf ("[ListA] Input the number of Nodes : ");
	scanf ("%d", &node_num);

	/* 메모리 할당 */
	list = createList();
	list->head = &Sentinel;

	/* Node를 list의 앞에 순차적으로 저장 후 출력 */
	for (i=0; i<node_num; i++) {
		tempNode = createNode ();                // Node 동적메모리로 생성
		insertNode (list->head, tempNode);       // 생성된 Node를 List의 앞 부분에 저장
		tempNode = NULL;
	}
	printf ("\n");
	printf ("Function : insert Node At Front \n");
	printAllNodes (list);


	/* List에서 key를 검색 후
	     존재시 새로 할당된 Node를 key값 뒤에 저장
	   비존재시 새로 할당된 Node를 처음에 저장     */
	printf ("Function : Search Node and Insert Node \n");
	key = inputKey();
	searchResult = searchNode(list, key);

	tempNode = createNode();
	if (searchResult) insertNode (searchResult, tempNode);   // search 값 존재시
	else insertNode (list->head, tempNode);                  // search 값 비존재시
	printAllNodes (list);


	/* List에서 key를 검색 후 Node삭제     */
	printf ("Function : Delete Node \n");
	key = inputKey();
	searchResult = searchNode(list, key);

	if (searchResult) {                      // search 값 존재시
		deleteNode (list, searchResult);
		printAllNodes (list);
	}
	else printf("Impossible Deletion\n");    // search 값 비존재시


	/* List의 Node 갯수 출력 */
	listLength = countNode (list);
	printf("List Length : %d\n", listLength);
	

	/* 메모리 해제 */
	freeNode (list);
	free (list);    // list 해제
	list = NULL;

	return 0;
}

/* Node->data 값 찾기
   list or key == NULL, NULL 반환
   key값 찾으면,      curNode 반환
   값이 없으면           NULL 반환  */
node_t *searchNode (list_t* list, int key) {

	node_t *curNode = list->head->next;

	if (list==NULL || key==NULL) return (node_t*) NULL;
	
	while (curNode != list->head) {
		if (curNode->data == key) return curNode;
		curNode = curNode->next;
	}

	return (node_t*)NULL;
}


/* list의 전체원소 출력 */
void printAllNodes (list_t* list) {

	node_t* curNode;

	curNode = list->head->next;
	if (!curNode) {
		printf ("None\n");
		return;
	}

	printf("현재 Node 값    이전Node 주소, 값    다음Node 주소, 값\n");
	while (curNode->next!=list->head->next) {
		printf ("%12d     %12p  %2d     %12p  %2d\n", curNode->data, curNode->prev, curNode->prev->data, curNode->next, curNode->next->data);
		curNode = curNode->next;
	}
	printf ("\n");

	return;
}

// list의 맨 앞에 Node추가
void insertNodeAtFront (list_t* list, node_t* node) {
	
	node_t *Sentinel = list->head;

	if (list==NULL || node==NULL) return;

	node->next = Sentinel->next;
	node->prev = Sentinel;

	Sentinel->next->prev = node;
	Sentinel->next = node;

	return;
}


// list의 node 뒤에 newNode 추가
void insertNode (node_t *node, node_t *newNode) {
	if (node==NULL || newNode==NULL) return;

	newNode->next = node->next;
	newNode->prev = node;

	node->next->prev = newNode;
	node->next = newNode;

	return;
}


// Node 삭제
void deleteNode (list_t *list, node_t *targetN) {

	if (list==NULL || targetN==NULL) return;

	targetN->prev->next = targetN->next;
	targetN->next->prev = targetN->prev;
	
	free(targetN);
	targetN = NULL;
		
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

	// key값 입력받음
	printf ("Search Key : ");      
	scanf ("%d", &key);

	return key;
}

/* #HW7_C2, 4.2.4번, Node 수를 세는 함수 */
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