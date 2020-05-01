#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；
//并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
//你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	assert(*g && *s);
	int i = 0;
	int j = 0;
	int count = 0;
	qsort(g, gSize, sizeof(int), cmp);
	qsort(s, sSize, sizeof(int), cmp);
	for (i = 0; i < gSize; i++)
	{
		for (j = 0; j < sSize; j++)
		{
			if (g[i] <= s[j])
			{
				s[j] = -1;
				count++;
				break;
			}
		}
	}
	return count;
}

int main()
{
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 1, 2 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int ret = findContentChildren(arr1, sz1, arr2, sz2);
	printf("%d\n", ret);
	return 0;
}