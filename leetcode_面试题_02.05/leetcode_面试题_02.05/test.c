#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

//给定两个用链表表示的整数，每个节点包含一个数位。
//这些数位是反向存放的，也就是个位排在链表首部。
//编写函数对这两个整数求和，并用链表形式返回结果。


typedef struct ListNode {
	int val;
	struct ListNode *next;
}SlistNode;
/*

*/
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

struct ListNode* Buy_Node(int data)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newNode == NULL)
	{
		assert(0);
	}
	newNode->next = NULL;
	newNode->val = data;

	return newNode;
}

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	struct ListNode* node = NULL;
//	struct ListNode* newnode = NULL;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int ret = 0;
//	int count = 0;
//
//	struct ListNode* cur1 = l1;
//	struct ListNode* cur2 = l2;
//	struct ListNode* cur = node;
//
//	while (cur1)
//	{
//		a = a + pow(10, count)*(cur1->val);
//		count++;
//		cur1 = cur1->next;
//	}
//
//	count = 0;
//	while (cur2)
//	{
//		b = b + pow(10, count)*(cur2->val);
//		count++;
//		cur2 = cur2->next;
//	}
//
//	c = a + b;
//
//	while (c)
//	{
//		ret = c % 10;
//		c /= 10;
//		newnode = Buy_Node(ret);
//		if (node == NULL)
//		{
//			node = newnode;
//			cur = node;
//		}
//		else
//		{
//			cur->next = newnode;
//			cur = cur->next;
//		}
//	}
//	return node;
//}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* node = NULL;
	struct ListNode* newnode = NULL;
	struct ListNode* cur = newnode;

	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;

	int a = 0;
	int ret = 0;

	//长度相同时
	while (cur1 && cur2)
	{
		a = (cur1->val) + (cur2->val) + ret;
		if (a > 9)
		{
			ret = 1;
			a %= 10;
		}
		else
		{
			ret = 0;
		}

		newnode = Buy_Node(a);
		if (node == NULL)
		{
			node = newnode;
			cur = node;
		}
		else
		{
			cur->next = newnode;
			cur = cur->next;
		}

		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	if (cur1 == NULL&& cur2 != NULL)
	{
		if (ret == 0)
		{
			cur->next = cur2;
		}
		else
		{
			while (cur2)
			{
				a = cur2->val + ret;

				if (a > 9)
				{
					ret = 1;
					a %= 10;
				}
				else
				{
					ret = 0;
				}

				newnode = Buy_Node(a);
				cur->next = newnode;
				cur = cur->next;
				cur2 = cur2->next;
			}
		}
	}
	if (cur2 == NULL&& cur1 != NULL)
	{
		if (ret == 0)
		{
			cur->next = cur1;
		}
		else
		{
			while (cur1)
			{
				a = cur1->val + ret;

				if (a > 9)
				{
					ret = 1;
					a %= 10;
				}
				else
				{
					ret = 0;
				}

				newnode = Buy_Node(a);
				cur->next = newnode;
				cur = cur->next;
				cur1 = cur1->next;
			}
		}
	}
	if (ret == 1)
	{
		newnode = Buy_Node(1);
		cur->next = newnode;
	}

	return node;
}

int main()
{
	struct ListNode* head1 = NULL;
	struct ListNode* head2 = NULL;

	SlistPushBack(&head1, 2);

	SlistPushBack(&head2, 8);
	SlistPushBack(&head2, 9);
	SlistPushBack(&head2, 9);


	addTwoNumbers(head2, head1);

	return 0;
}