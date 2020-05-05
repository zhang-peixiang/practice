#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。

char * longestCommonPrefix(char strs[][7], int strsSize)
{
	if (strsSize == 0)
	{
		return "";
	}
	if (strsSize == 1)
	{
		return strs[0];
	}
	int i = 0;
	int a = strsSize;//行
	int b = strlen(strs[0]);//列
	int j = 0;
	int count = 0;
	for (i = 0; i < a-1; i++)
	{
		count = 0;
		for (j = 0; j < b; j++)
		{
			if (strs[i][j] != strs[i + 1][j])
			{
				b = count;
				break;
			}
			else
			{
				count++;//记录有几个相同的前缀
			}
		}
	}
	strs[0][b] = '\0';
	if (count == 0)
	{
		return "";
	}
	else
	{
		return strs[0];
	}
}
int main()
{
	char str[3][7] = { {"flower" }, { "flow" }, { "flight" }};
	int sz = sizeof(str) / sizeof(str[0]);
	char* ret = longestCommonPrefix(str, sz);
	printf("%s\n", ret);
	return 0;
}