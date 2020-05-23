#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
/*
1.���ж��ƶ��Ĳ���
2.�ƶ�k�����ʹ���������λ�ÿ�ʼ��ǰ����k�����������ƶ�ʱ������
3.�������е�Ԫ�������ƶ�k��λ��Ҳ���ǽ�numsSize-k����ֵ�����ƶ�����numsSize-k-1λ�÷ŵ����һ��λ�ã�Ȼ��������ǰ��
4.�����ٵ������е�Ԫ�طŻ�nums���飬��0��ʼ��������š�
*/
void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize) //��k>=numsSize���ƶ��Ĳ���
	{
		k = k - numsSize;
	}
	int i = 0;
	int* arr = (int*)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)//
	{
		arr[i] = nums[numsSize - k + i];
	}
	//�������е�Ԫ�������ƶ�k��λ��Ҳ���ǽ�numsSize-k����ֵ�����ƶ�����numsSize-k-1λ�÷ŵ����һ��λ�ã�Ȼ��������ǰ��
	for (i = 0; i < numsSize - k; i++)
	{
		nums[numsSize - 1 - i] = nums[numsSize - k - 1 - i];
	}
	//�����ٵ������е�Ԫ�طŻ�nums���飬��0��ʼ��������š�
	for (i = 0; i < k; i++)
	{
		nums[i] = arr[i];
	}
	free(arr);
	arr = NULL;
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[1]);
	rotate(arr, sz, k);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}