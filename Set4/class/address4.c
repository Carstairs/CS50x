// Stores and prints an integer via its address

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; //store the address of the variable n
    printf("%i\n", *p); // prints value in the pointer
}
