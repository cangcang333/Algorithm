/*************************************************************************
	> File Name: dualLink.c
	> Author: 
	> Mail: 
	> Created Time: 四  2/ 1 21:45:52 2018
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define OK     1
#define ERROR  0

typedef char    ElemType;
typedef int     Status;

typedef struct DualNode
{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
} DualNode, *DuLinkList;

int main()
{
    
    return 0;
}
