#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Stack
{
	char* array;
	int capacity;
	int size;
}Stack;

//初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps,char data);

//出栈
void StackPop(Stack* ps);

//获取栈顶元素
char StackTop(Stack* ps);
//验空
int StackEmpty(Stack* ps);


//销毁
void StackDestroy(Stack* ps);
