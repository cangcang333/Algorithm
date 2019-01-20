/*************************************************************************
	> File Name: infixExpression.c
	> Author: 
	> Mail: 
	> Created Time: 一  1/14 21:32:22 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (NULL == s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}


void Push(sqStack *s, ElemType e)
{
    // If stack is empty, then add space
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    // If stack is empty, then pop nothing
    if (s->top == s->base)
    {
        return ;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    sqStack s;
    char c, e;

    InitStack(&s);

    printf("Please input infix expression, end with '#': ");
    scanf("%c", &c);

    while (c != '#')
    {
        scanf("%c", &c);
    }

    return 0;
}


