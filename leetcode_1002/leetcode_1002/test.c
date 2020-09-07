#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
//例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
//
//你可以按任意顺序返回答案。

void compare(int *A, int *B, int *count)
{
	int sum = 0;
	for (int i = 0; i<26; i++)
	{
		if (A[i]>B[i])
			A[i] = B[i];
		sum += A[i];
	}
	*count = sum;
	return;
}
//对第一个字符串每个字符进行个数统计
char ** commonChars(char ** A, int ASize, int* returnSize){
	int  S[26] = { 0 };
	char *p = A[0];
	while (*p != '\0')
	{
		int k = *p - 'a';
		S[k]++;
		p++;
	}
	int num; //num为出现字符个数总和
	//分别对每个字符串进行字符个数统计，结果保存在R中
	for (int i = 1; i<ASize; i++)
	{
		int R[26] = { 0 };
		p = A[i];
		while (*p != '\0')
		{
			int k = *p - 'a';
			R[k]++;
			p++;
		}
		compare(S, R, &num);//每得到一个R与S进行去交必须是每个字符在每个字符串出现的最小次数
	}
	//统计的num个字符，生成num个字符串，每个字符串只有一个字符（字符串结尾不要忽略'\0'）二维数组。
	char **B = (char**)malloc(num*sizeof(char*));
	char **q = B;
	for (int i = 0; i<26; i++)
	{
		while (S[i]>0)
		{
			*q = (char*)malloc(2 * sizeof(char));
			(*q)[0] = 'a' + i;
			(*q)[1] = '\0';//
			q++;
			S[i]--;
		}
	}
	*returnSize = num;
	return B;
}
