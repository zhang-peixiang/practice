#define _CRT_SECURE_NO_WARNINGS 1


//给你一个整数数组 nums，请你将该数组升序排列。

int Partion(int* array, int left, int right)
{
	if (left == right)
		return;
	int begin = left;
	int end = right-1;
	int key = array[end];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		if (begin < end)
			array[end--] = array[begin];
		while (begin < end && array[end]>=key)
			end--;
		if (begin < end)
			array[begin++] = array[end];
	}
	if (begin != right - 1)
		array[begin] = key;
	
	return begin;
}


void QuickSort(int* array, int left, int right)
{
	if (right - left > 1)
	{
		int div = Partion(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	if (numsSize == 1)
		return nums;
	QuickSort(nums, 0, numsSize);
	return nums;
}


int main()
{
	int array[] = { 5, 2, 3, 1 };
	int a = 0;
	sortArray(array, 4, &a);

}