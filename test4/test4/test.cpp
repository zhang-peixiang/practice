#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include <iostream>
using namespace std;
class Solution {
public:
	int StrToInt(string str) 
	{
		int i = 0;
		int n = str.size();
		int count = 0;
		int flag = 3;
		for (i = 0; i < n; i++)
		{
			int tmp = str[i] - '0';
			if ((i == 0) && (str[i] == '+' || str[i] == '-'))
			{
				if (str[i] == '+')
					flag = 1;
				else if (str[i] == '-')
					flag = 0;
			}
			else if (tmp >= 0 && tmp < 10)
			{
				count = count * 10 + tmp;
			}
			else
				return 0;
		}
		if (flag == 0)
			count = -count;
		return count;
	}
};

#endif


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	vector<int> v;
	while (cin >> n)
	{
		int i = 0;
		int a = 0;
		int tmp = 0;
		int count = 0;
		int max = 0;
		for (i = 0; i < n; ++i)
		{
			cin >> a;
			v.push_back(a);
		}
		tmp = v[0];
		max = v[0];
		for (i = 1; i < n; i++)
		{
			count = tmp;
			tmp += v[i];
			if (count>tmp)
			{
				if (count > max)
				{
					max = count;
				}
				tmp = 0;
			}
		}
		if (max<0 && v[n - 1]>0)
		{
			max = v[n - 1];
		}
		else if (tmp > max)
			cout << tmp;
		v.clear();
		
		cout << max << endl;
	}
	return 0;
}