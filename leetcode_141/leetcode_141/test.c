#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ��
//�������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast &&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}