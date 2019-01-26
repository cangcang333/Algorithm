#include <stdio.h>

#define left   0
#define middle 1
#define right  2


void move(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("Move %c --> %c\n", x, z);
	}
	else
	{
		move(n-1, x, z, y);
		printf("Move %c --> %c\n", x, z);
		move(n-1, y, x, z);
	}

}

int main()
{
	int n = 3;
	move(n, 'x', 'y', 'z');

	return 0;
}
