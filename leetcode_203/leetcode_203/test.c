#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ɾ�������е��ڸ���ֵ val �����нڵ㡣

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
				//��ͷ�ڵ�--ͷɾ
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