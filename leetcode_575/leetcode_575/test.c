#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}



//����ȡ�з�-----��������Ļ�׼ֵȡ���������м����
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

//���淨
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

//�ڿӷ�
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
		//endλ���γ���һ���µĿ�
		// ��begin��ǰ�����ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;
		// ��beginλ�ô��Ԫ����endλ�õĿ�
		if (begin < end)
			array[end--] = array[begin];

		//beginλ���γ���һ���µĿ�
		// ��end�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ���beginλ�õĿ�
		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
			array[begin++] = array[end];
	}
	//�û�׼ֵ������һ����
	if (begin != right - 1)
		array[begin] = key;
	return begin;
}

//˫ָ�뷨
int Partion3(int* array, int left, int right)
{
	//��������ȡ�з�����ȡ����ֵ�ĸ���
	int keyofindex = GetMiddleIndex(array, left, right);
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int cur = left;
	int prev = left - 1;
	int key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur) //++prev ��ǵ��Ǳ�key�����  cur��ǵ��Ǳ�keyС����
			Swap(&array[cur], &array[prev]);
		cur++;
	}

	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);
	return prev;
}

//��������
//[left,right] ��ʾ������Ԫ�ص�����
void QuickSort(int* array, int left, int right)
{

	if (right - left>1)
	{
		//Partion���ջ�׼ֵ�����������е�ĳ��Ԫ�أ���������л��ֳ������֣��󲿷�Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
		//�ú������ػ�׼ֵ�������е�λ��
		//[left,right] �����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ�����Ҳ಻һ������
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

