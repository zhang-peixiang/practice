#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，
//就返回 true ；否则返回 false 。


//erro--只能交换俩字母
//int cmp_char(const void* e1, const void* e2)
//{
//	//return ((char*)e1) - ((char*)e2);
//	return strcmp((char*)e1, (char*)e2);
//}
//
//bool buddyStrings(char * A, char * B)
//{
//	int i = 0;
//	int j = 0;
//	int sz1 = strlen(A);
//	int sz2 = strlen(B);
//	if (sz1 != sz2 || sz1==0)
//	{
//		return false;
//	}
//	if (strcmp(A, B) == 0)
//	{
//		for (i = 0; i < sz1 - 1; i++)
//		{
//			if (A[i] == A[i + 1])
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	qsort(A, sz1, sizeof(char), cmp_char);
//	qsort(B, sz2, sizeof(char), cmp_char);
//	if (strcmp(A, B) == 0)
//	{
//		return true;
//	}
//	return false;
//}

int cmp_char(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

bool buddyStrings(char * A, char * B)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int sz1 = strlen(A);
	int sz2 = strlen(B);
	int count = 0;
	if (sz1 != sz2 || sz1 == 0)
	{
		return false;
	}
	//用来判断这类例子："aa""aa"或者"ab""ab"
	if (strcmp(A, B) == 0)
	{
		qsort(A, sz1, sizeof(char), cmp_char);//排序用来判断"abab""abab"这种类型，排序完只要有相同的存在，即为真
		for (i = 0; i < sz1 - 1; i++)
		{
			if (A[i] == A[i + 1])
			{
				return true;
			}
		}
		return false;
	}
	//检查一共有几个不相同的字符
	for (i = 0; i < sz1; i++)
	{
		if (A[i] != B[i])
		{
			count++;
			if (count == 1)
			{
				a = i;
			}
			else
			{
				b = i;
			}
		}
		if (count>2)//证明不相同的大于2  直接返回false
		{
			return false;
		}
	}
	if (A[a] == B[b] && A[b] == B[a]) //用来判断这类例子 "abcaa" "abcbb"
	{
		return true;
	}
	return false;
}

int main()
{
	char str1[] = "ab";
	char str2[] = "ba";
	buddyStrings(str1, str2);
	return 0;
}

