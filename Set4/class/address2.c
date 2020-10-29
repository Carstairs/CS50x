// Prints an integer via its address

#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", *&n);
}

// * = show the value in the memory location