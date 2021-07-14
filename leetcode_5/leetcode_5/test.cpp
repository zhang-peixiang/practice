#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// 动态规划
// 思路
// 先判断长度为2的子串是否为回文字符串，然后判断长度为3，直到判断长度为n
// 子串长度小于等于3时，只用判断第一个字符和最后一个字符是否相等，相等则为回文串
// 子串长度大于3时， 判断子串是否为回文串需要先判断[i][j]是否相同，相同再判断[i+1][j-1]是否是回文串，如果是，则该子串为回文字符串

//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int n = s.size();
//		if (n < 2) {
//			return s;
//		}
//
//		int maxLen = 1;
//		int begin = 0;
//		// dp[i][j] 表示 s[i..j] 是否是回文串
//		vector<vector<int>> dp(n, vector<int>(n));
//		// 初始化：所有长度为 1 的子串都是回文串
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = true;
//		}
//		// 递推开始
//		// 先枚举子串长度
//		for (int L = 2; L <= n; L++) {
//			// 枚举左边界，左边界的上限设置可以宽松一些
//			for (int i = 0; i < n; i++) 
//			{
//				// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//				int j = L + i - 1;
//				// 如果右边界越界，就可以退出当前循环
//				if (j >= n) {
//					break;
//				}
//
//				if (s[i] != s[j]) {
//					dp[i][j] = false;
//				}
//				else {
//					if (j - i < 3) {
//						dp[i][j] = true;
//					}
//					else {
//						dp[i][j] = dp[i + 1][j - 1];
//					}
//				}
//
//				// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//				if (dp[i][j] && j - i + 1 > maxLen) {
//					maxLen = j - i + 1;
//					begin = i;
//				}
//			}
//		}
//		return s.substr(begin, maxLen);
//	}
//};

// 动态规划思路同上
class Solution {
public:
	string longestPalindrome(string s)
	{
		int n = s.size();
		if (n<2)
		{
			return s;
		}
		int L = 2;
		int max = 1;
		vector<vector<int>> dp(n, vector<int>(n));
		int begin = 0;
		int i = 0;
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			dp[i][i] = 1;
		}
		for (L = 2; L <= n; ++L)
		{
			if (L > n)
			{
				break;
			}
			for (i = 0; i < n; ++i)
			{
				j = L + i - 1;
				if (j > n - 1)
				{
					break;
				}
				if (s[i] != s[j])
				{
					dp[i][j] = 0;
				}
				else
				{
					if (L - 1 <3)
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				if (dp[i][j] == 1 && L > max)
				{
					max = L;
					begin = i;
				}
			}

		}

		return s.substr(begin, max);
	}
};


// 暴力法 超时
//class Solution {
//public:
//	string longestPalindrome(string s)
//	{
//		if (s.size() < 2)
//		{
//			return s;
//		}
//		int i = 0;
//		int j = 0;
//		int max = 1;
//		int maxi = 0;
//		int maxj = 0;
//		int ret = 0;
//		for (i = 0; i < s.size() - 1; ++i)
//		{
//			for (j = i + 1; j < s.size(); ++j)
//			{
//				if (is_huiwen(s, i, j))
//				{
//					ret = j - i + 1;
//					if (ret > max)
//					{
//						max = ret;
//						maxi = i;
//						maxj = j;
//					}
//				}
//			}
//		}
//		string s1;
//		while (maxi <= maxj)
//		{
//			s1.push_back(s[maxi]);
//			++maxi;
//		}
//		return s1;
//	}
//
//
//	bool is_huiwen(string s, int i, int j)
//	{
//		while (i < j)
//		{
//			if (s[i] != s[j])
//			{
//				return false;
//			}
//			i++;
//			j--;
//		}
//		return true;
//	}
//	
//};

int main()
{
	string s("bb");
	Solution s1;
	s1.longestPalindrome(s);
	return 0;
}