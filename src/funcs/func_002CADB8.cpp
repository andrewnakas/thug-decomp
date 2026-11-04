typedef int qword __attribute__((mode(TI)));

union Vec_002CADB8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Box_002CADB8 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

struct Park_002CADB8 {
    char pad0[0x352C];
    Box_002CADB8 m352C;
};

extern void* D_0039274C;
extern "C" Park_002CADB8* func_002C0368();
extern "C" Vec_002CADB8 func_002C02B0(void* a, Box_002CADB8* c, Vec_002CADB8* out);

extern "C" bool func_002CADB8(Vec_002CADB8* p, float margin)
{
    Box_002CADB8 b = func_002C0368()->m352C;
    Vec_002CADB8 pos;
    Vec_002CADB8 size;
    pos = func_002C02B0(D_0039274C, &b, &size);
    if (pos.f.x + margin < p->f.x && p->f.x < pos.f.x + size.f.x - margin
        && pos.f.z + margin < p->f.z && p->f.z < pos.f.z + size.f.z - margin)
        return true;
    return false;
}
