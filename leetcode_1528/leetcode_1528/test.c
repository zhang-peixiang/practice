#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// ����һ���ַ��� s ��һ�� ������ͬ ���������� indices ��
//
// �������������ַ��� s �����е� i ���ַ���Ҫ�ƶ��� indices[i] ָʾ��λ�á�
//
// �����������к���ַ�����

char * restoreString(char * s, int* indices, int indicesSize)
{
	int i = 0;
	char* s1 = (char*)malloc(sizeof(char)*(indicesSize + 1));
	for (i = 0; i < indicesSize; i++)
	{
		int num = indices[i];
		s1[num] = s[i];
	}
	s1[i] = 0;
	return s1;
}