// Implements a phone book with structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

//create your own custom data structure
typedef struct
{
    // what is in the structure - type and var name
    string name;
    string number;
}
// name of structure
person;


int main(void)
{
    // declare array with datatype (your new custom one) and variable name
    person people[4];

    // set your values
    people[0].name = "EMMA";
    people[0].number = "617-555-0100";
    //see phonebook1.c

    //agreement to keep the names and numbers in the same order
    //string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
    //string numbers[] = {"617-555-0100", "617-555-0101", "617-555-0102", "617-555-0103"};


    // use "strcmp" to compare strings
    // returns 0 if they are the same (-1 if )
    for (int i = 0; i < 4; i++)
    {
        if (!strcmp(people[i].name, "EMMA"))
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
