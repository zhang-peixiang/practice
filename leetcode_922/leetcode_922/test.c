#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
	*returnSize = ASize;
	if (ASize == 1)
		return A;
	int fast = 0;
	int slow = 1;
	while (fast < ASize && slow < ASize)
	{
		while (fast < ASize && A[fast] % 2 == 0)
		{
			fast+=2;
		}

		while (slow < ASize && A[slow] % 2 == 1)
		{
			slow += 2;
		}

		if (fast < ASize && slow < ASize)
		{
			int tmp = A[fast];
			A[fast] = A[slow];
			A[slow] = tmp;
			fast += 2;
			slow += 2;
		}
	}

	return A;
}


int main()
{
	int arr[] = { 4, 2, 5, 7 };
	int a = 0;
	sortArrayByParityII(arr, 4, &a);
	return 0;
}
