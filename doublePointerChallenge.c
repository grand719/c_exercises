#include <stdio.h>
#include <stdlib.h>

char *lines[] = {"test", "asd", "abcd"};

void printLines(char *lines[])
{
    while (*lines != NULL)
    {
        printf("String: %s\n", *lines);
        while (*lines[0] != '\0')
        {
            printf("    Char: %c\n", *lines[0]++);
        }

        lines++;
    }
}

void modifyPtrVal(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int));
    **ptr = 5;
}

int main(int argc, char const *argv[])
{
    int t = 10;
    int *ptr_t = &t;
    int **pp_t = &ptr_t;
    printf("%d\n", t);
    printf("%d\n", *ptr_t);
    printf("%d\n", **pp_t);

    printf("%p\n", &t);
    printf("%p\n", ptr_t);
    printf("%p\n", *pp_t);

    printf("%p\n", ptr_t);
    printf("%p\n", *pp_t);

    printf("%p\n", &ptr_t);
    printf("%p\n", pp_t);

    printf("%p\n", pp_t);
    printf("%p\n", &pp_t);

    int k = 20;

    int *ptr_k;

    modifyPtrVal(&ptr_k);

    printf("%d\n", *ptr_k);

    free(ptr_k);

    printLines(lines);

    return 0;
}
