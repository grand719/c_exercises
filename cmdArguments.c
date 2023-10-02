#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STACKMAXVAL 50

double stackBuff[STACKMAXVAL];
int stackIndex = 0;

double pop(void);
void push(double c);

int main(int argc, char *argv[])
{
    int c;
    double summary = 0.0;
    double v, valueToPush;
    while (*++argv != NULL)
    {
        c = *argv[0];

        switch (c)
        {
        case '-':
            v = pop();
            push((v - pop()));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        default:
            valueToPush = atof(*argv);
            push(valueToPush);
            break;
        }
    }
    summary = pop();
    printf("%f\n", summary);
    return 0;
}

void push(double f)
{
    if (stackIndex < STACKMAXVAL)
        stackBuff[stackIndex++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (stackIndex > 0)
        return stackBuff[--stackIndex];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// simple reversed polish calculator

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define STACKMAXVAL 50

// double stackBuff[STACKMAXVAL];
// int stackIndex = 0;

// double pop(void);
// void push(double c);

// int main(int argc, char *argv[])
// {
//     int c;
//     double summary = 0.0;
//     double v, valueToPush;
//     while (*++argv != NULL)
//     {
//         c = *argv[0];

//         switch (c)
//         {
//         case '-':
//             v = pop();
//             push((v - pop()));
//             break;
//         case '+':

//             push(pop() + pop());
//             break;
//         default:
//             valueToPush = atof(*argv);
//             push(valueToPush);
//             break;
//         }
//     }
//     summary = pop();
//     printf("%f\n", summary);
//     return 0;
// }

// void push(double f)
// {
//     if (stackIndex < STACKMAXVAL)
//         stackBuff[stackIndex++] = f;
//     else
//         printf("error: stack full, can't push %g\n", f);
// }

// double pop(void)
// {
//     if (stackIndex > 0)
//         return stackBuff[--stackIndex];
//     else
//     {
//         printf("error: stack empty\n");
//         return 0.0;
//     }
// }

// Grep v2

// char **pptr_test = argv;

// printf("test: %c\n", *++pptr_test[0]);

// size_t bufferSize = 1000;
// char line[bufferSize];
// char *ptr_line = line;
// long lineno = 0;
// int found = 0, except = 0, number = 0, c;

// // tutaj (*++argv) to przechodzimy o +1 czyli jestesmy na index 1
// // i dodanie do tego [0] oznacza ze sprawdzamy zawartosc tego wskaznika na jego pozycji 0
// while (--argc > 0 && (*++argv)[0] == '-')
// {
//     // printf("test: %s", *argv);
//     // zapis *++argv[0] inkrementuje sie po tym na co wskazuje wskaznik
//     while ((c = *++argv[0]))
//     {
//         // printf("test: %c", *argv[0]);
//         switch (c)
//         {
//         case 'x':
//             except = 1;
//             break;
//         case 'n':
//             number = 1;
//             break;
//         default:
//             printf("find: illegal option %c\n", c);
//             argc = 0;
//             found = -1;
//             break;
//         }
//     }
// }
// if (argc != 1)
// {
//     printf("usage: find -x -n patterm\n");
// }
// else
//     while (getline(&ptr_line, &bufferSize, stdin) > 0)
//     {
//         lineno++;
//         if ((strstr(line, *argv) != NULL) != except)
//         {
//             if (number)
//             {
//                 printf("%ld: ", lineno);
//             }
//             printf("%s", line);
//             found++;
//         }
//     }

// return found;

// Grep implementation

// size_t bufferSize = 1000;
// char line[bufferSize];
// char *ptr_line = line;
// int found = 0;
// int k;
// if (argc != 2)
//     printf("Usage: fin pattern\n");
// else
//     while ((k = getline(&ptr_line, &bufferSize, stdin)) > 0)
//     {
//         printf("num of lines: %d\n", k);
//         if (strstr(line, argv[1]) != NULL)
//         {
//             printf("%s\n", line);
//             found++;
//         }
//     }

// printf("Found patter: %d", found);
// return found;

// Echo implementation:

// while (--argc > 0)
// {
//     printf("%s%s", *++argv, (argc > 1) ? " " : "");
// }
// printf("\n");
