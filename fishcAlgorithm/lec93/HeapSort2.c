#include <stdio.h>

int count = 0;

void printArray(int a[], int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int a[], int i, int j)
{
	int temp;
	
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void heapAdjust(int a[], int s, int n)
{
	int i;
	
	int temp = a[s];
	for (i = 2 * s; i < n+1; i *= 2)
	{
		count++;
		if (i < n && a[i] < a[i+1])
		{
			i = i + 1;
		}

		if (temp > a[i])
		{
			break;
		}
		a[s] = a[i];
		s = i;
	}
	a[s] = temp;
}

void heapSort(int a[], int n)
{
	int i;

	for (i = n / 2; i > 0; i--)
	{
		heapAdjust(a, i, n);
	}

	for (i = n; i > 1; i--)
	{
		swap(a, 1, i);
		heapAdjust(a, 1, i-1);
	}
	printf("count = %d\n", count);
}

int main()
{
	int a[] = {-1, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a2[] = {-1, 2, 3, 4, 6, 7, 8, 9, 1, 0};
	int a3[] = {-1, 38, 65, 56, 76, 13, 27, 49, 55, 4};

	int a4[] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

	heapSort(a4, 9);
	heapSort(a, 9);
	heapSort(a2, 9);
	heapSort(a3, 9);

	printArray(a, 10);
	printArray(a2, 10);
	printArray(a3, 10);
	printArray(a4, 10);

	return 0;
}
