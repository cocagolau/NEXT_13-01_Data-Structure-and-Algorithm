#include <stdio.h>

void comb (int list[], int list_size, int start);
void comb_count (int list[], int list_size, int start, int digit);

int main(void)
{
	int list[] = {'A','B', 'c'};
	int list_size = sizeof(list) / sizeof(int);

	comb (list, list_size, 0);

	return 0;
}

void comb(int list[],int list_size, int start, int count)
{
	int i;

	if (count == list_size-1) {
		for(i=0; i<3; i++){
			printf("%c",list[i]);
		}
	}

	for (i=start; i<list_size; i++) {
		comb_count (list, list_size, start, i);
	}
}

void comb_count (int list[], int list_size, int start, int digit)
{
	if(
}