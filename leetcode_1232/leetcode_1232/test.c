#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，
//其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。
//请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。


//bool checkStraightLine(int coordinates[][2], int coordinatesSize, int* coordinatesColSize)
//{
//	int i = 0;
//	int count = 0;
//	if (coordinatesSize < 3)
//		return true;
//	for (i = 0; i < coordinatesSize - 2; i++)
//	{
//		int ret1 = (coordinates[i + 2][0] - coordinates[i + 1][0]);
//		int ret2 = (coordinates[i + 2][1] - coordinates[i + 1][1]);
//		int tmp1 = (coordinates[i + 1][0] - coordinates[i][0]);
//		int tmp2 = (coordinates[i + 1][1] - coordinates[i][1]);
//		if (ret2 == 0 && tmp2 != 0)
//		{
//			count++;
//			return false;
//		}
//		else if (tmp2 == 0 && ret2 != 0)
//		{
//			count++;
//			return false;
//		}
//		else if (ret1 == 0 && tmp1 != 0)
//		{
//			count++;
//			return false;
//		}
//		else if (tmp1 == 0 && ret1 != 0)
//		{
//			count++;
//			return false;
//		}
//		double ret3 = (ret2 / ret1)*1.0;
//		double tmp3 = (tmp2 / tmp1)*1.0;
//		if (ret3 != tmp3)
//		{
//			return false;
//		}
//	}
//	return true;
//}


bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
	double x = coordinates[1][0] - coordinates[0][0], y = coordinates[1][1] - coordinates[0][1];
	double k;
	int t = 0;
	if (y == 0)
		t = 1;
	else
		k = x / y;
	for (int i = 1; i<coordinatesSize - 1; i++){
		y = coordinates[i + 1][1] - coordinates[i][1];
		if (t&&y)
			return false;
		x = coordinates[i + 1][0] - coordinates[i][0];
		if (!t&&k != x / y)
			return false;
	}
	return true;
}

int main()
{
	int arr[][2] = { { 1, 1 }, { 2, 2 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 7, 7 } };
	int row = sizeof(arr) / sizeof(arr[1]);
	int col = sizeof(arr[1]) / sizeof(arr[1][1]);
	int ret = checkStraightLine(arr, row, &col);
	printf("%d\n", ret);
	return 0;
}