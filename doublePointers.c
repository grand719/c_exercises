#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *test[] = {"test", "asd"};

// void foo(int **ptr)
// {
//     int a = 5;
//     *ptr = &a;
// }

void foo(char **ptr)
{
    *ptr = malloc(255);
    strcpy(*ptr, "Hello world");
}

int main(int argc, char const *argv[])
{
    int a = 10;

    int *p1 = NULL;
    int **p2 = NULL;

    char **ptr_test = NULL;

    ptr_test = &test;

    p1 = &a;
    p2 = &p1;

    printf("Address of a= %u\n", &a);
    printf("Address of p1= %u\n", &p1);
    printf("Address of p2= %u\n", &p2);

    printf("value at address p2: %u\n", *p2);
    printf("value at address p1: %d\n", *p1);
    printf("value at address **p2: %d\n", **p2);

    printf("test value: %s\n", *test);

    // int *ptr = NULL;
    // ptr = (int *)malloc(sizeof(int));

    // *ptr = 10;

    // foo(&ptr);

    char *ptr = NULL;
    foo(&ptr);

    printf("%s\n", ptr);

    free(ptr);

    return 0;
}
