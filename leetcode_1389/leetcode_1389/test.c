#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//���������������� nums �� index������Ҫ�������¹��򴴽�Ŀ�����飺
//
//Ŀ������ target ���Ϊ�ա�
//�������ҵ�˳�����ζ�ȡ nums[i] �� index[i]���� target �����е��±� index[i] ������ֵ nums[i] ��
//�ظ���һ����ֱ���� nums �� index �ж�û��Ҫ��ȡ��Ԫ�ء�
//���㷵��Ŀ�����顣
//
//��Ŀ��֤���ֲ���λ�����Ǵ��ڡ�



int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
{
	*returnSize = numsSize;
	int i = 0;
	int* ret = (int*)malloc(sizeof(int)*(numsSize + 1));
	for (i = 0; i < numsSize; i++)
	{
		if (i == index[i])
		{
			ret[i] = nums[i];
		}
		else
		{
			int j = 0;
			for (j = i + 1; j >index[i]; j--)
			{
				ret[j] = ret[j - 1];
			}
			ret[index[i]] = nums[i];
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 0, 1, 2, 3, 4 };
	int index[] = { 0, 1, 2, 2, 1 };
	int a = 0;
	createTargetArray(arr, 5, index, 5, &a);
	return 0;
}





