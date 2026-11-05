struct E_001E5548 {
    char m0, m1;
    unsigned char m2;
    char m3;
    int m4, m8;
    void* mC;
};

extern "C" E_001E5548* func_001E5040(unsigned int name, int flag);

extern "C" void* func_001E5548(unsigned int name, int flag)
{
    E_001E5548* p = func_001E5040(name, flag);
    if (p) {
        if (p->m2 == 10) return p->mC;
        return 0;
    }
    return 0;
}
