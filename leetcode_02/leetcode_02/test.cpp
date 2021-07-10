#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
using namespace std;

// �������

/*˼·��

1. �������������
   1�� l1��l2����Ϊ��
   2�� l1Ϊ�� l2��Ϊ��
   3�� l1��Ϊ�� l2Ϊ��

����tmp��ʾ������ӵ�ֵ
����ret ��ʾ�Ƿ��λ

��tmp����9ʱ����ret=1��
��ret = 1ʱ��l�ĳ�ʼ��val=1��

*/


 struct ListNode {
     int val;
	 ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 
 
class Solution 
{
public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	 {
		 struct ListNode* l = new struct ListNode;
		 struct ListNode* ls = new struct ListNode;

		 ls->next = l;
		 int ret = 0;
		 while (l1 != nullptr || l2 != nullptr)
		 {
			 int tmp = 0;

			 struct ListNode* f = new struct ListNode;
			 if (ret > 0)
			 {
				 l->val = 1;
				 ret = 0;
			 }
			 l->next = f;
			 if (l1 != nullptr && l2 != nullptr)
			 {

				 tmp = l1->val + l2->val + l->val;
				 if (tmp > 9)
				 {
					 ret = 1;
					 tmp = tmp % 10;
				 }
				 l->val = tmp;
				 l = l->next;
				 l1 = l1->next;
				 l2 = l2->next;
			 }
			 else if (l1 == nullptr && l2 != nullptr)
			 {
				 tmp = l2->val + l->val;
				 if (tmp > 9)
				 {
					 ret = 1;
					 tmp = tmp % 10;
				 }
				 l->val = tmp;
				 l = l->next;
				 l2 = l2->next;
			 }
			 else if (l1 != nullptr && l2 == nullptr)
			 {
				 tmp = l1->val + l->val;
				 if (tmp > 9)
				 {
					 ret = 1;
					 tmp = tmp % 10;
				 }
				 l->val = tmp;
				 l = l->next;
				 l1 = l1->next;
			 }
		 }
		 l = ls->next;
		 while (l->next)
		 {
			 if (l->next->next == NULL)
			 {
				 break;
			 }
			 l = l->next;
		 }
		 if (ret > 0)
		 {
			 l->next->val = 1;
			 ret = 0;
		 }
		 else
		 {
			 l->next = NULL;
		 }
		 return ls->next;
	 }
 };

int main()
{

	struct ListNode* l1 = new struct ListNode;
	l1->val = 2;
	struct ListNode* l11 = new struct ListNode;
	l11->val = 4;
	l1->next = l11;
	struct ListNode* l12 = new struct ListNode;
	l12->val = 3;
	l11->next = l12;
	struct ListNode* l13 = new struct ListNode;
	l13->val = NULL;
	l12->next = l13;

	struct ListNode* l2 = new struct ListNode;
	l2->val = 5;
	struct ListNode* l21 = new struct ListNode;
	l21->val = 6;
	l2->next = l21;
	struct ListNode* l22 = new struct ListNode;
	l22->val = 4;
	l21->next = l22;
	struct ListNode* l23 = new struct ListNode;
	l23->val = NULL;
	l22->next = l23;

	struct ListNode* l4 = new struct ListNode;
	Solution s;
	l4 = s.addTwoNumbers(l1, l2);

	return 0;
}