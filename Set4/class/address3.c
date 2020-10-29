// Stores and prints an integer's address

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // prints address
}

// the * here is a POINTER - here is a pointer to an int