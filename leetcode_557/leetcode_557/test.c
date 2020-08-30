#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。


void swap(char* s, int left, int right)
{
	while (left < right)
	{
		char tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}
}

char * reverseWords(char * s){
	int len = strlen(s);
	int left = 0;
	int right = 0;
	int i = 0;
	if (len<2)
		return s;
	while (i <= len)
	{
		if (s[i] == ' ' || s[i]=='\0')
		{
			right = i;
			swap(s, left, right - 1);
			left = right + 1;
		}
		i++;
	}
	// swap(s, left, len - 1); //交换最后一个单词
	return s;
}



int main()
{
	char s[] = "Let's take LeetCode contest";
	char* a = reverseWords(s);
	return 0;
}