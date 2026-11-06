struct Rng_0015F870 {
    char pad0[0x10];
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    void Fn(int n);
};

void Rng_0015F870::Fn(int n)
{
    if (n <= 0)
        return;
    unsigned int a = m1C;
    unsigned int b, c;
    b = m14;
    c = m18;
    unsigned int d;
    do {
        d = (a << 1) | (((a >> 4) ^ (a >> 22)) & 1);
        b ^= d;
        c ^= b;
        a ^= c;
    } while (--n);
    m18 = c;
    m14 = b;
    m10 = d;
    m1C = a;
}
