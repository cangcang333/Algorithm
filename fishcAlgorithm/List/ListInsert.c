/*************************************************************************
	> File Name: ListInsert.c
	> Author: 
	> Mail: 
	> Created Time: 二  1/ 9 07:50:40 2018
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 20

/**
 * 初始条件：顺序线性表L已存在， 1 <= i <= ListLength(L)
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
 */
Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;

    // 如果线性顺序表已达到最大容量，返回插入失败
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    // 如果i不在范围内，返回插入失败
    if (i < 1 || i > L->length+1)
    {
        return ERROR;
    }
    if (i <= L->length)
    {
        // 将要插入位置后数据元素向后移动一位
        for (k = L->length-1; k > i; k--)
        {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;

    return OK;
}
