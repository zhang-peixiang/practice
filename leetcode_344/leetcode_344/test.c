#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
void reverseString(char* s, int sSize){
	int i = 0;
	for (i = 0; i < sSize/2; i++)
	{
		char ret;
		ret = *(s + i);
		*(s + i) = *(s + sSize - 1 - i);
		*(s + sSize - 1 - i) = ret;
	}
}

int main()
{
	char str[] = { 'h', 'e', 'l', 'l', 'o' };
	int sz = sizeof(str) / sizeof(str[0]);
	int i = 0;
	reverseString(str, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%c ", str[i]);
	}
	return 0;
}
