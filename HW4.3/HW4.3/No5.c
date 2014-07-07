#include <stdio.h>

int* bsearch (int list[],int key, int left, int right, int list_result[]); //binary search �Լ�����
int L_bsearch(int list[], int left, int right, int last);                  //������ ã�� �Լ�����
int R_bsearch(int list[], int left, int right, int last);
int main(void)
{
	int list[] = {1,3,5,7,7,7,9,10,10,10,10,10,10,10,11,15,20};   // �������� �迭
	int list_size = sizeof(list) / sizeof(int);                   // �迭 ũ��
	int list_result[3]={-1,};
	int i, key;

	printf("Input : ");
	scanf("%d", &key);

	bsearch(list, key, 0, list_size,list_result);                 // list�� key�� 0������ listũ�⸸ŭ ����

	for(i=0; i<3; i++){
		printf("%d \n", list_result[i]);
	}

	return 0;
}

int* bsearch (int list[], int key, int left, int right, int list_result[])            
{
	int mid = left + (right - left)/2;                           // mid�Լ��� �߰��� ����, �����÷ο� �������� ��� ����

	if(left > right){                                            // ������ �ε����� ���� �ε������� �۾��� ã�� �Ҵ��� ���
		return list_result;                                      // -1 ����
	}
	else{                                                        // ã�� ���� ���� ���
		if(key == list[mid]){                                    // key�� mid���� ���� ���� ���
			list_result[0] = L_bsearch(list, left, mid-1, mid);  // �ּ� �ߺ����� �ִ��� ã�� �Լ� ���� (L_bsearch)
			list_result[1] = R_bsearch(list, mid+1, right, mid);
			list_result[2] = list_result[1] - list_result[0] +1;
			return list_result;
		}
		else if(key > list[mid]){                                // �������� �迭���� key������ mid���� Ŭ��� �߰��� ���� ������ �κи� �˻��ʿ�
			bsearch(list, key, mid+1, right,list_result);        // ���ȣ��, left -> mid+1
		}
		else{                                                    // �߰��� ���� ���ʺκ� �˻� �ʿ��
			bsearch(list, key, left, mid-1, list_result);        // ���ȣ��, right -> mid-1
		}
	}
}

int L_bsearch(int list[], int left, int right, int last)
{
	int mid = left + (right - left) / 2;                    // �߰��� ����
	if(left>right){                                         // ã������ ���� ���
		return last;                                        // ������ �� ��ȯ
	}
	else{
		if(list[last] != list[mid]){                        // �߰����� ������ ����key ���� �ٸ� ���
			if(list[last] == list[mid+1]){                  // ������key���� �߰��� �ٷ� �����ʰ��� ������ ��
				return mid+1;                               // ������ �߰� �����ʰ� ��ȯ
			}
			else{                                           // ������key���� �߰��� �ٷ� ������ ���� �ٸ����
				L_bsearch(list, mid+1, right, last);        // ������ �κ� �˻�, ���ȣ��
			}
		}
		else{                                               // �߰����� ������ ����key ���� ���� ���
			last = mid;                                     // �������� ������ �߰����� �Է�
			L_bsearch(list, left, mid-1, last);             // ���� �κ� �˻�, ���ȣ��
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