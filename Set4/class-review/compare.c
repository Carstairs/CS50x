#include <stdio.h>
#include <cs50.h>

int main(void)
{
	/*
	* Using CS50 to get numbers to compare
	*/
	int i = get_int("i: ");
	int j = get_int("j: ");

	if (i == j)
	{
		printf("Same \n");
	}
	else
	{
		printf("Different\n");
	}

	char *s = get_string("s: "); //returns a pointer to first char address
	string t = get_string("t: ");

	//always different
	//compares the memory location of first char of each string
	if (s == t)
	{
		printf("Same \n");
	}
	else
	{
		printf("Different\n");
	}

	printf("%p\n", s);
	printf("%p\n", t);
}