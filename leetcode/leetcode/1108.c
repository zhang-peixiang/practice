#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����һ����Ч�� IPv4 ��ַ address��������� IP ��ַ����Ч���汾��
//��ν��Ч�� IP ��ַ����ʵ������ "[.]" ������ÿ�� "."��
//char* defangIPaddr(char * address){
//	int i = 0;
//	int len = strlen(address);
//	int count = 0;
//	int len_list = 0;
//	int k = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (address[i] == '.')
//		{
//			count++;
//		}
//	}
//	char* addresslist = (char*)calloc(len +1 + count * 2,sizeof(char));
//	len_list = strlen(addresslist);
//	for (i = 0; i < len; i++)
//	{
//		if (address[i] != '.')
//		{
//			addresslist[k] = address[i];
//			k++;
//		}
//		else
//		{
//			addresslist[k] = '[';
//			addresslist[k+1] = address[i];
//			addresslist[k + 2] = ']';
//			k = k + 3;
//		}
//	}
//	return addresslist;
//}
//
//int main()
//{
//	char address[] = "1.1.1.1";
//	defangIPaddr(address);
//	return 0;
//}

int decompressRLElist(int* arr, int sz)
{
	int i = 0, sum = 0;
	for (i = 0; i < sz - 1; i + 2)
	{
		sum = sum + arr[i];
	}
	return sum;
}
int main()
{
	int arr[] = { 2, 4, 3, 4 };
	int sum = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	decompressRLElist(arr, sz);
	printf("%d", sum);


}