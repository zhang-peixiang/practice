#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <vector>
#include <algorithm>>
#include <unordered_map>


using namespace std;

// ����֮��
// ��ϣ
// ˼·��
// 1. ������λ�÷���hash�У�key-value
// 2. ����hashʱ���ڹ�ϣ����Ѱ���Ƿ���target-nums[i]��ֵ������з����±꣬û�н�����룬������һ����
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return{ it->second, i };
			}
			hashtable[nums[i]] = i;
		}
		return{};
	}
};



// ������
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> v;
//		vector<int> v1(nums);
//		v.clear();
//		sort(nums.begin(), nums.end());
//		int left = 0;
//		int right = nums.size() - 1;
//		while (left<right)
//		{
//			int sum = nums[left] + nums[right];
//			if (sum<target)
//			{
//				left++;
//			}
//			else if (sum == target)
//			{
//				int flag1 = 0;
//				int flag2 = 0;
//				for (int i = 0; i<v1.size(); i++)
//				{
//					if (v.size() == 2)
//					{
//						break;
//					}
//					if (v1[i] == nums[left] && flag1 == 0)
//					{
//						flag1 = 1;
//						v.push_back(i);
//					}
//					else if (v1[i] == nums[right] && flag2 == 0)
//					{
//						flag2 = 1;
//						v.push_back(i);
//					}
//				}
//				break;
//			}
//			else
//			{
//				right--;
//			}
//		}
//		return v;
//	}
//};


int main()
{
	Solution s;
	vector<int> v1;
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	int ret = 6;
	v1 = s.twoSum(v, ret);

	return 0;
}