extern char D_0037A010[];
extern char D_0037A028[];
extern char D_0037A040[];
extern char D_0037A068[];

struct Node_002B8218 {
    int m0;
    unsigned int m4;
    Node_002B8218* m8;
};

struct Slot_002B8218 {
    int m0;
    char pad[0x2C];
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_002B65F0(void* p);
extern "C" void* func_0029C320();
extern "C" int func_0029B4A0(void* p);
extern "C" void func_0022A2B8(int n, int v);
extern "C" void* func_001E55B8(unsigned int name, int v);
extern "C" void func_0029B4E8(void* p, void* s, int* z, int v);
extern "C" void func_00229528();
extern "C" int func_00211D68(int a, int b);

struct Obj_002B8218 {
    unsigned int m0;
    Node_002B8218* m4;
    char pad8[0x64 - 8];
    char m64[0xCC - 0x64];
    Slot_002B8218 mCC[18];
    void Build(void* a);
};

extern "C" void func_002B8018(Obj_002B8218* o, void* a);
extern "C" void func_002B9460(Obj_002B8218* o, void* s, int* z);
extern "C" void func_002B9770(Obj_002B8218* o, void* s, int* z);
extern "C" void func_002B9A28(Obj_002B8218* o, void* s, int* z);
extern "C" void func_002B7FE8(Obj_002B8218* o);

void Obj_002B8218::Build(void* a)
{
    func_00103F28(D_0037A010);
    func_002B8018(this, a);
    int n = func_002B65F0(m64);
    func_00103F28(D_0037A028);
    int c = 0;
    for (Node_002B8218* x = m4; x; x = x->m8) {
        if (!(x->m4 & 0x20))
            c++;
    }
    n += c;
    for (int i = 0; i < 18; i++) {
        Slot_002B8218* p = &mCC[i];
        int v = p->m0;
        if (v)
            n++;
        if (v == 1)
            n++;
        if (v == 3)
            n++;
        if ((unsigned int)(v - 5) <= 3)
            n += 3;
    }
    func_0022A2B8(n + func_0029B4A0(func_0029C320()), 0);
    void* s = func_001E55B8(0xC472ECC5, 0);
    int z = 0;
    func_002B9460(this, s, &z);
    func_002B9770(this, s, &z);
    func_0029B4E8(func_0029C320(), s, &z, 0x3D0901);
    func_002B9A28(this, s, &z);
    func_002B7FE8(this);
    func_00103F28(D_0037A040);
    func_00229528();
    func_00103F28(D_0037A068);
    func_00211D68(0, 0);
    m0 |= 0x20;
}
