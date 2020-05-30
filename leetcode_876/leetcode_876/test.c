#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
struct ListNode* BuyListNode(int date)
{
	struct ListNode* newnode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newnode->next = NULL;
	newnode->val = date;
	return newnode;
}

void listpushfront(struct ListNode** head, int date)
{
	struct ListNode* newhead = BuyListNode(date);
	
	if (*head == NULL)
	{
		*head = newhead;
	}
	else
	{
		struct ListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newhead; 
	}
}

int main()
{
	struct ListNode* head = NULL;
	listpushfront(&head, 1);
	listpushfront(&head, 2);
	listpushfront(&head, 3);
	listpushfront(&head, 4);
	listpushfront(&head, 5);

	struct ListNode* print = middleNode(head);

	return 0;
}