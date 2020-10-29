// Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //agreement to keep the names and numbers in the same order
    string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
    string numbers[] = {"617-555-0100", "617-555-0101", "617-555-0102", "617-555-0103"};

    /*
    //this does not work becaues you cannot do == on strings in C
    for (int i = 0; i < 4; i++)
    {
        if(names[i] == "EMMA")
        {
            printf("Found\n");
        }
    }
    printf("Not found\n");
    */

    // use "strcmp" to compare strings
    // returns 0 if they are the same (-1 if )
    for (int i = 0; i < 4; i++)
    {
        if (!strcmp(names[i], "EMMA"))
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
