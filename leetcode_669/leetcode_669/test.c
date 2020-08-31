#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，
//使得所有节点的值在[L, R]中(R >= L) 。
//你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

// 二叉搜索树性质：
/*二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，
或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，
则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
	if (root == NULL)
		return NULL;

	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);

	if (root->val < L)
	{
		return root->right;
	}
	else if (root->val>R)
	{
		return root->left;
	}

	return root;
}