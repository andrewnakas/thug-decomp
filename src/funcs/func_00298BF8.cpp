struct Inner_00298BF8 {
    char pad[0x18];
    void* m18;
};

struct Mgr_00298BF8 {
    Inner_00298BF8* m0;
};

struct Obj_00298BF8 {
    char pad[0x34];
    int m34;
};

extern void* D_00391ED8;
extern "C" Mgr_00298BF8* func_002C0368();
extern "C" int func_00133418(void* p, int id);
extern "C" void func_00133D48(void* p, int v);

extern "C" void func_00298BF8(Obj_00298BF8* o)
{
    if (o->m34) {
        void* s = func_002C0368()->m0->m18;
        func_00133418(s, o->m34);
        o->m34 = 0;
        if (D_00391ED8)
            func_00133D48(s, 0);
    }
}
