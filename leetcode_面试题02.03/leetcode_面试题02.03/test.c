#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// ʵ��һ���㷨��
// ɾ�����������м��ĳ���ڵ㣨�����ǵ�һ�������һ���ڵ㣩��
// �ٶ���ֻ�ܷ��ʸýڵ㡣

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