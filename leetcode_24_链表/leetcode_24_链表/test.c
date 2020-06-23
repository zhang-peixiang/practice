#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* left = head;
	struct ListNode* newhead = NULL;
	struct ListNode* right = head->next;
	struct ListNode* tmp = NULL;
	struct ListNode* cur = newhead;
	while (left && left->next)
	{
		right = left->next;
		tmp = right->next;
		if (newhead == NULL)
		{
			newhead = right;
			right->next = left;
			cur = left;
		}
		else
		{
			right->next = left;
			cur->next = right;
			cur = left;
		}

		left = tmp;
	}
	if (left == NULL)
	{
		cur->next = NULL;
	}
	else
	{
		cur->next = left;
		cur = left;
		cur->next = NULL;
	}
	
	return newhead;
}