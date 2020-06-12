#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


int* reversePrint(struct ListNode* head, int* returnSize)
{
	struct ListNode* cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	*returnSize = count;
	cur = head;
	int* arr = (int*)malloc(sizeof(int)*count);
	while (cur)
	{
		arr[count - 1] = cur->val;
		count--;
		cur = cur->next;
	}
	return arr;
}
