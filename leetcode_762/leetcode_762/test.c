#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int countPrimeSetBits(int L, int R)
{
	int count1 = 0;
	int count = 0;
	int i = L;
	for (i = L; i <= R; i++)
	{
		int a = i;
		while (a > 0)
		{
			if (a & 1 == 1)
			{
				count1++;
			}
			a = a >> 1;
		}

		if (count1 != 1)
		{
			if (count1 % 2 != 0 && count1 % 3 != 0)
			{
				count++;
			}
			else if (count1 == 2 || count1 == 3)
			{
				count++;
			}
		}
		count1 = 0;
	}
	return count;
}

int main()
{
	// 2 3 5  7 11 13 17 19 
	int a = countPrimeSetBits(842, 888);
	return 0;
}