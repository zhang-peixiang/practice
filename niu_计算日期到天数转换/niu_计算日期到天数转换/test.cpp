#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdio.h>
using namespace std;


// ������������ڣ���������һ��ĵڼ��졣��

// ��ϸ������

// ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��

// ���������ж��飬ע��ѭ������

int main()
{
	int data[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;
	int i = 0;
	int count = 0;

	while (cin >> year >> month >> day)
	{
		count = 0;
		
		for (i = 1; i < month; i++)
		{
			count += data[i];
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			count++; 
		}
		count += day;
		cout << count << endl;
	}

	return 0;
}