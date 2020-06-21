#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode newhead1;//存放小于x的节点
	struct ListNode newhead2;//存放等于和大于x的节点
	newhead1.next = NULL;//带头节点的初始化
	newhead2.next = NULL;
	struct ListNode* cur = head;
	struct ListNode* tmp = NULL;//中间变量
	while (cur)
	{
		//每次循环完都要让cur往后走一步，直接用next标记cur->next，防止链表断开，找不到下一个节点，这里用head=cur->next也可以
		struct ListNode* next = cur->next;
		if (cur->val < x)
		{
			if (newhead1.next == NULL)
			{
				tmp = cur;
			}
			struct ListNode* cur1 = newhead1.next;
			newhead1.next = cur;
			cur->next = cur1;
		}
		else
		{
			struct ListNode* cur2 = newhead2.next;
			newhead2.next = cur;
			cur->next = cur2;
		}
		cur = next;
	}
	if (tmp != NULL)//如果tmp为空说明没有小于x的节点，返回newhead2.next
	{
		tmp->next = newhead2.next;
		return newhead1.next;
	}

	return newhead2.next;
}