#include<stdio.h>
#include<assert.h>

int bsearch(int arr[], int size, int key)
{
	int l=0,r=size-1,m;

	while(l<=r)
	{
		m = (l+r)/2;
		printf("l:%d m:%d r:%d <%d >%d\n", l, m, r, (*(arr+m) < key), (*(arr+m) > key)); 
		if(*(arr+m) == key)
			return m+1;
		l = l+((*(arr+m) < key)*(m+1-l));
		r = r-((*(arr+m) > key)*(m-1-l));
	}
	return -1;
}

int main(void)
{
	int arr[10] = {1,2,3,5,7,8,20,25,50,1000};
	int len = sizeof(arr) / sizeof(int);
	int key = 50;
	int pos = bsearch(arr,len,key);
	
	printf("%d\n", pos);



	return 0;
}