#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char test[] = "abecede\0";
    char test2[] = "abcd\0";
    char test3[] = "aaaaabcd\0";

    printf("%d %d", any(test, test2), any(test3, test2));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, position;

    position = -1;

    for (i = 0; s1[i] != '\0'; i++)
    {

        if (s1[i] == s2[0])
        {

            for (j = 1; s2[j] != '\0'; j++)
            {
                if (s1[i + j] == s2[j])
                {
                    position = i;
                }
                else
                {
                    position = -1;
                    break;
                }
            }
        }
    }

    return position;
}
