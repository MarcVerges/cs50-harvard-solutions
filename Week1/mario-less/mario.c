#include <cs50.h>
#include <stdio.h>

// Function resume
void build_pyramid(int altura);

// Main
int main(void)
{

    int altura;

    do
    {cas
        altura = get_int("Height: ");
    }
    while (altura <= 0);
    build_pyramid(altura);
}

// Functions
void build_pyramid(int altura)
{

    for (int i = 0; i < altura; i++)
    {
        for (int spc = 0; spc < (altura - (i + 1)); spc++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
