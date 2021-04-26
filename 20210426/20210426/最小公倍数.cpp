
// 求最小公倍数
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int ret = 0;
	cin >> a >> b;
	if (a>b)
	{
		ret = a;
	}
	else
	{
		ret = b;
	}

	while (ret <= a*b)
	{
		if (ret%a == 0 && ret %b == 0)
		{
			cout << ret << endl;
			break;
		}
		ret++;
	}
	return 0;
}
