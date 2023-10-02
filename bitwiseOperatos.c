
#include <stdio.h>

int isOdd(int k)
{
    // used to test bits
    return k & 1;
}

int combine(int k)
{
    // used to set bits
    return k | 0x90;
}

int clearValueWithMask(int k, unsigned int mask)
{
    return k & ~(7 << 4);
    // return k & mask;
}

int toggleBits(int k)
{
    return ^k;
}

int main(int argc, char const *argv[])
{
    int k = 46;

    printf("Is odd: %d | value: %d\n", isOdd(k), k);
    k = 47;
    printf("Is odd: %d | value: %d\n", isOdd(k), k);
    printf("Cleared bits: 0x%x | value: %d \n", clearValueWithMask(255, 0x8F), 255);
    printf("Cleared bits: 0x%x | value: %d \n", clearValueWithMask(255, 0x70), 255);

    return 0;
}
