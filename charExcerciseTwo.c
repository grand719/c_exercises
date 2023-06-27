#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, a, b;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            for (b = getchar(); b == ' '; b = getchar())
            {
                ;
            }

            putchar(c);
            putchar(b);
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}
