typedef int qword __attribute__((mode(TI)));

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;
extern "C" float sqrtf(float);

struct Vec_00137130 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00137130() {}
    Vec_00137130(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Rgba_00137130 {
    unsigned char r, g, b, a;
    Rgba_00137130() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Light_00137130 {
    Vec_00137130 pos;
    float m10;
    float m14;
    char pad18[4];
    unsigned char m1C;
    unsigned char m1D;
    unsigned char m1E;
    char pad1F[0x11];
};

extern Light_00137130 D_003C1C90[];
extern int D_00389E3C;

extern "C" void* func_00134F18(void* o);
extern "C" int func_00136F30(Light_00137130* l, void* o);
extern "C" int func_0013C7E0(void* g);
extern "C" void func_0013C808(void* g, Vec_00137130* v);
extern "C" void func_0013C8A8(void* g, Rgba_00137130* c);
extern "C" void func_0013C958(void* g, Rgba_00137130* c);

extern "C" void func_00137130(void* o)
{
    void* g = func_00134F18(o);
    if (!g)
        return;
    int lights[8];
    int n = 0;
    Light_00137130* l = D_003C1C90;
    for (int i = 0; i < D_00389E3C; l++, i++) {
        if (l->m10 > 0.0f && func_00136F30(l, o)) {
            lights[n] = i;
            n++;
            if (n >= 8)
                break;
        }
    }
    if (n == 0) {
        int nv = func_0013C7E0(g);
        if (nv <= 0)
            return;
        Rgba_00137130* col = new Rgba_00137130[nv];
        func_0013C8A8(g, col);
        func_0013C958(g, col);
        delete[] col;
    } else if (n > 0) {
        int nv = func_0013C7E0(g);
        if (nv <= 0)
            return;
        Vec_00137130* pos = new Vec_00137130[nv];
        Rgba_00137130* col = new Rgba_00137130[nv];
        func_0013C808(g, pos);
        func_0013C8A8(g, col);
        Rgba_00137130* cp = col;
        Vec_00137130* p = pos;
        for (int j = 0; j < nv; j++, cp++, p++) {
            float gr = 0.0f;
            float r = gr;
            float b = gr;
            for (int k = 0; k < n; k++) {
                Light_00137130* L = &D_003C1C90[lights[k]];
                Vec_00137130 d(p->x - L->pos.x, p->y - L->pos.y, p->z - L->pos.z, p->w - L->pos.w);
                float dist2 = d.x * d.x + d.y * d.y + d.z * d.z;
                if (dist2 < L->m14 * L->m14) {
                    float f = L->m10 * ((L->m14 - sqrtf(dist2)) / L->m14);
                    r += f * L->m1C;
                    gr += f * L->m1D;
                    b += f * L->m1E;
                }
            }
            Rgba_00137130 c = *cp;
            float t;
            t = c.r + r;
            c.r = t < 255.0f ? t : 255.0f;
            t = c.g + gr;
            c.g = t < 255.0f ? t : 255.0f;
            t = c.b + b;
            c.b = t < 255.0f ? t : 255.0f;
            *cp = c;
        }
        func_0013C958(g, col);
        delete[] pos;
        delete[] col;
    }
}
