struct Bits_001FAA28 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void Set(int a, int b);
};

void Bits_001FAA28::Set(int a, int b)
{
    m0 = a;
    m4 = a;
    mC = 0;
    m10 = b;
    m14 = 0;
}
