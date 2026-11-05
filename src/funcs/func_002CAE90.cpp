typedef int qword __attribute__((mode(TI)));

union Vec_002CAE90 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Box_002CAE90 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002CAE90() {}
    ~Box_002CAE90() {}
};

extern void* D_0039274C;
extern "C" Box_002CAE90* func_002BAA28(Box_002CAE90* b, int x, int y, int z, int w, int h, int d);
extern "C" int func_001E8180(void* p, unsigned int key, void** out, int v);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" void* func_002C0368();
extern "C" int func_002BFA78(void* p, Box_002CAE90 b);
extern "C" Vec_002CAE90 func_002C02B0(void* a, Box_002CAE90* c, Vec_002CAE90* out);
extern "C" void* func_0029C320();
extern "C" int func_0029A9C0(void* p, float a, float b, float c, float d);
extern "C" void* func_002977B0();
extern "C" int func_002967E0(void* p, float a, float b, float c, float d);

int func_002CAE90(void* params)
{
    Box_002CAE90 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    void* s = 0;
    if (func_001E8180(params, 0xB4F88771, &s, 0)) {
        int x, z, w, d;
        int ok = 1;
        func_001E7DE8(s, 0x7323E97C, &x, 0);
        func_001E7DE8(s, 0x9D2D8850, &z, 0);
        func_001E7DE8(s, 0xE39CF4ED, &w, 0);
        func_001E7DE8(s, 0x69F93D01, &d, 0);
        b.x = x;
        b.h = 1;
        b.z = z;
        b.w = w;
        b.d = d;
        b.y = 0;
        if (func_002BFA78(func_002C0368(), b)) ok = 0;
        Vec_002CAE90 pos;
        Vec_002CAE90 size;
        pos = func_002C02B0(D_0039274C, &b, &size);
        if (func_0029A9C0(func_0029C320(), pos.f.x + 10.0f, pos.f.z + 10.0f, pos.f.x + size.f.x - 10.0f, pos.f.z + size.f.z - 10.0f)) ok = 0;
        if (func_002967E0(func_002977B0(), pos.f.x, pos.f.z, pos.f.x + size.f.x, pos.f.z + size.f.z)) ok = 0;
        return ok;
    }
    return 0;
}
