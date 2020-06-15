#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
//�����1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
//���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6��
//�������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣


struct ListNode
{
	int val;
	struct ListNode *next;
};

/*
1.����cur��K��
2.Ȼ��pre��head��ʼ��curͬʱ�����ߣ���curΪ��ʱ��pre��Ϊ������k���ڵ�
*/

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* cur = head;
	struct ListNode* pre = head;
	int count = 0;
	while (k)
	{
		cur = cur->next;
		k--;
	}
	while (cur)
	{
		cur = cur->next;
		pre = pre->next;
	}
	return pre;
}