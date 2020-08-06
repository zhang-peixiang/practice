#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
		return head;
	struct ListNode* cur = head->next;
	struct ListNode* pre = headd;
	while (cur)
	{
		if (cur->val == pre->val)
		{
			pre->next = cur->next;
			cur = pre->next;
		}
		else
		{
			cur = cur->next;
			pre = pre->next;
		}
	}
	return head;
}