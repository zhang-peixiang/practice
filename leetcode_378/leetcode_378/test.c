#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ�� n x n ��������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е� k С��Ԫ�ء�
//��ע�⣬���������ĵ� k СԪ�أ������ǵ� k ����ͬ��Ԫ�ء�

//����һ��������
//int compare(int* a, int* b)
//{
//	return *a - *b;
//}
//
//int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
//	*matrixColSize = matrixSize;
//	int arr[1000000] = { 0 };
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	for (i = 0; i<matrixSize; i++)
//	{
//		for (j = 0; j<matrixSize; j++)
//		{
//			arr[a] = matrix[i][j];
//			a++;
//		}
//	}
//	qsort(arr, a, sizeof(arr[0]), compare);
//
//	return arr[k - 1];
//}


//����������ά����Ķ��ַ�
int check(int** matrix, int mid, int row, int col)
{
	int count = 0;
	int i = row - 1;
	int j = 0;
	while (i >= 0 && j < col)
	{
		if (matrix[i][j] <= mid)
		{
			j++;
			count = count + i + 1;
		}
		else
		{
			i--;
		}
	}
	return count;
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
	*matrixColSize = matrixSize;
	int left = matrix[0][0];
	int right = matrix[matrixSize - 1][matrixSize - 1];

	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		int ret = check(matrix, mid, matrixSize, *matrixColSize);
		if (ret< k)
		{
			left = mid + 1;
		}
		else if (ret == k)//�ɺ�else�ϲ���д�����������
		{
			right = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int main()
{
	int arr[][3] = { { 1, 5, 9 },
	{ 10, 11, 13 },
	{ 12, 13, 15 } };

	int a = 3;

	kthSmallest(arr, 3, &a, 8);
	return 0;
}