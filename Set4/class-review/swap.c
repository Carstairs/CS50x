#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
	int x = 1;
	int y = 2;

	printf("x is %i, y is %i\n", x, y);
	//this passes copies of your values, not the original values
	//noswap(x, y);
	swap(&x, &y); //pass address of x & y

	printf("x is %i, y is %i\n", x, y);
}

// passes copies, not the pointer to the original
// void noswap(int a, int b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

//accepst pointers using type * variableName
void swap(int *a, int *b)
{
	int tmp = *a; //goto x's address and get value
	*a = *b;	  //go to y's address and get value
	*b = tmp;
}

/*
* Order of computer memory
machine code
globals
heap
. heap grows down
.
. stack grows up
stack (your local var)

* Order in stack
    each function gets it's own frame
    main - gets x, y, 1, 2
    swap - gets a, b, tmp; gets 1, 2
    when swap is done it loses memory allocation and chages are not available

Pass pointers instead - so swap gets the pointer to x & y
*/