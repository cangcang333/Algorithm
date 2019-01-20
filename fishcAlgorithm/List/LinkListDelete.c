/*************************************************************************
	> File Name: getLinkListElem.c
	> Author: 
	> Mail: 
	> Created Time: 二  1/ 9 06:50:02 2018
 ************************************************************************/

#include<stdio.h>

/**
 * 初始条件：顺序线性表L已存在，1 <= i <= ListLength(L)
 * 操作结果：删除L中第i个位置元素，并用e返回其值，L的长度减1
 */
Status LinkListInsert(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;

    p = *L;
    j = 1;

    while (p && j < i)   // 用于寻找第i个结点
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
    {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);

    
    return OK;
}
