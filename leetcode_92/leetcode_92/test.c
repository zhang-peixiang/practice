#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

/*
1.记录开始反转的前一个节点，方便在链表断开后连接上反转后的第一个节点
2.记录开始反转的第一个节点，方便将其连接到反转的最后一个节点的next，连接链表
3.用计数器方法，等于m时开始反转，等于n时结束反转。
  将m到n这节看成与其他部分无关，将其反转。反转结束后利用记录的两个节点将链表连接起来。
*/

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
		return head;
	struct ListNode* cur = head;
	struct ListNode* ret = NULL;//记录开始反转的第一个节点
	struct ListNode* tmp = NULL;//记录开始反转的前一个节点
	struct ListNode* pre = NULL;
	struct ListNode* next = NULL;

	int count = 1;
	while (count != m)
	{
		tmp = cur;
		cur = cur->next;
		count++;
	}
	ret = cur;
	while (count - 1 != n)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		count++;
	}
	ret->next = cur;
	if (tmp != NULL)//如果不判空，从第一个节点开始反转，tmp为空，tmp->next  报错
	{
		tmp->next = pre;
	}
	else//如果tmp为空，证明链表从第一个节点开始反转，需要改变链表头的位置
	{
		head = pre;
	}

	return head;
}