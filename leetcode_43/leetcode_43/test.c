#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * multiply(char * num1, char * num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	if (len1 == 0)
		return len2;
	if (len2 == 0)
		return len1;

	if (len1 == 1 && num1[0] == '0')
		return num1;
	if (len2 == 1 && num2[0] == '0')
		return num2;

	int len = len1 + len2;
	int a = 0; //表示相乘之后的数
	int b = 0;
	int c = 0;
	int i = 0;
	int j = 0;

	int count = 0; //统计s中开头有几个0
	char* s = (char*)calloc(len + 1, sizeof(char));
	int tmp = len - 1;

	j = len2 - 1;
	while (j >= 0)
	{
		i = len1 - 1;
		tmp = len - 1 - c;
		while (i >= 0)
		{
			a += (num1[i--] - '0')*(num2[j] - '0')*pow(10, b);
			b++;
		}
		j--;
		b = 0;
		int p = 0;
		while (a > 0)
		{
			int q = 0;
			if (s[tmp] == '\0')
			{
				q = s[tmp] + a % 10 + p;
			}
			else
			{
				q = s[tmp] - '0' + a % 10 + p;
			}
			p = q / 10;
			s[tmp] = q % 10 + '0';
			tmp--;
			a /= 10;
		}
		while (p > 0)
		{
			int q = s[tmp] - '0' + p;
			p = q / 10;
			s[tmp] = p % 10 + '0';
			tmp--;
		}
		c++;
	}

	

	for (i = 0; i < len; i++)
	{
		if (s[i] != '\0')
			break;
		count++;
	}
	i = 0;
	j = count;
	while (j < len + 1)
	{
		s[i++] = s[j++];
	}

	return s;
}

int main()
{
	char s1[] = "123456789";
	char s2[] = "987654321";

	char* s= multiply(s1, s2);
	return 0;
}



