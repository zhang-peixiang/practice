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

//��ʼ��
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps,char data);

//��ջ
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
char StackTop(Stack* ps);
//���
int StackEmpty(Stack* ps);


//����
void StackDestroy(Stack* ps);
