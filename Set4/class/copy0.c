// Capitalizes a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    //string s = get_string("s: ");
    char *s = get_string("s: ");

    // Copy string's address (NOT VALUE)
    string t = s;

    // Capitalize first letter in string - this targets the shared address so BOTH vars get changed
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
