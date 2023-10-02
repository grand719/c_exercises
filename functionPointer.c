
#include <stdio.h>

int somedisplay();
void func1(int);
void func2(int);

typedef void FuncType(int);

int main(int argc, char const *argv[])
{
    FuncType *funcT_ptr = NULL;

    funcT_ptr = func1;
    (*funcT_ptr)(100);
    funcT_ptr = func2;
    (*funcT_ptr)(200);

    int (*func_ptr)();

    func_ptr = somedisplay;

    printf("\nAdress of function somedisply is %p\n", func_ptr);
    (*func_ptr)();
    return 0;
}

int somedisplay()
{
    printf("\n--Displaying some text--\n");
    return 0;
}

void func1(int testarg)
{
    printf("func1 got arg: %d\n", testarg);
}
void func2(int testarg)
{
    printf("func1 got arg: %d\n", testarg);
}
