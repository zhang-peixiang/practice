#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

/*
1.判断链表是否相交
2.哪个链表长 就让那个链表先走K步，K等于两个链表长度的差
3.然后同时向后移动，判断是否相等
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;
	int count1 = 0;
	int count2 = 0;
	int tmp = 0;
	while (cur1->next)
	{
		cur1 = cur1->next;
		count1++;
	}
	while (cur2->next)
	{
		cur2 = cur2->next;
		count2++;
	}
	if (cur1 != cur2)
	{
		return NULL;
	}
	cur1 = headA;
	cur2 = headB;
	tmp = count1 - count2;
	if (tmp > 0)
	{
		while (tmp--)
		{
			cur1 = cur1->next;
		}
	}
	else
	{
		while (tmp++)
		{
			cur2 = cur2->next;
		}
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}