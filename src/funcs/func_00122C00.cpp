struct Rgba_00122C00 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_00122C00(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
    Rgba_00122C00(const Rgba_00122C00& o) { v = o.v; }
};

struct Buf_00122C00 {
    int w[16];
};

extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int id, int* out, int req);
extern "C" void* func_00139468(void* mgr, int id);
extern "C" int func_001228A8(Buf_00122C00* b, int v);
extern "C" void func_001221B8(void* o, Buf_00122C00* b, int z, Rgba_00122C00 c);

extern void* D_00393EF4;

int func_00122C00(void* params)
{
    int id;
    func_001E8398(params, 0x7D99F28D, &id, 0);
    void* o = func_00139468(D_00393EF4, id);
    if (o) {
        int v = 0;
        func_001E8180(params, 0xAC3CD84C, &v, 0);
        if (v) {
            Buf_00122C00 b;
            func_001228A8(&b, v);
            func_001221B8(o, &b, 0, Rgba_00122C00(0x80, 0x80, 0x80, 0x80));
        }
    }
    return 1;
}
