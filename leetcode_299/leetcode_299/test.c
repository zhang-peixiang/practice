#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。
//每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），
//有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
//
//请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。

/*
1.先找公牛（对应位置数字相同），统计数量
2.找奶牛（位置不同，数字相同），遍历数组，如果有相同，直接跳出循环，并将该位置上改为取不到的char，避免有重复的数字时重复计算。
3.将公牛，奶牛对应放到开辟的空间中，然后返回。
*/

char * getHint(char * secret, char * guess)
{
	int i = 0;
	int j = 0;
	int len = strlen(secret);
	int count1 = 0;
	int count2 = 0;
	char* return_arr = (char*)calloc(100,sizeof(char));
	for (i = 0; i < len; i++)
	{
		if (secret[i] == guess[i])
		{
			count1++;
		}
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (secret[i] == guess[j])
			{
				count2++;
				guess[j] = 'q';
				break;
			}
		}
	}
	sprintf(return_arr, "%d %c %d %c", count1, 'A', count2 - count1, 'B');
	return return_arr;
}


int main()
{
	char str1[] = "1807";
	char str2[] = "7810";
	getHint(str1, str2);

	return 0;
}