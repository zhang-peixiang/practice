#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//������0��ʼ����ΪN������A������0��N - 1�������������ҵ����������ļ���S��S[i] = { A[i], A[A[i]], A[A[A[i]]], ... }���������µĹ���
//����ѡ������Ϊi��Ԫ��A[i]ΪS�ĵ�һ��Ԫ�أ�S����һ��Ԫ��Ӧ����A[A[i]]��֮����A[A[A[i]]]... �Դ����ƣ��������ֱ��S�����ظ���Ԫ�ء�


//erro ��ʱ
//int arrayNesting(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	int b = 0;
//	int* arr = (int*)calloc(numsSize+1 , sizeof(int));//���sԪ��
//	for (i = 0; i < numsSize; i++)
//	{
//	
//		int a = i;//����ֵ
//		int count = 0;//��¼s��arr�з��˼���Ԫ��
//		while (1)
//		{
//			a = nums[a];
//			arr[count] = a;
//			for (j = 0; j < count; j++)//���arr���Ƿ����ظ�Ԫ��
//			{
//				if (arr[j] == a)
//				{
//					break;
//				}
//			}
//			if (arr[j] == a && count != 0 && j != count)
//				//����whileѭ������ �����ظ���Ԫ�أ�����count���ܵ���0 ��j���ܵ���count��
//				//��count = jʱ��˵����һ��forѭ��û���ҵ��ظ���Ԫ��
//			{
//				break;
//			}
//			count++;
//		}
//		if (count > b)//��������countֵ
//		{
//			b = count;
//		}
//	}
//	return b;
//}
//��⣺
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



