#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的 深拷贝。
//我们用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个 [val, random_index] 表示：
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 


struct Node 
{
	int val;
	struct TreeNode *next;
	struct TreeNode *random;
};

struct Node* BuyNode(int date)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->val = date;
	newnode->next = NULL;
	newnode->random = NULL;
	return newnode;
}

struct Node* copyRandomList(struct Node* head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	struct Node* cur = head;
	struct Node* newnode = NULL;

	//复制链表 将1-2-3-4-5-null 编程 1-1-2-2-3-3-4-4-5-5-null
	while (cur)
	{
		newnode = BuyNode(cur->val);
		newnode->next = cur->next;
		cur->next = newnode;
		cur = newnode->next;
	}
	cur = head;
	struct Node* tmp = NULL;
	//复制random
	while (cur)
	{
		newnode = cur->next;
		if (cur->random != NULL)
		{
			tmp = cur->random;
			newnode->random = tmp->next;
		}
		cur = newnode->next;
	}

	//将复制的链表拆下来
	cur = head;
	struct Node* newHead = head->next;
	while (cur->next)
	{
		newnode = cur->next;
		cur->next = newnode->next;
		cur = newnode;
	}
	return newHead;
}