/*
	�ۼ���: 13�� 5�� 20�� ���� 11�� 46��
	�ۼ���: ������
	��  ��: head�ڷᱸ�� �ǽ� �� ����
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct head {
	int size;
	int capacity;
	int *element;
} heap_t;

heap_t *allocMaxHeapWithCapacity (int capacity);
void freeMaxHeap (heap_t *heap);
void printHeap (heap_t *heap);
heap_t *makeSampleHeap (int size);

void test_makeSampleMaxHeap (void);
int isMaxHeap (heap_t *heap);

void max_heapify (heap_t *heap, int pos);



// main
int main (void) {


	heap_t *newHeap;
	int resultHeap;

	// �Լ� test
	test_makeSampleMaxHeap ();

	newHeap = makeSampleHeap (12);

	// MaxHeap �˻�
	resultHeap = isMaxHeap (newHeap);
	
	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);
	printf ("\n");


	// maxHeap root ���� ��ȯ �� MaxHeap �˻�
	newHeap->element[1] = 0;

	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);


	// max_heapify ����
	max_heapify (newHeap, 1);
	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);



	// ���� �޸� ����
	freeMaxHeap (newHeap);



	return 0;
}

heap_t *allocMaxHeapWithCapacity (int capacity) {

	heap_t *newHeap;

	// newHeap�� ���� �޸� �Ҵ�
	newHeap = (heap_t*) malloc (sizeof(heap_t));
	if (!newHeap) return (heap_t*) NULL;

	// newHeap->capacity�� capacity�� ����
	newHeap->capacity = capacity;

	// newHeap->element�� (int*) capacity+1 ��ŭ ���� �޸� �Ҵ�
	newHeap->element = (int*) malloc (sizeof(int)*(capacity+1));
	if (!newHeap->element) {
		free (newHeap);	
		return (heap_t*) NULL;
	}

	// newHeap ��ȯ
	return newHeap;
}

void freeMaxHeap (heap_t *heap) {

	// heap �������� ���� ��� return
	if (!heap) return;

	// heap->element ����� free
	if (heap->element) {
		free (heap->element);
		heap->element = (int*) NULL;
	}

	// heap free
	free (heap);
	heap = (heap_t*) NULL;

	return;
}

void printHeap (heap_t *heap) {

	int i;

	// heap->element[1] ~ heap->element[heap->size] �� ���
	for (i=1; i<=heap->size; i++) {
		printf ("%2d ", heap->element[i]);
	}
	printf ("\n");

	return;
}

heap_t *makeSampleHeap (int size) {

	heap_t *newHeap;
	int i;

	// newHeap�� capacity��ŭ ���� �޸� �Ҵ�
	newHeap = allocMaxHeapWithCapacity (64);
	if (!newHeap) return (heap_t*) NULL;

	// newHeap->size�� size����
	newHeap->size = size;

	// max-heap �Ӽ��� �����ϴ� �� ����
	for (i=1; i<=size; i++) {
		newHeap->element[i] = size-i+1;
	}

	return newHeap;
}

int isMaxHeap (heap_t *heap) {

	int i, verify=0;

	for (i=1; i<heap->size; i++) {
		if (heap->element[i] < heap->element[i+1]) {
			verify = 1;
			break;
		}
	}

	// heap Ư�� �Ҹ����� 0��ȯ
	if (verify) return 0;

	return 1;
}

void test_makeSampleMaxHeap (void) {

	heap_t *newHeap;
	int resultHeap;

	newHeap = makeSampleHeap (12);

	// MaxHeap �˻�
	resultHeap = isMaxHeap (newHeap);
	
	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);
	printf ("\n");

	// maxHeap root ���� ��ȯ �� MaxHeap �˻�
	newHeap->element[1] = 0;

	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);

	// ���� �޸� ����
	freeMaxHeap (newHeap);
	
	return;
}


void max_heapify (heap_t *heap, int pos) {

	int temp;

	// heap�� �������� �ʰų� pos���� �� �̻� ���� ���� ���� ��� ��ȯ
	if (!heap || pos > heap->size) return;

	// leftChild
	if (heap->element[pos] < heap->element[2*pos]) {
		temp = heap->element[pos];
		heap->element[pos] = heap->element[2*pos];
		heap->element[2*pos] = temp;

		max_heapify (heap, 2*pos);
	}

	// rightChild
	else if (heap->element[pos] < heap->element[2*pos+1]) {
		temp = heap->element[pos];
		heap->element[pos] = heap->element[2*pos+1];
		heap->element[2*pos+1] = temp;

		max_heapify (heap, 2*pos+1);
	}

	// ��ü�� �ʿ䰡 ���� ��� ��ȯ
	else
		return;

	return;
}