#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。



// 时间长，运行效率低
//char * removeDuplicates(char * S)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(S);
//	if (len <= 1)
//	{
//		return S;
//	}
//
//	for (i = 0; i < len - 1; i++)
//	{
//		if (S[i] == S[i + 1])
//		{
//			for (j = i; j < len-2; j++)
//			{
//				S[j] = S[j + 2];
//			}
//			i = -1;
//			len -= 2;
//		}
//	}
//
//	S[len] = '\0';
//	return S;
//}


//  栈
char * removeDuplicates(char * S)
{
	int len = strlen(S);
	int i = 0;
	int sz = 0;
	char* s = (char*)calloc(sizeof(char), len + 1);
	if (len <= 1)
		return S;
	
	for (i = 0; i < len; i++)
	{
		if (sz > 0)
		{
			if (s[sz-1] == S[i])
			{
				sz--;
			}
			else
			{
				s[sz++] = S[i];
			}
		}
		else
		{
			s[sz++] = S[i];
		}
		
	}
	s[sz] = '\0';
	return s;
}




int main()
{
	char s[] = "abbaca";
	char* a = removeDuplicates(s);
	return 0;
}