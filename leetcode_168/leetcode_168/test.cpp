#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

// ����һ������������������ Excel �������Ӧ�������ơ�
#if 0
// �鷳����
class Solution {
public:
	string convertToTitle(int n) {
		string s;
		int tmp = n;
		int count = 0;
		while (tmp)
		{
			count++;
			tmp = (tmp - 1) / 26;
		}

		s.resize(count);
		int index = count - 1;
		while (n)
		{
			s[index] = (n - 1) % 26 + 'A';
			index--;
			n = (n - 1) / 26;

		}
		return s;
	}

};

#endif

// ��㷽��
class Solution {
public:
	string convertToTitle(int n) {
		string s;
		while (n)
		{
			n--;
			s.push_back(n % 26 + 'A');
			n /= 26;
		}
		reverse(s.begin(), s.end());
		return s;
	}
};