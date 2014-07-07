/*
     작성일 : 13.03.24 PM 3:19
     작성자 : 서동규
     과제명 : HW#3.1.C1(3)
*/

#include<stdio.h>

int bsearch(int list[], int left, int right, int key);
int SameValue_left(int list[], int index);
int SameValue_right(int list[], int index);

int main(void)
{
	int list[]={4,4,4,4,4,4,4,4,5,5,5};
	int list_size = sizeof(list) / sizeof(int);
	int key, result;

	printf("Input : ");
	scanf("%d", &key);

	result = bsearch(list, 0, list_size-1, key);

	printf("Output : %d\n", result);

	return 0;
}

int bsearch(int list[], int left, int right, int key)
{
	int mid = left+ (right-left) / 2;
	int SV_left, SV_right, result;

	if(left>right){
		return -1;
	}
	else{
		if(key == list[mid]){
			SV_left = SameValue_left(list, mid);
			SV_right = SameValue_right(list, mid);
			result = SV_right - SV_left +1;
			return result;
		}
		else if(key > list[mid]){
			bsearch(list, mid+1, right, key);
		}
		else{
			bsearch(list, left, mid-1, key);
		}
	}
}

int SameValue_left(int list[], int index)
{
	if(list[index] != list[index-1]){
		return index;
	}
	else{
		SameValue_left(list, index-1);
	}
}

int SameValue_right(int list[], int index)
{
	if(list[index] != list[index+1]){
		return index;
	}
	else{
		SameValue_right(list, index+1);
	}
}