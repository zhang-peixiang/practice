#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s)
{
	int len = strlen(s);
	int i = 0;

	int a = 0; //计算每个单词的长度
	int b = 0; //计算多余的空格
	int c = 0; //标记将原字符串往开辟的空间里的位置
	if (len == 0 || len == 1)
	{
		return s;
	}

	//删除多余的空格
	i = 1;
	while (i < len)
	{
		if (s[i - 1] == ' ' && s[i] == ' ')
		{
			b++;
		}
		i++;
	}
	if (s[0] == ' ')
	{
		b++;
	}
	if (s[len - 1] == ' ')
	{
		b++;
	}

	//翻转单词
	i = 0;
	c = len - b;
	char* s1 = (char*)calloc(sizeof(s[0]), len + 1 - b);
	while (i<len)
	{
		while (i<len && s[i] != ' ')
		{
			i++;
			a++;
		}

		c -= a;
		i -= a;
		b = a;//标记单词长度
		while (a>0)
		{
			s1[c++] = s[i++];
			a--;
		}
		if (b != 0)
		{
			c = c - b - 1;//标记单词长度,方便下面c=c-b-1
		}
		if (b != 0 && c >= 0)
		{
			s1[c] = ' ';
		}
		i++;
	}
	return s1;
}

int main()
{
	char s[] = " ";

	char* s1= reverseWords(s);
	return 0;
}