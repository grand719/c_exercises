#include <stdio.h>

void strcatn(char *s, char *t, int n)
{
    while (*++s)
        ;

    while (n > 0 && (*s++ = *t++))
        n--;
}

void strcatt(char *s, char *t)
{
    while (*++s)
        ;

    while ((*s++ = *t++))
        ;
}

int strendd(char *s, char *t)
{
    int result = 1;
    while (*++s)
        ;
    while (*t)
    {

        --s;

        if (*s == *t)
        {
            result = 1;
        }
        else
        {
            result = 0;
            break;
        }
        t++;
    }

    return result;
}

void reverse(char *s)
{
    char *end = s;
    char aux = 0;

    while ((*++end) != '\0')
        ;
    end--;

    while (s < end)
    {
        aux = *end;
        *end-- = *s;
        *s++ = aux;
    }
}

int strIndex(char *searchString, char *stringToSearch)
{
    char *pText = searchString;
    while (*searchString != '\0')
    {
        char *s = searchString;
        char *t = stringToSearch;

        while (*s == *t && *t != '\0')
        {
            s++;
            t++;
            if (*t == '\0')
            {
                return searchString - pText;
            }
        }
        searchString++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char s[] = "123bb";
    char t[] = "bb";

    /* strcatt(s, t); */
    char *p = s;
    p++;

    // /* printf("%d", strendd(s, t)); */
    // reverse(s);
    // printf("%s", s);
    // strcatn(s, t, 4);
    // printf("%s", s);
    printf("%d", strIndex(s, t));
    return 0;
}
