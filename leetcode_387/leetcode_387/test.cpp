#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;


// ����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
class Solution {
public:
	int firstUniqChar(string s) 
	{
		size_t sz = s.size();
		// 97-122 Сд��ĸ��asc��ֵ
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