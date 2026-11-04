extern char D_00371C78[];

struct Iter_002B0DA8 {
    int m0;
    int m4;
    void* m8;
    Iter_002B0DA8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002B0DA8() { m8 = D_00371C78; }
};

struct S_002B0DA8 {
    char pad[0x28];
    int m28;
    char pad2[0xA4 - 0x2C];
    void* mA4;
};

extern unsigned int D_00394174;
extern void* D_0038FC78;
extern "C" unsigned int func_0010FC30();
extern "C" void func_0022E6F8(void* g, int v);
extern "C" void* func_002A5820(S_002B0DA8* s);
extern "C" void func_002B2BC0(void* p, int v);
extern "C" void* func_002A53F8(S_002B0DA8* self, Iter_002B0DA8* it, int a);
extern "C" void* func_002A5490(S_002B0DA8* self, Iter_002B0DA8* it, int a);
extern "C" void func_002B2310(void* p);
extern "C" void func_001048F0(void* p);

struct Obj_002B0DA8 {
    char pad[0x20];
    S_002B0DA8* m20;
    void Reset();
};

void Obj_002B0DA8::Reset()
{
    S_002B0DA8* s = m20;
    Iter_002B0DA8 it;
    if (func_0010FC30() < D_00394174)
        return;
    func_0022E6F8(D_0038FC78, s->m28);
    void* t = func_002A5820(s);
    if (t)
        func_002B2BC0(t, 0);
    for (void* p = func_002A53F8(s, &it, 1); p; p = func_002A5490(s, &it, 1))
        func_002B2310(p);
    func_001048F0(s->mA4);
}
