#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

int getch(void);
void ungetch(int c);
void clearArray(char s[], int size);

int main(int argc, char const *argv[])
{
    int c, inputSize, result;
    char number[1000];
    char sign;
    bool isValid = true;

    result = inputSize = 0;

    while ((c = getch()) != EOF)
    {

        if (c <= 'z' || c >= 'a' || c <= 'Z' || c >= 'A')
        {
            number[inputSize++] = c;
            isValid = false;
            break;
        }

        if (c <= '9' && c >= '0')
        {
            if (inputSize == 0 && c == '0')
            {
                ungetch(EOF);
            }
            number[inputSize++] = c;
        }

        if (c == '=')
        {
            if (sign == '+')
            {
                result += atoi(number);
                clearArray(number, inputSize);
                inputSize = 0;
                printf("'%d' %c %s", result, sign, number);
            }
            else if (sign == '-')
            {
                result -= atoi(number);
                clearArray(number, inputSize);
                inputSize = 0;
            }
            else if (sign == '*')
            {
                result *= atoi(number);
                clearArray(number, inputSize);
                inputSize = 0;
            }
            else if (sign == '/')
            {
                result /= atoi(number);
                clearArray(number, inputSize);
                inputSize = 0;
            }
            ungetch(EOF);
        }

        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (result != 0)
            {
                if (sign == '+')
                {
                    result += atoi(number);
                    clearArray(number, inputSize);
                    inputSize = 0;
                }
                else if (sign == '-')
                {
                    result -= atoi(number);
                    clearArray(number, inputSize);
                    inputSize = 0;
                }
                else if (sign == '*')
                {
                    result *= atoi(number);
                    clearArray(number, inputSize);
                    inputSize = 0;
                }
                else if (sign == '/')
                {
                    result /= atoi(number);
                    clearArray(number, inputSize);
                    inputSize = 0;
                }

                sign = c;
            }
            else
            {
                result = atoi(number);
                clearArray(number, inputSize);
                inputSize = 0;
                sign = c;
            }
        }
    }

    if (isValid)
    {

        printf("result %d", result);
    }
    else
    {
        printf("Provided value is invalid: %s", number);
    }

    return 0;
}

char buff[SIZE];
int bufp = 0;

void clearArray(char s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        s[i] = '\0';
    }
}

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
