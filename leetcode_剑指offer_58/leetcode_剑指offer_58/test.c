#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s)
{
	int len = strlen(s);
	int i = 0;

	int a = 0; //����ÿ�����ʵĳ���
	int b = 0; //�������Ŀո�
	int c = 0; //��ǽ�ԭ�ַ��������ٵĿռ����λ��
	if (len == 0 || len == 1)
	{
		return s;
	}

	//ɾ������Ŀո�
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

	//��ת����
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
		b = a;//��ǵ��ʳ���
		while (a>0)
		{
			s1[c++] = s[i++];
			a--;
		}
		if (b != 0)
		{
			c = c - b - 1;//��ǵ��ʳ���,��������c=c-b-1
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