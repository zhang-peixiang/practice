#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//����������Сд��ĸ���ɵ��ַ��� A �� B ��ֻҪ���ǿ���ͨ������ A �е�������ĸ�õ��� B ��ȵĽ����
//�ͷ��� true �����򷵻� false ��


//erro--ֻ�ܽ�������ĸ
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
	//�����ж��������ӣ�"aa""aa"����"ab""ab"
	if (strcmp(A, B) == 0)
	{
		qsort(A, sz1, sizeof(char), cmp_char);//���������ж�"abab""abab"�������ͣ�������ֻҪ����ͬ�Ĵ��ڣ���Ϊ��
		for (i = 0; i < sz1 - 1; i++)
		{
			if (A[i] == A[i + 1])
			{
				return true;
			}
		}
		return false;
	}
	//���һ���м�������ͬ���ַ�
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
		if (count>2)//֤������ͬ�Ĵ���2  ֱ�ӷ���false
		{
			return false;
		}
	}
	if (A[a] == B[b] && A[b] == B[a]) //�����ж��������� "abcaa" "abcbb"
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

