struct Ref_00232688;
struct Thing_00232688 {
    char pad0[0xBC];
    Ref_00232688* mBC;
};

struct Args_00232688 {
    unsigned int m0;
    unsigned int m4;
    void* m8;
};

struct Net_00232688 {
    char pad0[0x160];
    int m160;
};

extern Net_00232688* D_00392068;

extern "C" void* func_0022E040(void* mgr);
extern "C" Ref_00232688* func_00187B48(void* mgr, unsigned int id);
extern "C" Thing_00232688* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                         int d, int e, int f, int g, int h);
extern "C" void func_00183CB8(Ref_00232688* obj, Ref_00232688** ref);
extern "C" void func_00183C98(Ref_00232688* obj, Ref_00232688** ref);
extern "C" int func_001EFDC0(Thing_00232688* th);
extern "C" void func_002A7EE8(Net_00232688* net, void* a, unsigned int b, unsigned int c);

static inline void SetRef(Ref_00232688** ref, Ref_00232688* const& obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) {
        func_00183C98(obj, ref);
    }
}

struct Cmd_00232688 {
    Args_00232688* m0;
    char pad4[0x1C - 0x4];
    void* m1C;
    bool Run();
};

bool Cmd_00232688::Run()
{
    void* o = m1C;
    Args_00232688* a = m0;
    if (D_00392068->m160) {
        Ref_00232688* r = func_00187B48(func_0022E040(o), a->m4);
        Thing_00232688* t = func_001F0750(a->m0, 0, 0, 0, (int)a->m8, 0, 0, 0, 0, 0);
        SetRef(&t->mBC, r);
        func_001EFDC0(t);
    } else {
        func_002A7EE8(D_00392068, a->m8, a->m4, a->m0);
    }
    return true;
}
