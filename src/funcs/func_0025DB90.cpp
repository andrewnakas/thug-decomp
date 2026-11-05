typedef int qword __attribute__((mode(TI)));

struct Vec_0025DB90 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0025DB90() {}
    Vec_0025DB90(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_0025DB90 {
    Vec_0025DB90 r[4];
};

struct Heap_0025DB90 {
    char m_pad[0x114];
    int m114;
};

extern Heap_0025DB90* D_00388A70;
extern "C" void func_0010A950(Heap_0025DB90* h, int ctx);
extern "C" void func_0010A9B0(Heap_0025DB90* h);
extern "C" void* func_00114DD8(void* o);
extern "C" Vec_0025DB90* func_00114E18(void* o);
extern "C" Mat_0025DB90* func_00114E48(void* o);
extern "C" void func_00144DF0(void* a, void* o, float b, float c);

struct Obj_0025DB90 {
    char m_pad0[0xC];
    void* mC;
    char m_pad10[0xB68 - 0x10];
    int mB68;
    float mB6C;
    float mB70;
    void Get(Vec_0025DB90* q, Vec_0025DB90* p);
    void Apply(void* o);
};

extern "C" void func_0025E6F0(Obj_0025DB90* self, Vec_0025DB90* q, Vec_0025DB90* p);

void Obj_0025DB90::Apply(void* o)
{
    func_00114DD8(o);
    Vec_0025DB90* pos = func_00114E18(o);
    Mat_0025DB90* m = func_00114E48(o);
    Vec_0025DB90 q(0.0f, 0.0f, 0.0f, 1.0f);
    Vec_0025DB90 p;
    func_0025E6F0(this, &q, &p);
    *pos = p;
    Vec_0025DB90 t(0.0f, 0.0f, 0.0f, 1.0f);
    q.x = -q.x;
    q.y = -q.y;
    q.z = -q.z;
    Vec_0025DB90 s;
    Vec_0025DB90 c;
    Vec_0025DB90 wv;
    s.x = q.x * q.x;
    s.y = q.y * q.y;
    s.z = q.z * q.z;
    c.x = q.y * q.z;
    c.y = q.z * q.x;
    c.z = q.x * q.y;
    wv.x = q.w * q.x;
    wv.y = q.w * q.y;
    wv.z = q.w * q.z;
    m->r[0].x = 1.0f - 2.0f * (s.y + s.z);
    m->r[0].y = 2.0f * (c.z + wv.z);
    m->r[0].z = 2.0f * (c.y - wv.y);
    m->r[0].w = 0.0f;
    m->r[1].x = 2.0f * (c.z - wv.z);
    m->r[1].y = 1.0f - 2.0f * (s.x + s.z);
    m->r[1].z = 2.0f * (c.x + wv.x);
    m->r[1].w = 0.0f;
    m->r[2].x = 2.0f * (c.y + wv.y);
    m->r[2].y = 2.0f * (c.x - wv.x);
    m->r[2].z = 1.0f - 2.0f * (s.x + s.y);
    m->r[2].w = 0.0f;
    m->r[3] = t;
    m->r[3].w = 1.0f;
    if (!mB68) {
        func_0010A950(D_00388A70, D_00388A70->m114);
        func_00144DF0(mC, o, mB6C, mB70);
        func_0010A9B0(D_00388A70);
    }
}
