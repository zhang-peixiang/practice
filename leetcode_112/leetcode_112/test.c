#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct queue
{
	int val;
	struct TreeNode* node;
	struct queue* next;
}queue;


void init(queue** p, int val, struct TreeNode* node)
{
	(*p) = (queue*)malloc(sizeof(queue));

	(*p)->val = val;
	(*p)->node = node;
	(*p)->next = NULL;
}


bool hasPathSum(struct TreeNode* root, int sum)
{
	if (root == NULL)
		return false;
	queue* fast;
	queue* slow;

	int tmp = 0;
	init(&slow, root->val, root);
	fast = slow;

	while (slow != NULL)
	{
		struct TreeNode* cur = slow->node;
		tmp = slow->val;
		if (cur->left == NULL && cur->right == NULL)
		{
			if (tmp == sum)
				return true;
		}
		if (cur->left != NULL)
		{
			init(&fast->next, cur->left->val + tmp, cur->left);
			fast = fast->next;
		}
		if (cur->right != NULL)
		{
			init(&fast->next, cur->right->val+tmp, cur->right);
			fast = fast->next;
		}

		slow = slow->next;
	}
	return false;
}