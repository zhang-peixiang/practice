#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
	int len;
	int top1;
	int top2;
	int *s1;//栈1，入栈=入队
	int *s2;//栈2，出栈=出队
} CQueue;



CQueue* cQueueCreate() 
{
	CQueue* q = (CQueue*)malloc(sizeof(CQueue));
	q->len = 10;
	q->top2 = 0;
	q->top1 = 0;
	q->s1 = (int*)malloc(sizeof(int)*q->len);
	q->s2 = (int*)malloc(sizeof(int)*q->len);

	return q;
}

void check_capcity(CQueue* q)
{
	if (q->len == q->top1)
	{
		int* tmp = (int*)malloc(sizeof(int)*q->len * 2);
		if (tmp == NULL)
		{
			assert(0);
		}
		q->s2 = (int*)malloc(sizeof(int)*q->len * 2);
		memcpy(tmp, q->s1, sizeof(int)*q->len);
		q->s1 = tmp;
		q->len = q->len * 2;
	}
}

void cQueueAppendTail(CQueue* obj, int value) 
{
	assert(obj);
	check_capcity(obj);

	obj->s1[(obj->top1)++] = value;
	
}

int cQueueDeleteHead(CQueue* obj) 
{
	int i = 0;
	int ret = 0;
	if (obj->top1 == 0)
		return -1;
	ret = obj->s1[(0)];
	while (obj->top1>1)
	{
		obj->s2[(obj->top2)++] = obj->s1[--(obj->top1)];
	}
	obj->top1--;
	while (obj->top2 > 0)
	{
		obj->s1[(obj->top1)++] = obj->s2[--(obj->top2)];
	}

	return ret;
}

void cQueueFree(CQueue* obj) 
{
	free(obj->s1); 
	free(obj->s2);
	free(obj);
}

int main()
{
	CQueue* q = cQueueCreate();
	int ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 281);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 94);
	cQueueAppendTail(q, 128);
	cQueueAppendTail(q, 226);
	cQueueAppendTail(q, 105);
	cQueueAppendTail(q, 204);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 165);
	cQueueAppendTail(q, 293);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 268);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 42);
	cQueueAppendTail(q, 134);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 152);
	cQueueAppendTail(q, 202);
	cQueueAppendTail(q, 58);
	ret = cQueueDeleteHead(q);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 202);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 184);
	cQueueAppendTail(q, 13);
	cQueueAppendTail(q, 18);
	cQueueAppendTail(q, 192);
	cQueueAppendTail(q, 87);
	ret = cQueueDeleteHead(q);
	ret = cQueueDeleteHead(q);
	cQueueAppendTail(q, 240);



	ret = cQueueDeleteHead(q);


	cQueueFree(q);
	return 0;
}
