struct Entry_001ADD00 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

struct Obj_001ADD00 {
    char pad[0xA70];
    int mA70;
    int mA74;
    Entry_001ADD00 mA78[100];
    void Method(int a, int b, int c);
};

void Obj_001ADD00::Method(int a, int b, int c)
{
    int idx = 0;
    if (mA70 == -1 && mA74 == -1) {
        mA70 = 0;
        mA74 = 0;
    } else {
        idx = mA74;
        if (++idx >= 100)
            idx = 0;
        if (idx == mA70)
            return;
        mA74 = idx;
    }
    mA78[idx].m0 = a;
    mA78[idx].m4 = b;
    mA78[idx].m10 = c;
}
