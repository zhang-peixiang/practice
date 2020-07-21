#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int GetHeight(struct TreeNode* root) 
{
	int leftHeight = 0, rightHeight = 0;
	if (root == NULL)
		return 0;

	leftHeight = GetHeight(root->left);
	rightHeight = GetHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	int leftHeight = 0, rightHeight = 0;
	leftHeight = GetHeight(root->left);
	rightHeight = GetHeight(root->right);
	if (abs(leftHeight - rightHeight) > 1)
		return false;
	return isBalanced(root->right) && isBalanced(root->left);
}