#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t, b, s, c;

    t = 116;
    b = 92;
    s = 92;

    while ((c = getchar()) != EOF)
    {
        if (c == 9)
        {
            putchar(s);
            putchar(t);
        }
        else if (c == 8)
        {
            putchar(s);
            putchar(b);
        }
        else if (c == 92)
        {
            putchar(s);
            putchar(s);
        }
        else if (c != EOF)
        {
            putchar(c);
        }
    }

    return 0;
}
