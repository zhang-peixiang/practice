#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

int cmp(int* left, int* right)
{
	return *left - *right;
}

int majorityElement(int* nums, int numsSize)
{
	int i = 0;
	int count = 1;
	qsort(nums, numsSize, sizeof(int), cmp);
	int tmp = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] == tmp)
		{
			count++;
		}
		else
		{
			count = 1;
			tmp = nums[i];
		}
		if (count > numsSize / 2)
		{
			break;
		}
	}
	return tmp;
}

int main()
{
	int arr[] = { 6,5,5 };
	int a = majorityElement(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}