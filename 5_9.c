#include <stdio.h>

char *monthNames[12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};

int main(int argc, char const *argv[])
{
    char **ptr_month = monthNames;

    char *month = monthNames[0];
    // printf("testt: %s\n", *++ptr_month);
    int c;
    while (*ptr_month != NULL)
    {
        if (*ptr_month == NULL)
            break;
        printf("%s\n", *ptr_month);
        while ((c = *++ptr_month[0]))
        {
            printf("month %c\n", c);
        }
        ptr_month++;
    }

    return 0;
}
