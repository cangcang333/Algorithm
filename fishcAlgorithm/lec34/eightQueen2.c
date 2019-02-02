#include <stdio.h>

int count = 0;

int notDanger(int row, int col, int (*a)[8])
{
	
	int i, j, k; 

	for (k = 0; k < col; k++)
	{
		if (a[row][k] == 1)
		{
			return 0;
		}
	}

	for (k = 0; k < row; k++)
	{
		if (a[k][col] == 1)
		{
			return 0;
		}
	}

	// 4 directions (\)
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i = i - 1, j = j - 1)
	{
		if (a[i][j] == 1)
		{
			return 0;
		}
	}

	// 4 directions (/)
	for (i = row -1, j = col + 1; i >= 0 && j < 8; i = i - 1, j = j + 1)
	{
		if (a[i][j] == 1)
		{
			return 0;
		}
	}

	return 1;
}

void EightQueen(int row, int n, int (*chess)[8])
{
	int i, j, chess2[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if (row == 8)
	{
		count++;
		printf("Got %dth solution\n", count);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d ", chess2[i][j]); 
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		for (j = 0; j < n; j++)
		{

			// Next line is important
			// Now chess represent the former good situation
			// chess2 represent the next good situation
			// If you use chess2, the later notDanger check will all failed, should not be like that.
			if (notDanger(row, j, chess))
			{
				for (i = 0; i < 8; i++)
				{
					*(*(chess2 + row) + i) = 0;
				}
				*(*(chess2 + row) + j) = 1;
				EightQueen(row+1, n, chess2);
			}
		}
	}
}

int main()
{
	int i, j;
	int chess[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			*(*(chess + i) + j)	= 0;
		}
	}

	EightQueen(0, 8, chess);
	
	return 0;
}
