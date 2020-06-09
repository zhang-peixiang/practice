#include "Stack.h"

void Checkcapacity(Stack* ps)
{
	if (ps->size == ps->capacity)
	{
		char* tmp = (char*)malloc(sizeof(char)* 2 * ps->size);
		if (tmp == NULL)
			return;
		memcpy(tmp, ps->array, sizeof(char)*ps->size);
		free(ps->array);
		ps->array = tmp;
		ps->capacity = ps->size * 2;
	}
}

//初始化
void StackInit(Stack* ps)
{
	assert(ps);

	ps->array = (char*)malloc(sizeof(char)* 10);
	if (ps->array == NULL)
	{
		assert(0);
		return;
	}
	ps->capacity = 10;
	ps->size = 0;
}

//入栈
void StackPush(Stack* ps,char data)
{
	assert(ps);
	Checkcapacity(ps);

	ps->array[ps->size] = data;
	ps->size++;
}

//出栈
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}

	ps->size--;
}

char StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));

	return ps->array[ps->size - 1];
}


//验空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}


//销毁
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}