#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个二叉树，返回它的 前序 遍历。


//用栈实现
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


typedef struct TreeNode* SDataType;

typedef struct Stack
{
	SDataType* array;
	int size;
}Stack;

void StackInit(Stack* s)
{
	s->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	if (s->array == NULL)
		return;
	s->size = 0;

}

void StackPush(Stack* s, SDataType root)
{
	s->array[(s->size)++] = root;
}

struct TreeNode* StackTop(Stack* s)
{
	return s->array[(s->size) - 1];
}

void StackPop(Stack* s)
{
	s->size--;
}

int StackEmpty(Stack* s)
{
	return s->size == 0;
}

void StackDestroy(Stack* s)
{
	free(s->array);
	s->array = NULL;
	s->size = 0;
}

int GetTreenode(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return GetTreenode(root->left) + GetTreenode(root->right) + 1;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int len = GetTreenode(root);
	*returnSize = len;
	int index = 0;
	int* arr = (int*)malloc(sizeof(int)*len);
	Stack s;
	StackInit(&s);
	StackPush(&s, root);
	while (!StackEmpty(&s))
	{
		struct TreeNode* cur = StackTop(&s);
		StackPop(&s);

		if (cur->right != NULL)
			StackPush(&s, cur->right);
		if (cur->left != NULL)
			StackPush(&s, cur->left);
		arr[index++] = cur->val;
	}
	StackDestroy(&s);
	return arr;
}