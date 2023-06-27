#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char test[] = "abecede\0";
    char test2[] = "abcd\0";

    squeeze(test, test2);
    printf("%s", test);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    k = 0;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; j++)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
}
