#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	while (getline(cin, s))
	{
		int len = s.size();
		int i = 0;
		int flag = 0;
		string s1;
		int count = 0;
		for (i = 0; i < len; i++)
		{
			if (s[i] == '"')
			{
				flag = 1;
				i++;
			}
			if (flag == 0)
			{
				while (i<len && s[i] != ' ')
				{
					s1.push_back(s[i]);
					i++;
				}
			}
			else
			{
				while (i<len && s[i] != '"')
				{
					s1.push_back(s[i]);
					i++;
				}
				flag = 0;
			}
			s1.push_back('1');
		}
		auto tmp = s1.begin();
		i = 0;
		while (tmp != s1.end())
		{
			if (s1[i]!='1')
			{
				printf("%c", s1[i]);
			}
			else
			{
				printf("\n");
			}
			i++;
		}
		s.clear();
		s1.clear;
	}
	return 0;
}