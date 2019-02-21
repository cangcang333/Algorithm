#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void merging(int *list1, int lSize, int *list2, int rSize)
{
//	int temp[lSize+rSize];
	int *temp;
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	temp = (int *)malloc(sizeof(lSize + rSize));
	
	while (i < lSize && j < rSize)
	{
		if (*(list1+i) <= *(list2+j))
		{
			temp[k++] = *(list1+i);
			i++;
		}
		else
		{
			temp[k++] = *(list2+j);
			j++;
		}
	}

	for (m = i; m < lSize; m++)
	{
		temp[k++] = *(list1+m);	
	}
	for (m = j; m < rSize; m++)
	{
		temp[k++] = *(list2+m);	
	}

//	printArray(temp, lSize+rSize);

	//	
	for (i = 0; i < lSize + rSize; i++)
	{
		*list1++ = temp[i];
	}
	//
	
}

void recursiveMergeSort(int a[], int n)
{
	int lSize, rSize;
	if (n > 1)
	{
		int *list1 = a;
		int *list2 = a + n/2;
		lSize = n / 2;
		rSize = n - lSize;
		recursiveMergeSort(list1, lSize);
		recursiveMergeSort(list2, rSize);
		
		merging(list1, lSize, list2, rSize);
		printf("\n\nlist1 is \n");
		printArray(list1, lSize+rSize);
	}
}

int main()
{
	int a[] = {5, 2, 9, 1, 4, 7, 8, 3};
	int a2[] = {5, 2, 9, 1, 4, 7, 8, 3, 6, 11, 0, 12, 10};

	int a3[] = {-1, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int a4[] = {-1, 2, 3, 4, 6, 7, 8, 9, 1, 0};
	int a5[] = {-1, 38, 65, 56, 76, 13, 27, 49, 55, 4};
	int a6[] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	//
	recursiveMergeSort(a, 8);
	recursiveMergeSort(a2, 13);
	recursiveMergeSort(a3, 10);
	recursiveMergeSort(a4, 10);
	recursiveMergeSort(a5, 10);
	//

	recursiveMergeSort(a6, 10);

	return 0;
}
