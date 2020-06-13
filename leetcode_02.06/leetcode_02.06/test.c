#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
};



bool isPalindrome(struct ListNode* head)
{
	if (head == NULL)
	{
		return true;
	}
	struct ListNode* first = head;
	struct ListNode* second = head;
	struct ListNode* tmp = NULL;

	struct ListNode* cur1 = NULL;


	//���е�
	while (second && second->next)
	{
		first = first->next;
		second = second->next->next;
	}


	//��������
	while (first)
	{
		cur1 = first->next;
		first->next = tmp;
		tmp = first;
		first = cur1;
	}


	//�жϻ��Ľṹ
	while (tmp && head)
	{
		if (tmp->val != head->val)
			return false;

		tmp = tmp->next;
		head = head->next;
	}
	return true;
}