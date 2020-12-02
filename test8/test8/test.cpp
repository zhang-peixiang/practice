#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// 最小公倍数
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	while ((cin >> a) && (cin >> b))
	{
		int n = 0;
		int tmp = 0;
		if (a > b)
		{
			n = a;
		}
		else
		{
			n = b;
		}
		tmp = n;
		while (1)
		{
			if (n%a == 0 && n%b == 0)
				break;
			n += tmp;
		}
		cout << n;
	}
	return 0;
}
#endif


#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <string.h>

int main()
{
	vector<string> v;
	int n = 0;
	while (cin >> n)
	{
		string s;
		int flag1 = 0;
		int flag2 = 0;
		int tmp = 0;
		int i = 0;
		for (i = 0; i < n; i++)
		{
			cin >> s;
			v.push_back(s);
		}

		if (v[0].size() > v[1].size())
		{
			tmp = 0;
		}
		else
		{
			tmp = 1;
		}
		// 字符串大小排序
		for (i = 1; i < n; i++)
		{
			if ((v[i].size()>v[i - 1].size() && tmp != 1)||
				(v[i].size()<v[i - 1].size() && tmp != 0))
			{
				break;
			}
		}
		if (i == n)
			flag1++;

		// 字典序大小排序
		if (strcmp(v[0].c_str(), v[1].c_str())>0)
		{
			tmp = 0;
		}
		else
		{
			tmp = 1;
		}
		for (i = 1; i < n; i++)
		{
			if ((strcmp(v[i].c_str(), v[i - 1].c_str())<0 && tmp != 0) ||
				(strcmp(v[i].c_str(), v[i - 1].c_str())>0 && tmp != 1))
				break;
		}
		if (i == n)
			flag2++;
		if (flag1 == 0 && flag2 ==0)
		{
			cout << "none";
		}
		else if (flag1 == 1 && flag2 == 0)
		{
			cout << "lengths";
		}
		else if (flag1 == 0 && flag2 == 0)
		{
			cout << "lexicographically";
		}
		else
		{
			cout << "both";
		}
	}
	return 0;
}