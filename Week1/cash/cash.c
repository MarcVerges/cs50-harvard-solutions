#include <cs50.h>
#include <stdio.h>

int number_of_coins(int change_owed);

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed <= 0);

    int n_coins = number_of_coins(change_owed);
    printf("%i\n", n_coins);
}

int number_of_coins(int change_owed)
{
    float possible[4] = {25, 10, 5, 1};

    int n_coins = 0;
    int i = 0;

    while (change_owed != 0)
    {
        if (change_owed >= possible[i])
        {
            n_coins++;
            change_owed = change_owed - possible[i];
        }
        else
        {
            i++;
        }
    }

    return n_coins;
}
