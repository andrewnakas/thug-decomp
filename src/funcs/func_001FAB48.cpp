struct Bits_001FAB48 {
    unsigned int* m0;
    int m4;
    unsigned int m8;
    int mC;
    void Flush();
};

void Bits_001FAB48::Flush()
{
    if (mC != 32) {
        *m0 = m8;
        mC = 32;
        m8 = 0;
        m0++;
    }
}
