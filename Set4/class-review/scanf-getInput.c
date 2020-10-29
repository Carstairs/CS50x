#include <stdio.h>

int main(void)
{

	//get a variable (int) from the user
	int x;
	printf("x: ");
	//make sure to use the address (&) pointer!
	scanf("%i", &x);
	printf("x: %i\n", x);

	//strings are a little different
	//char *s = null; //don't do this
	//allocate your memory with an array
	char s[16];
	printf("s: ");
	scanf("%s", s);
	printf("s: %s\n", s);
}