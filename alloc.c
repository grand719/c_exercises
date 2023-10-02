#include <stdio.h>

#define ALLOCKSIZE 10000

static char allockbuf[ALLOCKSIZE];
static char *allocp = allockbuf;

char *alloc(int n)
{
    if (allockbuf + ALLOCKSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        printf("not enougth space");
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allockbuf && p < allockbuf + ALLOCKSIZE)
        allocp = p;
}

int strlem(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        p++;
    }

    return p - s;
}

int main(int argc, char const *argv[])
{

    alloc(500);

    return 0;
}
