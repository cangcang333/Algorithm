#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int chess[X][Y];

// Find the (x, y) position that can be moved on
// count is the Nth possible path (8 situations, count can be 0 to 7)
int nextxy(int *x, int *y, int count)
{
	switch (count)
	{
		case 0:
			if (*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1] == 0)
			{
				*x = *x - 2;
				*y = *y - 1;
				return 1;
			}
			break;
		case 1:
			if (*x-2>=0 && *y+1<Y && chess[*x-2][*y+1] == 0)
			{
				*x = *x - 2;
				*y = *y + 1;
				return 1;
			}
			break;
		case 2:
			if (*x-1>=0 && *y+2<X && chess[*x-1][*y+2] == 0)
			{
				*x = *x - 1;
				*y = *y + 2;
				return 1;
			}
			break;
		case 3:
			if (*x+1<X && *y+2<Y && chess[*x+1][*y+2] == 0)
			{
				*x = *x + 1;
				*y = *y + 2;
				return 1;
			}
			break;
		case 4:
			if (*x+2<X && *y+1<Y && chess[*x+2][*y+1] == 0)
			{
				*x = *x + 2;
				*y = *y + 1;
				return 1;
			}
			break;
		case 5:
			if (*x+2<X && *y-1>=0 && chess[*x+2][*y-1] == 0)
			{
				*x = *x + 2;
				*y = *y - 1;
				return 1;
			}
			break;
		case 6:
			if (*x+1<X && *y-2>=0 && chess[*x+1][*y-2] == 0)
			{
				*x = *x + 1;
				*y = *y - 2;
				return 1;
			}
			break;
		case 7:
			if (*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2] == 0)
			{
				*x = *x - 1;
				*y = *y - 2;
				return 1;
			}
			break;
		default:
			break;
	}	

	return 0;
}

void printChess()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			printf("%2d\t", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * DFS traverse the chess
 * (x, y) : position
 * tag : current position, from 1 to 64, add 1 after every step
 */

int TravelChessBoard(int x, int y, int tag)
{
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag;

	if (tag > 62)
	{
		printChess();
	}

	if (X * Y == tag)
	{
		// job done, print the chess
		printChess();
		return 1;
	}

	// Find the next position(x1, y1) that can be use for the horse
	// if ok, flag set to 1, others, flag set to 0
	
	flag = nextxy(&x1, &y1, count);
	while (0 == flag && count < 7)
	{
		count++;
		flag = nextxy(&x1, &y1, count);
	}

	while (flag)
	{
		if (TravelChessBoard(x1, y1, tag+1))
		{
			return 1;
		}
		
		// Continue to search
		x1 = x;
		y1 = y;
		count++;

		flag = nextxy(&x1, &y1, count);
		while (0 == flag && count < 7)
		{
			count++;
			flag = nextxy(&x1, &y1, count);
		}
		
	}

	if (flag == 0)
	{
		chess[x][y] = 0;
	}

	return 0;
}

int main(void)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			chess[i][j] = 0;
		}
	}


	if(!TravelChessBoard(2, 0, 1))
	{
		printf("sorry, failed\n");
	}

	return 0;
}
