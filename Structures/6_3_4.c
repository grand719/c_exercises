#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define SIZE 1000

struct key
{
    char *word;
    int count;
} keytab[] = {
    "auto",
    0,
    "break",
    0,
    "case",
    0,
    "char",
    0,
    "const",
    0,
    "continue",
    0,
    "default",
    0,
    {"double",
     0},
    {"int",
     0},
    "unsigned",
    0,
    {"struct",
     0},
    {"switch",
     0},
    {"while",
     0},
    "void",
    0,
    "volatile",
    0,
};

#define NKeys (sizeof keytab / sizeof(struct key))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

char buff[SIZE];
int bufp = 0;

int getch()
{
    return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= SIZE)
    {
    }
    else
    {
        buff[bufp++] = c;
    }
}

int main(int argc, char const *argv[])
{
    struct key *p;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKeys)) != NULL)
                p->count++;
    }
    for (p = keytab; p < keytab; p++)
    {
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    }

    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c == '#')
    {
        while ((c = getch()) != '\n')
            ;
    }

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_')
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()) && *w != '_')
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
