/*
     작성일 : 13.03.15 PM 16:55
     작성자 : 서동규
     과제명 : HW#2.2.C2
     프로그램 소개: 변수간 값을 교환하는 프로그램
*/

#include<stdio.h>

void swap(int* a, int* b);  //사용자 함수 swap 선언, int형 포인터변수 a,b를 입력받아 swap함수 수행 후 void형 출력

int main(void)
{
	int i=10, j=20;         // int형 변수 i,j를 생성 후 각각 10, 20으로 초기화

	printf("main() : i=%d, j=%d \n", i,j);    // 10진 정수타입으로 i와 j의 값을 출력
	swap(&i, &j);                             // i의 주소값 (&i)과 j의 주소값(&j)으로 swap함수 호출
	printf("main() : i=%d, j=%d \n", i,j);    // 함수 실행 후, 10진 정수타입으로 i와 j의 값을 출력

	return 0;
}

void swap(int* a, int* b)   //사용자 함수 swap 정의, 포인터변수 a와 b가 생성되고 각각 &i와 &j를 저장
{
	int temp;        //int형 변수 temp 생성
	temp = *a;       //*연산자를 통해 a(==&i) i의 값을 간접참조(*a == *&i) 후 그 값을 temp에 대입
	*a = *b;         //위와 같은 방법으로, j변수의 값을 i변수에 대입 
	*b = temp;       //temp에 저장된 i변수의 값을 j변수에 대입
}                    //함수 종료시 포인터변수 a, 포인터변수 b, temp변수 소멸