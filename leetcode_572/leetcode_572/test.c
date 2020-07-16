#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool _isSubtree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;

	return _isSubtree(p->left, q->left) && _isSubtree(p->right, q->right);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t!=NULL)
		return false;
	if (s == NULL && t == NULL)
		return true;
	if (t == NULL)
		return true;
	if (s->val == t->val && _isSubtree(s, t))
		return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}