#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ�����ǵݼ�˳��������������� A��
//����ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������

int cmp(const int* left, const int* right)
{
	return *left - *right;
}


int* sortedSquares(int* A, int ASize, int* returnSize)
{
	int i = 0;
	int tmp = 0;
	int* arr = (int*)malloc(sizeof(int)*ASize);
	for (i = 0; i < ASize; i++)
	{
		int b = A[i] * A[i];
		arr[tmp++] = b;
	}

	qsort(arr, ASize, sizeof(int), cmp);
	*returnSize = ASize;
	return arr;
}