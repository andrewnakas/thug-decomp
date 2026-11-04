struct Rgba_0013A380 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_0013A380(unsigned char r, int g, int b, int a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
    Rgba_0013A380(const Rgba_0013A380& o) { v = o.v; }
};

extern void* D_00393EF4;
extern "C" int func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" int func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" void* func_00139468(void* dict, unsigned int key);
extern "C" void func_00138860(void* tex, unsigned short a, int b, int c, int changed, Rgba_0013A380 col);

extern "C" int func_0013A380(void* params)
{
    unsigned int name;
    func_001E8398(params, 0, &name, 0);
    void* tex = func_00139468(D_00393EF4, name);
    if (tex) {
        int a = 0;
        int b = 0;
        int c = 0;
        int red = 0x80;
        int green = 0x80;
        int blue = 0x80;
        int alpha = 0x80;
        func_001E7DE8(params, 0x485A0CDB, &a, 0);
        func_001E7DE8(params, 0x7AF07905, &b, 0);
        func_001E7DE8(params, 0x88CF948C, &c, 0);
        int changed = func_001E7DE8(params, 0xB7A78C53, &red, 0) != 0;
        changed |= func_001E7DE8(params, 0xDA7A68B8, &green, 0) != 0;
        changed |= func_001E7DE8(params, 0xAA109C37, &blue, 0) != 0;
        changed |= func_001E7DE8(params, 0x3319CD8D, &alpha, 0) != 0;
        Rgba_0013A380 col(red, green, blue, alpha);
        func_00138860(tex, a, b, c, changed, col);
    }
    return 1;
}
