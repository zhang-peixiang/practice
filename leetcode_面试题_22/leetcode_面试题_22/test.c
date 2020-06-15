#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，
//本题从1开始计数，即链表的尾节点是倒数第1个节点。
//例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。
//这个链表的倒数第3个节点是值为4的节点。


struct ListNode
{
	int val;
	struct ListNode *next;
};

/*
1.先让cur走K步
2.然后pre从head开始和cur同时往后走，当cur为空时，pre即为倒数第k个节点
*/

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* cur = head;
	struct ListNode* pre = head;
	int count = 0;
	while (k)
	{
		cur = cur->next;
		k--;
	}
	while (cur)
	{
		cur = cur->next;
		pre = pre->next;
	}
	return pre;
}