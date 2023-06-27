#include <stdio.h>

int strrindex(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char t[] = "ann";
    char pattern[] = "a";

    printf("%d", strrindex(t, pattern));
    return 0;
}

int strrindex(char s[], char t[])
{
    int currentIndex = -1;
    int k, j, i;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            currentIndex = i;
    }
    return currentIndex;
}
