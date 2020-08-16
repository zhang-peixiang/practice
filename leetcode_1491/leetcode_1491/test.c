#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
// 给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
//
// 请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。

double average(int* salary, int salarySize)
{
	int low = salary[0];
	int hight = salary[0];
	
	double count = 0;
	int i = 0;
	for (i = 0; i < salarySize; i++)
	{
		if (low>salary[i])
			low = salary[i];
		if (hight < salary[i])
			hight = salary[i];

		count += (double)salary[i];
	}
	count = (double)(count - low - hight);

	return (double)(count / (salarySize - 2));
}

int main()
{
	int arr[] = { 1000, 2000, 3000 };
	double a = average(arr, 3);
	return 0;
}