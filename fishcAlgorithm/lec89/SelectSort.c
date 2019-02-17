#include <stdio.h>

void printArray(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}	
	printf("\n");
}

void selectSort(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;
	int flag = 1;
	int min = 0;

	for (i = 0; i < n - 1 ; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			count1++;

			// Sort start little to big
			if (a[j] < a[min])	
			{
				min = j;
			}
		}
		
		// exchange minimal value and the ith minition
		if (min != i)
		{
			count2++;
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}

	printf("%d times comparison did and %d times exchange did\n", count1, count2);
	printArray(a, n);
}

int main()
{
	int a[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
	int a2[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
//	int a[] = {1, 0, 2, 3, 4, 5, 6, 7, 8};

	selectSort(a, 9);
	selectSort(a2, 10);

	return 0;
}
