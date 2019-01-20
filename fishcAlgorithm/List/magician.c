/*************************************************************************
	> File Name: magician.c
	> Author: 
	> Mail: 
	> Created Time: 四  3/ 1 10:57:03 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

/**
 * Define the node struct
 */

typedef struct node
{
    int data;
    struct node *next;
}sqlist, *linklist;


/**
 * Create the list
 * return a linklist
 */
linklist CreateList()
{
    linklist head = NULL;

    linklist p, q;
    p = head;
    
    int i = 0;
    for (i = 0; i < CardNumber; i++)
    {
        q = (linklist)malloc(sizeof(sqlist));
        q->data = i + 1;
        if (head == NULL)
        {
            head = q;
        }
        else
        {
            p->next = q;
        }
        p = q;
    }
    p->next = head;

    return head;
}

int main(int argc, char **argv)
{
    linklist shit = NULL;
    shit = CreateList();
    linklist r, s;
    r = shit;
    int j = 0;
    for (j = 0; j < CardNumber; j++)
    {
        s = (linklist)malloc(sizeof(sqlist));
        s = r->next;
        printf("j = %d and data is %d\n", j, r->data);
        r = s;

    }
    return 0;
}
