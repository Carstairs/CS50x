// Swaps two integers using pointers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    // send the ADDRESS using a pointer with the &
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// when you pass input to a function you pass COPIES of the values, not the values themselves
// so what it works with is a copy and it doesn't return anything to the main functio
/*
void noswap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
*/

// so instead of passing the values, take in a pointer to the address of the value (so you skip the whole copy drama)
void swap(int *a, int *b)
{
    int tmp = *a; //* means go to that address
    *a = *b;
    *b = tmp;
}

