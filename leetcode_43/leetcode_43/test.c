#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//错误i！！
//char * multiply(char * num1, char * num2)
//{
//	int len1 = strlen(num1);
//	int len2 = strlen(num2);
//	if (len1 == 0)
//		return len2;
//	if (len2 == 0)
//		return len1;
//
//	if (len1 == 1 && num1[0] == '0')
//		return num1;
//	if (len2 == 1 && num2[0] == '0')
//		return num2;
//
//	int len = len1 + len2;
//	int a = 0; //表示相乘之后的数
//	int b = 0;
//	int c = 0;
//	int i = 0;
//	int j = 0;
//
//	int count = 0; //统计s中开头有几个0
//	char* s = (char*)calloc(len + 1, sizeof(char));
//	int tmp = len - 1;
//
//	j = len2 - 1;
//	while (j >= 0)
//	{
//		i = len1 - 1;
//		tmp = len - 1 - c;
//		while (i >= 0)
//		{
//			a += (num1[i--] - '0')*(num2[j] - '0')*pow(10, b);
//			b++;
//		}
//		j--;
//		b = 0;
//		int p = 0;
//		if (a == 0)
//		{
//			int q = 0;
//			if (s[tmp] == '\0')
//			{
//				q = s[tmp] + a % 10 + p;
//			}
//			else
//			{
//				q = s[tmp] - '0' + a % 10 + p;
//			}
//			p = q / 10;
//			s[tmp] = q % 10 + '0';
//		}
//		while (a > 0)
//		{
//			int q = 0;
//			if (s[tmp] == '\0')
//			{
//				q = s[tmp] + a % 10 + p;
//			}
//			else
//			{
//				q = s[tmp] - '0' + a % 10 + p;
//			}
//			p = q / 10;
//			s[tmp] = q % 10 + '0';
//			tmp--;
//			a /= 10;
//		}
//		while (p > 0)
//		{
//			int q = 0;
//			if (s[tmp] == '\0')
//			{
//				q = s[tmp] + p;
//			}
//			else
//			{
//				q = s[tmp] - '0' + p;
//			}
//			p = q / 10;
//			s[tmp] = q % 10 + '0';
//			tmp--;
//		}
//		c++;
//	}
//
//	
//
//	for (i = 0; i < len; i++)
//	{
//		if (s[i] != '\0')
//			break;
//		count++;
//	}
//	i = 0;
//	j = count;
//	while (j < len + 1)
//	{
//		s[i++] = s[j++];
//	}
//
//	return s;
//}

// 别人答案
char* addStrings(char* num1, char* num2) {
	int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
	char* ans = malloc(sizeof(char)* (i + j + 5));
	int ansLen = 0;
	while (i >= 0 || j >= 0 || add != 0) {
		int x = i >= 0 ? num1[i] - '0' : 0;
		int y = j >= 0 ? num2[j] - '0' : 0;
		int result = x + y + add;
		ans[ansLen++] = result % 10;
		add = result / 10;
		i--;
		j--;
	}
	for (int i = 0; i < ansLen / 2; i++) {
		char t = ans[i];
		ans[i] = ans[ansLen - 1 - i];
		ans[ansLen - 1 - i] = t;
	}
	for (int i = 0; i < ansLen; i++) {
		ans[i] += '0';
	}
	ans[ansLen++] = 0;
	return ans;
}

char* multiply(char* num1, char* num2) {
	int m = strlen(num1), n = strlen(num2);
	char* ans = malloc(sizeof(char)* 2);
	ans[0] = '0', ans[1] = 0;
	if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
		return ans;
	}
	for (int i = n - 1; i >= 0; i--) {
		char* curr = malloc(sizeof(char)* (n + m + 5));
		int currLen = 0;
		int add = 0;
		for (int j = n - 1; j > i; j--) {
			curr[currLen++] = 0;
		}
		int y = num2[i] - '0';
		for (int j = m - 1; j >= 0; j--) {
			int x = num1[j] - '0';
			int product = x * y + add;
			curr[currLen++] = product % 10;
			add = product / 10;
		}
		while (add != 0) {
			curr[currLen++] = add % 10;
			add /= 10;
		}
		for (int i = 0; i < currLen / 2; i++) {
			char t = curr[i];
			curr[i] = curr[currLen - 1 - i];
			curr[currLen - 1 - i] = t;
		}
		for (int i = 0; i < currLen; i++) {
			curr[i] += '0';
		}
		curr[currLen++] = 0;
		char* tmp = addStrings(ans, curr);
		free(ans), free(curr);
		ans = tmp;
	}
	return ans;
}



int main()
{
	char s1[] = "12";
	char s2[] = "308";

	char* s= multiply(s1, s2);
	return 0;
}



