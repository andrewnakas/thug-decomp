typedef int qword_00129220 __attribute__((mode(TI)));

union Vec_00129220 {
    qword_00129220 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Ent_00129220 {
    void* m0;
    int m4;
    int pad8[2];
    Vec_00129220 m10;
};

struct C_00129220 {
    char pad[0x190];
    unsigned char m190;
    unsigned char m191;
    unsigned char m192;
    unsigned char m193;
    char pad194[0xC];
    Ent_00129220 m1A0[0x19];
    int m4C0;
    void* Add(void* a, Vec_00129220* v);
};

extern "C" void* func_00132100();
extern "C" int func_001291B0(C_00129220* o, void* x, void* a);
extern "C" int func_0013EC88(void* x, int r, int g, int b, int a);

void* C_00129220::Add(void* a, Vec_00129220* v)
{
    void* x;
    void* aa = a;
    x = func_00132100();
    if (aa)
        m1A0[m4C0].m4 = func_001291B0(this, x, aa);
    func_0013EC88(x, m190, m191, m192, m193);
    m1A0[m4C0].m0 = x;
    m1A0[m4C0].m10 = *v;
    m4C0++;
    return x;
}
