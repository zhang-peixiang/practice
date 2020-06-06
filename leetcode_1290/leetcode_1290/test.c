#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
//已知此链表是一个整数数字的二进制表示形式。
//请你返回该链表所表示数字的 十进制值


struct ListNode
{
	int val;
	struct ListNode *next;
};


/*
//方法1
int getDecimalValue(struct ListNode* head)
{
	struct ListNode* cur = head;
	int count = 0;
	int val = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	cur = head;
	while (count > 0)
	{
		val += pow(2, count-1)*(cur->val);
		count--;
		cur = cur->next;
	}
	return val;
}
*/

//方法二
int getDecimalValue(struct ListNode* head)
{
	struct ListNode* cur = head;
	int val = 0;
	while (cur)
	{
		val = val * 2 + cur->val;
		cur = cur->next;
	}
	return val;
}
