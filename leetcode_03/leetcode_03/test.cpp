#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;


// ˼·
// ����ָ��
// �̶���ָ�룬��ָ�������ƶ����ж�����ָ���м��Ƿ����ظ��ַ�
// û���ظ��ַ�����ָ��һֱ�����ƶ�
// ���ظ��ַ�������ָ����ָ����ַ���set��ɾ����Ȼ����ָ�������ƶ�1�������ָ������ƶ����ж��Ƿ����ظ�

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