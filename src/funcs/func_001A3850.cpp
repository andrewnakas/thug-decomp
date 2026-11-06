extern void* D_0038E0A0;
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct Lerp_001A3850 {
    char pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
};

struct Obj_001A3850;
extern "C" Lerp_001A3850* func_001DEA98(void* mgr, Obj_001A3850* o, unsigned int id);
extern "C" Lerp_001A3850* func_001A3620(Obj_001A3850* o, unsigned int id);

struct Obj_001A3850 {
    void Method(void* params);
};

void Obj_001A3850::Method(void* params)
{
    struct {
        unsigned int id;
        float a;
        float b;
    } t;
    t.a = 100.0f;
    t.b = 100.0f;
    func_001E8398(params, 0, &t.id, 0);
    Lerp_001A3850* l = func_001DEA98(D_0038E0A0, this, t.id);
    if (!l) {
        l = func_001A3620(this, t.id);
        if (!l)
            return;
    }
    if (func_001E7EB0(params, 0x330F3415, &t.a, 0)) {
        l->m1C = l->m14 * t.a * 0.01f;
        if (!func_001E7EB0(params, 0xDAA9A3C2, &l->m24, 0))
            l->mC = l->m1C;
    }
    if (func_001E7EB0(params, 0xEE616C13, &t.b, 0)) {
        l->m18 = l->m10 * t.b * 0.01f;
        if (!func_001E7EB0(params, 0x7B090774, &l->m20, 0))
            l->m8 = l->m18;
    }
}
