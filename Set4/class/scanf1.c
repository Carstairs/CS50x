// Incorrectly gets a string from user using scanf

#include <stdio.h>

int main(void)
{
    //char *s = NULL; //if you don't know what your input is going to be
    char s[5];
    printf("s: ");
    scanf("%s", s); //why isn't this one an &s? Because char * is already a pointer
    printf("s: %s\n", s);
}
