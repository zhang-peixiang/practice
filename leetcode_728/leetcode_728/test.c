#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 自除数 是指可以被它包含的每一位数除尽的数。
// 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
// 还有，自除数不允许包含 0 。
// 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。



int* selfDividingNumbers(int left, int right, int* returnSize)
{
	int sz = right - left + 1;
	int* rz = (int*)malloc(sizeof(int)*sz);
	int a = 0;
	int tmp = 0;
	int k = 0;
	while (left <= right)
	{
		k = left;

		while (k)
		{
			tmp = k % 10;
			if (tmp == 0)
			{
				break;
			}
			if (left % tmp != 0)
			{
				break;
			}
			if (k / 10 == 0)
			{
				rz[a++] = left;
			}
			k /= 10;
		}
		left++;
	}
	*returnSize = a;
	return rz;
}


int main()
{
	int a = 1;
	int b = 22;
	int c = 0;
	int* d = selfDividingNumbers(99, 190, &c);
	return 0;
}