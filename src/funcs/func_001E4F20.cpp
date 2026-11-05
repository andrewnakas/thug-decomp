struct C_001E4F20 {
    union {
        int m0;
        struct { char m0b, m1b, m2b, m3b; };
    };
    int m4;
    int m8;
    int mC;
    int m10;
    void Reset();
};

void C_001E4F20::Reset()
{
    m0 &= ~0x100;
    m0 &= ~0x200;
    m8 = 0;
    m4 = 0;
    mC = 0;
    m10 = 0;
    m2b = 0;
}
