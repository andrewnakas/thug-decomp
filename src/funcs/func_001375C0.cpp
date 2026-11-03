struct Rgba_001375C0 {
    unsigned char r, g, b, a;
    Rgba_001375C0(unsigned char ar, int ag, int ab, int aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
};

struct Light_001375C0 {
    char pad[0x10];
    float m_radius;
    float m_invRadius;
    float m_intensity;
    Rgba_001375C0 m_rgba;
    void SetRgba(Rgba_001375C0 c) { m_rgba = c; }
    void SetRadius(float r)
    {
        m_radius = r;
        m_invRadius = 1.0f / r;
    }
};

extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" void* func_00131E48();
extern "C" void* func_00136D58(void* id);
extern "C" Light_001375C0* func_001365E8(void* id);
extern "C" void func_00136E58(void* light, float f);
extern "C" void func_00136DF8(void* light, float f);
extern "C" void func_00136F60(void* light);
extern "C" void func_00136EA8(void* light, Rgba_001375C0 c);
extern "C" void func_00137528(void* mgr, void* id);
extern float D_003875A8;
extern float D_003875AC;

extern "C" void func_001375C0(void* id, void* params)
{
    void* mgr = func_00131E48();
    void* light = func_00136D58(id);
    float intensity;
    float radius;
    int r;
    int g;
    int b;
    if (light) {
        if (func_001E7EB0(params, 0x9E497FC6, &intensity, 0)) {
            intensity *= D_003875A8;
            func_00136E58(light, intensity);
        }
        if (func_001E7EB0(params, 0x0999151B, &radius, 0)) {
            func_00136DF8(light, radius);
            func_00136F60(light);
        }
        if (func_001E7DE8(params, 0x059EA070, &r, 0)) {
            func_001E88D8(params, 0x2F6511DE, &g, 1);
            func_001E88D8(params, 0x61C9354B, &b, 1);
            Rgba_001375C0 c(r, g, b, 0xFF);
            func_00136EA8(light, c);
        }
        func_00137528(mgr, id);
        return;
    }
    Light_001375C0* l = func_001365E8(id);
    if (l) {
        if (func_001E7EB0(params, 0x9E497FC6, &intensity, 0)) {
            intensity *= D_003875AC;
            l->m_intensity = intensity;
        }
        if (func_001E7EB0(params, 0x0999151B, &radius, 0)) {
            l->SetRadius(radius);
        }
        if (func_001E7DE8(params, 0x059EA070, &r, 0)) {
            func_001E88D8(params, 0x2F6511DE, &g, 1);
            func_001E88D8(params, 0x61C9354B, &b, 1);
            Rgba_001375C0 c(r, g, b, 0xFF);
            l->SetRgba(c);
        }
    }
}
