#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	int count = 0;
	struct ListNode* pre = NULL;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	cur = head;
	if (k >= count)
	{
		k = k%count;
	}
	if (k == 0)
	{
		return head;
	}

	while (count - k != 0)
	{
		pre = cur;
		cur = cur->next;
		count--;
	}

	newhead = cur;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = head;
	pre->next = NULL;
	return newhead;
} 