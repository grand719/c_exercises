#include <stdio.h>

void swap(int *px, int *py);

int main(int argc, char const *argv[])
{
    int b[10];
    for (int i = 0; i < 10; i++)
    {
        b[i] = i;
    }

    swap(&b[1], &b[3]);

    for (int j = 0; j < 10; j++)
    {
        printf("%d", b[j]);
    }

    return 0;
}

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}