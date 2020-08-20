#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 给定一个Excel表格中的列名称，返回其相应的列序号。


int titleToNumber(char * s)
{
	int len = strlen(s);
	int sum = 0;
	int i = 0;
	int tmp = 0;
	if (len == 0)
	{
		return 0;
	}

	while (len)
	{
		tmp = s[i] - 'A' + 1;
		if (len > 1)
		{
			sum += tmp * pow(26,len-1);
		}
		else
		{
			sum += tmp;
		}
		len--;
		i++;
	}
	return sum;
}


int main()
{
	char s[] = "ABA";
	int a = titleToNumber(s);
	return 0;
}