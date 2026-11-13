/* fuzzy: 89.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00203370 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mtx_00203370 {
    Vec_00203370 row[4];
    const Vec_00203370& Row(int i) const { return row[i]; }
    Mtx_00203370& operator=(const Mtx_00203370& o)
    {
        row[0].q = o.Row(0).q;
        row[1].q = o.Row(1).q;
        row[2].q = o.Row(2).q;
        row[3].q = o.Row(3).q;
        return *this;
    }
    void Identity()
    {
        row[0].x = 1.0f; row[0].y = 0.0f; row[0].z = 0.0f; row[0].w = 0.0f;
        row[1].x = 0.0f; row[1].y = 1.0f; row[1].z = 0.0f; row[1].w = 0.0f;
        row[2].x = 0.0f; row[2].y = 0.0f; row[2].z = 1.0f; row[2].w = 0.0f;
        row[3].x = 0.0f; row[3].y = 0.0f; row[3].z = 0.0f; row[3].w = 1.0f;
    }
};

struct Model_00203370 {
    char pad0[0x70];
    Mtx_00203370 m70;
};

struct Inst_00203370 {
    char pad0[0xC];
    Model_00203370* mC;
    char pad10[0x10];
    Mtx_00203370 m20;
    Vec_00203370 m60;
    Vec_00203370 m70;
    Vec_00203370 m80;
    char pad90[0x10];
    Vec_00203370 mA0;
};

struct Obj_00203370 {
    char pad0[0x50];
    Vec_00203370 m50;
    Vec_00203370 m60;
    Mtx_00203370 m70;
    char padB0[0x10];
    Mtx_00203370 mC0;
    char pad100[0x1B8];
    int m2B8;
    char pad2BC[0x24];
    Inst_00203370* m2E0;
    void Place(int node);
};

extern "C" int func_001E55B8(unsigned int id, int a);
extern "C" int func_001E9378(int s, int node);
extern "C" void func_0022A090(int node, Vec_00203370* pos);
extern "C" void func_00186398(Obj_00203370* o, int f);
extern "C" void func_0022A268(int s, Vec_00203370* rot);
extern "C" Mtx_00203370* func_00100890(Mtx_00203370* m, float a);
extern "C" Mtx_00203370* func_00100928(Mtx_00203370* m, float a);
extern "C" Mtx_00203370* func_001009C0(Mtx_00203370* m, float a);
extern "C" void func_00323318(Mtx_00203370* d, Mtx_00203370* a, Mtx_00203370* b);
extern "C" void func_001B6BC0(int h, Vec_00203370* p);
extern "C" void func_001B6BD0(int h, Vec_00203370* p);

void Obj_00203370::Place(int node)
{
    Mtx_00203370* m = &m70;
    m->Identity();
    if (node < 0) return;
    int s = func_001E9378(func_001E55B8(0xC472ECC5, 0), node);
    func_0022A090(node, &m50);
    m60.q = m50.q;
    m2E0->mA0.q = m60.q;
    func_00186398(this, 1);
    Vec_00203370 rot;
    func_0022A268(s, &rot);
    m->Identity();
    Vec_00203370* r = &rot;
    if (r->x != 0.0f || r->y != 0.0f || r->z != 0.0f) {
        Mtx_00203370 t;
        func_00323318(m, func_00100890(&t, r->x), m);
        func_00323318(m, func_00100928(&t, r->y), m);
        func_00323318(m, func_001009C0(&t, r->z), m);
    }
    m2E0->m20 = m2E0->mC->m70;
    Vec_00203370* up = &m70.row[1];
    qword v = up->q;
    m2E0->m70.q = v;
    m2E0->m80.q = v;
    m2E0->m60.q = v;
    func_001B6BC0(m2B8, &m50);
    func_001B6BD0(m2B8, up);
    mC0 = m2E0->m20;
}
