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

    int test[10] = {3, 4, 8, 4, 5, 6, 7, 8, 9, 3};
    int slow = test[0];
    int fast = test[0];

    int testt = test[0];
    /*     printf("%d\n", testt);
        testt = test[testt];
        printf("%d\n", testt); */
    printf("%d-%d\n", testt, test[3]);
    testt = test[test[3]];
    printf("%d\n", testt);
    do
    {
        slow = test[slow];
        fast = test[test[fast]];
    } while (slow != fast);

    fast = test[0];

    while (slow != fast)
    {
        slow = test[slow];
        fast = test[fast];
    }
    printf("%d", fast);

    return 0;
}
