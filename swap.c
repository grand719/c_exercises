#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t _z;         \
        _z = x;       \
        x = y;        \
        y = _z;       \
    };

int main(int argc, char const *argv[])
{
    int k = 10;
    int l = 9;
    swap(int, k, l);
    printf("%dk %dl", k, l);
    return 0;
}
