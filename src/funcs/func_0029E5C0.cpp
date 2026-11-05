struct Sub_0029E5C0 {
    char pad0[0x18];
    int m18;
    char pad1C[0x320 - 0x1C];
    int m320;
};

struct Obj_0029E5C0 {
    char pad0[0xC];
    Sub_0029E5C0* mC;
    char pad10[0x1C - 0x10];
    int m1C;
};

extern void* D_0038C7B0;
extern "C" int func_001F0D00(int id);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, int id, void* s, int a);

extern "C" void func_0029E5C0(Obj_0029E5C0* o)
{
    if (func_001F0D00(o->mC->m320 + 0x83321DEA))
        func_00189750(D_0038C7B0, 0x813CC576, o->mC->m320 + 0x83321DEA, o->mC->m18, 0, 0);
    o->m1C = 0;
}
