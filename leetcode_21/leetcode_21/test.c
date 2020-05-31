#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct ListNode* head = NULL;
	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;
	struct ListNode* prev = NULL;
	struct ListNode* next = NULL;
	if (cur1->val > cur2->val)
	{
		head = cur2;
		cur2 = cur2->next;
	}
	else
	{
		head = cur1;
		cur1 = cur1->next;
	}
	prev = head;
	while (cur1 && cur2)
	{
		if (cur1->val < cur2->val)
		{
			next = cur1->next;
			prev->next = cur1;
			prev = prev->next;
			cur1 = next;
		}
		else
		{
			next = cur2->next;
			prev->next = cur2;
			prev = prev->next;
			cur2 = next;
		}
	}
	if (cur1 == NULL)
	{
		prev->next = cur2;
	}
	else if (cur2 == NULL)
	{
		prev->next = cur1;
	}
	return head;
}