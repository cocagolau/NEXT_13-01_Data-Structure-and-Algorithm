#include <stdio.h>
#include <stdlib.h>

int main (void) {

	int i,j;
	char a;

	for (i=1; i<=9; i++) {
		for (j=1; j<=9; j++) {
			printf ("%3d", i*j);
		}
		printf ("\n");
	}
	system("pause");
	return 0;
}