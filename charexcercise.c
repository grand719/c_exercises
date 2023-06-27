#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nl, c;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' | c == '\t' | ' ')
        {
            ++nl;
        }
    printf("%d\n", nl);
    return 0;
}