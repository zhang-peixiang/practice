#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

// 计算字符串最后一个单词的长度，单词以空格隔开。


int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.begin() == s.end())
		{
			cout << 0 << endl;
		}
		int count = 0;
		auto it = s.end();
		it--;
		while (*it != ' ')
		{

			count++;
			it--;
			if (it == s.begin())
			{
				count++;
				break;
			}
		}
		cout << count;
		s.clear();
	}
	return 0;
}