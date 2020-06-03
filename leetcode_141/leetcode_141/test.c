#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
//（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast &&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}