#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
char* replaceSpace(char* s)
{
	int i = 0;
	int len = strlen(s);
	int count = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		if (*(s + i) == ' ')
		{
			count++;
		}
	}
	char* returnStr = (char*)calloc(len + 1+count*2, sizeof(char));
	for (i = 0; i < len; i++)
	{
		if (*(s + i) == ' ')
		{
			returnStr[j] = '%';
			returnStr[j + 1] = '2';
			returnStr[j + 2] = '0';
			j += 3;
		}
		else
		{
			returnStr[j] = *(s + i);
			j++;
		}
	}
	return returnStr;
}
int main()
{
	char str[] = "We are happy.";
	char* ret = replaceSpace(str);
	printf("%s\n", ret);
	return 0;
}