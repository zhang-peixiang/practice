#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//�Լ�����������
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (t1 == NULL)
	{
		return t2;
	}
	else if (t2 == NULL)
	{
		return t1;
	}
	node->val = t1->val + t2->val;
	node->left = mergeTrees(t1->left, t2->left);
	node->right = mergeTrees(t1->right, t2->right);
	return node;
}

//���˵�
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
	if (t1 == NULL) return t2;        //���t1,t2��ΪNULL,�򷵻ص�Ҳ��NULL
	if (t2 == NULL) return t1;
	t1->val += t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
}
