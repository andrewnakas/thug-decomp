struct Vec_00120E38 {
    float x, y, z, w;
};

struct Obj_00120E38 {
    char pad[0x48];
    char m48[0xC];
};

extern Obj_00120E38* D_00389520;
extern void* D_00389518;

extern "C" int func_00131288(Vec_00120E38* out, void* params);
extern "C" int func_001E89F0(void* params, unsigned int id, void** out, int req);
extern "C" void func_0013EDD0(void* o, Vec_00120E38* c);
extern "C" void* func_0011FE68(Obj_00120E38* o, unsigned int id);
extern "C" int func_001E8618(void* params, unsigned int id);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int id, int* out, int req);

int func_00120E38()
{
    Vec_00120E38 c;
    c.x = 1.0f;
    c.y = 1.0f;
    c.z = 1.0f;
    c.w = 1.0f;
    if (!func_00131288(&c, D_00389520->m48)) {
        void* s = 0;
        if (!func_001E89F0(D_00389520->m48, 0x812684EF, &s, 0) || !func_00131288(&c, s))
            goto custom;
    }
    func_0013EDD0(D_00389518, &c);
    return 1;
custom:
    void* p = func_0011FE68(D_00389520, 0x8B314358);
    if (p && func_001E8618(p, 0x5A96985D)) {
        int off;
        func_001E7DE8(p, 0x5A96985D, &off, 0);
        if (off)
            return 0;
        int r;
        int g;
        int b;
        if (func_001E88D8(p, 0x7323E97C, &r, 0) && func_001E88D8(p, 0x0424D9EA, &g, 0)
            && func_001E88D8(p, 0x9D2D8850, &b, 0)) {
            Vec_00120E38 v;
            v.x = r * 0.01f;
            v.y = g * 0.01f;
            v.z = b * 0.01f;
            v.w = 1.0f;
            func_0013EDD0(D_00389518, &v);
        }
        return 1;
    }
    return 0;
}
