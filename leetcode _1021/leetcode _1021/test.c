#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串， + 代表字符串的连接。
//例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
//如果有效字符串 S 非空，且不存在将其拆分为 S = A + B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
//给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
//对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。
//char * removeOuterParentheses(char * S)//erro
//{
//	int len = strlen(S);
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	int count1 = 0;
//	int count2 = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (S[i] == '('&& S[i + 1] != ')')//判断是否是最外层括号，并将外括号'(' 删除
//		{
//			for (a = i+1; a < len; a++)
//			{
//				if (S[a] == '('&& S[a + 1] != ')')
//				{
//					for (j = i; j < len; j++)
//					{
//						S[j] = S[j + 1];
//					}
//					S[len - 1] = '\0';
//					len--;
//					i--;
//					break;
//				}
//			}
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		if (S[i] == '(')
//		{
//			count1++;
//		}
//		else
//		{
//			count2++;
//		}
//		if (count2>count1)
//		{
//			S[i] = '0';//将多余的')'变成0，进行标记，在下面代码中进行删除。
//			count2--;
//		}
//	}
//	for (i = 0; i < len; i++)//将'0'删除
//	{
//		if (S[i] == '0')
//		{
//			for (j = i; j < len; j++)
//			{
//				S[i] = S[i + 1];
//			}
//			S[len - 1] = '\0';
//			len--;
//			i--;
//		}
//	}
//
//	return S;
//}
//char * removeOuterParentheses(char * S)//erro 
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	int len = strlen(S);
//	for (i = 0; i < len; i++)
//	{
//		int count1 = 0;
//		int count2 = 0;
//		if (S[i] == '(' &&S[i + 1] != ')')
//		{
//			for (j = i; j < len; j++)
//			{
//				if (S[j] == '(')
//				{
//					count1++;
//				}
//				else
//				{
//					count2++;
//				}
//				if (count1 == count2)//删除外括号 ')' 
//				{
//					for (a = j; a < len-1; a++)
//					{
//						S[a] = S[a + 1];
//					}
//					S[len - 1] = '\0';
//					len--;
//					break;
//				}
//			}
//			for (a = i; a < len-1; a++)
//			{
//				S[a] = S[a + 1];
//			}
//			S[len - 1] = '\0';
//			len--;
//		}
//		i = j-2;
//	}
//	return S;
//}
#include <assert.h>
char * removeOuterParentheses(char * S)
{
	assert(S);//断言S不能为空指针
	int i = 0;
	int j = 0;
	int a = 0;
	int len = strlen(S);
	for (i = 0; i < len; i++)
	{
		int count1 = 0;
		int count2 = 0;
		for (j = i; j < len; j++)
		{
			if (S[j] == '(')
			{
				count1++;
			}
			else
			{
				count2++;
			}
			if (count1 == count2)
				//当count1和count2相等时，确定最外层括号。
			{
				for (a = j; a < len - 1; a++)
					//字符串左移，覆盖最外层括号中的 ')'
				{
					S[a] = S[a + 1];
				}
				S[len - 1] = '\0';
				len--;
				break;
				//跳出循环，此时的j记录的是最外层括号中的 ')' 的位置
			}
		}
		for (a = i; a < len - 1; a++)
		//字符串左移，覆盖最外层括号中的 '('
		{
			S[a] = S[a + 1];
		}
		S[len - 1] = '\0';
		len--;
		i = j - 2;
		// j记录的是字符串未左移之前的外层括号的 ')' 位置，
		//循环应该从j开始，但是字符串左移两次，所以从j=2开始。
	}
	return S;
}

int main()
{
	char str[] = "(()())(())";
	char* ret = removeOuterParentheses(str);
	printf("%s\n", ret);
	return 0;
}