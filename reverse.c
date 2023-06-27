#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxLength);
void reverse(char string[], int stringLength);

int main(int argc, char const *argv[])
{
    int c, ln;
    char line[MAXLINE];
    char rev[MAXLINE];

    while ((ln = getLine(line, MAXLINE)) > 0)
    {
        reverse(line, ln);
    }

    return 0;
}

int getLine(char s[], int maxLength)
{
    int c, i;

    for (i = 0; i < maxLength && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
        if (c == '\n')
        {
            s[i] = c;
        }
    }

    s[i] = '\0';
    return i;
}

void reverse(char string[], int length)
{
    int i;
    char rev[length];
    for (i = 0; i < length; ++i)
    {
        rev[i] = string[(length - 1) - i];
    }

    printf("Orginal value: %s | Reversed value: %s \n", string, rev);
}