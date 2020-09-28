#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 求1 + 2 + 3 + ... + n，
// 要求不能使用乘除法、for、while、if、else、switch、case等
// 关键字及条件判断语句（A ? B : C）。


class addsum
{
public:
	addsum()
	{
		count++;
		sum += count;
	}

	static void sum_init()
	{
		count = 0;
		sum = 0;
	}

	static int Getsum()
	{
		return sum;
	}

private:
	static int count;
	static int sum;
};

int addsum::count = 0;
int addsum::sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		addsum::sum_init();
		addsum s[n];
		return addsum::Getsum();
	}
};


//int main()
//{
//	addsum::sum_init();
//	addsum s[3];
//	
//	cout << addsum::Getsum() << endl;
//
//	return 0;
//}