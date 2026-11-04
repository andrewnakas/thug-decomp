typedef int qword __attribute__((mode(TI)));

union Vec_002CDD78 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Game_002CDD78;

struct NodeA_002CDD78 {
    char pad0[0x18];
    NodeA_002CDD78* m18;
};

struct NodeB_002CDD78 {
    int m0;
    NodeB_002CDD78* m4;
};

struct Arg_002CDD78 {
    char pad0[0x44];
    int m44;
    char pad48[0x70 - 0x48];
    int m70;
};

struct Obj_002CDD78;

extern "C" Game_002CDD78* func_002C4970(int v);
extern "C" void func_002C49C0();
extern "C" int func_002C6A28(Game_002CDD78* g, int w, int d);
extern "C" int func_002CCB88(NodeA_002CDD78* n, unsigned int x, unsigned int z, Arg_002CDD78* a);
extern "C" int func_00299898(NodeB_002CDD78* g);
extern "C" void* func_0029C320();
extern "C" int func_0029C020(void* p);
extern "C" void func_002CCC50(NodeA_002CDD78* n, unsigned int x, int a, unsigned int z, Arg_002CDD78* arg);
extern "C" Vec_002CDD78 func_002CE298(Obj_002CDD78* o);
extern "C" Vec_002CDD78* func_002C7090(Game_002CDD78* g);
extern "C" void* func_0029B378(void* p);
extern "C" void func_00299DE0(void* p, NodeB_002CDD78* n);
extern "C" void func_00299E48(void* p, Vec_002CDD78* c, Vec_002CDD78* v, float f);
extern "C" void func_002996A8(void* n, Vec_002CDD78* c, Vec_002CDD78* v, float f);
extern "C" void func_00299748(void* n, Vec_002CDD78* c, Vec_002CDD78* v, float f);
extern Vec_002CDD78 D_00453140;

struct Ref_002CDD78 {
    int m0;
    Game_002CDD78* m4;
    Ref_002CDD78(Game_002CDD78* p) { m4 = p; }
};

class Ctx_002CDD78 {
public:
    int m0;
    Ref_002CDD78 m4;
    Ctx_002CDD78() : m4(func_002C4970(0)) {}
    Ref_002CDD78* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_002CDD78() { func_002C49C0(); }
};

struct Obj_002CDD78 {
    char pad0[7];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    NodeA_002CDD78* mC;
    NodeB_002CDD78* m10;
    int Place(Arg_002CDD78* a);
};

int Obj_002CDD78::Place(Arg_002CDD78* a)
{
    Ctx_002CDD78 ctx;
    NodeA_002CDD78* n;
    NodeB_002CDD78* g;
    if (!func_002C6A28(ctx.GetRef()->m4, m9 - m7 + 1, mA - m8 + 1)) return 0;
    unsigned x = (unsigned)(m7 + m9) >> 1;
    unsigned z = (unsigned)(m8 + mA) >> 1;
    for (n = mC; n; n = n->m18) {
        if (!func_002CCB88(n, x, z, a)) return 0;
    }
    int sum = 0;
    for (g = m10; g; g = g->m4) sum += func_00299898(g);
    if (func_0029C020(func_0029C320()) < sum) return 0;
    for (n = mC; n; n = n->m18) func_002CCC50(n, x, a->m70, z, a);
    Vec_002CDD78 c = func_002CE298(this);
    Vec_002CDD78 v = *func_002C7090(ctx.GetRef()->m4);
    for (g = m10; g; g = g->m4) {
        void* p = func_0029B378(func_0029C320());
        func_00299DE0(p, g);
        func_00299E48(p, &c, &v, a->m44 * 90.0f);
        func_002996A8(p, &D_00453140, &D_00453140, 0.0f);
        func_00299748(p, &D_00453140, &D_00453140, 0.0f);
    }
    return 1;
}
