// Ceaser style cryptography

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int digitsOnly(string str);

int main(int argc, string argv[])
{
    // CLI argument input of key K (argv[1])
    // if no key or more than one
    if (argc != 2)
    {
        printf("Input an integer for your key\n");
        return 1;
    }
    else
    {
        // make sure its digits
        int onlyDigits = digitsOnly(argv[1]);
        //if not, exit
        if (onlyDigits != 0)
        {
            return 1;
        }

        //convert key to integer <= number of letters in alphabet
        int origKey = atoi(argv[1]);

        if (origKey > 26)
        {
            origKey = origKey % 26;
            if (origKey == 0)
            {
                origKey = 26;
            }
        }

        // get plaintext
        string plaintext = get_string("plaintext: ");

        // loop through array of plain
        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i ++)
        {
            int origCharInt = (int) plaintext[i];
            int newChar = origCharInt + origKey;

            if ( isalpha(plaintext[i]) )
            {
                //if greater than Z subtract 26
                //for lowercase
                if ( islower(plaintext[i]) )
                {
                    if ( newChar > 122 )
                    {
                        int newCharRotated = newChar - 26;
                        printf("%c", newCharRotated);
                    }
                    else
                    {
                        printf("%c", newChar);
                    }

                }
                //for uppercase
                else if ( isupper(plaintext[i]) )
                {
                    if ( newChar > 90 )
                    {
                        int newCharInt = newChar - 26;
                        printf("%c", newCharInt);
                    }
                    else
                    {
                        printf("%c", newChar);
                    }
                }
            }
            //not a letter so print it back out
            else
            {
                printf("%c", origCharInt);
            }
        }
        printf("\n");
        return 0;

    } //end else
}

//module to check if a string is only digits
int digitsOnly(string str)
{
    for (int j = 0, n = strlen(str); j < n; j++)
    {
        if ( !isdigit(str[j]) )
        {
            printf("Usage: ./ceaser key\n");
            return 1;
            break;
        }
    }
    return 0;
}
