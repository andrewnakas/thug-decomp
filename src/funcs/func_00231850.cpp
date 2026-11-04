struct Pkt_00231850 {
    unsigned char m0;
    char pad1[3];
    int m4;
};

struct X_00231850 {
    char pad0[0x24];
    int m24;
};

struct Ctx_00231850 {
    Pkt_00231850* m0;
    char pad4[0x10];
    int m14;
    int m18;
    void* m1C;
    int Handle();
};

extern void* D_00392068;
extern "C" X_00231850* func_002A5248(void* m, int id);
extern "C" void* func_0022E358(void* m);
extern "C" unsigned int func_0024F938(void* p);
extern "C" int func_002A7660(void* m);

int Ctx_00231850::Handle()
{
    void* m = D_00392068;
    void* t = m1C;
    X_00231850* x = func_002A5248(m, m14);
    if (!x) return 3;
    Pkt_00231850* p = m0;
    if (func_0024F938(func_0022E358(t)) == 0x1C471C60) return 3;
    if (func_002A7660(m) != p->m0) return 3;
    x->m24 = p->m4;
    return 1;
}
