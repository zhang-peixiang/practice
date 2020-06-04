#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//对链表进行插入排序。

/*
1.检测初始链表是否是空链表或者链表中只有一个节点，直接返回head
2.定义一个新链表
3.当新链表为NULL时，将head中的第一个元素放进去
4.然后将原链表的元素与新链表中的进行比较，找到插入位置，将其插入。
*/

struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL;
	
	while (cur)
	{
		struct ListNode* prev = newhead;
		struct ListNode* pos = NULL;//记录插入的前一个节点
		head = cur->next;
		//找到插入位置
		while (prev)
		{
			if (prev->val > cur->val)
			{
				break;
			}
			pos = prev;
			prev = prev->next;
		}

		//插入位置为第一个节点
		if (pos == NULL)
		{
			cur->next = prev;
			newhead = cur;
		}
		//插入位置为后面节点
		else
		{
			cur->next = prev;
			pos->next = cur;
		}
		cur = head;
	}
	return newhead;
}