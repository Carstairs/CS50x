// Determines the reading level of a text block

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    //prompt for string using get_string
    string text = get_string("Text: ");
    int textLength = strlen(text);

    //count the number of letters (not numbers, punctuation, etc)
    int letters = 0;
    for (int i = 0; i < textLength; i++)
    {
        //if character is not a letter, don't increase count
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    //printf("Letters: %i\n", letters);

    //words
    //increase by one to include the last word that will not have a space after it
    int words = 1;
    for (int i = 0; i < textLength; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    //printf("Words: %i\n", words);

    //sentences (. = 46, ! = 33, ? = 63)
    int sentences = 0; //1?
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    //printf("Sentence(s): %i\n", sentences);

    //compute index inputs
    // L = average number of letters per 100 words
    // S = average number of sentences per 100 words

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    //apply Coleman-Liau Index
    // index = 0.0588 * L - 0.296 * S - 15.8
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int gradeInt = roundf(grade);

    if (gradeInt < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeInt >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeInt);
    }

}
