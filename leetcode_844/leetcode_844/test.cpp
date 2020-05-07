#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，
//判断二者是否相等，并返回结果。 # 代表退格字符。
//思路开辟空间，在开辟的空间上进行操作，
//如果不为'#'，将其存放到开辟的空间上，
//如果等于'#'，令开辟的空间上的拷贝过去的最后一个字符等于0
//最后将两个开辟的空间进行比较即可
int backspaceCompare(char * S, char * T)
{
	int len1 = strlen(S);
	int len2 = strlen(T);
	int a = 0;
	int b = 0;
	int ret = 0;
	char* Ss = (char*)calloc(len1+1, sizeof(S[0]));
	char* Tt = (char*)calloc(len2+1, sizeof(T[0]));
	int i = 0;
	if (Ss == NULL || Tt == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		for (i = 0; i < len1; i++)
		{
			if (S[i] != '#')
			{
				Ss[a] = S[i];
				a++;
			}
			else if (S[i] == '#' && a != 0)
			{
				Ss[a - 1] = 0;
				a--;
			}
		}
		for (i = 0; i < len2; i++)
		{
			if (T[i] != '#')
			{
				Tt[b] = T[i];
				b++;
			}
			else if (T[i] == '#' && b != 0)
			{
				Tt[b - 1] = 0;
				b--;
			}
		}
		ret = strcmp(Ss, Tt);
		free(Ss);
		Ss = NULL;
		free(Tt);
		Tt = NULL;
		if (ret == 0)
		{
			return 0;
		}
		else
			return -1;
	}
}
int main()
{
	char s[] = "xywrrmp";
	char t[] = "xywrrmu#p";
	int i = backspaceCompare(s, t);
	printf("%d\n", i);
	return 0;
}