/*************************************************************************
	> File Name: josephusLink.c
	> Author: 
	> Mail: 
	> Created Time: 五  1/12 21:38:52 2018
 ************************************************************************/

#include<stdio.h>



typedef struct node
{
    int data;
    struct node *next;
}node;

node *create(int n)
{
    node *p = NULL;
    node *head;
    head = (node*)malloc(sizeof(node));
    p = head;
    node *s;
    int i = 1;

    if (0 != n)
    {
        while (i <= n)
        {
            s = (node*)malloc(sizeof)(node);
            s->data = i++;    // 为循环链表初始化，第一个结点为1，第二个结点为2
            p->next = s;
            p = s;
        }
        s->next = head->next;
    }
    free(head);

    return s->next;

}
