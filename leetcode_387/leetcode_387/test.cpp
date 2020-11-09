#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;


// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
class Solution {
public:
	int firstUniqChar(string s) 
	{
		size_t sz = s.size();
		// 97-122 小写字母的asc码值
		int* arr = new int[26];
		memset(arr, 0, sizeof(int)* 26);
		for (size_t i = 0; i < sz; i++)
		{
			arr[s[i] - 'a']++;
		}
		for (size_t i = 0; i < sz; i++)
		{
			if (arr[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};