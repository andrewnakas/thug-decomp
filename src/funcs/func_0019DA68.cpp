typedef int qword __attribute__((mode(TI)));

struct Vec_0019DA68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0019DA68() {}
    Vec_0019DA68(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float LengthSqr() const { return x * x + y * y + z * z; }
};

inline Vec_0019DA68 operator-(const Vec_0019DA68& a, const Vec_0019DA68& b)
{
    return Vec_0019DA68(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct N_0019DA68 {
    int m0;
    int m_data;
    int m_pri;
    N_0019DA68* m_next;
    N_0019DA68* m_prev;
};

struct Mgr_0019DA68 {
    int m_pad[12];
    N_0019DA68 m_list;
};

struct Obj_0019DA68 {
    int m_pad[20];
    Vec_0019DA68 m50;
    int m60[20];
    Vec_0019DA68 mB0;
};

struct Thing_0019DA68 {
    int m_pad[47];
    void* mBC;
};

extern Mgr_0019DA68* D_0038FC78;
extern "C" float func_0010FAB8();
extern "C" Obj_0019DA68* func_0022DE70(Mgr_0019DA68* mgr, int i);
extern "C" Thing_0019DA68* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);
extern "C" void func_001EFDC0(Thing_0019DA68* th);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

static inline void SetRef_0019DA68(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_0019DA68 {
    int m_pad[3];
    void* mC;
    int m10[3];
    unsigned int m1C;
    int m20[10];
    int m48;
    int m4C[10];
    float m74;
    int m78;
    short m7C;
    short m7E;
    unsigned int m80;
    void* m84;
    int m88[2];
    Vec_0019DA68 m90;
    int mA0[24];
    float m100;
    void Update();
    void Touch(Vec_0019DA68& v, const Vec_0019DA68& p);
    void Finish();
};

void C_0019DA68::Update()
{
    Mgr_0019DA68* mgr = D_0038FC78;
    unsigned int count = 0;
    N_0019DA68* n = mgr->m_list.m_next;
    for (;;) {
        N_0019DA68* c = 0;
        if (n->m_data != -1) c = n;
        if (!c) break;
        count++;
        n = c->m_next;
    }
    m100 = func_0010FAB8();
    if (!(m1C & 1) && (m7C != 2 || (!m78 && m48))) {
        for (unsigned int i = 0; i < count; i++) {
            Obj_0019DA68* o = func_0022DE70(mgr, i);
            float dx = m90.x - o->m50.x;
            float dy = m90.y - o->m50.y;
            float dz = m90.z - o->m50.z;
            float dw = m90.w - o->m50.w;
            Vec_0019DA68 d;
            d.x = dx;
            d.y = dy;
            d.z = dz;
            d.w = dw;
            if (dx * dx + dy * dy + dz * dz < m74) {
                if (m80) {
                    Thing_0019DA68* th = func_001F0750(m80, m84, 0, 0, -1, 0, 0, 0, 0, 0);
                    SetRef_0019DA68(&th->mBC, mC);
                    func_001EFDC0(th);
                }
                d = o->mB0;
                Touch(d, o->m50);
            }
        }
    }
    switch (m7C) {
    case 0:
        m7C = 1;
        break;
    case 1:
        break;
    case 2:
        Finish();
        break;
    }
}
