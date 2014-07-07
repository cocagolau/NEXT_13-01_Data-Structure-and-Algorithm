#include<stdio.h>

void sort(int* list, int n);
void swap(int* i, int* j);

int main(void)
{
	int list[]={5,6,2,7,9,1};
	int list_size = sizeof(list)/sizeof(int);
	int i;

	sort(list, list_size);
	for(i=0; i<list_size; i++){
		printf("%d", list[i]);
	}
	printf("\n");

	return 0;
}

void sort(int* list, int n)
{
	int i,j;
	int min;

	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(list[min] > list[j]){
				min = j;
			}
		}
		swap(&list[i], &list[min]);
	}
}

void swap(int* i, int* j)
{
	int temp = *j;
	*j = *i;
	*i = temp;
}