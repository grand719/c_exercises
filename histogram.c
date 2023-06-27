#include <stdio.h>

#define MAXWORDS 10

int main(int argc, char const *argv[])
{
    int wordsCount[MAXWORDS];
    int c, wc, i, max, state;

    wc = i = max = 0;
    for (int a = 0; a < MAXWORDS; a++)
        wordsCount[a] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            wordsCount[i] = wc;
            if (wc >= max)
            {
                max = wc;
            }
            wc = 0;
            ++i;
        }
        else
        {
            ++wc;
        }
    }

    for (int k = 0; k < max; k++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j > 0)
            {
                printf("\t");
            }
            if (k < wordsCount[j])
            {
                printf("|");
            }
            else
            {
                printf("");
            }
        }

        printf("\n");
    }

    return 0;
}
