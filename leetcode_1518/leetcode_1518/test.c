#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ��㹺���� numBottles ƿ�ơ�
//
// ����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ��ɿյġ�
//
// ������� ��� �ܺȵ�����ƿ�ơ�


int numWaterBottles(int numBottles, int numExchange)
{
	int count = numBottles; // ��¼��ƿ��
	int a = 0;

	while (count < numExchange)
	{
		a = count%numExchange;
		numBottles += count / numExchange;
		count /= numExchange;
		count += a;
	}
	return numBottles;
}