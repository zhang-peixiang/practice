#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ������ 0, 1, 2, ..., n �� n ���������У��ҳ� 0 .. n ��û�г����������е��Ǹ�����
//int missingNumber(int* nums, int numsSize)//��ʱ
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < numsSize; i++)//ð�����򣬴�С��������
//	{
//		int ret = 0;
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j]>nums[j + 1])
//			{
//				ret = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = ret;
//			}
//		}
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		
//		if (nums[i] - i != 0)
//		{
//			return i ;
//		}
//	}
//
//}
//������Ǵ�0��ʼ�����飬����λ�þ͵���λ���ϵ���
//����һ��
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize; i++)//i��ʾλ��
//	{
//		for (j = 0; j < numsSize; j++)
//		{
//			if (nums[j] == i)//֤��������������������ѭ��
//			{
//				break;
//			}
//		}
//		if (j == numsSize)//���������û�ҵ�i������ȱʧi
//		{
//			return i;
//		}
//	}
//	return i;//֤��ÿ�����ֶ���ȱ�٣�����numsSize������[0,1] ����2.
//}
//�����������������
int missingNumber(int* nums, int numsSize)
{
	int i = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum1 += i;
		sum2 += nums[i];
	}
	if (sum2 - sum1 == 0)
	{
		return numsSize;
	}
	else
	{
		int ret = abs(sum1 - sum2);
		return numsSize - ret;
	}
}

int main()
{
	int arr[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = missingNumber(arr, sz);
	printf("%d\n", ret);
	return 0;
}