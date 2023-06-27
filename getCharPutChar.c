#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    c = getchar();

    while (c != EOF)
    {
        putchar(c);
        /* printf("%d", (c == 0xA)); */ /* 0xA = \n */
        c = getchar();
    }

    return 0;
}
