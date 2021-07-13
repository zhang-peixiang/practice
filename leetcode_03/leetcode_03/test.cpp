#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;


// 思路
// 左右指针
// 固定左指针，右指针往右移动，判断左右指针中间是否有重复字符
// 没有重复字符，右指针一直往右移动
// 有重复字符，将左指针所指向的字符从set中删除，然后左指针向右移动1，随后右指针继续移动，判断是否有重复

class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> hash;
		int flag = -1;
		int maxlen = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i != 0)
			{
				hash.erase(s[i - 1]);
			}
			while (flag + 1 < s.size() && 0 == hash.count(s[flag+1]))
			{
				hash.insert(s[flag + 1]);
				flag++;
			}
			maxlen = max(maxlen, flag - i + 1);
			if (flag + 1 == s.size())
			{
				break;
			}
		}

		return maxlen;
	}
};

int main()
{
	string s("cdd");
	Solution s1;
	s1.lengthOfLongestSubstring(s);
	return 0;
}