#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
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
