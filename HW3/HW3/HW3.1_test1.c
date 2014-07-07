#include<stdio.h>

int bsearch(int list[], int left, int right, int key);

int main(void)
{
	int list[]={1,2,4,6,10,100,500,1000};
	int list_size = sizeof(list) / sizeof(int);
	int num,result;

	printf("input : ");
	scanf("%d", &num);

	result = bsearch(list, 0, list_size-1, num);

	printf("%d", result);

	return 0;
}

int bsearch(int list[], int left, int right, int key)
{
	int mid = (left+right)/2;

	if(left>right){
		return -1;
	}
	else{
		if(key == list[mid]){
			return mid;
		}
		else if(key > list[mid]){
			bsearch(list, mid+1, right, key);
		}
		else{
			bsearch(list, left, mid-1, key);

		}
	}
}