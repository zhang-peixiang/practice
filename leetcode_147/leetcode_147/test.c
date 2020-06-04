#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������в�������

/*
1.����ʼ�����Ƿ��ǿ��������������ֻ��һ���ڵ㣬ֱ�ӷ���head
2.����һ��������
3.��������ΪNULLʱ����head�еĵ�һ��Ԫ�طŽ�ȥ
4.Ȼ��ԭ�����Ԫ�����������еĽ��бȽϣ��ҵ�����λ�ã�������롣
*/

struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL;
	
	while (cur)
	{
		struct ListNode* prev = newhead;
		struct ListNode* pos = NULL;//��¼�����ǰһ���ڵ�
		head = cur->next;
		//�ҵ�����λ��
		while (prev)
		{
			if (prev->val > cur->val)
			{
				break;
			}
			pos = prev;
			prev = prev->next;
		}

		//����λ��Ϊ��һ���ڵ�
		if (pos == NULL)
		{
			cur->next = prev;
			newhead = cur;
		}
		//����λ��Ϊ����ڵ�
		else
		{
			cur->next = prev;
			pos->next = cur;
		}
		cur = head;
	}
	return newhead;
}