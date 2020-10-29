// Stores and prints a string without using the CS50 Library

#include <stdio.h>

int main(void)
{
    char *s = "EMMA";
    printf("%s\n", s);      //value

                            //value of each place in the array - using c
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);

    printf("%p\n", s);      //address of var = address of the first char

                            //address of the nth place of the (&)pointer - using %p
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    // using the pointer var "go to this value" - this is what [3] gets converted to
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+3));
}
