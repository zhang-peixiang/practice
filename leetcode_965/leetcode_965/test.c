#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


#if 0
bool _isUnivalTree(struct TreeNode* root, int ret)
{
	if (root == NULL)
		return true;
	if (ret != root->val)
		return false;
	return _isUnivalTree(root->left, ret) && _isUnivalTree(root->right, ret);
}


bool isUnivalTree(struct TreeNode* root)
{
	int ret = 0;
	if (root == NULL)
		return true;
	ret = root->val;

	return _isUnivalTree(root, ret);
}

#endif


//队列
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


bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	
	queue* q;
	queue* p;
	int ret = root->val;
	init(&q, root->val, root);
	
	p = q;
	while (p != NULL)
	{
		struct TreeNode* cur = p->node;
		if (cur->val != ret)
			return false;
		if (cur->left)
			init(q->next, cur->left->val, cur->left);
		if (cur->right)
			init(q->next, cur->right->val, cur->right);
		p = p->next;
	}
	return true;
}