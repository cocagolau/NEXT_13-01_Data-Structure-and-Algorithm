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

	/* 첫번째 list 생성 */
	printf ("[ListA]\n");
	/* 메모리 할당 */
	list = createList();

	/* Node를 list의 앞에 순차적으로 저장 후 출력 */
	for (i=0; i<9; i++) {
		tempNode = createNode (arrayA[i]);                // Node 생성
		insertNode (list, (node_t*)NULL, tempNode);      // 생성된 Node를 List 앞에 저장
	}
	printAllNodes (list);
	printf ("\n");


	/* 두번째List, listB 생성 */
	printf ("[ListB]\n");
	listB = createList();

	// Node를 listB의 앞에 순차적으로 저장 후 출력
	for (i=0; i<6; i++) {
		tempNode = createNode (arrayB[i]);                // Node 생성
		insertNode (listB, (node_t*)NULL, tempNode);      // 생성된 Node를 List 앞에 저장
	}
	printAllNodes (listB);
	printf ("\n");


	/* ListA와 ListB의 Node를 ListResult에 오름차순으로 재정렬 */
	ListResult = createList();
	mergeList (ListResult, list, listB);
	printAllNodes (ListResult);

	/* 메모리 해제 */
	freeNode (ListResult);
	free (ListResult);    // list 해제
	ListResult = (list_t*)NULL;

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


/* list의 nodeA 뒤에 nodeB 추가
   list or nodeB가 NULL인 경우, 종료

   mergeList의 특성을 고려해서
   추가할 Node의 next값을 수정하지 못하도록 수정  */
void insertNode (list_t *list, node_t *nodeA, node_t *nodeB) {
	if (!list || !nodeB) return;

	if (nodeA) {  // nodeA가 있을 경우
		//nodeB->next = nodeA->next;
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
	list->head = (node_t*)NULL;

	return list;
}

// Node생성
node_t *createNode(int data) {

	node_t *newNode;

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
	입력: ListResult, 오름차순 정렬된 ListA & ListB
	출력: void

	내용: ListA의 Node와 ListB의 Node를 비교하며 ListResult에 오름차순 정렬
	
	만약 ListA의 첫 Node값이 ListB의 첫 Node값보다 클 경우 ListA와 ListB를 서로 교환
	두 리스트를 순차적으로 비교하며 오름차순 정렬   */

void mergeList (list_t *ListResult, list_t *ListA, list_t *ListB) {
	
	/*  ListA의 Node를 이동하는 포인터 Aptr
		ListB의 Node를 이동하는 포인터 Bptr */
	node_t *Aptr, *Bptr, *listTail=(node_t*)NULL;
	list_t *tempList;
	
	// ListA, ListB가 한개라고 존재하지 않을경우 리턴
	if (!ListA || !ListB) return;

	// ListA의 첫 Node값이 ListB의 첫 Node값보다 항상 작거나 같도록 List 변경
	if ( ListA->head->data > ListB->head->data) {
		tempList = ListA;
		ListA = ListB;
		ListB = tempList;
		tempList = (list_t*) NULL;
	}

	// ListResult, listTail의 초기값 설정
	ListResult->head = ListA->head;
	listTail = ListResult->head;

	// Aptr과 Bptr의 초기값을 설정
	Aptr = ListA->head->next;
	Bptr = ListB->head;
	if (listTail->data == Bptr->data) Bptr = Bptr->next;

	// Aptr과 Bptr이 모두 존재할 경우 While Loop 실행
	printf("Result :");

	while( Aptr && Bptr ){
		// Aptr의 값이 Bptr의 값보다 작거나 같을 경우, Aptr을 ListResult의 listTail 뒤에 추가, Aptr 증가
		if (Aptr->data <= Bptr->data) {
			insertNode (ListResult, listTail, Aptr);
			listTail = Aptr;

			if (Aptr->data == Bptr->data) Bptr = Bptr->next; // 두 값이 같을 경우, Bptr 증거
			Aptr = Aptr->next;
		}

		// Aptr의 값이 Bptr의 값보다 클 경우, Bptr을 ListResult의 listTail 뒤에 추가, Bptr 증가
		else {
			insertNode (ListResult, listTail, Bptr);
			listTail = Bptr;
			Bptr = Bptr->next;
		}
	}

	// Aptr이나 Bptr에 남은 값이 있을 경우 ListResult에 이어 붙임
	if (Aptr) concatenate (ListResult->head, Aptr);
	if (Bptr) concatenate (ListResult->head, Bptr);

	// ListA, ListB 동적메모리 해제
	free (ListA); 
	free (ListB);

	return;
}