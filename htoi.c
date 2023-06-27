#include <stdio.h>
#include <ctype.h>
#include <math.h>

int htoi(char hexCode[]);
int calcLength(char s[]);

int main(int argc, char const *argv[])
{
    printf("%d", htoi("0x2F5\0"));
    return 0;
}

int calcLength(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        ++i;
    }

    return i;
}

int htoi(char s[])
{
    int i;
    int wynik = 0;
    int lenght = calcLength(s);
    int l;
    double wage = 16.0;
    double po = 0.0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        l = lenght - 2;
    }

    for (i = 0; i < l; ++i)
    {
        if (isdigit(s[(lenght - 1) - i]))
        {
            wynik = wynik + ((s[(lenght - 1) - i] - '0') * pow(wage, po));
            po = po + 1;
        }
        else if (s[(lenght - 1) - i] >= 'a' && s[(lenght - 1) - i] <= 'f')
        {
            wynik = wynik + ((s[(lenght - 1) - i] - 87) * pow(wage, po));
            po = po + 1;
        }
        else if (s[(lenght - 1) - i] >= 'A' && s[(lenght - 1) - i] <= 'F')
        {
            wynik = wynik + ((s[(lenght - 1) - i] - 55) * pow(wage, po));
            po = po + 1;
        }
    }

    return wynik;
}