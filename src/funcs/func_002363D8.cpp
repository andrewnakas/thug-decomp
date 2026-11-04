int func_002363D8_Round(int v);

int func_002363D8_Round(int v)
{
    if (v > 1000000)
        return 1000000;
    if (v > 100000)
        return 100000;
    if (v > 10000)
        return 10000;
    if (v > 1000)
        return 100;
    if (v > 100)
        return 100;
    if (v > 10)
        return 10;
    return 1;
}
