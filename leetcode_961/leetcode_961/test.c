#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// �ڴ�СΪ 2N ������ A ���� N + 1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
// �����ظ��� N �ε��Ǹ�Ԫ�ء�


int cmp(int* left, int* right)
{
	return *left - *right;
}


int repeatedNTimes(int* A, int ASize)
{
	qsort(A, ASize, sizeof(int), cmp);
	int i = 0;
	int n = 0;
	for (i = 0; i < ASize-1; i++)
	{
		if (A[i] == A[i + 1])
		{
			break;
		}
	}

	return A[i];
}