//
// Created by Łukasz Pawłowski on 25/06/2023.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define VARNUM 26
#define NUMBER '0'
#define VARSET '1'
#define VARGET '2'

char var = '0';

int getop(char[]);
void push(double);
double pop(void);
double getStackTop(void);
void printStackTop(void);
void swapStackTop(void);
void clearStack(void);
double test(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    double var_buff[VARNUM];

    int varindex = 0;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case VARSET:
            var_buff[varindex++] = pop();
            printf("variable %c: %.3f\n", 'a' + varindex - 1, var_buff[varindex - 1]);
            break;
        case VARGET:
            push(var_buff[var - 'a']);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t %f\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double getStackTop(void)
{
    double t = pop();
    push(t);
    return t;
}

void swapStackTop(void)
{
    int i;
    double t[2];
    for (i = 0; i < 2; i++)
    {
        t[i] = pop();
    }
    for (i = 1; i > 0; i--)
    {
        push(t[i]);
    }
}

void clearStack(void)
{
    double t = pop();
    while (t != 0.0)
    {
        t = pop();
    }
}

void printStackTop(void)
{
    double t = pop();
    push(t);
    printf("%f\n", t);
}

double test(void)
{
    return val[sp - 1];
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (isalpha(c))
    {
        var = c;
        return VARGET;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;

    if (c == '-')
    {
        int nextChar = getch();
        if (!isdigit(nextChar) && nextChar != '.')
        {
            ungetch(nextChar);
            return c;
        }

        s[++i] = c = nextChar;
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
char bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}