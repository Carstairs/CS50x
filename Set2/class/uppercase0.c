// Uppercases a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");


    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            //convert to uppercase - which are 32 values below the lowercase
            printf("%c", s[i] - 32);
        }
        else
        {
            //leave it alone
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
