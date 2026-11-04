extern char D_00371C78[];
extern char D_00379590[];

struct Iter_002B0FB8 {
    int m0;
    int m4;
    void* m8;
    Iter_002B0FB8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002B0FB8() { m8 = D_00371C78; }
};

struct Comp_002B0FB8 {
    char pad[0x1C];
    void* m1C;
};

struct Elem_002B0FB8 {
    char pad0[0x18];
    void* m18;
    char pad1C[0x30 - 0x1C];
    int m30;
};

extern void* D_0038FC78;
extern "C" Elem_002B0FB8* func_002A56E0(void* t);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" Elem_002B0FB8* func_002A53F8(void* self, Iter_002B0FB8* it, int a);
extern "C" Elem_002B0FB8* func_002A5490(void* self, Iter_002B0FB8* it, int a);
extern "C" int func_002B2280(Elem_002B0FB8* e);
extern "C" int func_002B1FE8(Elem_002B0FB8* e);
extern "C" void* func_00240850();
extern "C" int func_0023DC38(void* p, int team);
extern "C" Comp_002B0FB8* func_00185578(void* obj, unsigned int id);
extern "C" int func_002392B8(void* p);

extern "C" int func_002B0FB8(void* m, int team)
{
    Iter_002B0FB8 it;
    void* sk = D_0038FC78;
    Elem_002B0FB8* host = func_002A56E0(m);
    bool isX = func_0024F938(func_0022E358(sk)) == func_001F0D78(D_00379590);
    int sum = 0;
    for (Elem_002B0FB8* e = func_002A53F8(m, &it, 0); e; e = func_002A5490(m, &it, 0)) {
        if (func_002B2280(e) && e->m30 == team) {
            if (isX && !func_002B1FE8(host))
                return func_0023DC38(func_00240850(), team);
            sum += func_002392B8(func_00185578(e->m18, 0xD262802F)->m1C);
        }
    }
    return sum;
}
