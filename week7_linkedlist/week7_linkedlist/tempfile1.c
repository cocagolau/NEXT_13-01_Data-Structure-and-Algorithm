#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *link;
}node_t;

typedef struct list {
	node_t *left;
	node_t *right;
}list_t;

node_t *createNode(void);
list_t *createList(void);

int main (void) {

	list_t *list;
	node_t *node;
	node_t *tempNode=(node_t*)NULL, *curNode=(node_t*)NULL;
	//int node_num=4;
	int i;

	list = (list_t*) malloc (sizeof(list_t));
	node = (node_t*) malloc (sizeof(node_t));


	tempNode = createNode();
	list->left = (node_t*) ((int)list->right ^ (int)tempNode);
	list->right = (node_t*) ((int)tempNode ^ (int)list->left);
	tempNode->data = 0;
	tempNode->link = (node_t*) ((int)list->left ^ (int)list->right);


	curNode = (node_t*)((int)list->left ^ (int)list->right);
	printf ("tempNode: %p, %d \n", curNode , curNode->data);
	tempNode = curNode;

	curNode = (node_t*)((int)curNode ^ (int)list->left);
	printf ("list->right: %p \n", curNode, curNode);

	curNode = (node_t*)((int)list->right ^ (int)tempNode);
	printf ("list->left: %p \n", curNode, curNode);



	/*
	list->left = node;

	node->data = 0;
	node->link = (node_t*)((int)Sentinel ^ (int)(node+1));

	(node+1)->data = 1;
	(node+1)->link = (node_t*)((int)node ^ (int)(node+2));

	(node+2)->data = 2;
	(node+2)->link = (node_t*)((int)(node+1) ^ (int)(node+3));

	(node+3)->data = 3;
	(node+3)->link = (node_t*)((int)(node+2) ^ (int)Sentinel);
	
	list->right = node+3; 
	// 

	tempNode = list->left;
	printf ("node[%d]: %p, %d \n", 0, tempNode , tempNode->data);

	tempNode = (node_t*)((int)node->link ^ (int)Sentinel);
	printf ("node[%d]: %p, %d \n", 1, tempNode , tempNode->data);

	tempNode = (node_t*)((int)(node+1)->link ^ (int)node);
	printf ("node[%d]: %p, %d \n", 2, tempNode , tempNode->data);

	tempNode = (node_t*)((int)(node+2)->link ^ (int)(node+1));
	printf ("node[%d]: %p, %d \n", 3, tempNode , tempNode->data);
	
	//
	printf("\n\n");
	tempNode = list->right;
	printf ("node[%d]: %p, %d \n", 3, tempNode , tempNode->data);

	tempNode = (node_t*)((int)(node+3)->link ^ (int)Sentinel);
	printf ("node[%d]: %p, %d \n", 2, tempNode , tempNode->data);

	tempNode = (node_t*)((int)(node+2)->link ^ (int)(node+3));
	printf ("node[%d]: %p, %d \n", 1, tempNode , tempNode->data);

	tempNode = (node_t*)((int)(node+1)->link ^ (int)(node+2));
	printf ("node[%d]: %p, %d \n", 0, tempNode , tempNode->data); */

	free(node);
	free(list);
	//free(Sentinel);

	return 0;
}


// Node持失
node_t *createNode(void) {

	node_t *newNode;
	//int data;

	/*
	printf(" - Input data : ");
	scanf("%d", &data); */

	newNode = (node_t*) malloc (sizeof(node_t));
	//newNode->data = data;

	return newNode;
}

// list 持失
list_t *createList(void) {

	list_t* list;

	list = (list_t*) malloc (sizeof(list_t));
	list->left = (node_t*)NULL;
	list->right = (node_t*)NULL;

	return list;
}