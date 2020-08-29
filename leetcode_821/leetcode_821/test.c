#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 给定一个字符串 S 和一个字符 C。
// 返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

int* shortestToChar(char * S, char C, int* returnSize)
{
	int len = strlen(S);
	int i = 0;
	int* arr = (int*)calloc(sizeof(int),len);
	*returnSize = len;
	int a = 0;
	int tmp = 1;

	// 找到c在s中的位置 标记为-1
	for (i = 0; i < len; i++)
	{
		if (S[i] == C)
		{
			arr[i] = -1;
		}
	}
	
	// 从-1的位置向左右进行标记
	for (i = 0; i < len; i++)
	{
		if (arr[i] == -1)
		{
			//向左
			a = i - 1;
			tmp = 1;
			while (a >= 0 && arr[a] != -1)
			{
				if (arr[a] != 0 && arr[a] < tmp) //确定最小位置
				{
					break;
				}
				else
				{
					arr[a--] = tmp++;
				}
			}
			//向右
			a = i + 1;
			tmp = 1;
			while (a < len && arr[a] != -1)
			{
				if (arr[a] != 0 && arr[a] < tmp)
				{
					break;
				}
				else
				{
					arr[a++] = tmp++;
				}
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		if (arr[i] == -1)
		{
			arr[i] = 0;
		}
	}
	return arr;
}

int main()
{
	char s1[] = "loveleetcode";
	char s2 = 'e';
	int a = 0;

	int* b = shortestToChar(s1, s2, &a);
	return 0;
}