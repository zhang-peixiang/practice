#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// ���ǲ�ȫ
//char * frequencySort(char * s)
//{
//	int len = strlen(s);
//	int i = 0;
//	int* arr = (int*)calloc(63, sizeof(int));
//	int maxcount = 1;
//	int tmp = 0; //����ַ�����λ��
//	int b = 0; //���Ԫ�طŻ�s��λ��
//
//	if (len < 2)
//	{
//		return s;
//	}
//
//	//ͳ��ÿ���ַ��ĸ���
//	for (i = 0; i < len; i++)
//	{
//		//����Сд��ĸ����arr��ǰ52��
//		if (s[i]>64)
//		{
//			int a = s[i] - 'A';
//			if (a< 26)
//			{
//				arr[a]++;
//			}
//			else
//			{
//				a -= 6;
//				arr[a]++;
//			}
//			
//		}
//		else if (s[i]>47 && s[i] < 58) //�����ַ� ����'0'
//		{
//			int a = s[i] - '0';
//			arr[a + 52]++;
//		}
//		else
//			arr[62]++;
//	}
//
//	while (1)
//	{
//		maxcount = arr[0];
//		tmp = 0;
//		for (i = 0; i < 63; i++)
//		{
//			if (arr[i]>maxcount)
//			{
//				maxcount = arr[i];
//				tmp = i;
//			}
//		}
//		if (maxcount == 0)
//		{
//			break;
//		}
//
//		while (arr[tmp])
//		{
//			if (tmp < 26)
//			{
//				s[b++] = tmp + 'A';
//			}
//			else if (tmp>25 && tmp<52)
//			{
//				s[b++] = tmp + 6 + 'A';
//			}
//			else if(tmp>52 && tmp<62)
//			{
//				s[b++] = tmp - 52 + '0';
//			}
//			else
//			{
//				s[b++] = ' ';
//			}
//			arr[tmp]--;
//		}
//		
//	}
//
//	free(arr);
//	return s;
//}


char * frequencySort(char * s)
{
	int len = strlen(s);
	int i = 0;
	int* arr = (int*)calloc(95, sizeof(int));
	int maxcount = 1;
	int tmp = 0; //����ַ�����λ��
	int b = 0; //���Ԫ�طŻ�s��λ��

	if (len < 2)
	{
		return s;
	}

	for (i = 0; i < len; i++)
	{
		int a = s[i] - ' ';
		arr[a]++;
	}

	while (1)
	{
		maxcount = arr[0];
		tmp = 0;
		for (i = 0; i < 95; i++)
		{
			if (arr[i]>maxcount)
			{
				maxcount = arr[i];
				tmp = i;
			}
		}
		if (maxcount == 0)
		{
			break;
		}

		while (arr[tmp])
		{
			s[b++] = tmp + ' ';
			arr[tmp]--;
		}

	}
	return s;
}


int main()
{
	char s[] = "a 33";
	char* a = frequencySort(s);

	return 0;
}