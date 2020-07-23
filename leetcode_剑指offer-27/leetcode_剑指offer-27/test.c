#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct TreeNode* mirrorTree(struct TreeNode* root){
	if (!root){
		return NULL;
	}
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = root->val;
	node->right = mirrorTree(root->left);
	node->left = mirrorTree(root->right);
	return node;
}