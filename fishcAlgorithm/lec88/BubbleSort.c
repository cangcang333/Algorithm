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

// This is not really bubble sort, just brute force comparison
void bubbleSort(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			count1++;

			// Sort start big to little
			// if (a[i] < a[j])

			// Sort start little to big
			if (a[i] > a[j])	
			{
				count2++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("%d times comparison did and %d times exchange did\n", count1, count2);
	printArray(a, n);
}

// This is real bubble sort, compare two adjacent number
void bubbleSort2(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			count1++;

			// Sort start big to little
			// if (a[i] < a[j])

			// Sort start little to big
			if (a[j - 1] > a[j])	
			{
				count2++;
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d times comparison did and %d times exchange did\n", count1, count2);
	printArray(a, n);
}

// Optimize bubble sort, cut unnecessary comparison
void bubbleSort3(int a[], int n)
{
	int i, j, temp;
	int count1 = 0;
	int count2 = 0;
	int flag = 1;

	for (i = 0; i < n - 1 && flag == 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			count1++;
			flag = 0;

			// Sort start big to little
			// if (a[i] < a[j])

			// Sort start little to big
			if (a[j - 1] > a[j])	
			{
				count2++;
				flag = 1;
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d times comparison did and %d times exchange did\n", count1, count2);
	printArray(a, n);
}

int main()
{
	int a[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
	int a2[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
	int a3[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
//	int a[] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
	int a4[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	printf("sizeof(a[0]) = %ld\n", sizeof(a[0]));
	printf("a length is = %ld\n", sizeof(a) / sizeof(a[0]));
	bubbleSort(a, 9);
	bubbleSort2(a2, 9);
	bubbleSort3(a3, 9);
	bubbleSort3(a4, 10);

	return 0;
}
