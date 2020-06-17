#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//删除重复，并将首字母大写，单词中的字母变小写
char* check(char* s)
{
	int len = strlen(s);
	int i = 0;
	int count = 0;
	char* s1 = (char*)malloc(sizeof(char)*(len + 1));
	//去掉重复元素
	for (i = 0; i < len; i+=2)
	{
		if (s[i] != s[i + 1])
		{
			s1[count] = s[i];
			s1[count + 1] = s[i + 1];
			count += 2;
		}
		else
		{
			s1[count] = s[i];
			count++;
		}
	}
	//改大小
	for (i = 0; i < count; i++)
	{
		char ch = s1[i];
		//判断第一个字符
		if (s1[0]>='a' && s1[0] <= 'z')
		{
			s1[0] = s1[0] - 32;
		}
		else if (s1[i]>='a' && s1[i] <= 'z' && s1[i - 1] == ' ')
			s1[i] = s1[i] - 32;
		else if (s1[i]>='A' && s1[i] <= 'Z' && s1[i - 1] != ' ')
			s1[i] = s1[i] + 32;
	}

	return s1;
}


int main()
{
	char s[] = "whoo lovEE sAAm";
	char* s1 = check(s);
	printf("%s\n", s1);
	return 0;
}

