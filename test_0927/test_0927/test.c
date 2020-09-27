#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


#if 0
int main()
{
	int arr[7] = { 0 }; 
	int sum = 0;
	int a, b, c, d, e, f, g;
	while (scanf("%d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&g) != EOF)
	{
		int i = 0;
		int max1 = 0;
		int max2 = 0;
		int min = 0;
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		arr[4] = e;
		arr[5] = f;
		arr[6] = g;

		// 求最大值 次大值  最小值
		if (arr[4] > arr[5] && arr[4]>arr[6])
		{
			max1 = 4;
			if (arr[5] > arr[6])
			{
				max2 = 5;
				min = 6;
			}
			else
			{
				max2 = 6;
				min = 5;
			}
		}
		else if (arr[5] > arr[4] && arr[5] > arr[6])
		{
			max1 = 5;
			if (arr[4] > arr[6])
			{
				max2 = 4;
				min = 6;
			}
			else
			{
				max2 = 6;
				min = 4;
			}
		}
		else
		{
			max1 = 6;
			if (arr[4] > arr[5])
			{
				max2 = 4;
				min = 5;
			}
			else
			{
				max2 = 5;
				min = 4;
			}
		}

		// 计算价格
		if (arr[3] > arr[max1 - 4])
		{
			arr[3] -= arr[max1 - 4];
			sum += arr[max1 - 4] * arr[max1];
			if (arr[3] > 0)
			{
				if (arr[3] > arr[max2 - 4])
				{
					arr[3] -= arr[max2 - 4];
					sum += arr[max2 - 4] * arr[max2];
					if (arr[3] > 0)
					{
						if (arr[3] > arr[min - 4])
						{
							sum += arr[min - 4] * arr[min];
						}
						else
						{
							sum += arr[3] * arr[min];
						}
					}
				}
				else
				{
					sum += arr[3] * arr[max2];
				}
			}
			
		}
		else
		{
			sum += arr[3] * arr[max1];
		}
		printf("%d\n", sum);
		return sum;
	}
	return 0;
}
#endif

int main()
{
	int n = 0;
	int i = 0;
	while (scanf("%d", &n) != EOF)
	{
		char s[n];
		for (i = 0; i < n; i++)
		{
			scanf("%c", &s[i]);
		}
		int max = 0;
		int a = 0; //标记E的位置
		int b = 0;// 标记F的位置
		int flag = 0;
		int c = 0;// 表示第一次遇见F

		for (i = 0; i < n; i++)
		{
			if (s[i] == 'F' && flag==0 )
			{
				a = i;
				flag = 1;
				if (c == 0)
				{
					max = i;
					c = 1;
				}
			}
			else if (s[i] == 'F' && flag == 1)
			{
				b = i;
				flag = 0;
				
				if (b - a - 1 > max)
				{
					max = b - a - 1;
				}
			}
		}
		printf("%d\n", max);
		
	}
	return 0;
}