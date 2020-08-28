#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//在二维平面上，有一个机器人从原点(0, 0) 开始。给出它的移动顺序，
//判断这个机器人在完成移动后是否在 (0, 0) 处结束。
//
//移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。
//机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
//如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
//
//注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，
//“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
//

bool judgeCircle(char * moves)
{
	int rcount = 0;
	int lcount = 0;
	int ucount = 0;
	int dcount = 0;
	int len = strlen(moves);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (moves[i] == 'R')
			rcount++;
		else if (moves[i] == 'L')
			lcount++;
		else if (moves[i] == 'U')
			ucount++;
		else
			dcount++;
	}
	if (rcount == lcount && ucount == dcount)
		return true;
	return false;
}