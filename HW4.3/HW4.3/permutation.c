#include <stdio.h>

void perm (int list[], int start, int end);
void swap (int* i, int* j);

int main(void)
{
	int list[] = {'A','B','C'};
	int list_size = sizeof(list) / sizeof(int);

	perm (list, 0, list_size);

	return 0;
}

void perm(int list[], int start, int end)
{
	int i;

	if (start == end) {
		for(i=0; i<3; i++){
			printf("%c", list[i]);
		}
		printf("\n");
	}
	else {
		for (i = start; i < end; i++) {
			swap (&list[start], &list[i]);
			perm (list, start+1, end);
			swap (&list[i], &list[start]);
		}
	}
}

void swap (int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}