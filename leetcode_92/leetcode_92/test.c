#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��

/*
1.��¼��ʼ��ת��ǰһ���ڵ㣬����������Ͽ��������Ϸ�ת��ĵ�һ���ڵ�
2.��¼��ʼ��ת�ĵ�һ���ڵ㣬���㽫�����ӵ���ת�����һ���ڵ��next����������
3.�ü���������������mʱ��ʼ��ת������nʱ������ת��
  ��m��n��ڿ��������������޹أ����䷴ת����ת���������ü�¼�������ڵ㽫��������������
*/

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
		return head;
	struct ListNode* cur = head;
	struct ListNode* ret = NULL;//��¼��ʼ��ת�ĵ�һ���ڵ�
	struct ListNode* tmp = NULL;//��¼��ʼ��ת��ǰһ���ڵ�
	struct ListNode* pre = NULL;
	struct ListNode* next = NULL;

	int count = 1;
	while (count != m)
	{
		tmp = cur;
		cur = cur->next;
		count++;
	}
	ret = cur;
	while (count - 1 != n)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		count++;
	}
	ret->next = cur;
	if (tmp != NULL)//������пգ��ӵ�һ���ڵ㿪ʼ��ת��tmpΪ�գ�tmp->next  ����
	{
		tmp->next = pre;
	}
	else//���tmpΪ�գ�֤������ӵ�һ���ڵ㿪ʼ��ת����Ҫ�ı�����ͷ��λ��
	{
		head = pre;
	}

	return head;
}