#include <stdio.h>
#include <cs50.h>

int main(void)
{
	/*
	* Addresses & Pointers
	*/
	// int n = 50;
	// printf("%i\n", n);

	// pointer %p and &var to get physical address
	int n = 50;
	printf("%p\n", &n);

	//* go to the address and give me the value in it
	// you have to know the type (int, char, etc)
	printf("%i\n", *&n);

	// POINTER : address of the var
	int *p = &n;
	//print physical address
	printf("%p\n", p);
	//print value of address (make sure to use the right type)
	printf("%i\n", *p);

	//pointers are useful for abstracting away from actual addresses

	/*
	* Working with Pointers
	*/

	//string is an array of char pointers
	//all you need is the first letter and go to the null terminating char (\0)

	//string s1 = "EMMA"; //requires CS50
	//is the same as the chars
	char *s = "EMMA1";
	printf("%s\n", s);
	printf("%p\n", s);
	printf("%p\n", &s[0]);
	printf("%p\n", &s[1]);

	printf("%c\n", *s);
	printf("%c\n", s[1]);

	printf("%c\n", *(s + 1));

}