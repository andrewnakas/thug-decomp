struct Heap_002D37D0 {
    char pad0[0x104];
    void* m104;
};

struct Count_002D37D0 {
    int m0;
    int m4;
    void Dec() { m4--; }
};

struct Info_002D37D0 {
    char pad0[0x13C];
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    Count_002D37D0 m150;
    void* m158;
    int m15C;
    void* m160;
    void* m164;
};

struct Mgr_002D37D0 {
    int m0;
    Info_002D37D0* m4;
};

extern Heap_002D37D0* D_00388A70;
extern Mgr_002D37D0* D_00392068;
extern "C" void func_0010A950(void* h, void* ctx);
extern "C" void func_0010A9B0(void* h);
extern "C" void func_002D2DB8(Info_002D37D0* p);
extern "C" void func_002D0680(Info_002D37D0* p);
extern "C" void func_001048F0(void* p);
extern "C" void func_00306EC0(void* p);
extern "C" void func_00305A78(void* p);
extern "C" void func_00305BC8(void* p);
extern "C" void func_002D3CC8(Info_002D37D0* p);

bool Cmd_002D37D0()
{
    Mgr_002D37D0* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    while (m->m4->m150.m4)
        m->m4->m150.Dec();
    func_002D2DB8(m->m4);
    func_002D0680(m->m4);
    func_001048F0(m->m4->m160);
    func_001048F0(m->m4->m164);
    m->m4->m13C = 0;
    m->m4->m144 = 1;
    if (m->m4->m158) {
        func_00306EC0(m->m4->m158);
        func_00305A78(m->m4->m158);
        func_00305BC8(m->m4->m158);
    }
    func_002D3CC8(m->m4);
    func_0010A9B0(D_00388A70);
    return true;
}
