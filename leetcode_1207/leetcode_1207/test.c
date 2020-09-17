#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const int* left, const int* right)
{
	return *left - *right;
}

bool uniqueOccurrences(int* arr, int arrSize)
{
	int i = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	int tmp = arr[i];
	int count = 1;
	int arr1[1000] = { 0 };
	for (i = 1; i < arrSize; i++)
	{
		if (tmp == arr[i])
		{
			count++;
		}
		else
		{
			arr1[count]++;
			count = 1;
			tmp = arr[i];
		}
	}
	if (arr[arrSize - 1] != arr[arrSize - 2])
	{
		arr1[1]++;
	}
	for (i = 0; i < 1000; i++)
	{
		if (arr1[i]>1)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int arr[6] = { 1, 2, 2, 1, 1, 3 };
	uniqueOccurrences(arr, 6);
	return 0;
}