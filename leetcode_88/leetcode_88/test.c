#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	assert(nums1 &&nums2);
	int i = 0;
	int count1 = 0;
	int count2 = 0;
	int count = m + n - 1;
	while (count>=0)
	{
		if (nums1[m - 1] > nums2[n - 1])
		{
			nums1[count--] = nums1[m - 1];
			m--;
		}
		else
		{
			nums1[count--] = nums2[n - 1];
			n--;
		}
	}
}

int main()
{

	return 0;
}