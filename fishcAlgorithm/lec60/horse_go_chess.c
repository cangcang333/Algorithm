#include <stdio.h>

int count = 0;

void PrintArray(int (*a)[8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void InitArray(int (*a)[8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a[i][j] = 0;
		}
	}
}

void HorseGo(int (*a)[8], int row, int col, int pos)
{
	int i, j;

	if (row >= 0 && row < 8 && col >= 0 && col < 8 && a[row][col] == 0)
	{
		a[row][col] = pos;
	}
	else
	{
		// a[row][col] != 0 means this position has been taken
		return;
	}
	
	if (64 == pos)
	{
		count++;
		printf("Got %dth solution\n", count);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}


	/*
	printf("Now row = %d, col = %d, pos = %d\n", row, col, pos);
	if (pos > 61)
	{
		PrintArray(a);
	}
	*/

	int a2[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a2[i][j] = a[i][j];
		}
	}
	int a3[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a3[i][j] = a[i][j];
		}
	}
	int a4[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a4[i][j] = a[i][j];
		}
	}
	int a5[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a5[i][j] = a[i][j];
		}
	}
	int a6[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a6[i][j] = a[i][j];
		}
	}
	int a7[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a7[i][j] = a[i][j];
		}
	}
	int a8[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a8[i][j] = a[i][j];
		}
	}
	int a9[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			a9[i][j] = a[i][j];
		}
	}

	if (row - 2 >= 0 && col - 1 >= 0 && a2[row-2][col-1] == 0)
	{
		HorseGo(a2, row - 2, col - 1, pos + 1);
	}
	if (row - 2 >= 0 && col + 1 < 8 && a3[row-2][col+1] == 0)
	{
		HorseGo(a3, row - 2, col + 1, pos + 1);
	}
	if (row - 1 >= 0 && col - 2 >= 0 && a4[row-1][col-2] == 0)
	{
		HorseGo(a4, row - 1, col - 2, pos + 1);
	}
	if (row - 1 >= 0 && col + 2 < 0 && a5[row-1][col+2] == 0)
	{
		HorseGo(a5, row - 1, col + 2, pos + 1);
	}
	if (row + 1 < 8 && col - 2 >= 0 && a6[row+1][col-2] == 0)
	{
		HorseGo(a6, row + 1, col - 2, pos + 1);
	}
	if (row + 1 < 8 && col + 2 < 8 && a7[row+1][col+2] == 0)
	{
		HorseGo(a7, row + 1, col + 2, pos + 1);
	}
	if (row + 2 < 8 && col - 1 >= 0 && a8[row+2][col-1] == 0)
	{
		HorseGo(a8, row + 2, col - 1, pos + 1);
	}
	if (row + 2 < 8 && col + 1 < 8 && a9[row+2][col+1] == 0)
	{
		HorseGo(a9, row + 2, col + 1, pos + 1);
	}

	return;
}

int main()
{
	int a[8][8];
	InitArray(a);
	PrintArray(a);

	int row = 2;
	int col = 0;
	int pos = 1;
	HorseGo(a, row, col, pos);

	return 0;

}
