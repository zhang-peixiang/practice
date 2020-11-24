#define _CRT_SECURE_NO_WARNINGS 1


#if 0
//  反转字符，例如 i like beijing！ 变为 beijing! like i
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	string s1;
	while (getline(cin, s))
	{
		stack <char> q;
		auto it = s.rbegin();
		while (it != s.rend())
		{
			while (it != s.rend() && *it != ' ')
			{
				q.push(*it);
				it++;
			}

			while (!q.empty())
			{
				s1.push_back(q.top());
				q.pop();
			}
			
			if (it != s.rend())
			{
				s1.push_back(*it);
				it++;
			}
				
		}
		cout << s1;
	}

	return 0;
}
#endif 

// 通过90%
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	int a;
	while (cin >> n)
	{
		v.resize(n+1);
		int i = 0;
		int count = 0;
		int flag = 0;
		for (i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		
		for (i = 0; i < n-1; i++)
		{
			if (i<n - 1 && v[i]>=v[i + 1])
			{
				i++;
				while (i < n - 1 && v[i] >= v[i + 1])
				{
					++i;
				}
				count++;
			}
			else if (i < n - 1 && v[i] <= v[i + 1])
			{
				i++;
				while (i < n - 1 && v[i] <= v[i + 1])
				{
					i++;
				}
				count++;
			}
			if (i == n - 2)
				count++;
		}
		
		cout << count;

	}

	return 0;
}
