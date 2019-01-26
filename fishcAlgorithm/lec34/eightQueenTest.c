#include <stdio.h>

#define SIZE  8

int i = 0;
int j = 0;

void InitialArray(int a[SIZE][SIZE])
{
	for(i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			a[i][j] = -1;
		}
	}
}
	
void DisplayArray(int a[SIZE][SIZE])
{
	for(i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetZero(int (*a)[SIZE], int row, int col)
{
	printf("row = %d, col = %d\n", row, col);
	i = row; 
	j = col;
	int k = 0;
	for (k = 0; k < SIZE; k++)
	{
		if (a[i][k] != 0 && a[i][k] != 1)
		{
			a[i][k] = 0;
		}
		else
		{
			continue;
		}
	}

	for (k = 0; k < SIZE; k++)
	{
		if (a[k][j] != 0 && a[k][j] != 1)
		{
			a[k][j] = 0;
		}
		else
		{
			continue;
		}
	}
//	printf("Set 0 to current row and column\n");
//	DisplayArray(a);
	
	// 4 direction (\)
	for (i = row + 1, j = col + 1; i < SIZE && j < SIZE; i = i + 1, j = j + 1)
	{
		a[i][j] = 0;
	}


	// 4 directions (\)
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i = i - 1, j = j - 1)
	{
		a[i][j] = 0;
	}

	// 4 directions (/)
	for (i = row -1, j = col + 1; i >= 0 && j < SIZE; i = i - 1, j = j + 1)
	{
		a[i][j] = 0;
	}

	// 4 directions (/)
	for (i = row + 1, j = col - 1; i < SIZE && j >= 0; i = i + 1, j = j - 1)
	{
		a[i][j] = 0;
	}
	printf("Set 0 to 4 directions\n");
	DisplayArray(a);
}

void Queen(int (*a)[SIZE], int row, int col)
{
	int a2[SIZE][SIZE];
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			a2[i][j] = a[i][j];
		}
	}
	printf("Now row = %d, col = %d\n", row, col);

	int k;
	for (k = row ; k < SIZE; k++)
	{
		if (a2[row][k] == -1)
		{
			a2[row][k] = 1;
			SetZero(&a2, row, k);
			if (row + 1 < SIZE)
			{
				Queen(&a2, row+1, col);
			}
		}	
		else
		{
			continue;
		}
	}
	


}

int main()
{
	// Initial the 2-dimension array
	int a[SIZE][SIZE];

	InitialArray(a);

	int row = 0;
	int col = 0;

	DisplayArray(a);

	Queen(&a, row, col);

	
	return 0;
}
		
