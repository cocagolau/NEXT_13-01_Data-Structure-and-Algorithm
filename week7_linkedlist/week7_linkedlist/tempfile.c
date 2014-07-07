/*
	날짜: 13년 4월 28일 오후 6시 30분
	이름: 서동규
	내용: 자구알 HW7_ p1 과제
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *link;
}node_t;

typedef struct list {
	node_t *head;
}list_t;

int main (void) {

	list_t list;
	node_t node[10];
	node_t *tempNode=(node_t*)NULL, *curNodeAddr, *Node, *nodeTail;

	int tempAdd, i;

	list.head = &node[0];
	nodeTail = &node[3];

	node[0].data = 0;
	node[0].link = (node_t*)((int)NULL ^ (int)&node[1]);

	node[1].data = 1;
	node[1].link = (node_t*)((int)&node[0] ^ (int)&node[2]);

	node[2].data = 2;
	node[2].link = (node_t*)((int)&node[1] ^ (int)&node[3]);

	node[3].data = 3;
	node[3].link = (node_t*)((int)&node[2] ^ (int)NULL);
	
	// 

	i=0;
	tempNode = list.head;
	printf ("node[%d]: %p, %d \n", i, tempNode , tempNode->data);

	while (tempNode) {
		if (i==0) {
			tempNode = (node_t*) ((int)node[i].link ^ (int)NULL);
			printf ("node[%d]: %p, %d \n", i+1, tempNode , tempNode->data);
		}
		else if (i==3) {
			tempNode = (node_t*) ((int)node[i].link ^ (int)&node[i-1]);
		}
		else {
			tempNode = (node_t*) ((int)node[i].link ^ (int)&node[i-1]);
			printf ("node[%d]: %p, %d \n", i+1, tempNode , tempNode->data);
		}
		i++;
	}
	printf("\n\n");
	
	/*
	tempNode = list.head;
	printf ("node[%d]: %p, %d \n", 0, tempNode , tempNode->data);

	tempNode = (node_t*)((int)node[0].link ^ (int)NULL);
	printf ("node[%d]: %p, %d \n", 1, tempNode , tempNode->data);

	tempNode = (node_t*)((int)node[1].link ^ (int)&node[0]);
	printf ("node[%d]: %p, %d \n", 2, tempNode , tempNode->data);

	tempNode = (node_t*)((int)node[2].link ^ (int)&node[1]);
	printf ("node[%d]: %p, %d \n", 3, tempNode , tempNode->data);



	tempNode = (node_t*)((int)node[3].link ^ (int)&node[2]);
	printf ("node[%d]: %p \n", 4, tempNode);
	
	if (tempNode) printf("ok\n");
	else printf("no\n");

	*/
	//
	/*
	tempNode = nodeTail;
	printf ("node[%d]: %p, %d \n", 3, tempNode , tempNode->data);


	tempNode = (node_t*)((int)node[3].link ^ (int)NULL);
	printf ("node[%d]: %p, %d \n", 2, tempNode , tempNode->data);



	tempNode = (node_t*)((int)node[2].link ^ (int)&node[3]);
	printf ("node[%d]: %p, %d \n", 1, tempNode , tempNode->data);

	tempNode = (node_t*)((int)node[1].link ^ (int)&node[2]);
	printf ("node[%d]: %p, %d \n", 0, tempNode , tempNode->data);



	tempNode = (node_t*)((int)node[0].link ^ (int)&node[1]);
	printf ("node[%d]: %p \n", 0, tempNode);
	*/
	
	
	i--;
	tempNode = nodeTail;
	printf ("node[%d]: %p, %d \n", i, tempNode , tempNode->data);

	while (tempNode) {
		if (i==3) {
			tempNode = (node_t*) ((int)node[i].link ^ (int)NULL);
			printf ("node[%d]: %p, %d \n", i-1, tempNode , tempNode->data);
		}
		else if (i==0) {
			tempNode = (node_t*) ((int)node[i].link ^ (int)&node[i+1]);
		}
		else {
			tempNode = (node_t*) ((int)node[i].link ^ (int)&node[i+1]);
			printf ("node[%d]: %p, %d \n", i-1, tempNode , tempNode->data);
		}
		i--;
	}
	


	return 0;
}