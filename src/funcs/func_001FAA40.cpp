struct Bits_001FAA40 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void Set(int a, int b);
};

void Bits_001FAA40::Set(int a, int b)
{
    m0 = a;
    m4 = a;
    m10 = b;
    mC = 0x20;
    m14 = 0;
}
