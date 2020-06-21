#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode newhead1;//���С��x�Ľڵ�
	struct ListNode newhead2;//��ŵ��ںʹ���x�Ľڵ�
	newhead1.next = NULL;//��ͷ�ڵ�ĳ�ʼ��
	newhead2.next = NULL;
	struct ListNode* cur = head;
	struct ListNode* tmp = NULL;//�м����
	while (cur)
	{
		//ÿ��ѭ���궼Ҫ��cur������һ����ֱ����next���cur->next����ֹ����Ͽ����Ҳ�����һ���ڵ㣬������head=cur->nextҲ����
		struct ListNode* next = cur->next;
		if (cur->val < x)
		{
			if (newhead1.next == NULL)
			{
				tmp = cur;
			}
			struct ListNode* cur1 = newhead1.next;
			newhead1.next = cur;
			cur->next = cur1;
		}
		else
		{
			struct ListNode* cur2 = newhead2.next;
			newhead2.next = cur;
			cur->next = cur2;
		}
		cur = next;
	}
	if (tmp != NULL)//���tmpΪ��˵��û��С��x�Ľڵ㣬����newhead2.next
	{
		tmp->next = newhead2.next;
		return newhead1.next;
	}

	return newhead2.next;
}