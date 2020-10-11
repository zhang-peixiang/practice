#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// 实现一种算法，
// 删除单向链表中间的某个节点（即不是第一个或最后一个节点），
// 假定你只能访问该节点。

struct ListNode {
	int val;
	struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
	if (node == NULL)
	{
		return;
	}
	struct ListNode* p = node->next;
	node->val = p->val;
	node->next = p->next;
	free(p);
}