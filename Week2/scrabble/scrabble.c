#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <string.h>

// Constants
const int NUM_PLAYERS = 2;
const int NUM_OF_LETTERS = 26;

// Data structures
typedef struct
{
    int points;
    string word;
} Player;

typedef struct
{
    char letter[NUM_OF_LETTERS];
    int points[NUM_OF_LETTERS];
} scrabble_letter;

// Functions
int calculate_points(string word, scrabble_letter ABC);
int comparison(Player players[]);


// Actual code
int main(void)
{
    // we create ABC (the pair of letter and points)
    scrabble_letter ABC = {
        .letter = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
        .points = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}};

    // we create and array of players

    Player players[NUM_PLAYERS];

    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        players[i].word = get_string("Player %i: ", (i + 1));
        players[i].points = calculate_points(players[i].word, ABC);
    }

    int ret = comparison(players);

    if (ret == 0)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", ret);
    }
}

int calculate_points(string word, scrabble_letter ABC)
{
    int points = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {

        char letter = toupper(word[i]);
        int j = 0;

        while (letter != ABC.letter[j] && j < NUM_OF_LETTERS)
        {
            j++;
        }

        points += ABC.points[j];
    }

    return points;
}

int comparison(Player players[])
{
    int max = players[0].points;
    int ret = 1;

    for (int i = 1; i < NUM_PLAYERS; i++)
    {

        if (players[i].points > max)
        {
            max = players[i].points;
            ret = (i + 1);
        }
        else if (players[i].points == max)
        {
            ret = 0;
        }
    }

    return ret;
}
