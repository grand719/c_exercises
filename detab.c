#include <stdio.h>

int numSpace = 3;

int main(int argc, char const *argv[])
{
    int c, i, j;

    extern int numSpace;

    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            for (i = 0; i < numSpace; ++i)
            {
                putchar(' ');
            }
        }
        else if (c != EOF)
        {
            putchar(c);
        }
    }

    return 0;
}