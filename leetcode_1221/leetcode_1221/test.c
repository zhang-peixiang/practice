#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。
//给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
//返回可以通过分割得到的平衡字符串的最大数量。
int balancedStringSplit(char * s)
{
	int len = strlen(s);
	int i = 0;
	int count = 0;
	int a = 0;
	int b = 0;
	for (i = 0; i < len; i++)
	{
		if (s[i] == 'L')
		{
			a++;
		}
		else
		{
			b++;
		}
		if (a == b)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	char s[] = "RLRRLLRLRL";
	int ret = 0;
	ret = balancedStringSplit(s);
	printf("%d\n", ret);
	return 0;
}