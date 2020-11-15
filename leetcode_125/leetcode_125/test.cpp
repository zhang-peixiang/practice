#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <string>
//
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。

class Solution {
public:
	bool isPalindrome(string s)
	{
		int len = s.size();
		if (len == 0)
		{
			return true;
		}
		int left = 0;
		int right = len - 1;
		while (left < right)
		{
			while ((left < right) && !isalnum(s[left]))
			{
				left++;
			}
			while ((left < right) && !isalnum(s[right]))
			{
				right--;
			}
			if (left < right)
			{
				if (tolower(s[left]) != tolower(s[right]))
					return false;
			}
				
			
			left++;
			right--;
		}
		
		return true;
	}
};

int main()
{
	Solution v;
	string s("a.");
	int a = v.isPalindrome(s);
	return 0;
}