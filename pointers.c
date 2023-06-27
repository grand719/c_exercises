int main(int argc, char const *argv[])
{
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x;
    y = *ip;
    *ip = 0;
    ip = &z[0];
    return 0;
}
