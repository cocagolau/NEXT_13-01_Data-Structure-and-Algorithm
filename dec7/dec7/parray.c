#include <stdio.h>
#include <stdlib.h>

int ** make2dArray(int rows, int cols)
{
	int **arr, i;

	arr = (int **) malloc (sizeof(int*) * rows);

	for (i=0; i<rows; i++){
		arr[i] = (int *) malloc (sizeof(int) * cols);
	}

	return arr;
}

int main(void)
{
	int ** twoDimArr;
	int rid, cid;
	
	twoDimArr = make2dArray(3,5);

	for (rid=0; rid<3; rid++) {
		for (cid=0; cid<5; cid++) {
			twoDimArr[rid][cid] = 5*rid+rid;
			printf("%d", twoDimArr[rid][cid]);
		}
		printf("\n");
	}

	free(twoDimArr);
	twoDimArr = NULL;

	return 0;
}