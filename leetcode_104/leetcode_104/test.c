#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;

	int leftHight = maxDepth(root->left);
	int rightHight = maxDepth(root->right);

	return leftHight > rightHight ? leftHight + 1 : rightHight + 1;
}