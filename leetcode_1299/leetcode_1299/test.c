#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ������ arr �����㽫ÿ��Ԫ�������ұ�����Ԫ���滻����������һ��Ԫ�أ��� -1 �滻��
//��������滻���������㷵��������顣
int* replaceElements(int* arr, int arrSize, int* returnSize)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < arrSize - 1; i++)
	{
		int a = arr[i+1];//��a����¼�����Ƚϵ����ֵ��
		for (j = i + 1; j < arrSize; j++)//��i�����һ��Ԫ�ؿ�ʼѭ�������ֵ
		{
			if (a < arr[j])
			{
				a = arr[j];
			}
		}
		arr[i] = a;
	}
	arr[arrSize - 1] = -1;
	*returnSize = arrSize;
	return arr;
}
int main()
{
	int arr[] = { 17, 18, 5, 4, 6, 1 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	int* ret = replaceElements(arr, sz, &sz);
	return 0;
}