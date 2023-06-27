#include <stdio.h>

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* donle ograniczenie */
    upper = 300; /* gorne ograniczenie */
    step = 20;   /* postaienie */

    fahr = lower;
    printf("\tFahrenheit\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    float fahrenheit, cel, init;
    int up, row;

    init = 0.2;
    up = 150;
    row = 10;

    cel = init;
    printf("\tCelsius\n");
    while (cel <= up)
    {
        fahrenheit = (9.0 / 5.0) * cel + 32;
        printf("%6.1f\t%3.0f\n", cel, fahrenheit);
        cel = cel + row;
    }

    return 0;
}
