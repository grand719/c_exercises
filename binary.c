#include <stdio.h>

int bitcount(unsigned x);

int main(int argc, char const *argv[])
{
    int n = 22;
    int x = 22;

    n = n & 01;
    /*     x = x | 1100; */
    x = x << 2;

    printf("%d", bitcount((unsigned)6));
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= x - 1)
        ++b;
    return b;
}