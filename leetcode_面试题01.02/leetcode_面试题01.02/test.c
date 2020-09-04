#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

int cmp(const char* left, const char* right)
{
	return *left - *right;
}

bool CheckPermutation(char* s1, char* s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = 0;
	if (len1 != len2)
		return false;
	qsort(s1, len1, sizeof(char), cmp);
	qsort(s2, len2, sizeof(char), cmp);

	for (i = 0; i < len1; i++)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

int main()
{
	char s1[] = "acb";
	char s2[] = "bca";
	int a = CheckPermutation(s1, s2);
	return 0;
}