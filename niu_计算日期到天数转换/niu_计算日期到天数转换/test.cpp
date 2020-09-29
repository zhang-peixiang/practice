#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdio.h>
using namespace std;


// 根据输入的日期，计算是这一年的第几天。。

// 详细描述：

// 输入某年某月某日，判断这一天是这一年的第几天？。

// 测试用例有多组，注意循环输入

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