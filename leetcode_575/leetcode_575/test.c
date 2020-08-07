#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}



//三数取中法-----快排里面的基准值取三数中最中间的数
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid]>array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;

	}
}

//常规法
int Partion1(int* array, int left, int right)
{
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin<end)
	{
		while (begin<end && array[begin] <= key)
		{
			begin++;
		}
		while (begin<end && array[end] >= key)
		{
			end--;
		}
		if (begin<end)
		{
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right - 1)
	{
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}

//挖坑法
int Partion2(int* array, int left, int right)
{
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int begin = left;
	int end = right - 1;
	int key = array[end];
	while (begin < end)
	{
		//end位置形成了一个新的坑
		// 让begin从前往后找比基准值大的元素
		while (begin < end && array[begin] <= key)
			begin++;
		// 让begin位置大的元素填end位置的坑
		if (begin < end)
			array[end--] = array[begin];

		//begin位置形成了一个新的坑
		// 让end从后往前找比基准值小的元素，填begin位置的坑
		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			array[begin++] = array[end];
	}
	//用基准值填最后的一个坑
	if (begin != right - 1)
		array[begin] = key;
	return begin;
}

//双指针法
int Partion3(int* array, int left, int right)
{
	//采用三数取中法降低取到极值的概率
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int cur = left;
	int prev = left - 1;
	int key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur) //++prev 标记的是比key大的数  cur标记的是比key小的数
			Swap(&array[cur], &array[prev]);
		cur++;
	}

	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);
	return prev;
}

//快速排序
//[left,right] 表示待排序元素的区间
void QuickSort(int* array, int left, int right)
{

	if (right - left>1)
	{
		//Partion按照基准值（就是区间中的某个元素）对区间进行划分成两部分，左部分元素比基准值小，右侧部分比基准值大
		//该函数返回基准值在区间中的位置
		//[left,right] 区间中的基准值位置已经存放好了，基准值左侧和右侧不一定有序
		int div = Partion2(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}



int distributeCandies(int* candies, int candiesSize)
{
	int i = 0;
	int count = 1;
	if (candiesSize == 0 || candiesSize == 2)
		return candiesSize / 2;
	QuickSort(candies, 0, candiesSize);
	for (i = 0; i < candiesSize - 1; i++)
	{
		if (candies[i] != candies[i + 1])
		{
			count++;
		}
	}
	return candiesSize / 2<count ? candiesSize / 2 : count;
}

