typedef int qword __attribute__((mode(TI)));

extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Color_0020F590 {
    unsigned char r, g, b, a;
    Color_0020F590() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Vec_0020F590 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0020F590() {}
    Vec_0020F590& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Item_0020F590 {
    char pad0[8];
    int m_id;
};

extern "C" void func_00132A80(void* list);
extern "C" Item_0020F590* func_00132A90(void* list, int a);
extern "C" void* func_00134F18(Item_0020F590* item);
extern "C" int func_0013C7E0(void* mesh);
extern "C" void func_0013C808(void* mesh, Vec_0020F590* buf);
extern "C" void func_0013C8A8(void* mesh, Color_0020F590* buf);
extern "C" void func_0013C958(void* mesh, Color_0020F590* buf);

struct Self_0020F590 {
    char pad0[0xD0];
    void* m_list;

    void Noise(float amount);
};

static inline void Clamp_0020F590(float& v)
{
    if (v < 0.0f) v = 0.0f;
    if (v > 255.0f) v = 255.0f;
}

void Self_0020F590::Noise(float amount)
{
    void* list = m_list;
    if (!list)
        return;
    func_00132A80(list);
    Item_0020F590* item;
    for (item = func_00132A90(list, 0); item; item = func_00132A90(list, 0)) {
        void* mesh = func_00134F18(item);
        if (!mesh)
            continue;
        int n = func_0013C7E0(mesh);
        if (!n)
            continue;
        Vec_0020F590* pos = new Vec_0020F590[n];
        Color_0020F590* buf = new Color_0020F590[n];
        func_0013C808(mesh, pos);
        func_0013C8A8(mesh, buf);
        Color_0020F590* p = buf;
        Vec_0020F590* v = pos;
        for (int i = 0; i < n; i++) {
            Color_0020F590 c;
            Vec_0020F590 f;
            Vec_0020F590* pf = &f;
            c.a = p->a;
            float r = p->r;
            float g = p->g;
            float b = p->b;
            f.x = r;
            f.y = g;
            f.z = b;
            pf->w = 1.0f;
            int h = ((int)(v->x * 16.0f) * (int)(v->y * 16.0f) ^ (int)(v->z * 16.0f)) & 0x7FFF;
            float t = h * (1.0f / 32768.0f);
            float s = (t + t) * amount + 1.0f - amount;
            f *= s;
            Clamp_0020F590(f.x);
            Clamp_0020F590(f.y);
            Clamp_0020F590(f.z);
            c.r = (int)f.x;
            c.g = (int)f.y;
            c.b = (int)f.z;
            *p = c;
            v++;
            p++;
        }
        func_0013C958(mesh, buf);
        delete[] pos;
        delete[] buf;
    }
}
