/*
	�ۼ���: 13�� 5�� 12�� ���� 1�� 30��
	�ۼ���: ������
	���� : 10���� �ǽ� ����
*/

#include <stdio.h>
#include <stdlib.h>

void sampleArrayTest (int array[], int arraySize);
int *makeSampleArrayInIncreasingOrder (int num);
int *makeSampleArrayInDecreasingOrder (int num);
int *makeSampleArray (int num);
int *makeSampleArrayWithSameValue (int num, int key);


int main (void) {

	int *Array, *Array1, *Array2, *Array3;
	int num = 10, i;

	/* Increasing */
	Array = makeSampleArrayInIncreasingOrder (num);
	sampleArrayTest (Array, num);
	printf ("\n");

	printf ("Increasing \n");
	for (i=0; i<num; i++) {
		printf ("%d ", Array[i]);
	}
	printf ("\n\n");

	/* Decreasing */
	Array1 = makeSampleArrayInDecreasingOrder (num);
	sampleArrayTest (Array1, num);
	printf ("\n");

	printf ("Decreasing \n");
	for (i=0; i<num; i++) {
		printf ("%d ", Array1[i]);
	}
	printf ("\n");

	/* Array with random Number */
	Array2 = makeSampleArray (num);
	printf ("\n");

	printf ("Random Number \n");
	for (i=0; i<num; i++) {
		printf ("%d ", Array2[i]);
	}
	printf ("\n");


	/* Array with Same Value */
	Array3 = makeSampleArrayWithSameValue (num,777);
	printf ("\n");

	printf ("Same Value \n");
	for (i=0; i<num; i++) {
		printf ("%d ", Array3[i]);
	}
	printf ("\n");


	/* �޸� ���� */
	free (Array);
	Array = (int*) NULL;

	free (Array1);
	Array = (int*) NULL;

	free (Array2);
	Array2 = (int*) NULL;

	free (Array3);
	Array3 = (int*) NULL;

	return 0;
}

int *makeSampleArrayInIncreasingOrder (int num) {

	int *newArray;
	int i;

	newArray = (int*) malloc (sizeof(int)*num);
	if (!newArray) return (int*) NULL;

	for (i=0; i<num; i++)
		*(newArray+i) = i;


	return newArray;
}


int *makeSampleArrayInDecreasingOrder (int num) {

	int *newArray;
	int i;

	newArray = (int*) malloc (sizeof(int)*num);
	if (!newArray) return (int*) NULL;

	for (i=0; i<num; i++)
		*(newArray+i) = (num-1)-i;


	return newArray;
}

void sampleArrayTest (int array[], int arraySize) {
	
	int i=0;
	int max, min, distance;

	min = i;
	max = i;
	for (i=0; i<arraySize; i++) {
		if (array[min] > array[i]) min = i;
		if (array[max] < array[i]) max = i;

		if (i>=1 && i<arraySize) {
			distance = array[i] - array[i-1];
			printf ("Array[%d] - Array[%d] = %d \n", i, i-1, distance);
		}
	}
	printf ("\n");
	printf ("Min : Array[%d] = %d \n", min, array[min]);
	printf ("Max : Array[%d] = %d \n", max, array[max]);

	return;
}


int *makeSampleArray (int num) {
	int i;
	int *newArray;

	newArray = (int*) malloc (sizeof(int)*num);
	if (!newArray) return (int*) NULL;
	
	for (i=0; i<num; i++)
		*(newArray+i) = rand()%9999;

	return newArray;
}


int *makeSampleArrayWithSameValue (int num, int key) {

	int *newArray;
	int i;

	newArray = (int*) malloc (sizeof(int)*num);
	if (!newArray) return (int*) NULL;

	for (i=0; i<num; i++)
		*(newArray+i) = key;


	return newArray;
}