#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明 : 叶子节点是指没有子节点的节点。



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

};

int minDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int min = 10000000000;
	if (root->left != NULL)
	{

		min = fmin(minDepth(root->left), min);
	}
	if (root->right != NULL)
	{
		min = fmin(minDepth(root->right), min);
	}

	return min + 1;
}

