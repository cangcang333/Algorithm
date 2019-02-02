#include <stdio.h>

#define SIZE  8

int count = 0;

void InitialArray(int (*a)[SIZE])
{
	int i = 0;
	int j = 0;
	for(i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			a[i][j] = 0;
		}
	}
}
	
void DisplayArray(int (*a)[SIZE])
{
	int i = 0;
	int j = 0;
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
	int i = row; 
	int j = col;
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
//	printf("Set 0 to 4 directions\n");
//	DisplayArray(a);
}

int Check(int (*a)[SIZE], int row, int col)
{
	
	int i = row; 
	int j = col;
//	printf("fxxk, i = %d, j = %d\n", row, col);
	int k = 0;

//	DisplayArray(a);

	for (k = 0; k < col; k++)
	{
		if (a[i][k] == 1)
		{
			return -1;
		}
	}

//	printf("shit\n");
//	DisplayArray(a);
	for (k = 0; k < row; k++)
	{
//		printf("k = %d, j = %d, a[k][j] = %d\n", k, col, a[k][j]);
		if (a[k][j] == 1)
		{
			return -1;
		}
	}

	// 4 directions (\)
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i = i - 1, j = j - 1)
	{
		if (a[i][j] == 1)
		{
			return -1;
		}
	}

	// 4 directions (/)
	for (i = row -1, j = col + 1; i >= 0 && j < SIZE; i = i - 1, j = j + 1)
	{
		if (a[i][j] == 1)
		{
			return -1;
		}
	}

	return 0;
}

// row: the start row
// col: column
// (*a)[SIZE]: the pointer point to every row in the chess
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
//	printf("Now row = %d, col = %d\n", row, col);

	if (8 == row)
	{
		count++;
		printf("Got %dth solution\n", count);
		DisplayArray(a);
		return;
	}

	int k;
	for (k = 0; k < SIZE; k++)
	{
		if (a2[row][k] == 0)
		{
			col = k;
//			printf("Now row = %d, col = %d\n", row, col);
			a2[row][k] = 1;
			int result = Check(a2, row, col);
//			printf("check result = %d\n\n", result);
			if (result == 0 && row  < SIZE)
			{
				a2[row][k] = 1;
				Queen(a2, row+1, col);
			}
			else
			{
				a2[row][k] = 0;
			}
		}	
		else
		{
			continue;
		}
	}
	
	if (row - 1 > -1)
	{
		for (k = 0; k < SIZE; k++)
		{
			if (a2[row-1][k] == 1)
			{
				col = k;
				a2[row-1][col] = -1;  // make this point dead for now
//				printf("Recursive, row - 1 = %d, col + 1 = %d\n", row - 1, col + 1);
				for (k = 0; k < SIZE; k++)
				{
					// reset the -1 in next row to 0
					a2[row][k] = 0;
				}
				Queen(a2, row-1, col+1);
			}
		}
	}

	return;
}

int main()
{
	// Initial the 2-dimension array
	int a[SIZE][SIZE];

	InitialArray(a);

	int row = 0;
	int col = 0;

	DisplayArray(a);

	Queen(a, row, col);

	printf("count = %d\n", count);

	
	return 0;
}
		
