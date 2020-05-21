#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�


int removeDuplicates(int* nums, int numsSize)
{
	assert(nums);
	if (numsSize < 2)
	{
		return numsSize;
	}
	int i = 0;
	int count = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[count] != nums[i])
		{
			nums[++count] = nums[i];
		}
	}
	return ++count;
}


int main()
{
	int nums[] = { 1, 1, 2 };
	int sz = sizeof(nums) / sizeof(nums[1]);
	int ret = removeDuplicates(nums, sz);
	printf("%d\n", ret);
	return 0;
}