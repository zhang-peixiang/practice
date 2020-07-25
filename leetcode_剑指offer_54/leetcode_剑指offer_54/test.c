#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ�ö��������������ҳ����е�k��Ľڵ㡣

//�����������Binary Search Tree�������֣���������������������������������һ�ÿ����������Ǿ����������ʵĶ������� 
//���������������գ��������������н���ֵ��С�����ĸ�����ֵ��
//���������������գ��������������н���ֵ���������ĸ�����ֵ�� ������������Ҳ�ֱ�Ϊ������������

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