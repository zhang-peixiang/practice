#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ħ�������� ������A[0...n - 1]�У�����ν��ħ����������������A[i] = i��
//����һ�������������飬��дһ�ַ����ҳ�ħ�����������еĻ���������A���ҳ�һ��ħ��������
//���û�У��򷵻� - 1�����ж��ħ����������������ֵ��С��һ����




int findMagicIndex(int* nums, int numsSize)
{
	int i = 0;
	
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == i)
			return nums[i];
	}
	return -1;
}