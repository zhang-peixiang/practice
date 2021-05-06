#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;


// ��һ���������������������㰴�ո��ڵ�һ��һ����������α�ţ��������Ϊ1��
// ���������ڵ�a��b�����һ���㷨��a��b�������������ȵر��

class LCA {
public:
	int getLCA(int a, int b) {
		// ��֤a����С��
		if (a>b)
		{
			swap(a, b);
		}
		int min = 0;
		int max = 0;
		int reta = 0;
		int retb = 0;
		// ȷ��a��b�ڶ������ĵڼ���
		while (1)
		{
			min = pow(2, reta);
			max = min * 2;
			if (a >= min && a<max)
			{
				break;
			}
			reta++;
		}
		retb = reta;
		while (1)
		{
			min = pow(2, retb);
			max = min * 2;
			if (b >= min && b<max)
			{
				break;
			}
			retb++;
		}
		// ��a��b���ڶ�������ͬһ��
		while (reta<retb)
		{
			b /= 2;
			retb--;
		}
		// �ж��Ƿ���ͬһ���ڵ�
		while (a / 2 != b / 2)
		{
			a /= 2;
			b /= 2;
		}
		return a / 2;
	}
};
