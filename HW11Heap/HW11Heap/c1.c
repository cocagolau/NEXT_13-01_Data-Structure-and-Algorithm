/*
	작성일: 13년 5월 20일 오전 11시 46분
	작성자: 서동규
	내  용: head자료구조 실습 및 연습
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

	// 함수 test
	test_makeSampleMaxHeap ();

	newHeap = makeSampleHeap (12);

	// MaxHeap 검사
	resultHeap = isMaxHeap (newHeap);
	
	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);
	printf ("\n");


	// maxHeap root 강제 변환 후 MaxHeap 검사
	newHeap->element[1] = 0;

	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);


	// max_heapify 진행
	max_heapify (newHeap, 1);
	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);



	// 동적 메모리 해제
	freeMaxHeap (newHeap);



	return 0;
}

heap_t *allocMaxHeapWithCapacity (int capacity) {

	heap_t *newHeap;

	// newHeap에 동적 메모리 할당
	newHeap = (heap_t*) malloc (sizeof(heap_t));
	if (!newHeap) return (heap_t*) NULL;

	// newHeap->capacity에 capacity를 저장
	newHeap->capacity = capacity;

	// newHeap->element에 (int*) capacity+1 만큼 동적 메모리 할당
	newHeap->element = (int*) malloc (sizeof(int)*(capacity+1));
	if (!newHeap->element) {
		free (newHeap);	
		return (heap_t*) NULL;
	}

	// newHeap 반환
	return newHeap;
}

void freeMaxHeap (heap_t *heap) {

	// heap 존재하지 않을 경우 return
	if (!heap) return;

	// heap->element 존재시 free
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

	// heap->element[1] ~ heap->element[heap->size] 값 출력
	for (i=1; i<=heap->size; i++) {
		printf ("%2d ", heap->element[i]);
	}
	printf ("\n");

	return;
}

heap_t *makeSampleHeap (int size) {

	heap_t *newHeap;
	int i;

	// newHeap에 capacity만큼 동적 메모리 할당
	newHeap = allocMaxHeapWithCapacity (64);
	if (!newHeap) return (heap_t*) NULL;

	// newHeap->size에 size저장
	newHeap->size = size;

	// max-heap 속성을 만족하는 값 저장
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

	// heap 특성 불만족시 0반환
	if (verify) return 0;

	return 1;
}

void test_makeSampleMaxHeap (void) {

	heap_t *newHeap;
	int resultHeap;

	newHeap = makeSampleHeap (12);

	// MaxHeap 검사
	resultHeap = isMaxHeap (newHeap);
	
	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);
	printf ("\n");

	// maxHeap root 강제 변환 후 MaxHeap 검사
	newHeap->element[1] = 0;

	resultHeap = isMaxHeap (newHeap);

	if (resultHeap) printf ("Correct Heap \n");
	else printf ("Incorrect Heap \n");

	printHeap (newHeap);

	// 동적 메모리 해제
	freeMaxHeap (newHeap);
	
	return;
}


void max_heapify (heap_t *heap, int pos) {

	int temp;

	// heap이 존재하지 않거나 pos값이 더 이상 비교할 값이 없을 경우 반환
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

	// 교체될 필요가 없을 경우 반환
	else
		return;

	return;
}