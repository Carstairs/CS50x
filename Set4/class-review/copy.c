#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	string s = get_string("s: ");

	// 	string t = s;
	// 	t[0] = toupper(t[0]);

	printf("%s\n", s); //changes to t change s
	//printf("%s\n", t);
	//t is just a pointer to s

	// to actualy create a new variable
	// allocate memory
	char *u = malloc(strlen(s) + 1);

	//make sure to copy the null char (n + 1)
	for (int i = 0, n = strlen(s); i < n + 1; i++)
	{
		u[i] = s[i];
	}
	u[0] = toupper(u[0]);

	printf("%s\n", u);

	//the easier way in string.h
	char *v = malloc(strlen(s) + 1);
	strcpy(v, s);
	v[1] = toupper(v[1]);
	printf("%s\n", v);

	//hand back the malloc memory you got earlier to prevent memory leaks
	//to check for it: $ valgrind ./filename
	//help50 will clarify error messages: $ help50 valgrind ./filename

	free(u);
	free(v);
}