#include <stdio.h>

int longWord = 40;
int tab = 5;

int main(int argc, char const *argv[])
{
    extern longWord, tab;
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            i = i + tab;
        }
    }

    return 0;
}
