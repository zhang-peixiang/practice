#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


struct ListNode {
	int val;
	struct ListNode *next;
};
/*
����aΪ����ǰ�ľ��� bΪ�����ĵ�һ���ڵ㵽first��second�ཻ�Ľڵ�  cΪ�ཻ�ڵ㵽������һ���ڵ�ľ���
a+b=x  y=a+2b+c   y=x*2
����2a+2b=a+2b+c -->a=c

1.���ж��������Ƿ��л�--�ÿ���ָ��--second�ߵĽڵ�����y��ʾ  first�ߵĽڵ�����x��ʾ �ཻʱ�й�ϵʽ��2*x=y
2.�ҽ����ĵ�һ��ָ��
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