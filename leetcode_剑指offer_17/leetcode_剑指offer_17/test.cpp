#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

// �������� n����˳���ӡ���� 1 ������ n λʮ��������
// �������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999

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