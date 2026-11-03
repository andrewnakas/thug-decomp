typedef int qword __attribute__((mode(TI)));

union Vec_002CE390 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct NodeA_002CE390 {
    char pad0[0x18];
    NodeA_002CE390* m18;
};

struct NodeB_002CE390 {
    int m0;
    NodeB_002CE390* m4;
};

struct Obj_002CE390;

extern "C" void func_002CD050(NodeA_002CE390* n, int x, int a, int z, Vec_002CE390 v, float f);
extern "C" Vec_002CE390 func_002CE298(Obj_002CE390* o);
extern "C" void func_002996A8(NodeB_002CE390* n, Vec_002CE390* c, Vec_002CE390* v, float f);
extern "C" void func_00299748(NodeB_002CE390* n, Vec_002CE390* c, Vec_002CE390* v, float f);

struct Obj_002CE390 {
    char pad0[7];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    NodeA_002CE390* mC;
    NodeB_002CE390* m10;
    void Update(Vec_002CE390* v, int a, float f);
};

void Obj_002CE390::Update(Vec_002CE390* v, int a, float f)
{
    unsigned x = (unsigned)(m7 + m9) >> 1;
    unsigned z = (unsigned)(m8 + mA) >> 1;
    for (NodeA_002CE390* n = mC; n; n = n->m18)
        func_002CD050(n, x, a, z, *v, f);
    Vec_002CE390 c = func_002CE298(this);
    for (NodeB_002CE390* m = m10; m; m = m->m4) {
        func_002996A8(m, &c, v, f);
        func_00299748(m, &c, v, f);
    }
}
