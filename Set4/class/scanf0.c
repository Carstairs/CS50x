// Gets an int from user using scanf

#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");

    //scan from the user's keyboard
    scanf("%i", &x);

    printf("x: %i\n", x);
}


//basic version
/*
int x;
printf("x: ");
scanf("%i", &x); //note &x
*/