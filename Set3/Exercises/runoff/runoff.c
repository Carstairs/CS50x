#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("Tied: %s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Find a matching candidate name to elimiate bad votes
        if (strcmp(name, candidates[i].name) == 0)
        {
            //put the candidates index (our current index since we're using the count) into the voters next preference spot
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        //skip the loop if we can
        int firstChoice = preferences[i][0];
        if (!candidates[firstChoice].eliminated)
        {
            candidates[firstChoice].votes++;
        }
        else
        {
            int j = 0;
            while (j < candidate_count)
            {
                int nextCandidate = preferences[i][j];
                //assign vote to first candidate in preferences list that is not eliminated
                if (!candidates[nextCandidate].eliminated)
                {
                    //printf("name: %s\n", candidates[j].name);
                    candidates[nextCandidate].votes++;
                    break;

                }
                j++;
            }
        }
    }

    /* Debug
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Votes for %s: %i\n", candidates[i].name, candidates[i].votes);
    }
    */

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // does anyone have more than 50% of the vote? if so print name and return true
    for (int i = 0; i < candidate_count; i++)
    {
        int minVotesToWin = round(voter_count * 0.5);
        /* Debug
        printf("Min: %i - Votes: %i\n", minVotesToWin, candidates[i].votes);
        */

        if (candidates[i].votes > minVotesToWin)
        {

            printf("Winner is %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //seed the smallest vote
    int smallest_vote = candidates[0].votes;

    // of the non-elimated candidates, what is the smallest number of votes? return that value
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            int current_votes = candidates[i].votes;
            //printf("current votes: %i\n", current_votes);
            if (current_votes <= smallest_vote)
            {
                smallest_vote = current_votes;
            }
        }

    }
    return smallest_vote;
}

// Return true if every candidate remaining in the election has the same number of votes, return false otherwise
bool is_tie(int min)
{
    // input: min = minimum number of votes from find_min function
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && (candidates[i].votes != min))
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // The function should eliminate the candidate (or candidates) who have min number of votes.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
