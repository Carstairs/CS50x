// Averages three numbers using an array and a constant

#include <cs50.h>
#include <stdio.h>

//function prototype
float average(int length, int array[]);

int main(void)
{
    int n = get_int("Number of scores: ");
    int scores[n];

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    // Print average
    printf("Average: %.1f\n", average(n, scores));
}

float average(int length, int array[])
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / (float) length;
}