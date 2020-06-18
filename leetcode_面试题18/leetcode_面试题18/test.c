#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。

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