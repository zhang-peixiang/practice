#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <string>
//
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

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