#include <stdio.h>

int tab = 3;

int main(int argc, char const *argv[])
{
    extern int tab;
    int c, i, j;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++i;
            if (i == tab)
            {
                putchar('\t');
                i = i - tab;
            }
        }
        else if (c != EOF)
        {
            putchar(c);
        }
    }

    return 0;
}
