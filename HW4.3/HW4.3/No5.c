#include <stdio.h>

int* bsearch (int list[],int key, int left, int right, int list_result[]); //binary search 함수선언
int L_bsearch(int list[], int left, int right, int last);                  //같은값 찾는 함수선언
int R_bsearch(int list[], int left, int right, int last);
int main(void)
{
	int list[] = {1,3,5,7,7,7,9,10,10,10,10,10,10,10,11,15,20};   // 오름차순 배열
	int list_size = sizeof(list) / sizeof(int);                   // 배열 크기
	int list_result[3]={-1,};
	int i, key;

	printf("Input : ");
	scanf("%d", &key);

	bsearch(list, key, 0, list_size,list_result);                 // list의 key와 0번부터 list크기만큼 전달

	for(i=0; i<3; i++){
		printf("%d \n", list_result[i]);
	}

	return 0;
}

int* bsearch (int list[], int key, int left, int right, int list_result[])            
{
	int mid = left + (right - left)/2;                           // mid함수에 중간값 설정, 오버플로우 막기위한 방법 설정

	if(left > right){                                            // 오른쪽 인덱스가 왼쪽 인덱스보다 작아져 찾기 불능일 경우
		return list_result;                                      // -1 리턴
	}
	else{                                                        // 찾을 값이 있을 경우
		if(key == list[mid]){                                    // key와 mid값을 비교해 같을 경우
			list_result[0] = L_bsearch(list, left, mid-1, mid);  // 최소 중복값이 있는지 찾는 함수 실행 (L_bsearch)
			list_result[1] = R_bsearch(list, mid+1, right, mid);
			list_result[2] = list_result[1] - list_result[0] +1;
			return list_result;
		}
		else if(key > list[mid]){                                // 오름차순 배열에서 key값보다 mid값이 클경우 중간값 기준 오른쪽 부분만 검색필요
			bsearch(list, key, mid+1, right,list_result);        // 재귀호출, left -> mid+1
		}
		else{                                                    // 중간값 기준 왼쪽부분 검색 필요시
			bsearch(list, key, left, mid-1, list_result);        // 재귀호출, right -> mid-1
		}
	}
}

int L_bsearch(int list[], int left, int right, int last)
{
	int mid = left + (right - left) / 2;                    // 중간값 지정
	if(left>right){                                         // 찾을값이 없을 경우
		return last;                                        // 마지막 값 반환
	}
	else{
		if(list[last] != list[mid]){                        // 중간값과 마지막 동일key 값이 다를 경우
			if(list[last] == list[mid+1]){                  // 마지막key값과 중간값 바로 오른쪽값과 같은지 비교
				return mid+1;                               // 같으면 중간 오른쪽값 반환
			}
			else{                                           // 마지막key값과 중간값 바로 오른쪽 값과 다를경우
				L_bsearch(list, mid+1, right, last);        // 오른쪽 부분 검색, 재귀호출
			}
		}
		else{                                               // 중간값과 마지막 동일key 값이 같을 경우
			last = mid;                                     // 마지막값 변수에 중간값을 입력
			L_bsearch(list, left, mid-1, last);             // 왼쪽 부분 검색, 재귀호출
		}
	}
}

int R_bsearch(int list[], int left, int right, int last)
{
	int mid = left + (right - left) / 2;
	if(left>right){
		return last;
	}
	else{
		if(list[last] != list[mid]){
			if(list[last] == list[mid-1]){
				return mid-1;
			}
			else{
				L_bsearch(list, left, mid-1, last);
			}
		}
		else{
			last = mid;
			L_bsearch(list, mid+1, right, last);
		}
	}
}