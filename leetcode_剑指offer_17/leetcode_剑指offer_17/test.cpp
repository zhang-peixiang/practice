#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
// 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) 
	{
		int i = 0;
		int max = 10;
		vector<int> v;
		while (n>1)
		{
			max *= 10;
			n--;
		}
		for (i = 1; i < max; i++)
		{
			v.push_back(i);
		}
		return v;
	}
};