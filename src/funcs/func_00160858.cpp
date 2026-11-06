int func_00160858(void** n, int depth)
{
    int r = 0;
    if (n) {
        if (depth > 0) {
            for (int i = 0; i < 16; i++)
                r += func_00160858((void**)n[i], depth - 1);
        } else {
            r = 1;
        }
    }
    return r;
}
