// Capitalizes a copy of a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for another string - var value plus terminating null char
    // This creates an actual copy instead of duplicating the pointer
    char *t = malloc(strlen(s) + 1);

    //since string is not a single thing, you have to work through the array - tedious

    // Copy string into memory
    //using a var for the string length n
    //need to include the null char at the end so n + 1

    for (int i = 0, n = strlen(s); i < n + 1; i++)
    {
        t[i] = s[i];
    }

    // Capitalize copy's first letter
    t[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
