typedef int qword __attribute__((mode(TI)));

struct Vec_00136308 {
    qword q;
};

struct Rgba_00136308 {
    unsigned char r, g, b, a;
    Rgba_00136308(const Rgba_00136308& o) { *this = o; }
};

struct Light_00136308 {
    Vec_00136308 pos;
    float m10;
    float m14;
    int m18;
    Rgba_00136308 m1C;
    char pad20[0x10];
};

extern Light_00136308 D_003C1C90[150];
extern int D_00389E3C;

extern "C" void func_00136E58(Light_00136308* l, float v);
extern "C" void func_00136DF8(Light_00136308* l, float v);
extern "C" void func_00136F60(Light_00136308* l);
extern "C" void* func_00131E48();
extern "C" void func_00137528(void* scene, int id);
extern "C" void func_00136EA8(Light_00136308* l, Rgba_00136308 c);

extern "C" void func_00136308(int id, Vec_00136308* pos, Rgba_00136308 col, float intensity, float radius)
{
    int n = D_00389E3C;
    if (n < 150) {
        Light_00136308* l = &D_003C1C90[n++];
        D_00389E3C = n;
        l->m18 = id;
        l->pos = *pos;
        func_00136E58(l, intensity * 0.01f);
        func_00136EA8(l, col);
        func_00136DF8(l, radius);
        func_00136F60(l);
        if (intensity > 0.0f)
            func_00137528(func_00131E48(), id);
    }
}
