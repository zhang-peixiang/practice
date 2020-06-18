#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//
//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//����ɾ����������ͷ�ڵ㡣

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* deleteNode(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	if (head->val == val)
		head = head->next;
	struct ListNode* cur = head->next;
	struct ListNode* pre = head;
	while (cur)
	{
		if (cur->val == val)
		{
			pre->next = cur->next;
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	return head;
}