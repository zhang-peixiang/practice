#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//�������������� A �� B ���������������й����ġ��������������ĳ��ȡ�

//��ʱ
//int findLength(int* A, int ASize, int* B, int BSize)
//{
//	if (ASize == 0 || BSize == 0)
//		return 0;
//	int i = 0;
//	int j = 0;
//	int ret = 0;
//	int count = 0;
//	int tmp = 0;
//
//	int a = 0;
//	int b = 0;
//
//	for (i = 0; i < ASize; i++)
//	{
//		for (j = 0; j < BSize; j++)
//		{
//			
//			if (A[i] == B[j])
//			{
//				ret = 0;
//				a = i;
//				b = j;
//				while (a < ASize && b < BSize)
//				{
//					
//					if (A[a] != B[b])
//						break;
//					ret++;
//					a++;
//					b++;
//				}
//				if (ret>count)
//				{
//					count = ret;
//				}
//			}
//		
//		}
//	}
//	return count;
//}

//��̬�滮

/*
1.����һ����ΪASize+1����ΪBSize+1�Ķ�ά����
2.����ά����ĵ�һ�к͵�һ����Ϊ0��Ϊ�˷������arr[i][j]=arr[i-1][j-1]+1 
3.������������бȽϣ����A[i-1]=B[j-1]����arr[i][j]λ�õ�����������б�Ϸ�ֵ+1������arr[i][j]=arr[i-1][j-1]+1 
4��ȡ����arr[i][j] ��Ϊ����ֵ
*/


int findLength(int* A, int ASize, int* B, int BSize)
{
	int i = 0;
	int j = 0;

	int ret = 0;
	int count = 0;

	int arr[ASize + 1][BSize + 1];
	for (i = 0; i < ASize+1; i++)
	{
		arr[i][0] = 0;
	}
	for (j = 0; j < BSize + 1; j++)
	{
		arr[0][j] = 0;
	}

	for (i = 1; i < ASize + 1; i++)
	{
		for (j = 1; j < BSize + 1; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = 0;
			}
			int ret = arr[i][j];
			if (ret > count)
				count = ret;
		}
	}
	return count;
}


int main()
{
	int arr1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int arr2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int ret = findLength(arr1,10, arr2,10);
	return 0;
}