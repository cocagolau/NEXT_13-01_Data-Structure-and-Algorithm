/*
	작성일 : 13년 4월 18일 오후8시 40분
	작성자 : 131036 서동규
	내  용 : Linked_List 연습 및 함수 구현

	모든 원소 출력
	void printAllNodes (list_t *list);

	Node를 List 앞에 저장
    void insertNodeAtFront (list_t *list, node_t *node);

	List에 Key값을 검색
    node_t *searchNode(list_t *list, int *key);

	List의 NodeA 앞에 NodeB 저장
    void insertNode(list_t *list, node_t *nodeA, node_t *nodeB);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node 구조체 선언
typedef struct node {
	int data;
	struct node *next;
} node_t;

// list 구조체 선언
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
	//node_t *node[7], *searchResult;   // node를 만들기 위한 node_t 포인터변수로 선언
	node_t **node = NULL;
	node_t *searchResult, insert_node;
	list_t *list = NULL;
	int i, key, node_num, *elementsNum;

	/* node의 갯수 입력 */
	printf("Input Node_num : ");
	scanf("%d", &node_num); 
	
	/* 메모리 할당 */
	list = createList();
	elementsNum = &list->elementsNum;  // elementsNum에 총 원소를 담는 변수의 주소를 저장

	node = createNode (list, node, node_num);  // node 생성
	

	/* Node를 list의 앞에 순차적으로 저장 후 출력 */
	for (i=0; i<*elementsNum; i++) {    
		insertNodeAtFront (list, node[i]);
	}
	printAllNodes (list);


	/* list에서 key 검색 후 아래 형식으로 출력
	   비존재시 : None
	     존재시 : data값  */
	printf("Search Key : ");       //key값 입력받음
	scanf("%d", &key);

	searchResult = searchNode (list, &key);

	if(!searchResult)
		printf ("search Result : None\n");
	else
		printf ("search Result : %d \n", searchResult->data);

	/* Node 추가 */
	node = createNode (list, node, 1);
	insertNode(list, node[3], node[(list->latestKey)-1]);
	printAllNodes(list);

	printf ("%d\n", *elementsNum);

	/* 메모리 해제 */
	for (i=0; i<*elementsNum; i++) {           // node 해제
		free (node[i]);
		node[i] = (node_t*)NULL;
	}
	free (node);
	node = (node_t**) NULL;
	
	free (list);                  // list 해제
	list=NULL;

	return 0;
}

// list의 전체원소 출력
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

// list에서 key값을 검색
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

// list의 nodeA 앞에 nodeB 추가
void insertNode(list_t *list, node_t *nodeA, node_t *nodeB)
{
	if (list==NULL || nodeB==NULL) return;

	if (nodeA) {  // nodeA가 있을 경우
		nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else         // nodeA가 없는 경우
		insertNodeAtFront (list, nodeB);

	return;
}

// list 생성
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->head = NULL;
	list->elementsNum = 0;

	return list;
}

/* Node생성
   list, nodeNum <추가할 노드 갯수>를 입력
   node의 주소 출력
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
	/* list->elementsNum의 여부에 따라 realloc, malloc 결정 */
	if (node)
		node = (node_t**) realloc (node, sizeof(node_t*)*memorySize);
	else
		node = (node_t**) malloc (sizeof(node_t*)*memorySize);
	
	/* 추가된 배열포인터에 메모리할당 후 주소 저장 */
	for (i=*elementsNum; i<memorySize; i++) {
		node[i] = (node_t*) malloc (sizeof(node_t));

		/* value에 값 입력 후 node에 저장 */
		printf("input data[%d] : ", i);
		scanf("%d", &value);
		node[i]->data = value;
		value = NULL;  // value 초기화
	}

	/* 최종원소 값 최신화 */ 
	*elementsNum = memorySize;
	*latestKey = memorySize;

	return node;
}

