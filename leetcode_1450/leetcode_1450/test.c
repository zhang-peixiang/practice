#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// ���������������� startTime����ʼʱ�䣩�� endTime������ʱ�䣩��
// ��ָ��һ������ queryTime ��Ϊ��ѯʱ�䡣
//
// ��֪���� i ��ѧ���� startTime[i] ʱ��ʼд��ҵ���� endTime[i] ʱ�����ҵ��
//
// �뷵���ڲ�ѯʱ�� queryTime ʱ��������ҵ��ѧ����������ʽ�ϣ�
// �����ܹ�ʹ queryTime ��������[startTime[i], endTime[i]]��������ѧ��������


int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime)
{
	if (startTime == 0)
	{
		return 0;
	}
	int i = 0;
	int count = 0;
	for (i = 0; i < startTimeSize; i++)
	{
		if (startTime[i] <= queryTime && endTime[i] >= queryTime)
		{
			count++;
		}
	}
	return count;
}