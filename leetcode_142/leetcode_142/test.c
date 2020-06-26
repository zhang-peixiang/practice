#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


struct ListNode {
	int val;
	struct ListNode *next;
};
/*
假设a为进环前的距离 b为进环的第一个节点到first和second相交的节点  c为相交节点到进环第一个节点的距离
a+b=x  y=a+2b+c   y=x*2
所以2a+2b=a+2b+c -->a=c

1.先判断链表中是否有环--用快慢指针--second走的节点数用y表示  first走的节点数用x表示 相交时有关系式：2*x=y
2.找进环的第一个指针
*/

struct ListNode *detectCycle(struct ListNode *head) 
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return NULL;

	struct ListNode* first = head;
	struct ListNode* second = head;

	while (second && second->next)
	{
		first = first->next;
		second = second->next->next;

		if (first == second)
			break;
	}
	if (first != second)
		return NULL;


	struct ListNode* cur = head;
	while (cur != first)
	{
		cur = cur->next;
		first = first->next;
	}

	return cur;
}