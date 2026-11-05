typedef int qword __attribute__((mode(TI)));
union Vec_002960A8 {
    qword q;
    struct { float x, y, z, w; } f;
};

extern "C" float sqrtf(float);
extern "C" float func_001E5318(unsigned int id, int def);

struct Elem_002960A8 {
    int m0;
    char pad4[0x29D];
    unsigned char m2A1;
    char pad2A2[3];
    unsigned char m2A5;
    char pad2A6[0xAA];
};

extern "C" void func_00294AB0(Elem_002960A8* e, Vec_002960A8* out, int k);

struct Mgr_002960A8 {
    char pad[0x20];
    Elem_002960A8 m20[50];
    bool Near(Vec_002960A8* pos, int id, int k, float dy);
};

bool Mgr_002960A8::Near(Vec_002960A8* pos, int id, int k, float dy)
{
    Vec_002960A8 p = *pos;
    p.f.y += dy;
    float r = func_001E5318(0x71B20276, 0);
    for (int i = 0; i < 50; i++) {
        Elem_002960A8* e = &m20[i];
        if (e->m2A5 && e->m0 == id && k < e->m2A1) {
            Vec_002960A8 d;
            func_00294AB0(e, &d, k);
            d.f.x -= p.f.x;
            d.f.y -= p.f.y;
            d.f.z -= p.f.z;
            d.f.w -= p.f.w;
            if (sqrtf(d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z) < r)
                return true;
        }
    }
    return false;
}
