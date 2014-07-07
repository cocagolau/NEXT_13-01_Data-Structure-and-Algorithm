/*
	작성일 : 2013.3.30
	작성자 : ㅇㅇㅇ
	과제명 : HW#3.1.C2
*/

#include <stdio.h>
#include <stdlib.h>

//================================================================
// 전방 함수 선언
//================================================================
void all_combination(const int n, const char * list);
void n_combination(const int n, const char * list, int * select_list, const int k, const int position);

//================================================================
// 테스트용 메인 함수
//================================================================
int main(void)
{
	char list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-";		// 입력받기 귀찮아서 미리 셋팅
	int n;

	//------------------------------------------------
	// Step 1: 입력 받기
	printf("input n = ");
	scanf("%d", &n);

	//------------------------------------------------
	// Step 2: 문제 해결
	all_combination(n, list);
	printf("\n");

	return 0;
}

//================================================================
// 기능 구현
//================================================================
/**
 * 모든 조합(모든 길이)을 출력 해 주는 함수.
 * for문을 돌면서 길이 별로 n_combination() 함수를 한번 씩 호출 해 준다.
 *
 * 입력 :
 *		list	[in] A부터 n번째 글자까지 들어있는 문자 배열 (문자열 아님)
 *		n		[in] 전체 글자 갯수 n
 * 출력 : void
 */
void all_combination(const int n, const char * list)
{
	int * select_list;		// 조합의 글자들이 들어가는 배열. malloc()으로 할당한다.
	int i;					// for문을 위한 변수

	//------------------------------------------------
	// Step 1 : 조합을 출력하기 전에 저장 할 배열을 할당 받는다.
	select_list = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
	{
		select_list[i] = 0;		// 0으로 초기화
	}

	//------------------------------------------------
	// Step 2 : 길이 별로 나누어 n_combination() 함수를 호출한다.
	for(i = 1; i <= n; i++)
	{
		n_combination( n, list, select_list, i, 0 );
	}

	//------------------------------------------------
	// Step 3 : 배열 메모리를 해제한다.
	free(select_list);
}

/**
 * 길이가 k인 모든 조합을 출력 하는 함수
 * 재귀 함수를 돌면서 result_list에 선택여부 저장 하다가,
 * k개를 전부 선택되면 (종료 조건 1) 출력한다.
 * k개가 되기 전에 n에 도달하면 아무 일도 일어나지 않는다. (종료 조건 2)
 *
 * 입력 :
 *		n			[in] 전체 글자 갯수 n
 *		list		[in] A부터 n번째 글자까지 들어있는 문자 배열
 *		select_list	[in, out] 조합의 글자들이 들어가는 배열
 *		k			[in] 조합의 "남은" 부분의 길이
 *		position	[in] 현재 기준이 되고 있는 원래 집합의 문자의 위치
 */
void n_combination(const int n, const char * list, int * select_list, const int k, const int position)
{
	int i;

	if( k == 0 )
	{
		// 마지막 문자까지 선택 되었다면,
		// 지금까지 선택 한 문자들을 모두 출력한다.
		printf("{");
		for(i = 0; i < n; i++)
		{
			// 선택 된 문자들이 배열 중간중간 위치하므로,
			// 각각의 문자들이 존재하는지 확인 후 출력 한다.
			if( select_list[i] != 0 )
				printf("%c", list[i]);
		}
		printf("} ");
	}
	else if( position < n )
	{
		// 아직 선택 해야 할 갯수(k)도 남아 있고,
		// 선택 할 수 있는 문자들(position ~ n-1)이 남아 있다면,
		for(i = position; i < n; i++)
		{
			// position 부터 n-1(마지막)까지의 각각의 문자에 대해서,
			// select_list에 저장한 후, 이후는 재귀로 처리한다.
			// (재귀 : 남은 k는 1 줄어들고, 남은 position은 i+1)
			select_list[i] = 1;
			n_combination( n, list, select_list, k - 1, i + 1 );
			select_list[i] = 0;
		}
	}
}
