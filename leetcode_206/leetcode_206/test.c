#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//反转一个单链表。

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* cur = head;
	struct ListNode* pre = NULL;
	struct ListNode* next = NULL;
	while (cur->next)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	cur->next = pre;
	return cur;
}