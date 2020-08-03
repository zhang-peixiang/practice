#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//提示：
//num1 和num2 的长度都小于 5100
//num1 和num2 都只包含数字 0 - 9
//num1 和num2 都不包含任何前导零
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
//


char * addStrings(char * num1, char * num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int maxlen = len1 > len2 ? len1 : len2;
	char* s = (char*)calloc(sizeof(num1[0]), maxlen + 2);
	int len = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	int add = 0;//标记有无进位
	int count = 0;//标记相加结果
	while (i >= 0 && j >= 0)
	{
		count = add + num1[i--] - '0' + num2[j--] - '0';
		s[len++] = count % 10 + '0';
		add = count / 10;
	}
	while (i >= 0)
	{
		count = add + num1[i--] - '0';
		s[len++] = count % 10 + '0';
		add = count / 10;
	}
	while (j >= 0)
	{
		count = add + num2[j--] - '0';
		s[len++] = count % 10 + '0';
		add = count / 10;
	}
	if (add>0)
	{
		s[len++] = add + '0';
	}

	i = 0;
	len -= 1;
	while (i < len)
	{
		char tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}

	return s;
}

int main()
{
	char* s1 = "0";
	char* s2 = "0";

	char*s = addStrings(s1, s2);
	return 0;
}