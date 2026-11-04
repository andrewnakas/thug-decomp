extern char D_003668A0[];
extern void* D_00388A70;
extern "C" void func_0010A8D8(void*, void*);
extern "C" void func_003250C0(int, int*);
extern "C" void func_00326938();

struct Link_001F9D50 {
    int m0;
    int m4;
    int m8;
    Link_001F9D50* mC;
    Link_001F9D50* m10;
    void* m14;

    void Destroy()
    {
        m14 = D_003668A0;
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
};

struct Net_001F9D50 {
    int m0;
    Link_001F9D50 m4;
    Link_001F9D50 m1C;
    char m_pad[0x2C4 - 0x34];
    int m2C4;
};

void func_001F9D50(Net_001F9D50* n, int flags)
{
    int x;
    if (n->m2C4) {
        func_003250C0(2, &x);
        func_00326938();
    }
    n->m1C.Destroy();
    n->m4.Destroy();
    if (flags & 1)
        func_0010A8D8(D_00388A70, n);
}
