#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到并返回最大的集合S，S[i] = { A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
//假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。


//erro 超时
//int arrayNesting(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	int b = 0;
//	int* arr = (int*)calloc(numsSize+1 , sizeof(int));//存放s元素
//	for (i = 0; i < numsSize; i++)
//	{
//	
//		int a = i;//索引值
//		int count = 0;//记录s向arr中放了几个元素
//		while (1)
//		{
//			a = nums[a];
//			arr[count] = a;
//			for (j = 0; j < count; j++)//检查arr中是否有重复元素
//			{
//				if (arr[j] == a)
//				{
//					break;
//				}
//			}
//			if (arr[j] == a && count != 0 && j != count)
//				//跳出while循环条件 出现重复的元素，并且count不能等于0 且j不能等于count，
//				//当count = j时，说明上一个for循环没有找到重复的元素
//			{
//				break;
//			}
//			count++;
//		}
//		if (count > b)//保存最大的count值
//		{
//			b = count;
//		}
//	}
//	return b;
//}
//题解：
//int arrayNesting(int* nums, int numsSize){
//	int max = 0, i, j, count = 0, temp;
//	for (i = 0; i<numsSize; i++){
//		for (j = i; nums[j] != -1;)
//		{
//			count++;
//			temp = nums[j];
//			nums[j] = -1;
//			j = temp;
//		}
//		if (max<count){
//			max = count;
//		}
//		count = 0;
//	}
//	return max;
//}

int arrayNesting(int* nums, int numsSize)
{
	int i = 0;
	int max = 0;
	int j = 0;
	for (i = 0; i < numsSize; i++)
	{
		int count = 0;
		for (j = i; nums[j] != -1;)
		{
			int ret = nums[j];
			nums[j] = -1;
			j = ret;
			count++;
		}
		if (max < count)
		{
			max = count;
		}
	}
	return max;
}


int main()
{
	int arr[] = { 1,2,0 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	int ret = arrayNesting(arr, sz);
	printf("%d\n", ret);
	return 0;
}



