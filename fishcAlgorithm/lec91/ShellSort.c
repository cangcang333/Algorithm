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

void shellSort(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;
	int gap = n;

	do
	{	
		if (gap % 2 == 0)
		{
			gap = gap / 2;
		}
		else
		{
			gap = gap / 2 + 1;
		}

		for (i = gap; i < n; i++)
		{
			count1++;
			if (a[i] < a[i-gap])
			{
				temp = a[i];
			
				// Notice: j must be bigger than 0 to make sure a[] NOT out of bound
				for (j = i; j > gap - 1 && a[j-gap] > temp; j -= gap)
				{
					count2++;
					a[j] = a[j-gap];
				}
				a[j] = temp;
			}
		}
		printf("gap = %d\n", gap);
		printArray(a, 10);
	} while (gap > 1);
	printf("count1 = %d, count2 = %d\n", count1, count2);
}

int main()
{
	int a[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a2[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a3[] = {49, 38, 65, 56, 76, 13, 27, 49, 55, 4};

	shellSort(a3, 10);
	shellSort(a, 10);

	return 0;
}
