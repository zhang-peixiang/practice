#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。


struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* BuySlistNode(int data)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(int));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}

	newNode->val = data;
	newNode->next = NULL;
	return newNode;
}

void SlistPushFront(struct ListNode** head, int data)
{
	assert(head);
	struct ListNode* newNode = BuySlistNode(data);
	newNode->next = *head;
	*head = newNode;

	//if (*head == NULL)
	//{
	//	*head = newNode;
	//}
	//else
	//{
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;
	struct ListNode* head = NULL;
	struct ListNode* cur3 = NULL;
	if (cur1->val < cur2->val)
	{
		head = cur1;
		l1 = cur1->next;
		cur1->next = NULL;
		cur1 = l1;
	}
	else
	{
		head = cur2;
		l2 = cur2->next;
		cur2->next = NULL;
		cur2 = l2;
	}
	cur3 = head;
	while (cur1 && cur2)
	{
		if (cur1->val < cur2->val)
		{
			l1 = cur1->next;
			cur3->next = cur1;
			cur3 = cur1;
			cur3->next = NULL;
			cur1 = l1;
		}
		else
		{
			l2 = cur2->next;
			cur3->next = cur2;
			cur3 = cur2;
			cur3->next = NULL;
			cur2 = l2;
		}
	}
	if (cur1)
	{
		cur3->next = cur1;
	}
	else
	{
		cur3->next = cur2;
	}
	return head;
}

int main()
{
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	SlistPushFront(&l1, 5);
	SlistPushFront(&l1, 3);
	SlistPushFront(&l1, 1);
	SlistPushFront(&l2, 4);
	SlistPushFront(&l2, 2);
	SlistPushFront(&l2, 1);


	mergeTwoLists(l1, l2);

	return 0;
}