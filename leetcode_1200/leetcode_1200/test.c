#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//������������� arr������ÿ��Ԫ�ض� ����ͬ��
//
//�����ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�

int cmp(int* left, int* right)
{
	return *left - *right;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;
	int count = 0;
	int a = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	int low = arr[1] - arr[0];
	//����С��ֵ
	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] < low)
		{
			low = arr[i + 1] - arr[i];
		}
	}
	//ͳ����С��ֵ���м���
	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] == low)
		{
			count++;
		}
	}

	//���ٿռ�
	int** returnarr = (int**)malloc(sizeof(int*)*count);
	*returnColumnSizes = (int *)malloc(sizeof(int)*count);

	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] == low)
		{
			returnarr[a] = (int*)malloc(sizeof(int)* 2);
			returnarr[a][0] = arr[i];
			returnarr[a][1] = arr[i + 1];
			*(*returnColumnSizes + a) = 2;
			a++;
		}
	}
	*returnSize = count;
	
	return returnarr;
}



int main()
{
	int arr[] = { 4, 2, 1, 3 };
	int a = 0;
	int b = 0;
	int* p = &b;
	int** c= minimumAbsDifference(arr, 4, &a, &p);
	return 0;
}




