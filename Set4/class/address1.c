// Prints an integer's address

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}

// %p = pointer, displayed in hexidecimal
// &n = the location ADDRESS in memory