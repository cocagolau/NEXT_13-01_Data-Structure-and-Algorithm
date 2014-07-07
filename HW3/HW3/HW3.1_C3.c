/*
     �ۼ��� : 13.03.25 AM 5:37
     �ۼ��� : ������
     ������ : HW#3.1.C3
*/

#include<stdio.h>
#include<stdlib.h>

int horner(int list[], int x, int count, int list_size, int result);

int main(void)
{
	int* list = NULL;
	int list_size;
	int x, i, result;

	printf("List_size : ");
	scanf("%d", &list_size);

	printf("\nX �� �Է� : ");
	scanf("%d", &x);

	list = (int*)malloc(sizeof(int)*list_size);
	for(i=0; i<list_size; i++){
		printf("a[%d] �� �Է� : ",i);
		scanf("%d", list+i);
	}

	result= horner(list, x, 0, list_size, 0);
	printf("result : %d\n", result);

	free(list);
	list=NULL;

	return 0;
}

int horner(int list[], int x, int count, int list_size, int result)
{
	if(list_size-1 == count){
		return list[list_size-1];
	}
	result = horner(list,x,count+1, list_size, result)*x+list[count];
}