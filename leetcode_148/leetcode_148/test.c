#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
}SlistNode;


//超时
//struct ListNode* sortList(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode* newhead = NULL;
//	struct ListNode* cur1 = newhead;
//	struct ListNode* cur = head;
//	struct ListNode* pre = newhead;
//	while (cur)
//	{
//		head = cur->next;
//		cur1 = newhead;
//		if (cur1 == NULL)
//		{
//			newhead = cur;
//			cur->next = NULL;
//		}
//		else
//		{
//			if (cur1->val > cur->val)
//			{
//				cur->next = cur1;
//				newhead = cur;
//			}
//			else
//			{
//				while (cur1->val < cur->val && cur1->next != NULL)
//				{
//					pre = cur1;
//					cur1 = cur1->next;
//				}
//				if (cur1->val < cur->val)
//				{
//					pre = cur1;
//					cur1 = cur1->next;
//				}
//				cur->next = cur1;
//				pre->next = cur;
//			}
//		}
//		cur = head;
//	}
//	return newhead;
//}
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

void SlistPushFront(SlistNode** head, int data)
{
	assert(head);
	SlistNode* newNode = BuySlistNode(data);
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



//链表的归并排序
struct ListNode* cut(struct ListNode* head, int size){
	struct ListNode* p = head;
	while (p && --size){
		p = p->next;
	}
	if (!p) return NULL;

	struct ListNode* cur = p->next;
	p->next = NULL;
	return cur;
}
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2){

	struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	dummyHead->next = NULL;
	struct ListNode *p = dummyHead;
	while (l1 && l2){
		if (l1->val < l2->val){
			p->next = l1;
			p = l1;
			l1 = l1->next;
		}
		else{
			p->next = l2;
			p = l2;
			l2 = l2->next;
		}
	}

	p->next = l1 ? l1 : l2;

	return dummyHead->next;
}

struct ListNode* sortList(struct ListNode* head){

	if (!head) return NULL;

	//获取链表长度
	int length = 0;
	struct ListNode *p = head;
	while (p){
		length++;
		p = p->next;
	}
	struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
	//哑节点
	dummyHead->val = 0;
	dummyHead->next = head;
	for (int size = 1; size < length; size *= 2){
		struct ListNode *cur = dummyHead->next;
		struct ListNode *tail = dummyHead;
		struct ListNode *left, *right;
		while (cur){
			left = cur;
			right = cut(left, size);
			cur = cut(right, size);

			tail->next = merge(left, right);
			while (tail->next){
				tail = tail->next;
			}
		}
	}

	return dummyHead->next;
}



int main()
{
	SlistNode* listhead = NULL;
	SlistPushFront(&listhead, 3);
	SlistPushFront(&listhead, 1);
	SlistPushFront(&listhead, 2);
	SlistPushFront(&listhead, 4);
	
	sortList(listhead);

}