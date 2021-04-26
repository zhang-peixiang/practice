// ÅÐ¶Ï×Ö·û´®µÄÅÅÐò
#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	vector<string> v;
	string s;
	cin >> n;
	if (n <= 1)
	{
		cout << "both" << endl;
		return 0;
	}
	for (int i = 0; i<n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	int ret1 = 1;
	int ret2 = 1;

	// ÅÐ¶Ï
	for (int j = 0; j<v.size() - 1; ++j)
	{
		string s1 = v[j];
		string s2 = v[j + 1];
		if (s1.compare(s2) != 1)
		{
			ret1++;
		}

		if (s1.size() <= s2.size())
		{
			ret2++;
		}
	}

	if (ret1 == n && ret2 == n)
	{
		cout << "both" << endl;
	}
	else if (ret1 == n)
	{
		cout << "lexicographically" << endl;
	}
	else if (ret2 == n)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}
#endif