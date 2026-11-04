struct Comp_002B2070 {
    char pad[0x1C];
    void* m1C;
};

struct Stat_002B2070 {
    char pad[0x1C];
    int m1C;
};

struct Sk_002B2070 {
    char pad[0x2DC];
    Stat_002B2070* m2DC;
};


struct Mgr_002B2070 {
    char pad[0x68];
    int m68;
    unsigned int HasMask(const unsigned int& m) { return m68 & m; }
    unsigned int Has(int f) { return HasMask(f); }
};

extern void* D_0038FC78;
extern "C" int func_00206A00(Sk_002B2070* s);
extern "C" unsigned int func_0010FC30();
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" Comp_002B2070* func_00185578(void* obj, unsigned int id);
extern "C" int func_002392B8(void* p);

struct Elem_002B2070 {
    char pad0[0x18];
    Sk_002B2070* m18;
    Mgr_002B2070* m1C;
    char pad20[0x14C - 0x20];
    int m14C;
    char pad150[0x158 - 0x150];
    unsigned int m158;
    bool Check();
    void Drop();
};

static inline bool Elapsed_002B2070(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

extern "C" void func_002B2058(Elem_002B2070* e);

bool Elem_002B2070::Check()
{
    void* sk = D_0038FC78;
    if (!m1C->Has(1))
        return true;
    if (!func_00206A00(m18))
        return true;
    if (m18->m2DC->m1C < 10)
        return true;
    if (func_0010FC30() - m158 < 1000)
        return true;
    if (func_0024F938(func_0022E358(sk)) == (int)0xBFF33600) {
        if (func_002392B8(func_00185578(m18, 0xD262802F)->m1C) <= 0)
            return true;
    }
    if (Elapsed_002B2070(5000, func_0010FC30(), m158)) {
        func_002B2058(this);
        return false;
    }
    if (m14C & 2)
        return true;
    return false;
}
