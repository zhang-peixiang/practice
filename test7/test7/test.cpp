#define _CRT_SECURE_NO_WARNINGS 1



#if 0

  :90%
#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	while (cin >> n)
	{
		if (n < 4)
		{
			return 0;
		}
		int a = 1;
		int b = 1;
		int c = 0;
		int min = 0;
		while (c<=n)
		{
			c = a + b;
			a = b;
			b = c;
		}
		if ((c - n) > (n - a))
			cout << n - a;
		else
			cout << c - n;
	}
	return 0;
}
#endif



// :100%
#include <iostream>
#include <stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) 
	{
		if (n % 2 == 1)
		{
			return false;
		}
		stack<char> s;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == '(' || A[i] == ')')
			{
				if (A[i] == '(')
					s.push(A[i]);
				else
				{
					if (s.empty())
						return false;
					s.pop();
				}
			}
			else
			{
				return false;
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};