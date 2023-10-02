#include <stdio.h>
#include <stdlib.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define swap(t, x, y) \
    {                 \
        t temp;       \
        temp = x;     \
        x = y;        \
        y = temp;     \
    }
int main(int argc, char const *argv[])
{
    // int x, y;
    // x = 10;
    // y = 20;
    // printf("%d %d\n", x, y);
    // swap(int, x, y);
    // printf("%d %d", x, y);
    /* code */
    char lineBuffer[10000];
    size_t bufferSize = 100;
    ssize_t lineLength;
    char *ptr_lineBuffer = lineBuffer;
    char **ptrr_lineBuffer = &ptr_lineBuffer;
    // lineBuffer = malloc(bufferSize * sizeof(char));
    lineLength = getline(&ptr_lineBuffer, &bufferSize, stdin);
    printf("%zu \n", lineLength);
    printf("%s\n", lineBuffer);
    return 0;
}
