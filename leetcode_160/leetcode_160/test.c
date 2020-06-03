#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//编写一个程序，找到两个单链表相交的起始节点。

struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;
	int count1 = 0;
	int count2 = 0;

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
	int tmp = count1 - count2;
	if (tmp > 0)
	{
		while (tmp--)
		{
			cur1 = cur1->next;
		}
	}
	else if (tmp < 0)
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
