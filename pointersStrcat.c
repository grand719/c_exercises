#include <stdio.h>

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

int main(int argc, char const *argv[])
{
    char s[] = "1234567890bb";
    char t[] = "bb";

    /* strcatt(s, t); */
    char *p = s;
    p++;

    /* printf("%d", strendd(s, t)); */
    printf("%s", p);
    return 0;
}
