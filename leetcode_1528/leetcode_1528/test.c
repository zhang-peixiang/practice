#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// 给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
//
// 请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
//
// 返回重新排列后的字符串。

char * restoreString(char * s, int* indices, int indicesSize)
{
	int i = 0;
	char* s1 = (char*)malloc(sizeof(char)*(indicesSize + 1));
	for (i = 0; i < indicesSize; i++)
	{
		int num = indices[i];
		s1[num] = s[i];
	}
	s1[i] = 0;
	return s1;
}