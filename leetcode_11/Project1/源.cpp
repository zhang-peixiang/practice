#include <iostream>
#include <vector>

using namespace std;

// 超时
//class Solution {
//public:
//	int maxArea(vector<int>& height)
//	{
//		if (height.size() == 0)
//		{
//			return 0;
//		}
//		int prex = 0;
//		int prey = 0;
//		int nextx = 0;
//		int nexty = 0;
//		int max = height[0];
//		int ret = 0;
//		for (int i = 0; i<height.size(); i++)
//		{
//			ret = 0;
//			prex = i;
//			prey = height[i];
//			
//			for (int j = i + 1; j<height.size(); j++)
//			{
//				int min = prey;
//				nextx = j;
//				nexty = height[j];
//				if (nexty < prey)
//				{
//					min = nexty;
//				}
//				ret = (nextx - prex)*min;
//				if (ret>max)
//				{
//					max = ret;
//				}
//			}
//		}
//		return max;
//	}
//};

// 双指针法 左右指针移动
class Solution {
public:
	int maxArea(vector<int>& height)
	{
		if (height.size() == 0)
		{
			return 0;
		}
		if (height.size() == 1)
		{
			return height[0];
		}
		int left = 0;
		int right = height.size() - 1;
		int max = 0;
		int ret = 0;
		while (left < right)
		{
			int min = height[left];
			if (min > height[right])
			{
				min = height[right];
			}
			ret = (right - left)* min;
			if (ret > max)
			{
				max = ret;
			}
			if (min == height[left])
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return max;
	}
};



int main()
{
	Solution s;
	int arr[] = { 4, 3, 2, 1, 4 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	int a = s.maxArea(v);

	return 0;
}