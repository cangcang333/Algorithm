/*************************************************************************
	> File Name: getElem.c
	> Author: 
	> Mail: 
	> Created Time: 日  1/ 7 20:44:18 2018
 ************************************************************************/

#include<stdio.h>

#define OK      1
#define ERROR   0
#define TRUE    1
#define FALSE   0


typedef int Status;


/**
 * 函数功能：获取顺序线性表中某一位置的元素
 * Status 是函数的返回类型，其值是函数结果状态代码，如OK/ERROR等。
 * 初始条件：顺序线性表L已存在，1 <= i <= ListLength(L)
 * 操作结果：用e返回L中第i个数据元素的值。
 */
Status GetElem(SqList L, int i, ElemType *e)
{
    // 注意i从1开始计数
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }

    *e = L.data[i-1];

    return OK;
}

