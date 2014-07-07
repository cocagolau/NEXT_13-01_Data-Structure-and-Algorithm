#include <stdio.h>

int print_combination();
void run_print(char * array, int size);
int i[100] = {NULL};

int main(void)
{
	int j, size = 0;
	char array[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	
	size = sizeof(array);

	printf("\norigin array is : \n");
	for(j = 0; j < size; j ++)
		printf(" %c ", * (array + j));
	printf("\n\n");

	run_print(array, size);

	return 0;
}

int print_combination(char * array, int size, int start, int count, int count_max)
{
	int index;

	for(i[count] = start; i[count] < size; i[count] ++)
	{
		if(count == count_max)
		{
			for(index = 0; index <= count_max; index ++)
				printf("%c ", array[i[index]]);
			printf("\n");
		}
		else
			print_combination(array, size, i[count] + 1, count + 1, count_max);
	}

	return 0;
}

void run_print(char * array, int size)
{
	int start = 0, count = 0, count_max = 0;
	for(count_max = 0; count_max < size; count_max ++)
		print_combination(array, size, start, count, count_max);
}