#include <stdio.h>
#include <ctype.h>

#define SIZE 20;

int main(int argc, char const *argv[])
{
    char s[6];
    int i = 0;
    int k;
    int c;
    s[5] = '\0';
    while ((c = getchar()) != EOF && i < 5)
    {
        if (isdigit(c))
        {
            s[i++] = c;
        }
        else
        {
            k = c;
        }
    }

    printf("%s | %d | %c | %c | %c", s, i, s[i - 1], k, c);
    return 0;
}