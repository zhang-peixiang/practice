#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б�
//���磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�
//
//����԰�����˳�򷵻ش𰸡�

void compare(int *A, int *B, int *count)
{
	int sum = 0;
	for (int i = 0; i<26; i++)
	{
		if (A[i]>B[i])
			A[i] = B[i];
		sum += A[i];
	}
	*count = sum;
	return;
}
//�Ե�һ���ַ���ÿ���ַ����и���ͳ��
char ** commonChars(char ** A, int ASize, int* returnSize){
	int  S[26] = { 0 };
	char *p = A[0];
	while (*p != '\0')
	{
		int k = *p - 'a';
		S[k]++;
		p++;
	}
	int num; //numΪ�����ַ������ܺ�
	//�ֱ��ÿ���ַ��������ַ�����ͳ�ƣ����������R��
	for (int i = 1; i<ASize; i++)
	{
		int R[26] = { 0 };
		p = A[i];
		while (*p != '\0')
		{
			int k = *p - 'a';
			R[k]++;
			p++;
		}
		compare(S, R, &num);//ÿ�õ�һ��R��S����ȥ��������ÿ���ַ���ÿ���ַ������ֵ���С����
	}
	//ͳ�Ƶ�num���ַ�������num���ַ�����ÿ���ַ���ֻ��һ���ַ����ַ�����β��Ҫ����'\0'����ά���顣
	char **B = (char**)malloc(num*sizeof(char*));
	char **q = B;
	for (int i = 0; i<26; i++)
	{
		while (S[i]>0)
		{
			*q = (char*)malloc(2 * sizeof(char));
			(*q)[0] = 'a' + i;
			(*q)[1] = '\0';//
			q++;
			S[i]--;
		}
	}
	*returnSize = num;
	return B;
}
