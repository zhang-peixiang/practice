#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

// 给定一个字符串 S，返回 “反转后的” 字符串，
// 其中不是字母的字符都保留在原地，而所有字母的位置发生反



class Solution {
public:
	string reverseOnlyLetters(string S)
	{
		size_t sz = S.size();
		size_t left = 0;
		size_t right = sz - 1;
		// 65--90   97-122	
		while (left < right)
		{
			if (((S[left] >= 65 && S[left] <= 90) || (S[left] >= 97 && S[left] <= 122))
				&& ((S[right] >= 65 && S[right] <= 90) || (S[right] >= 97 && S[right] <= 122)))
			{
				char tmp = S[left];
				S[left] = S[right];
				S[right] = tmp;
				right--;
				left++;
			}
			else if ((S[left] >= 65 && S[left] <= 90) || (S[left] >= 97 && S[left] <= 122))
			{
				right--;
			}
			else
			{
				left++;
			}
		}
		return S;
	}
};
int main()
{
	Solution s;
	string s1("jIhg-fEd-Cb-a");
	s.reverseOnlyLetters(s1);
	return 0;
}