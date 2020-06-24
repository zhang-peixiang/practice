#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
/*
1.���ĸ�ָ�룬����ĸ��ڵ㣬���һ��ָ��ָ�������ָ�룬�ڶ���ָ��ָ����ĸ�ָ��
2.���һ��ָ����ڵ�����ָ�룬�ڶ���ָ����ڵ��ĸ�ָ��
3.��Ϊѭ��һ��ֻ�ı�����ָ��ָ������ѭ������ֱ���жϵ�����ָ��͵��ĸ�ָ��Ϳ���
4.��Ϊ����3���ڵ������������ڿ�ʼ��Ҫ�Ե��ĸ�ָ������пղ�����
*/
struct ListNode* oddEvenList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	if (head->next->next == NULL)
		return head;
	struct ListNode* pre = head;
	struct ListNode* left = head->next;
	struct ListNode* right = left->next;
	struct ListNode* next = right->next;
	if (next == NULL)
	{
		pre->next = right;
		left->next = next;
		right->next = left;
		return head;
	}
	struct ListNode* ret = head->next;//���ż���ڵ�ĵ�һ���ڵ�
	
	while (next && right)
	{
		left = pre->next;
		right = left->next;
		if (right == NULL)
		{
			pre->next = ret;
			break;
		}
		next = right->next;

		pre->next = right;
		left->next = next;

		pre = right;
	}
	if (next == NULL)
		right->next = ret;

	return head;
}