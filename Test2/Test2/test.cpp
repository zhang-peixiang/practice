#define _CRT_SECURE_NO_WARNINGS 1


#if 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		sort(numbers.begin(), numbers.end());
		int n = numbers.size();
		int count = 1;
		for (int i = 0; i < n-1; i++)
		{
			if (numbers[i] == numbers[i + 1])
			{
				count++;
				if (count>n / 2)
					return numbers[i];
			}
			else
			{
				count = 1;
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> v{ 1,2,3,2,2,2,5,4,2};
	Solution s;
	int a = s.MoreThanHalfNum_Solution(v);

	return 0;
}

#endif 


#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.size();
		string s1;
		string s2;
		int count = 0;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			s1.clear();
			if (s[i] - '0' >= 0 && s[i] - '0' < 10)
			{
				while (i<n && s[i] - '0' >= 0 && s[i] - '0' < 10)
				{
					s1.push_back(s[i]);
					i++;
				}
				if (s1.size()>s2.size())
				{
					s2 = s1;
				}
			}
		}
		cout << s2 << endl;
		s2.resize(0);
	}
	return 0;
}

#endif