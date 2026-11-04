typedef int qword __attribute__((mode(TI)));

struct Vec_002B7988 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_002B7988() {}
    Vec_002B7988(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Bounds_002B7988 {
    Vec_002B7988 mn;
    Vec_002B7988 mx;
};

struct Node_002B7988 {
    void* m0;
    char pad4[4];
    Node_002B7988* m8;
    char padC[4];
    float m10;
    float m14;
    float m18;
};

struct Pool_002B7988 {
    char pad0[0xD8];
    int mD8;
};

struct Model_002B7988 {
    char pad0[0x84];
    void* m84;
    char pad88[0xD0 - 0x88];
    void* mD0;
};

extern Pool_002B7988* D_00388A70;
extern char D_00392638[];
extern char D_00392640[];
extern char D_00392648[];
extern char D_00379FD0[];
extern float D_003881C8;

struct Obj_002B7988;
extern "C" void func_002B7CE0(Obj_002B7988* o);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int n);
extern "C" void* func_002B73B8(Obj_002B7988* o, char* name);
extern "C" void* func_0010C190(void* p, void* q);
extern "C" int func_0010AF60(void* p, void* q, int a, char* name);
extern "C" Model_002B7988* func_00131E20(char* name);
extern "C" void func_00132A80(void* p);
extern "C" void* func_00132A90(void* p, int a);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Node_002B7988* func_002B6E18(void* p);
extern "C" void* func_00134F08(void* p);
extern "C" Bounds_002B7988* func_00135120(void* p);
extern "C" void* func_001319B0(char* name, void* p, int a);
extern "C" Bounds_002B7988* func_001022D8(Bounds_002B7988* b);
extern "C" void func_00102358(Bounds_002B7988* b, Vec_002B7988* v);
extern "C" void func_00133BD0(void* p, Bounds_002B7988* b);
extern "C" void func_002BA848(Obj_002B7988* o);

struct Obj_002B7988 {
    unsigned int m0;
    char pad4[4];
    Node_002B7988* m8;
    char padC[4];
    int m10;
    Model_002B7988* m14;
    void* m18;
    int m1C;
    void* m20;
    int m24;
    void Init(int a, int b, int c);
};

void Obj_002B7988::Init(int a, int b, int c)
{
    if (m0 & 2)
        func_002B7CE0(this);
    m1C = 0x20;
    m0 |= 2;
    func_0010A950(D_00388A70, D_00388A70->mD8);
    void* mem = func_001046B0(0x1C);
    m20 = func_0010C190(mem, func_002B73B8(this, D_00392638));
    func_0010A9B0(D_00388A70);
    m24 = func_0010AF60(D_00388A70, m20, 1, D_00379FD0);
    m14 = func_00131E20(D_00392640);
    void* it = m14->mD0;
    func_00132A80(it);
    Bounds_002B7988 bb;
    void* e;
    while ((e = func_00132A90(it, 0)) != 0) {
        func_0010A950(D_00388A70, m24);
        Node_002B7988* n = func_002B6E18(func_0010A638(D_00388A70, 0x30, 1, 0));
        func_0010A9B0(D_00388A70);
        n->m8 = m8;
        m8 = n;
        n->m0 = func_00134F08(e);
        bb = *func_00135120(e);
        int ix = (int)((bb.mx.x - bb.mn.x + 2.0f) * D_003881C8);
        if (ix <= 0)
            ix = 1;
        n->m10 = ix * 120.0f;
        int iz = (int)((bb.mx.z - bb.mn.z + 2.0f) * D_003881C8);
        if (iz <= 0)
            iz = 1;
        n->m18 = iz * 120.0f;
        float dy = bb.mx.y - bb.mn.y;
        n->m14 = dy;
        if (dy < 48.0f && 0.0f < dy)
            n->m14 = 48.0f;
        m10++;
    }
    m18 = func_001319B0(D_00392648, m14->m84, 1);
    func_001022D8(&bb);
    Vec_002B7988 lo(-(a * 120.0f) * 0.5f, -(b * 48.0f) * 0.5f, -(c * 120.0f) * 0.5f, 1.0f);
    func_00102358(&bb, &lo);
    Vec_002B7988 hi(a * 60.0f, b * 24.0f, c * 60.0f, 1.0f);
    func_00102358(&bb, &hi);
    func_00133BD0(m18, &bb);
    func_002BA848(this);
}
