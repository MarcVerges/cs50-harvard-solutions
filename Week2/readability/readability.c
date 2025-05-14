#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// func declaration
int *get_parameters(string text);
float get_L(int letters, int words);
float get_S(int words, int sentences);

int main(void)
{

    // get text
    string text = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // get parameters
    int *parameters = get_parameters(text);
    if (parameters != NULL)
    {
        letters = parameters[0];
        words = parameters[1];
        sentences = parameters[2];
    }
    free(parameters);
    parameters = NULL;

    // calc of final parameters
    float l = get_L(letters, words);
    float s = get_S(words, sentences);

    // actual problem demand
    float ret = 0.0588 * l - 0.296 * s - 15.8;
    int res = round(ret);

    if (res < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (res < 16)
    {
        printf("Grade %i\n", res);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// func declaration
int *get_parameters(string text)
{
    // we go letter by letter counting them, if we find a ' ' we count a word and if we find a dot
    // or questionmark or exclamation we coiunt a sente

    int letters = 0;
    int words = 1;
    int sente = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sente++;
        }
    }

    int *res = malloc(3 * sizeof(int));
    if (res == NULL)
    {
        return NULL;
    }

    res[0] = letters;
    res[1] = words;
    res[2] = sente;

    return res;
}

float get_L(int letters, int words)
{
    return (((float) letters / words) * 100);
}
float get_S(int words, int sentences)
{
    return (((float) sentences / words) * 100);
}
