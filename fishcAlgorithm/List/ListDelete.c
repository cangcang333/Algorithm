/*************************************************************************
	> File Name: ListDelete.c
	> Author: 
	> Mail: 
	> Created Time: 一  1/ 8 08:07:56 2018
 ************************************************************************/

#include<stdio.h>

/**
 * 初始条件：顺序线性表L已存在，1 <= i <= ListLength(L)
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 */

Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }

    // 取出第i个位置的值，赋给*e
    *e = L->data[i-1];
    // 第i个位置之后的每个元素先前移动一个位置
    int k = 0;
    for (k = i-1; k < L->length-1; k++)
    {
        L->data[k] = L->data[k+1]; 
    }

    // 顺序线性表的长度减1
    L->length--;
}
