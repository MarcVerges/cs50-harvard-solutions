#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, string argv[])
{

    if (args != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        string plain = get_string("plaintext: ");
        char ciper[strlen(plain) + 1];

        int key = atoi(argv[1]) % 26;

        printf("ciphertext: ");

        for (int i = 0, n = strlen(plain); i < n; i++)
        {

            if (islower(plain[i]))
            {
                char centrada = (plain[i] - 'a' + key) % 26;
                ciper[i] = (centrada + 'a');
            }
            else if (isupper(plain[i]))
            {
                char centrada = (plain[i] - 'A' + key) % 26;
                ciper[i] = (centrada + 'A');
            }
            else
            {
                ciper[i] = plain[i];
            }
            printf("%c", ciper[i]);
        }
        printf("\n");
    }
}
