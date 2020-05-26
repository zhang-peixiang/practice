#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//删除链表中等于给定值 val 的所有节点。

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)
			{
				//是头节点--头删
				prev = cur->next;
				head = prev;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
		
	}
	return head;
}