#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ�����������ҳ�����С��ȡ�
//
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣



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

