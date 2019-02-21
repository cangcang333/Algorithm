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

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int Partition(int a[], int low, int high)
{
	int point = a[low];
	while (low < high)
	{
		while (low < high && a[high] > point)
		{
			high--;
		}
		swap(a, low, high);
		while (low < high && a[low] <= point)
		{
			low++;
		}
		swap(a, low, high);
	}

	return low;
}

void qSort(int a[], int low, int high)
{
	int point;

	if (low < high)
	{
		point = Partition(a, low, high);
		qSort(a, low, point-1);
		qSort(a, point+1, high);
	}
}

void quickSort(int a[], int n, int start, int end)
{
	qSort(a, 0, n-1);
	printArray(a, n);
}

int main()
{
	int a[] = {5, 2, 9, 1, 4, 7, 8, 3};
	int a2[] = {5, 2, 9, 1, 4, 7, 8, 3, 6, 11, 0, 12, 10};

	int a3[] = {-1, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a4[] = {-1, 2, 3, 4, 6, 7, 8, 9, 1, 0};
	int a5[] = {-1, 38, 65, 56, 76, 13, 27, 49, 55, 4};
	int a6[] = {5, 2, 6, 0, 3, 9, 1, 7, 4};
//	int a7[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a7[] = {5, 2, 6, 0, 3, 9, 1, 7, 5, 5};

	quickSort(a, 8, 0, 8);
	printf("\n\n\n");
	quickSort(a2, 13, 0, 13);
	printf("\n\n\n");
	quickSort(a3, 10, 0, 10);
	printf("\n\n\n");
	quickSort(a4, 10, 0, 10);
	printf("\n\n\n");
	quickSort(a5, 10, 0, 10);
	printf("\n\n\n");
	quickSort(a6, 9, 0, 9);
	printf("\n\n\n");
	quickSort(a7, 10, 0, 10);

	return 0;
}
