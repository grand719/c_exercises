#include <stdio.h>

double celsius(int fahr);
int fahrenheit(double celsius);

int main(int argc, char const *argv[])
{
    int upper, step, low, fahr;
    double cel = 0;
    low = 0;
    upper = 300;
    step = 20;

    fahr = low;

    while (upper >= fahr)
    {
        printf("%3d - %6.1f\n", fahr, celsius(fahr));
        printf("%6.1f - %3d\n", celsius(fahr), fahrenheit(celsius(fahr)));
        fahr = fahr + step;
    }

    return 0;
}

double celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

int fahrenheit(double celsius)
{
    return (9.0 / 5.0) * celsius + 32;
}