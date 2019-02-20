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

void quickSort(int a[], int n, int start, int end)
{
	int sum = 0;
	int i, j, k;
	int temp = 0;

	printf("First\n");
	printf("n = %d, start = %d, end = %d\n", n, start, end);
	printArray(a, n);

	if (end - start < 2)
	{
		return;
	}
	else if (end - start == 2)
	{
		printf("shit a[start] = %d, a[end - 1] = %d\n", a[start], a[end - 1]);
		if (a[start] > a[end - 1])
		{
			temp = a[start];
			a[start] = a[start + 1];
//			a[start + 1] = temp;	
			a[end - 1] = temp;
		}
		printArray(a, n);
		return;
	}

	int a2[n];
	for (i = 0; i < n; i++)
	{
		a2[i] = a[i];
	}
	

	for (i = start; i < end; i++)
	{
		sum += a[i];	
	}
	float aver = ((float)sum) / (end - start);
	printf("aver = %f\n", aver);

	j = start;
	k = 0;
	for (i = start; i < end; i++)
	{
		if (a[i] < aver)
		{
			a2[j] = a[i];
			j++;
		}
		else
		{
			a2[end - 1 - k] = a[i];
			k++;
		}
		printf("Now a[i] = %d, j = %d, k = %d, i = %d\n", a[i], j, k, i);
		
	}
	printArray(a2, n);
	
	for (i = 0; i < n; i++)
	{
		a[i] = a2[i];
	}

	quickSort(a, n, start, j);
	quickSort(a, n, j, end);
}

int main()
{
	int a[] = {5, 2, 9, 1, 4, 7, 8, 3};
	int a2[] = {5, 2, 9, 1, 4, 7, 8, 3, 6, 11, 0, 12, 10};

	int a3[] = {-1, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a4[] = {-1, 2, 3, 4, 6, 7, 8, 9, 1, 0};
	int a5[] = {-1, 38, 65, 56, 76, 13, 27, 49, 55, 4};
	int a6[] = {5, 2, 6, 0, 3, 9, 1, 7, 4};

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

	return 0;
}
