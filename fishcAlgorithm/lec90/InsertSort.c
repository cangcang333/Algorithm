#include <stdio.h>

void printArray(int a[], int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertSort(int a[], int n)
{
	int i, j, k, temp;
	int count1 = 0;
	int count2 = 0;

	for (i = 0; i < n - 1; i++)
	{
		count1++;
		if (a[i+1] < a[i] )
		{
			if (i == 0)
			{
				count2++;
				temp = a[0];
				a[0] = a[1];
				a[1] = temp;
			}
			else
			{
				for (j = 0; j < i; j++)
				{
					count1++;
					if (a[i+1] > a[j])
					{
						continue;
					}
					else
					{
						break;
					}
				}
				
				if (j == i)
				{
					count2++;
					temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
				else
				{
					temp = a[i+1];
					for (k = i+1; k > j; k-- )
					{
						count2++;
						a[k] = a[k-1];
					}	
					a[j] = temp;
				}
			}
		}
		printf("i = %d\n", i);
		printArray(a, 10);
	}
	printf("count1 = %d, count2 = %d\n", count1, count2);
	printArray(a, 10);
}

// Simplify the insert sort code
void insertSort2(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;
	
	for (i = 1; i < n; i++)
	{
		count1++;
		if (a[i] < a[i-1])
		{
			temp = a[i];
			
			// Notice: j must be bigger than 0 to make sure a[] NOT out of bound
			for (j = i; j > 0 && a[j-1] > temp; j--)
			{
				count2++;
				a[j] = a[j-1];
			}
			a[j] = temp;
		}
	}
	printf("count1 = %d, count2 = %d\n", count1, count2);
	printArray(a, 10);
}

int main()
{
	int a[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a2[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	insertSort(a, 10);
	insertSort2(a2, 10);

	return 0;
}
