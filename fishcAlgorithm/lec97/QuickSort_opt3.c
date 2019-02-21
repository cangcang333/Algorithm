#include <stdio.h>

#define MAX_LENGTH_INSERT_SORT 7

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
	}
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int Partition(int a[], int low, int high)
{
	// optimize method 1
	int m = low + (high - low) / 2;
	if (a[low] > a[high])
	{
		swap(a, low, high);
	}
	if (a[m] > a[high])
	{
		swap(a, m, high);
	}
	if (a[low] < a[m])
	{
		swap(a, low, m);
	}

//	printf("low = %d, m = %d, high = %d\n", low, m, high);
//	printf("a[low] = %d, a[m] = %d, a[high] = %d\n", a[low], a[m], a[high]);

	int point = a[low];

	while (low < high)
	{
		while (low < high && a[high] > point)
		{
			high--;
		}
//		swap(a, low, high);
		a[low] = a[high]; 

		while (low < high && a[low] <= point)
		{
			low++;
		}
//		swap(a, low, high);
		a[high] = a[low];
	}
	a[low] = point;

	return low;
}

void qSort(int a[], int low, int high)
{
	int point;

	if ( high - low > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			point = Partition(a, low, high);
			if (point - low < high - point)
			{
				qSort(a, low, point-1);
				low = point + 1;
			}
			else
			{
				qSort(a, point+1, high);
				high = point - 1;
			}
		}
	}
	else
	{
		insertSort(a+low, high-low+1);
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
