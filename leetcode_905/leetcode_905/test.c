#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�


//˼·������ڿӷ�
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	int begin = 0;
	int end = ASize - 1;
	*returnSize = ASize;
	if (ASize == 1)
		return A;
	while (begin < end)
	{
		while (begin < end && A[begin] % 2 == 0)
		{
			begin++;
		}
		while (begin < end && A[end] % 2 == 1)
		{
			end--;
		}
		if (begin < end)
		{
			int tmp = A[begin];
			A[begin++] = A[end];
			A[end--] = tmp;
		}
	}
	return A;
}