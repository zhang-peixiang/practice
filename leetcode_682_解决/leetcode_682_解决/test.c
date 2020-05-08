#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//你现在是棒球比赛记录员。
//给定一个字符串列表，每个字符串可以是以下四种类型之一：
//1.整数（一轮的得分）：直接表示您在本轮中获得的积分数。
//2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
//3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
//4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。
//每一轮的操作都是永久性的，可能会对前一轮和后一轮产生影响。
//你需要返回你在所有回合中得分的总和。

//erro--值溢出--int count --int 类型存放不下例子的值
//int calPoints(char** ops, int opsSize)
//{
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	int b = 0;//用来移动Score的值
//	int Score1[20] = { 0 };
//	//int* Score1 = (int*)calloc(opsSize,sizeof(int));//用来存放类型转换之后的值--存放每一轮的得分
//	//int* Score = (int*)calloc(opsSize,sizeof(int));//存放每一轮的得分
//	for (i = 0; i < opsSize; i++)
//	{
//		int a = 0;//10的幂
//		int count = 0;//用来计算char变int的数值
//		for (j = 0; ops[i][j] != 0; j++)
//		{
//			if (ops[i][j] != '-' && ops[i][j] != 'C' && ops[i][j] != 'D')
//			{
//				ops[i][j];
//				int c = ((int)ops[i][j]) - 48;
//				count = count * pow(10, a) + ((int)ops[i][j]) - 48;
//				a++;
//			}
//		}
//		if (ops[i][0] == '-')
//		{
//			count = -1 * count;
//			Score1[b] = count;
//		}
//		else if (ops[i][0] == 'C')
//		{
//			Score1[b - 1] = 0;
//			/*Score[b - 1] = 0;*/
//			b -= 2;
//		}
//		else if (ops[i][0] == 'D')
//		{
//			count = abs(Score1[b - 1]) * 2;
//			if (Score1[b - 1]<0)
//			{
//				count = -count;
//			}
//			Score1[b] = count;
//		}
//		else if (ops[i][0] == '+')
//		{
//			count = Score1[b - 1] + Score1[b - 2];
//			Score1[b] = count;
//		}
//		else
//		{
//			Score1[b] = count;
//		}
//		/*sum += count;
//		Score[b] = sum;*/
//		b++;
//	}
//	for (i = 0; i < opsSize; i++)
//	{
//		sum += Score1[i];
//	}
//	return sum;
//}
int calPoints(char ops[][10], int opsSize)
{
	int i = 0;
	int sum = 0;
	int b = 0;//用来移动Score的值
	//int Score1[100] = { 0 };
	int* Score1 = (int*)calloc(opsSize,sizeof(int));//用来存放类型转换之后的值--存放每一轮的得分

	for (i = 0; i < opsSize; i++)
	{
		if (ops[i][0] == 'C')
		{
			Score1[b - 1] = 0;
			b -= 2;
		}
		else if (ops[i][0] == 'D')
		{
			Score1[b] = Score1[b - 1] * 2;
		}
		else if (ops[i][0] == '+')
		{
			Score1[b] = Score1[b - 1] + Score1[b - 2];
		}
		else
		{
			Score1[b] = atoi(ops[i]);
		}
		b++;
	}
	for (i = 0; i < opsSize; i++)
	{
		sum += Score1[i];
	}
	return sum;
}

int main()
{
	char str[][10] = { "15788", "25148", "-24609", "24869", "D", "-23282", "14614",
		"-2921", "C", "-26517", "1891", "C", "-18324", "+", "+", "-23184",
		"D", "-12585", "C", "D", "7308", "-11988", "-16148", "+", "8834",
		"+", "+", "D", "19519", "+", "11289", "+", "D", "C", "-13033", "D",
		"+", "-278", "-14043", "C", "-906", "C", "28518", "C", "-29295",
		"-22758", "-13872", "-20255", "29870", "-1104" };//字符0的ASCLL码值为48
	int sz = sizeof(str) / sizeof(str[0]);
	int ret = calPoints(str, sz);
	printf("%d\n", ret);
	return 0;
}



//int main()
//{
//	char str1 = '12';
//	char str2 = '1';
//	int a = (int)str1 + (int)str2;
//	return 0;
//}