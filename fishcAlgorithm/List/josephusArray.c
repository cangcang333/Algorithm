/*************************************************************************
	> File Name: josephusArray.c
	> Author: 
	> Mail: 
	> Created Time: 四  1/11 21:28:05 2018
 ************************************************************************/

#include<stdio.h>

/**
 * 程序功能：用数组模拟约瑟夫环，37个人从1开始报数，数到3的输出，后面从1接着开始数，直到所有人都输出
 */


int main(int argc, char *args[])
{
    int a[10];
    int i = 0;
    for (i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        // 每个人初始状态置为1
        a[i] = 1;
    }

    i = 0;
    int j = 0;
    int count = 0;
    while (1)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 2 && a[i] == 1)
            {
                // 数到第3个，且之前未被输出，此次输出
                printf("BINGO, output i --> [%d]\n", i);
                a[i] = 0;
                i++;
                j = -1;
                count++;
            }
            else if (j != 2 && a[i] == 1)
            {
                // 还未数到第3个，且之前未被输出，此次有效
                printf("Not yet\n");
                i++;
            }
            else if (j != 2 && a[i] == 0)
            {
                // 还未到第3个数，但是这个已经被输出了，此次无效
                printf("This one has been killed\n");
                i++;
                j--;
            }
            else if (j == 2 && a[i] == 0 && i < 10)
            {
                // 数到3，但这个已被输出，下一个
                printf("This one dead, look for next one\n");
                i++;
                j--;
            }

        printf("count is %d\n", count);
        printf("a length is %d\n", sizeof(a)/sizeof(int));
        if (count > sizeof(a)/sizeof(int) - 1 )
        {
            printf("END\n");
//            break;
            return 1;
        }                                  
        i = i % 10;
        printf("now i is %d, a[i] is %d\n", i, a[i]);

            
        }


    }




    return 0;
}
