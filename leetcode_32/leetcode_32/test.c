#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>


//��ջ
/*
1.����'(' ��ջ  ����')'��ջ

ջ�е�һ��Ԫ��Ϊ-1  ԭ����char�ַ����Ǵ�0��ʼ
*/

int longestValidParentheses(char * s)
{
	int len = strlen(s);
	if (len == 0 || len == 1)
		return 0;
	int i = 0;
	int arr[len + 1];
	int ret = 0;
	int count = 0;
	int top = -1;

	arr[++top] = -1;

	for (i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			arr[++top] = i;
		}
		else
		{
			--top;
			if (top == -1)
			{
				arr[++top] = i;
			}
			else
			{
				count = fmax(count, i - arr[top]);
			}
		}
	}
	return count;
}



int main()
{
	char str[] = "()(()";

	int ret = longestValidParentheses(str);
	return 0;
}