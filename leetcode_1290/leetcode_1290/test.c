#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ������������ý�� head��������ÿ������ֵ���� 0 ���� 1��
//��֪��������һ���������ֵĶ����Ʊ�ʾ��ʽ��
//���㷵�ظ���������ʾ���ֵ� ʮ����ֵ


struct ListNode
{
	int val;
	struct ListNode *next;
};


/*
//����1
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

//������
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
