
#include <stdio.h>

#include <stdbool.h>

int main(void)
{
    float change_owed = get_float("Change owed: ");
    float possible[4] ={25,10,5,1};

    int n_coins = 0;
    int i = 0;

    bool acabado = false;

    while (!acabado)
    {
        if (change_owed > possible[i])
        {
            n_coins++;
            change_owed = change_owed - possible[i];
        }
        else if (change_owed == 0)
        {
            acabado = true;
        }
        else
        {
            i++;
        }
    }

    printf ("%i",n_coins);

}

