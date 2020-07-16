#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//����һ�����������ҳ��������ȡ�
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

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