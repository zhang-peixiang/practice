#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
/*
1.给四个指针，标记四个节点，令第一个指针指向第三个指针，第二个指针指向第四个指针
2.令第一个指针等于第三个指针，第二个指针等于第四个指针
3.因为循环一次只改变两个指针指向，所以循环条件直接判断第三个指针和第四个指针就可以
4.因为存在3个节点的情况，所以在开始就要对第四个指针进行判空操作。
*/
struct ListNode* oddEvenList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	if (head->next->next == NULL)
		return head;
	struct ListNode* pre = head;
	struct ListNode* left = head->next;
	struct ListNode* right = left->next;
	struct ListNode* next = right->next;
	if (next == NULL)
	{
		pre->next = right;
		left->next = next;
		right->next = left;
		return head;
	}
	struct ListNode* ret = head->next;//标记偶数节点的第一个节点
	
	while (next && right)
	{
		left = pre->next;
		right = left->next;
		if (right == NULL)
		{
			pre->next = ret;
			break;
		}
		next = right->next;

		pre->next = right;
		left->next = next;

		pre = right;
	}
	if (next == NULL)
		right->next = ret;

	return head;
}