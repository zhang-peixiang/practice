#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ����һ���������� A������������е�ÿ��Ԫ�� A[i] ������һ���������� x �� - K <= x <= K�����Ӷ��õ�һ�������� B ��

// �������� B �����ֵ����Сֵ֮����ܴ��ڵ���С��ֵ��

int cmp(int* left, int* right)
{
	return *left - *right;
}
int smallestRangeI(int* A, int ASize, int K)
{
	int i = 0;
	qsort(A, ASize, sizeof(int), cmp);
	int tmp = A[ASize - 1] - A[0];
	if (tmp <= 2 * K)
	{
		return 0;
	}
	
	return tmp - 2 * K;
}


int main()
{
	int arr[] = { 0, 10 };
	int k = 2;
	int a = smallestRangeI(arr, 2, 2);
	return 0;
}