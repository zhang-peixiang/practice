#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}SlistNode;


void reorderList(struct ListNode* head)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
		return head;
	struct ListNode* first = head;
	struct ListNode* second = head;
	struct ListNode* cur = head;

	while (second && second->next)//找中间节点
	{
		first = first->next;
		second = second->next->next;
	}

	//链表逆序
	struct ListNode* pre = NULL;
	struct ListNode* next = NULL;
	while (first)
	{
		next = first->next;

		first->next = pre;
		pre = first;
		first = next;
	}

	struct ListNode* ret = NULL;
	struct ListNode* tmp = NULL;
	while (pre)//pre保存的逆序链表的最后一个节点
	{
		tmp = pre->next;
		ret = pre;//保存最后一个不为空的节点，将其next指向NULL
		pre->next = cur->next;
		cur->next = pre;

		cur = pre->next;
		pre = tmp;
	}
	ret->next = NULL;
}

SlistNode* BuySlistNode(int data)
{
	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}

	newNode->val = data;
	newNode->next = NULL;
	return newNode;
}



//尾插
void SlistPushBack(SlistNode** head, int data)
{
	assert(head);
	SlistNode* newNode = BuySlistNode(data);
	//空链表
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		//非空链表
		SlistNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

int main()
{
	struct ListNode* head = NULL;
	SlistPushBack(&head, 1);
	SlistPushBack(&head, 2);
	SlistPushBack(&head, 3);
	SlistPushBack(&head, 4);

	reorderList(head);

	return 0;
}