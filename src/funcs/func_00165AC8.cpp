int Bits_00165AC8(unsigned int x)
{
    int n = 0;
    while (x) {
        x >>= 1;
        n++;
    }
    return n;
}
