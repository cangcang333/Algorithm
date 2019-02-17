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

void mergeSortOneTime(int a[], int n, int num)
{
	int i, k, temp;

	printf("num = %d\n", num);
	for (k = 0 ; num * k < n; k++)
	{
		// Notice: Make sure index i in array size, do not make out of bounds mistake.
		for (i = num * k + 1; i < n && i < num * (k + 1); i++)
		{
			temp = a[i];
			while (i - 1 >= num * k && temp < a[i - 1])
			{
				a[i] = a[i - 1];
				i--;
			}
			a[i] = temp;
		}

	}
	printArray(a, n);
}

void mergeSort(int a[], int n)
{
	int num;
	for (num = 2; num <= n; num *= 2)
	{
		mergeSortOneTime(a, n, num);
	}
	
	printf("Last\n");
	int i, temp;
	for (i = 1; i < n; i++)
		{
			temp = a[i];
			while (i - 1 >= 0 && temp < a[i - 1])
			{
				a[i] = a[i - 1];
				i--;
			}
			a[i] = temp;
		}
	printArray(a, n);
}

int main()
{
	int a[] = {5, 2, 9, 1, 4, 7, 8, 3};
	int a2[] = {5, 2, 9, 1, 4, 7, 8, 3, 6, 11, 0, 12, 10};

	int a3[] = {-1, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a4[] = {-1, 2, 3, 4, 6, 7, 8, 9, 1, 0};
	int a5[] = {-1, 38, 65, 56, 76, 13, 27, 49, 55, 4};
	int a6[] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

	mergeSort(a, 8);
	mergeSort(a2, 13);
	mergeSort(a3, 10);
	mergeSort(a4, 10);
	mergeSort(a5, 10);
	mergeSort(a6, 10);

	return 0;
}
