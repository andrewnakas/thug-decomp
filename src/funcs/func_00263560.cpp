int CountBits_00263560(unsigned int x)
{
    int n = 0;
    for (int i = 31; i >= 0; i--) {
        n += x & 1;
        x >>= 1;
    }
    return n;
}
