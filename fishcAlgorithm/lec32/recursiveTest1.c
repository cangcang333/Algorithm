#include <stdio.h>

void reverseCharacter();

int main()
{
	reverseCharacter();

	printf("\n");
	return 0;
}

void reverseCharacter()
{
	char a;
	scanf("%c", &a);
	
	if (a != '#')
	{
		reverseCharacter();
	}

	if (a != '#')
	{
		printf("%c", a);
	}
}
