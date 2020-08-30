#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��


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
	// swap(s, left, len - 1); //�������һ������
	return s;
}



int main()
{
	char s[] = "Let's take LeetCode contest";
	char* a = reverseWords(s);
	return 0;
}