#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
	//name of file, r /read, w /write, a /append as the second parameter
	FILE *file = fopen("phonebook.csv", "a");

	char *name = get_string("Name: ");
	char *number = get_string("Number: ");

	//write strings to the file (csv format)
	fprintf(file, "%s,%s\n", name, number);

	fclose(file);
}