// Prints two strings' addresses

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings (string is just a char *, first char of an array)
    string s = get_string("s: ");
    string t = get_string("t: ");
    
    // Compare strings' ADDRESSES not their values
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    
    // Print strings values
    printf("%s\n", s);
    printf("%s\n", t);

    // Print strings' addresses
    printf("%p\n", s);
    printf("%p\n", t);
}
