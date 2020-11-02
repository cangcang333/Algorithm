//
// Created by Danial on 2020/11/2.
//

#include <iostream>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *InitList()
{
    ListNode *listNode = nullptr;
    listNode->val = 0;
    listNode->next = nullptr;

    return listNode;
}


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        //ListNode *l3 = new ListNode[101];
        ListNode l3[101];

        int more = 0;
        int i = 0;

        for (i = 0; i < 101; ++i)
        {
            l3[i].val = -1;
        }

        if (nullptr == l1)
        {
            return l2;
        }
        else if (nullptr == l2)
        {
            return l1;
        }

        for(i = 0; l1 != nullptr && l2 != nullptr &&  i < 101; ++i)
        {

            l3[i].val = (l1->val + l2->val + more) % 10;
            more = (l1->val + l2->val + more) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 == nullptr)
        {
            for (; l1 != nullptr && i < 101; ++i) {
                l3[i].val = (l1->val + 0 + more) % 10;
                more = (l1->val + 0 + more) / 10;
                l1 = l1->next;
            }
        }

        if (l1 == nullptr)
        {
            for (; l2 != nullptr && i < 101; ++i) {
                l3[i].val = (l2->val + 0 + more) % 10;
                more = (l2->val + 0 + more) / 10;
                l2 = l2->next;
            }
        }

        if (more == 1)
        {
            l3[i].val = 1;
        }

        int j = 0;
        for (j = 0; l3[j].val >= 0 && l3[j+1].val >= 0 && j < 101; j++)
        {
            l3[j].next = &l3[j+1];
        }


        for (j = 0; j < 101 && l3[j].val >= 0; ++j)
        {
            std::cout << l3[j].val << "  ";
        }
        std::cout << std::endl;

        return std::move(l3);
    }
};


int main()
{
    //ListNode *l1 = new ListNode[3];
    ListNode *l1 = (ListNode *) malloc(sizeof(ListNode) * 7);
    ListNode node1(9);
    ListNode node2(9);
    ListNode node3(9);
    ListNode node4(9);
    ListNode node5(9);
    ListNode node6(9);
    ListNode node7(9);

    l1[0] = node1;
    l1[1] = node2;
    l1[2] = node3;
    l1[3] = node4;
    l1[4] = node5;
    l1[5] = node6;
    l1[6] = node7;

    int j = 0;
    for (j = 0; l1[j].val >= 0 && l1[j+1].val >= 0 && j < 6; j++)
    {
        l1[j].next = &l1[j+1];
    }

    std::cout << "l1 is ...\n";
    /*
    while (l1 != nullptr)
    {
        std::cout << l1->val << "  ";
        l1 = l1->next;
    }
    std::cout << std::endl;
    */

    ListNode *l2 = new ListNode[4];
    ListNode node84(9);
    ListNode node85(9);
    ListNode node86(9);
    ListNode node87(9);

    l2[0] = node84;
    l2[1] = node85;
    l2[2] = node86;
    l2[3] = node87;

    for (j = 0; l2[j].val >= 0 && l2[j+1].val >= 0 && j < 3; j++)
    {
        l2[j].next = &l2[j+1];
    }

    std::cout << "l2 is ...\n";
    /*
    while (l2 != nullptr)
    {
        std::cout << l2->val << "  ";
        l2 = l2->next;
    }
    std::cout << std::endl;
    */

    std::cout << "l3 is ...\n";
    Solution *solution = new Solution;
    solution->addTwoNumbers(l1, l2);

    return 0;
}

