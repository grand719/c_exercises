#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point p2;
};

int main(int argc, char const *argv[])
{
    struct point pt = {200, 100};
    // struct maxpt = {320, 200};

    double dist, sqrt(double);

    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);

    printf("%d %d %.2f\n", pt.x, pt.y, dist);
    return 0;
}
