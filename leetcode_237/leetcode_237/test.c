#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ�


struct ListNode 
{
	int val;
	struct ListNode *next;
};


void deleteNode(struct ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}