// Capitalizes a copy of a string using strcpy

//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Get a string
    //char *s = get_string("s: ");
    char *s = "soren";

    // Allocate memory for another string - but it's never actually freed
    char *t = malloc(strlen(s) + 1);

    // Copy string into memory once you've created your new memory
    strcpy(t, s);

    // Capitalize copy
    t[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}


// Debug functionality: "valgrind" to check for memory leaks
// $ valgrind ./programExecutable
// $ valgrind ./copy2

//then run help50 on the valgrind program
// $ help50 valgrind ./copy2