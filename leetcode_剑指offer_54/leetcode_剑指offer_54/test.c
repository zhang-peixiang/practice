#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一棵二叉搜索树，请找出其中第k大的节点。

//二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 
//若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
//若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int GetTreelen(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return GetTreelen(root->left) + GetTreelen(root->right) + 1;
}


void _kthLargest(struct TreeNode* root, int* k, int* a)
{
	if (root == NULL)
		return;

	_kthLargest(root->left, k, a);
	(*k)--;
	if ((*k) == -1)
	{
		(*a) = root->val;
	}
	_kthLargest(root->right, k, a);
}

int kthLargest(struct TreeNode* root, int k)
{
	int len = GetTreelen(root);
	int a = len - k;
	int b = 0;
	_kthLargest(root, &a, &b);
	return b;
}