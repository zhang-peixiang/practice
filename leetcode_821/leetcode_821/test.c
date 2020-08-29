#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����һ���ַ��� S ��һ���ַ� C��
// ����һ�������ַ��� S ��ÿ���ַ����ַ��� S �е��ַ� C ����̾�������顣

int* shortestToChar(char * S, char C, int* returnSize)
{
	int len = strlen(S);
	int i = 0;
	int* arr = (int*)calloc(sizeof(int),len);
	*returnSize = len;
	int a = 0;
	int tmp = 1;

	// �ҵ�c��s�е�λ�� ���Ϊ-1
	for (i = 0; i < len; i++)
	{
		if (S[i] == C)
		{
			arr[i] = -1;
		}
	}
	
	// ��-1��λ�������ҽ��б��
	for (i = 0; i < len; i++)
	{
		if (arr[i] == -1)
		{
			//����
			a = i - 1;
			tmp = 1;
			while (a >= 0 && arr[a] != -1)
			{
				if (arr[a] != 0 && arr[a] < tmp) //ȷ����Сλ��
				{
					break;
				}
				else
				{
					arr[a--] = tmp++;
				}
			}
			//����
			a = i + 1;
			tmp = 1;
			while (a < len && arr[a] != -1)
			{
				if (arr[a] != 0 && arr[a] < tmp)
				{
					break;
				}
				else
				{
					arr[a++] = tmp++;
				}
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		if (arr[i] == -1)
		{
			arr[i] = 0;
		}
	}
	return arr;
}

int main()
{
	char s1[] = "loveleetcode";
	char s2 = 'e';
	int a = 0;

	int* b = shortestToChar(s1, s2, &a);
	return 0;
}