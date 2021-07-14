#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// ��̬�滮
// ˼·
// ���жϳ���Ϊ2���Ӵ��Ƿ�Ϊ�����ַ�����Ȼ���жϳ���Ϊ3��ֱ���жϳ���Ϊn
// �Ӵ�����С�ڵ���3ʱ��ֻ���жϵ�һ���ַ������һ���ַ��Ƿ���ȣ������Ϊ���Ĵ�
// �Ӵ����ȴ���3ʱ�� �ж��Ӵ��Ƿ�Ϊ���Ĵ���Ҫ���ж�[i][j]�Ƿ���ͬ����ͬ���ж�[i+1][j-1]�Ƿ��ǻ��Ĵ�������ǣ�����Ӵ�Ϊ�����ַ���

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
//		// dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
//		vector<vector<int>> dp(n, vector<int>(n));
//		// ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
//		for (int i = 0; i < n; i++) {
//			dp[i][i] = true;
//		}
//		// ���ƿ�ʼ
//		// ��ö���Ӵ�����
//		for (int L = 2; L <= n; L++) {
//			// ö����߽磬��߽���������ÿ��Կ���һЩ
//			for (int i = 0; i < n; i++) 
//			{
//				// �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
//				int j = L + i - 1;
//				// ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
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
//				// ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
//				if (dp[i][j] && j - i + 1 > maxLen) {
//					maxLen = j - i + 1;
//					begin = i;
//				}
//			}
//		}
//		return s.substr(begin, maxLen);
//	}
//};

// ��̬�滮˼·ͬ��
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


// ������ ��ʱ
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