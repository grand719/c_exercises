#include <stdio.h>
#include <ctype.h>
#include <math.h>
// void swap(int *px, int *py);
#define swap(t, x, y)  \
    {                  \
        t temp = *(x); \
        *(x) = *(y);   \
        *(y) = temp;   \
    }

int getch(void);
void ungetch(int c);
int getint(int *pn);
void printbuf(void);
int getfloat(double *pn);

int main(int argc, char const *argv[])
{
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x;
    y = *ip;
    *ip = 0;
    ip = &z[0];
    ++*ip;
    (*ip)++;
    printf("t: %d %d \n", x, y);

    swap(int, &x, &y);

    printf("t %d %d \n", x, y);

    int n, array[100], getint(int *);

    // for (n = 0; n < 100 && getint(&array[n]) != EOF; n++)
    //     ;
    // printf("%d", array[1]);

    n = 0;
    getint(&n);
    printf("%d \n", n);
    printbuf();
    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // Bufor dla ungetch()
int bufpos = 0;    // Aktualna pozycja w buforze

// Pobiera pojedynczy znak bez wyświetlania na ekranie
int getch()
{
    // Jeśli bufor nie jest pusty, pobierz znak z bufora
    // W przeciwnym razie pobierz znak z wejścia standardowego
    return bufpos > 0 ? buf[--bufpos] : getchar();
}

// Umieszcza znak z powrotem do bufora
void ungetch(int c)
{
    if (bufpos < BUFSIZE)
    {
        buf[bufpos++] = c; // Jeśli bufor nie jest pełny, umieść znak w buforze
    }
    else
    {
        printf("Error: Buffer is full. Cannot ungetch().\n");
    }
}

void printbuf(void)
{
    printf("Buffer [\n");
    for (int i = 0; i < bufpos; i++)
    {
        printf("%c\n", buf[i]);
    }
    printf("]\n");
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // to nie jest liczba
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(double *pn)
{
    int c, i;
    double sign, result;

    while ((isspace(c = getch())))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    while (isdigit(c = getch()))
    {
        *pn = 10.0 * *pn + (c - '0');
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn * (c - '0');
    }

    if (c == '.')
    {
        for (i = 1; ((c = getch()) && isdigit(c)); ++i)
            *pn += (c - '0') * pow(10.0, i);
    }
    if (c != EOF)
        ungetch(c);

    *pn = sign * *pn;
    return c;
}