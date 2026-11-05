struct Heap_00253D48 {
    char pad[0xE4];
    int mE4;
};

struct TE_00253D48 {
    int m0;
    char m4[0x4C];
    char m50[0x44];
};

struct Tab_00253D48 {
    int m0;
    int m4;
    TE_00253D48 m8[8];
};

struct Mgr_00253D48 {
    int m0;
    int m4;
    char m8[4];
};

struct Ent_00253D48 {
    char pad[0x1C];
    void* m1C;
    int m20;
    int m24;
};

extern Heap_00253D48* D_00388A70;
extern Mgr_00253D48* D_0038C308;
extern Tab_00253D48* D_0038C3C0;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00105260(void* p, void* q);

struct Obj_00253D48 {
    char pad[0x18];
    void* m18;
    char pad1C[0xC];
    Ent_00253D48* m28[2];
    void Fn();
};

void Obj_00253D48::Fn()
{
    func_0010A950(D_00388A70, D_00388A70->mE4);
    func_00105260(D_0038C308->m8, m18);
    Tab_00253D48* t = D_0038C3C0;
    for (int i = 0; i < 2; i++) {
        Ent_00253D48* e = m28[i];
        func_00105260(t->m8[e->m24].m4, e);
        e->m1C = t->m8[e->m24].m50;
        e->m20 = t->m8[e->m24].m0;
    }
    func_0010A9B0(D_00388A70);
}
